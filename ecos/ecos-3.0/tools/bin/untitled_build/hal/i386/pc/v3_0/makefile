# eCos makefile

# This is a generated file - do not edit

export PREFIX := /opt/ecos/ecos-3.0/tools/bin/untitled_install
export COMMAND_PREFIX := i386-elf-
export CC := $(COMMAND_PREFIX)gcc
export OBJCOPY := $(COMMAND_PREFIX)objcopy
export HOST := UNIX
export AR := $(COMMAND_PREFIX)ar

export REPOSITORY := /opt/ecos/ecos-3.0/packages
PACKAGE := hal/i386/pc/v3_0
OBJECT_PREFIX := hal_i386_pc
CFLAGS := -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions
LDFLAGS := -g -nostdlib -Wl,--gc-sections -Wl,-static
VPATH := $(REPOSITORY)/$(PACKAGE)
INCLUDE_PATH := $(INCLUDE_PATH) -I$(PREFIX)/include $(foreach dir,$(VPATH),-I$(dir) -I$(dir)/src -I$(dir)/tests) -I.
MLT := $(wildcard $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.ldi $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.h)
TESTS := 

build: headers libtarget.a.stamp

LIBRARY := libtarget.a
COMPILE := src/hal_diag.c src/plf_misc.c src/plf_stub.c
OBJECTS := $(COMPILE:.cxx=.o.d)
OBJECTS := $(OBJECTS:.cpp=.o.d)
OBJECTS := $(OBJECTS:.c=.o.d)
OBJECTS := $(OBJECTS:.S=.o.d)

$(LIBRARY).stamp: $(OBJECTS)
	$(AR) rcs $(PREFIX)/lib/$(@:.stamp=) $(foreach obj,$?,$(if $(obj:%.o=),$(dir $(obj))$(OBJECT_PREFIX)_$(notdir $(obj:.o.d=.o)),$(obj)))
	@cat $(foreach obj,$^,$(obj:.o=.o.d)) > $(@:.stamp=.deps)
	@touch $@

headers: mlt_headers $(PREFIX)/include/cyg/hal/platform.inc $(PREFIX)/include/cyg/hal/plf_misc.h $(PREFIX)/include/cyg/hal/plf_intr.h $(PREFIX)/include/cyg/hal/plf_arch.h $(PREFIX)/include/cyg/hal/hal_diag.h $(PREFIX)/include/cyg/hal/plf_io.h $(PREFIX)/include/cyg/hal/plf_stub.h

$(PREFIX)/include/cyg/hal/platform.inc: $(REPOSITORY)/$(PACKAGE)/include/platform.inc
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/plf_misc.h: $(REPOSITORY)/$(PACKAGE)/include/plf_misc.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/plf_intr.h: $(REPOSITORY)/$(PACKAGE)/include/plf_intr.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/plf_arch.h: $(REPOSITORY)/$(PACKAGE)/include/plf_arch.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/hal_diag.h: $(REPOSITORY)/$(PACKAGE)/include/hal_diag.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/plf_io.h: $(REPOSITORY)/$(PACKAGE)/include/plf_io.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

$(PREFIX)/include/cyg/hal/plf_stub.h: $(REPOSITORY)/$(PACKAGE)/include/plf_stub.h
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

include $(REPOSITORY)/pkgconf/rules.mak

