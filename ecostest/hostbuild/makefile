# eCos makefile

# This is a generated file - do not edit

export HOST := UNIX
export PREFIX := /home/kelvin/hostbuild/install
export COMMAND_PREFIX := 
export CC := $(COMMAND_PREFIX)gcc
export OBJCOPY := $(COMMAND_PREFIX)objcopy
export AR := $(COMMAND_PREFIX)ar

.PHONY: default build clean tests headers

build: headers $(PREFIX)/include/pkgconf/ecos.mak
	$(MAKE) -r -C services/memalloc/common/v3_0 heapgeninc.tcl
	$(MAKE) -r -C services/memalloc/common/v3_0 heaps.cxx
	$(MAKE) -r -C hal/synth/arch/v3_0 $@
	$(MAKE) -r -C hal/synth/i386linux/v3_0 $@
	$(MAKE) -r -C hal/common/v3_0 $@
	$(MAKE) -r -C io/common/v3_0 $@
	$(MAKE) -r -C io/serial/v3_0 $@
	$(MAKE) -r -C infra/v3_0 $@
	$(MAKE) -r -C kernel/v3_0 $@
	$(MAKE) -r -C services/memalloc/common/v3_0 $@
	$(MAKE) -r -C isoinfra/v3_0 $@
	$(MAKE) -r -C language/c/libc/common/v3_0 $@
	$(MAKE) -r -C language/c/libc/i18n/v3_0 $@
	$(MAKE) -r -C language/c/libc/setjmp/v3_0 $@
	$(MAKE) -r -C language/c/libc/signals/v3_0 $@
	$(MAKE) -r -C language/c/libc/startup/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdio/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdlib/v3_0 $@
	$(MAKE) -r -C language/c/libc/string/v3_0 $@
	$(MAKE) -r -C language/c/libc/time/v3_0 $@
	$(MAKE) -r -C language/c/libm/v3_0 $@
	$(MAKE) -r -C io/wallclock/v3_0 $@
	$(MAKE) -r -C error/v3_0 $@
	$(MAKE) -r -C hal/common/v3_0 $(PREFIX)/lib/extras.o
	$(MAKE) -r -C hal/synth/arch/v3_0 $(PREFIX)/lib/target.ld
	$(MAKE) -r -C hal/synth/i386linux/v3_0 $(PREFIX)/lib/vectors.o
	@echo $@ finished

clean:
	$(MAKE) -r -C hal/synth/arch/v3_0 $@
	$(MAKE) -r -C hal/synth/i386linux/v3_0 $@
	$(MAKE) -r -C hal/common/v3_0 $@
	$(MAKE) -r -C io/common/v3_0 $@
	$(MAKE) -r -C io/serial/v3_0 $@
	$(MAKE) -r -C infra/v3_0 $@
	$(MAKE) -r -C kernel/v3_0 $@
	$(MAKE) -r -C services/memalloc/common/v3_0 $@
	$(MAKE) -r -C isoinfra/v3_0 $@
	$(MAKE) -r -C language/c/libc/common/v3_0 $@
	$(MAKE) -r -C language/c/libc/i18n/v3_0 $@
	$(MAKE) -r -C language/c/libc/setjmp/v3_0 $@
	$(MAKE) -r -C language/c/libc/signals/v3_0 $@
	$(MAKE) -r -C language/c/libc/startup/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdio/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdlib/v3_0 $@
	$(MAKE) -r -C language/c/libc/string/v3_0 $@
	$(MAKE) -r -C language/c/libc/time/v3_0 $@
	$(MAKE) -r -C language/c/libm/v3_0 $@
	$(MAKE) -r -C io/wallclock/v3_0 $@
	$(MAKE) -r -C error/v3_0 $@
	@echo $@ finished

tests: build
	$(MAKE) -r -C hal/synth/arch/v3_0 $@
	$(MAKE) -r -C hal/synth/i386linux/v3_0 $@
	$(MAKE) -r -C hal/common/v3_0 $@
	$(MAKE) -r -C io/common/v3_0 $@
	$(MAKE) -r -C io/serial/v3_0 $@
	$(MAKE) -r -C infra/v3_0 $@
	$(MAKE) -r -C kernel/v3_0 $@
	$(MAKE) -r -C services/memalloc/common/v3_0 $@
	$(MAKE) -r -C isoinfra/v3_0 $@
	$(MAKE) -r -C language/c/libc/common/v3_0 $@
	$(MAKE) -r -C language/c/libc/i18n/v3_0 $@
	$(MAKE) -r -C language/c/libc/setjmp/v3_0 $@
	$(MAKE) -r -C language/c/libc/signals/v3_0 $@
	$(MAKE) -r -C language/c/libc/startup/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdio/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdlib/v3_0 $@
	$(MAKE) -r -C language/c/libc/string/v3_0 $@
	$(MAKE) -r -C language/c/libc/time/v3_0 $@
	$(MAKE) -r -C language/c/libm/v3_0 $@
	$(MAKE) -r -C io/wallclock/v3_0 $@
	$(MAKE) -r -C error/v3_0 $@
	@echo $@ finished

headers:
	$(MAKE) -r -C hal/synth/arch/v3_0 $@
	$(MAKE) -r -C hal/synth/i386linux/v3_0 $@
	$(MAKE) -r -C hal/common/v3_0 $@
	$(MAKE) -r -C io/common/v3_0 $@
	$(MAKE) -r -C io/serial/v3_0 $@
	$(MAKE) -r -C infra/v3_0 $@
	$(MAKE) -r -C kernel/v3_0 $@
	$(MAKE) -r -C services/memalloc/common/v3_0 $@
	$(MAKE) -r -C isoinfra/v3_0 $@
	$(MAKE) -r -C language/c/libc/common/v3_0 $@
	$(MAKE) -r -C language/c/libc/i18n/v3_0 $@
	$(MAKE) -r -C language/c/libc/setjmp/v3_0 $@
	$(MAKE) -r -C language/c/libc/signals/v3_0 $@
	$(MAKE) -r -C language/c/libc/startup/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdio/v3_0 $@
	$(MAKE) -r -C language/c/libc/stdlib/v3_0 $@
	$(MAKE) -r -C language/c/libc/string/v3_0 $@
	$(MAKE) -r -C language/c/libc/time/v3_0 $@
	$(MAKE) -r -C language/c/libm/v3_0 $@
	$(MAKE) -r -C io/wallclock/v3_0 $@
	$(MAKE) -r -C error/v3_0 $@
	@echo $@ finished

$(PREFIX)/include/pkgconf/ecos.mak: makefile
	@echo 'ECOS_GLOBAL_CFLAGS = -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions' > $@
	@echo 'ECOS_GLOBAL_LDFLAGS = -g -nostdlib -Wl,--gc-sections -Wl,-static' >> $@
	@echo 'ECOS_COMMAND_PREFIX = $(COMMAND_PREFIX)' >> $@

