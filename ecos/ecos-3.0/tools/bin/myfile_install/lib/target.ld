STARTUP(vectors.o)
ENTRY(_start)
INPUT(extras.o)
GROUP(libtarget.a libgcc.a libsupc++.a)




MEMORY
{
    ram : ORIGIN = 0x0, LENGTH = 0x1000000
}

SECTIONS
{
   
    .vectors 0x108000 : { . = .; KEEP(*(.vectors)) } > ram
    .text ALIGN (0x4) : { _stext = .; *(.text*) *(.gnu.warning) *(.gnu.linkonce*) *(.init) } > ram _etext = .; PROVIDE (etext = .);
    .fini ALIGN (0x4) : { . = .; *(.fini) } > ram
    .rodata1 ALIGN (0x8) : { . = .; *(.rodata1) } > ram
    .rodata ALIGN (0x8) : { . = .; *(.rodata*) } > ram
    .fixup ALIGN (0x4) : { _FIXUP_START_ = ABSOLUTE(.); *(.fixup) _FIXUP_END_ = ABSOLUTE(.);} > ram
    .gcc_except_table ALIGN (0x1) : { _EXCEPT_START_ = ABSOLUTE(.); KEEP(*(.gcc_except_table)) *(.gcc_except_table.*) _EXCEPT_END_ = ABSOLUTE(.);} > ram
    .rel.text ALIGN (0x1) : { *(.rel.text*) *(.rel.gnu.linkonce*) } > ram .rel.data ALIGN (0x1) : { *(.rel.data*) } > ram .rel.got ALIGN (0x1) : { *(.rel.got) } > ram
    .data ALIGN (0x8) : { __ram_data_start = ABSOLUTE(.); *(.data*) _GOT1_START_ = ABSOLUTE(.); *(.got1) _GOT1_END_ = ABSOLUTE(.); . = ALIGN(8); __CTOR_LIST__ = ABSOLUTE(.); KEEP(*(SORT(.ctors*))) __CTOR_END__ = ABSOLUTE(.); __DTOR_LIST__ = ABSOLUTE(.); KEEP(*(SORT(.dtors*))) __DTOR_END__ = ABSOLUTE(.); . = ALIGN(32); KEEP(*( SORT (.ecos.table.*))); _GOT2_START_ = ABSOLUTE(.); *(.got2) _GOT2_END_ = ABSOLUTE(.); _GOT_START_ = ABSOLUTE(.); _GLOBAL_OFFSET_TABLE_ = ABSOLUTE(. + 32768); _SDA_BASE_ = ABSOLUTE(.); *(.got.plt) *(.got) _GOT_END_ = ABSOLUTE(.); *(.dynamic) *(.eh_frame) _SDATA_START_ = ABSOLUTE(.); *(.sdata*) . = ALIGN (4); *(.2ram.*) } > ram __rom_data_start = LOADADDR(.data); __ram_data_end = .; PROVIDE(__ram_data_end = .); _edata = .; PROVIDE (edata = .);
    .sbss ALIGN (0x4) : { __bss_start = ABSOLUTE (.); _SBSS_START_ = ABSOLUTE(.); *(.sbss*) _SBSS_END_ = ABSOLUTE(.); *(.scommon*) } > ram
    .bss ALIGN (0x10) : { . = .; *(.dynbss*) *(.bss*) *(COMMON) } > ram __bss_end = .;
    __pci_window = ALIGN(0x10); . = __pci_window + 0x64000;
    __heap1 = ALIGN (0x8);
    . = ALIGN(4); _end = .; PROVIDE (end = .);
}
idtStart = 0x00001000;
hal_vsr_table = 0x00001800;
hal_virtual_vector_table = 0x00001c00;
cyg_hal_smp_cpu_sync = 0x00002800;
cyg_hal_smp_cpu_sync_flag = 0x00002900;
cyg_hal_smp_cpu_entry = 0x00002a00;
cyg_hal_smp_cpu_running = 0x00002b00;
cyg_hal_smp_vsr_sync_flag = 0x00002c00;
