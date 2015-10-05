# eCos makefile

# This is a generated file - do not edit

export PREFIX := /home/kelvin/kernel-net/install
export COMMAND_PREFIX := 
export CC := $(COMMAND_PREFIX)gcc
export OBJCOPY := $(COMMAND_PREFIX)objcopy
export HOST := UNIX
export AR := $(COMMAND_PREFIX)ar

export REPOSITORY := /opt/ecos/ecos-3.0/packages
PACKAGE := hal/synth/i386linux/v3_0
OBJECT_PREFIX := hal_synth_i386linux
CFLAGS := -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions
LDFLAGS := -g -nostdlib -Wl,--gc-sections -Wl,-static
VPATH := $(REPOSITORY)/$(PACKAGE)
INCLUDE_PATH := $(INCLUDE_PATH) -I$(PREFIX)/include $(foreach dir,$(VPATH),-I$(dir) -I$(dir)/src -I$(dir)/tests) -I.
MLT := $(wildcard $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.ldi $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.h)
TESTS := 

build: headers libtarget.a.stamp

LIBRARY := libtarget.a
COMPILE := src/context.S src/syscall-i386-linux-1.0.S src/profile.c
OBJECTS := $(COMPILE:.cxx=.o.d)
OBJECTS := $(OBJECTS:.cpp=.o.d)
OBJECTS := $(OBJECTS:.c=.o.d)
OBJECTS := $(OBJECTS:.S=.o.d)

$(LIBRARY).stamp: $(OBJECTS)
	$(AR) rcs $(PREFIX)/lib/$(@:.stamp=) $(foreach obj,$?,$(if $(obj:%.o=),$(dir $(obj))$(OBJECT_PREFIX)_$(notdir $(obj:.o.d=.o)),$(obj)))
	@cat $(foreach obj,$^,$(obj:.o=.o.d)) > $(@:.stamp=.deps)
	@touch $@

$(PREFIX)/lib/vectors.o: $(wildcard $(REPOSITORY)/$(PACKAGE)/src/vectors.S)
	$(CC) -Wp,-MD,vectors.tmp $(INCLUDE_PATH) $(CFLAGS) -c -o $@ $<
	@echo $@ ": \\" > $(notdir $@).deps
	@tail -n +2 vectors.tmp >> $(notdir $@).deps
	@echo >> $(notdir $@).deps
	@rm vectors.tmp
	

headers: mlt_headers $(PREFIX)/include/cyg/hal/arch.inc $(PREFIX)/include/cyg/hal/var_arch.h $(PREFIX)/include/cyg/hal/var_intr.h $(PREFIX)/include/cyg/hal/basetype.h $(PREFIX)/include/cyg/hal/var_io.h

$(PREFIX)/include/cyg/hal/arch.inc: $(REPOSITORY)/$(PACKAGE)/include/arch.inc
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/var_arch.h: $(REPOSITORY)/$(PACKAGE)/include/var_arch.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/var_intr.h: $(REPOSITORY)/$(PACKAGE)/include/var_intr.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/basetype.h: $(REPOSITORY)/$(PACKAGE)/include/basetype.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/var_io.h: $(REPOSITORY)/$(PACKAGE)/include/var_io.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

include $(REPOSITORY)/pkgconf/rules.mak

