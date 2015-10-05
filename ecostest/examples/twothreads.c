#include <cyg/kernel/kapi.h>
#include <stdio.h>

cyg_handle_t simple_threadA ;
cyg_thread_entry_t simple_programA ;
cyg_thread thread_s[2];
char stack[2][4096] ;

void simple_programA(cyg_addrword_t data)
{

}

void cyg_user_start(void)
{


  cyg_thread_create(5, simple_programA, 0, "threadA", stack[0], 4096, &simple_threadA, &thread_s[0]);

}

#ifdef HH2

#include <cyg/kernel/kapi.h>
#include <stdio.h>

char stack[2][4096] ;

cyg_thread_entry_t simpleProgramA, simpleProgramB ;
cyg_handle_t simple_threadA, simple_threadB ;
cyg_thread thread_s[2] ;
cyg_mutex_t lockA, lockB ;
cyg_cond_t res_wait ;

void simple_programA(cyg_addrword_t data)
{

  while(1) {

      cyg_mutex_lock(&lockA);

      cyg_cond_wait(&res_wait);

      printf("simpleA \n") ;

      cyg_mutex_unlock(&lockA);

      cyg_thread_delay(100) ;

  }

}

void simple_programB(cyg_addrword_t data)
{
  while(1) {

    cyg_mutex_lock(&lockB);

    printf("simpleB \n") ;

    cyg_mutex_unlock(&lockB);

    cyg_cond_signal(&res_wait);

    cyg_thread_delay(100) ;

  }

}
void cyg_user_start(void)
{

  cyg_mutex_init(&lockA);
  cyg_mutex_init(&lockB);
  cyg_cond_init(&res_wait, &lockA);
 
  cyg_thread_create(5, simple_programA, 0, "ThreadA", stack[0], 4096, &simple_threadA,&thread_s[0]);
  cyg_thread_create(4, simple_programB, 0, "ThreadB", stack[1], 4096, &simple_threadB, &thread_s[1]);

  cyg_thread_resume(simple_threadA);
  cyg_thread_resume(simple_threadB);

}
#endif

#ifdef HH1

#include <cyg/kernel/kapi.h>
#include <stdio.h>
#include <stdio.h>

cyg_thread_entry_t simple_programA, simple_programB ;
cyg_handle_t simple_threadA, simple_threadB ;
cyg_thread thread_s[2] ;
cyg_mutex_t res_lock, m_lock1, m_lock2 ;
cyg_cond_t res_wait ;
int rescount ;

char stack[2][4096] ;

void simple_programA(cyg_addrword_t data)
{

  for(;;)
  {
   printf("In A above \n") ;

   while ( rescount == 0 ) cyg_cond_wait(&res_wait) ; 

   cyg_mutex_lock(&m_lock2);

   rescount-- ;
   printf("in A \n") ;
   cyg_mutex_unlock(&m_lock2);
   cyg_thread_delay(200) ;

  }

}

void simple_programB(cyg_addrword_t data)
{

  for(;;)
  {
      cyg_mutex_lock(&m_lock1);
      printf("In B \n") ;

      rescount++ ;
   
      cyg_cond_signal(&res_wait);
 
      cyg_thread_delay(100) ;
      cyg_mutex_unlock(&m_lock1);
  }

}

void cyg_user_start(void)
{

  rescount = 0 ;
  cyg_mutex_init(&m_lock1);
  cyg_mutex_init(&m_lock2);
  cyg_mutex_init(&res_lock);
  cyg_cond_init(&res_wait, &res_lock);
  cyg_thread_create(5, simple_programA,  0, "threadA", stack[0], 4096, &simple_threadA, &thread_s[0]);
  cyg_thread_create(4, simple_programB,  0, "threadB", stack[1], 4096, &simple_threadB, &thread_s[1]);
  cyg_thread_resume(simple_threadA);
  cyg_thread_resume(simple_threadB);


} 


#endif


#ifdef HH
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
  printf("***** ECOS APPLICATION STARTUP  ******* \n");

  printf("***** Comments and suggestions to sunildev40@gmail.com  ******* \n");

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

#endif
