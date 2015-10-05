STARTUP(vectors.o)
ENTRY(_start)
INPUT(extras.o)
GROUP(libtarget.a libgcc.a libsupc++.a libgcc_eh.a)
MEMORY
{
    rom : ORIGIN = 0x01000000, LENGTH = 0x800000
    ram : ORIGIN = 0x02000000, LENGTH = 0x800000
}
SECTIONS
{
   
    .vectors 0x01000000 : { . = .; KEEP(*(.vectors)) } > rom
    .text ALIGN (0x4) : { _stext = .; *(.text*) *(.gnu.warning) *(.gnu.linkonce.t.*) *(.init) *(.note.gnu.build-id) } > rom _etext = .; PROVIDE (etext = .);
    .fini ALIGN (0x4) : { . = .; *(.fini) } > rom
    .rodata1 ALIGN (0x8) : { . = .; *(.rodata1) } > rom
    .rodata ALIGN (0x8) : { . = .; *(.rodata*) *(.gnu.linkonce.r.*) } > rom
    .fixup ALIGN (0x4) : { _FIXUP_START_ = ABSOLUTE(.); *(.fixup) _FIXUP_END_ = ABSOLUTE(.);} > rom
    .rel.text : { *(.rel.text) *(.rel.text.*) *(.rel.gnu.linkonce.t*) } > rom .rela.text : { *(.rela.text) *(.rela.text.*) *(.rela.gnu.linkonce.t*) } > rom .rel.data : { *(.rel.data) *(.rel.data.*) *(.rel.gnu.linkonce.d*) } > rom .rela.data : { *(.rela.data) *(.rela.data.*) *(.rela.gnu.linkonce.d*) } > rom .rel.rodata : { *(.rel.rodata) *(.rel.rodata.*) *(.rel.gnu.linkonce.r*) } > rom .rela.rodata : { *(.rela.rodata) *(.rela.rodata.*) *(.rela.gnu.linkonce.r*) } > rom .rel.got : { *(.rel.got) } > rom .rela.got : { *(.rela.got) } > rom .rel.ctors : { *(.rel.ctors) } > rom .rela.ctors : { *(.rela.ctors) } > rom .rel.dtors : { *(.rel.dtors) } > rom .rela.dtors : { *(.rela.dtors) } > rom .rel.init : { *(.rel.init) } > rom .rela.init : { *(.rela.init) } > rom .rel.fini : { *(.rel.fini) } > rom .rela.fini : { *(.rela.fini) } > rom .rel.bss : { *(.rel.bss) } > rom .rela.bss : { *(.rela.bss) } > rom .rel.plt : { *(.rel.plt) } > rom .rela.plt : { *(.rela.plt) } > rom .rel.dyn : { *(.rel.dyn) } > rom
    . = ALIGN (0x4) ; . = ALIGN(8) ; .eh_frame_hdr . : { . = .; *(.eh_frame_hdr) } > rom = 0 . = ALIGN(8) ; .eh_frame . : AT ((LOADADDR (.eh_frame_hdr) + SIZEOF (.eh_frame_hdr) + 8 - 1) & ~ (8 - 1)) { . = .; __EH_FRAME_BEGIN__ = .; KEEP(*(.eh_frame)) KEEP(*(.eh_frame*)) __EH_FRAME_END__ = .; . = ALIGN(4) ; . = . + 8; } > rom = 0
    .rel.got ALIGN (0x1) : { *(.rel.got) } > rom
    .gcc_except_table ALIGN (0x1) : { _EXCEPT_START_ = ABSOLUTE(.); *(.gcc_except_table) *(.gcc_except_table.*) _EXCEPT_END_ = ABSOLUTE(.);} > rom
    .tls 0x02000000 : {
        *(.tls.*)
    } > ram
    .data 0x02000100 : { __ram_data_start = ABSOLUTE(.); *(.data*) *(.gnu.linkonce.d.*) _GOT1_START_ = ABSOLUTE(.); *(.got1) _GOT1_END_ = ABSOLUTE(.); . = ALIGN(8); __CTOR_LIST__ = ABSOLUTE(.); KEEP(*(SORT(.ctors*))) __CTOR_END__ = ABSOLUTE(.); __DTOR_LIST__ = ABSOLUTE(.); KEEP(*(SORT(.dtors*))) __DTOR_END__ = ABSOLUTE(.); . = ALIGN(8); __init_array_start__ = ABSOLUTE(.); KEEP(*(SORT(.init_array*))) __init_array_end__ = ABSOLUTE(.); . = ALIGN(32); KEEP(*( SORT (.ecos.table.*))); _GOT2_START_ = ABSOLUTE(.); *(.got2) _GOT2_END_ = ABSOLUTE(.); _GOT_START_ = ABSOLUTE(.); _GLOBAL_OFFSET_TABLE_ = ABSOLUTE(. + 32768); _SDA_BASE_ = ABSOLUTE(.); *(.got.plt) *(.got) _GOT_END_ = ABSOLUTE(.); *(.dynamic) _SDATA_START_ = ABSOLUTE(.); *(.sdata*) *(.gnu.linkonce.s.*) } > ram __rom_data_start = LOADADDR(.data); __ram_data_end = .; PROVIDE(__ram_data_end = .); _edata = .; PROVIDE (edata = .);
    .sbss ALIGN (0x4) : { __bss_start = ABSOLUTE (.); _SBSS_START_ = ABSOLUTE(.); *(.sbss*) *(.gnu.linkonce.sb.*) _SBSS_END_ = ABSOLUTE(.); *(.scommon*) } > ram
    .bss ALIGN (0x10) : { . = .; *(.dynbss*) *(.bss*) *(COMMON) *(.gnu.linkonce.b.*) } > ram __bss_end = .;
    __heap1 = ALIGN (0x10);
    .synth_heap __heap1 : { . = .; . = 0x02800000 - __heap1 ; } > ram
    . = ALIGN(4); _end = .; PROVIDE (end = .);
}
