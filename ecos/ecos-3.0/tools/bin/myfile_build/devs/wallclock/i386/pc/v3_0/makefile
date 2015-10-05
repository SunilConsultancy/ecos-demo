# eCos makefile

# This is a generated file - do not edit

export PREFIX := /opt/ecos/ecos-3.0/tools/bin/myfile_install
export COMMAND_PREFIX := i386-elf-
export CC := $(COMMAND_PREFIX)gcc
export OBJCOPY := $(COMMAND_PREFIX)objcopy
export HOST := UNIX
export AR := $(COMMAND_PREFIX)ar

export REPOSITORY := /opt/ecos/ecos-3.0/packages
PACKAGE := devs/wallclock/i386/pc/v3_0
OBJECT_PREFIX := devs_wallclock_i386_pc
CFLAGS := -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions
LDFLAGS := -g -nostdlib -Wl,--gc-sections -Wl,-static
VPATH := $(REPOSITORY)/$(PACKAGE)
INCLUDE_PATH := $(INCLUDE_PATH) -I$(PREFIX)/include $(foreach dir,$(VPATH),-I$(dir) -I$(dir)/src -I$(dir)/tests) -I.
MLT := $(wildcard $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.ldi $(REPOSITORY)/$(PACKAGE)/include/pkgconf/mlt*.h)
TESTS := 

build: headers

headers: mlt_headers $(PREFIX)/include/cyg/io/devices_wallclock_i386_pc.inl

$(PREFIX)/include/cyg/io/devices_wallclock_i386_pc.inl: $(REPOSITORY)/$(PACKAGE)/include/devices_wallclock_i386_pc.inl
	@mkdir -p $(dir $@)
	@cp $< $@
	@chmod u+w $@

include $(REPOSITORY)/pkgconf/rules.mak

