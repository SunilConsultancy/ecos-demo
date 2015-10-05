#include <cyg/kernel/kapi.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define THREADS_MAX 2

#define STACK_MAX 4096
#define RES_MAX 2

typedef int res_t ; /* good to have resource as int since this is only an example */ 

cyg_thread thread_s[2];		/* Create two thread variables  */

char stack[THREADS_MAX][STACK_MAX];		/* space for thread stack */

/* now the handles for the threads */
cyg_handle_t simple_threadA, simple_threadB;

/* Declares routines associated with the threadsss */
cyg_thread_entry_t simple_programA;
cyg_thread_entry_t simple_programB;

cyg_mutex_t mut_t ; /* This mutex can be used to protect critical sections */

cyg_mutex_t res_lock ; /* This mutex is for resource locking */
cyg_cond_t res_wait ; /* Conditional variable */

res_t res_pool[RES_MAX] ; /* This is a pool of resources */
res_t allocatedRes ; /* This holds a resource */

int res_count = RES_MAX ; /* Initally, resource count needs to be maximum */

void res_init(void) /* This routine initializes kernel variable for resource allocation */
{

  cyg_mutex_init(&res_lock) ;
  cyg_cond_init(&res_wait, &res_lock);

}

void res_free(res_t res) /* This routine frees a resource under mutex control  */
{

  cyg_mutex_lock(&res_lock);

  res_pool[res_count] = res ;
  res_count++ ;

  cyg_cond_signal(&res_wait);

  cyg_mutex_unlock(&res_lock);

}

res_t res_allocate(void) /* This routine allocates a resource under mutex control */
{
 
  res_t res ;
  cyg_mutex_lock(&res_lock);

  while ( res_count == 0 )
        cyg_cond_wait(&res_wait); /* The conditional variable puts the thread in blocked state when there are no resources */

  res_count-- ;

  res = res_pool[res_count] ;

  cyg_mutex_unlock(&res_lock);

  return res ;

}

/* This is the first control of execution and creates two ECOS threads  */
void cyg_user_start(void)
{
  printf("***** Comments and suggestions to sunildev40@gmail.com  **** \n") ;
  printf("***** ECOS APPLICATION STARTUP  ******* \n");

  cyg_mutex_init(&mut_t); /* Used to put printf under mutex control */

  res_init() ;

  cyg_thread_create(5, simple_programA, (cyg_addrword_t) 0,
		    "Thread A", (void *) stack[0], STACK_MAX,
		    &simple_threadA, &thread_s[0]);
  cyg_thread_create(4, simple_programB, (cyg_addrword_t) 1,
		    "Thread B", (void *) stack[1], STACK_MAX,
		    &simple_threadB, &thread_s[1]);

  cyg_thread_resume(simple_threadA);
  cyg_thread_resume(simple_threadB);

}


/* This code runs in the context of the first thread */
void simple_programA(cyg_addrword_t data)
{
  int msg = (int) data;
  int delay;

  printf("Start of execution ; thread %d\n", msg);

  cyg_thread_delay(200);

  for (;;) 
  {

    delay = 200 + (rand() % 50);

    allocatedRes  = res_allocate() ;

    cyg_mutex_lock(&mut_t); /* The printf needs to be protected by mutex lock */

    printf("Thread %d: Allocating resource \n", msg ) ;

    cyg_mutex_unlock(&mut_t);

    cyg_thread_delay(delay); /* This delay is necessary for thread switching */

  }

}

/* This code runs in the context of the second thread */
void simple_programB(cyg_addrword_t data)
{
  int msg = (int) data;
  int delay;

  printf("Start of execution ; thread %d\n", msg );

  cyg_thread_delay(200);

  for (;;) 
  {
 
    delay = 200 + (rand() % 50);

    res_free(allocatedRes);
    
    cyg_mutex_lock(&mut_t);

    printf("Thread %d: Freeing resource \n", msg ) ;

    cyg_mutex_unlock(&mut_t);

    cyg_thread_delay(delay); /* This delay is necessary for thread switching */
  
  }

}
