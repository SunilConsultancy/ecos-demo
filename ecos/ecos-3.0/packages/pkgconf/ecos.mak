 
ECOS_GLOBAL_CFLAGS = -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -mcpu=603e -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions
2	ECOS_GLOBAL_LDFLAGS = -mcpu=603e -g -nostdlib -Wl,--gc-sections -Wl,-static
3	ECOS_COMMAND_PREFIX = powerpc-eabi-