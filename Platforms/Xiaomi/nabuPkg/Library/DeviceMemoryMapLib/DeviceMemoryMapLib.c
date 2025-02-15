#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  {"RAM Partition",     0x80000000, 0x05700000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Hypervisor",        0x85700000, 0x00600000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"RAM Partition",     0x85D00000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN},
  {"AOP",               0x85F00000, 0x00020000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"AOP CMD DB",        0x85F20000, 0x00020000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"GPU PRR",           0x85F40000, 0x00010000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x85F50000, 0x000B0000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"SMEM",              0x86000000, 0x00200000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED},
  {"QTEE",              0x86200000, 0x01800000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"TZApps",            0x87A00000, 0x03D00000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"PIL Reserved",      0x8B700000, 0x0F400000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN},
  {"DBI Dump",          0x99E00000, 0x00D22000, NoHob,  MMAP_IO, INITIALIZED, Conv,   UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x9AB22000, 0x010DE000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Sched Heap",        0x9BC00000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"Display Reserved",  0x9C000000, 0x02400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},
  {"TGCM",              0x9E400000, 0x01400000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN},
  {"FV Region",         0x9F800000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"UEFI FD",           0x9FC00000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"SEC Heap",          0x9FF00000, 0x0008C000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"CPU Vectors",       0x9FF8C000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"MMU PageTables",    0x9FF8D000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"USB UCSI Temp",     0x9FF90000, 0x00002000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN},
  {"RAM Partition",     0x9FF92000, 0x0001E000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN},
  {"UEFI Stack",        0x9FFB0000, 0x00020000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"RSRV1",             0x9FFD0000, 0x0000A000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"TPMControl",        0x9FFDA000, 0x00003000, AddMem, MEM_RES, WRITE_COMBINEABLE, RtData, UNCACHED_UNBUFFERED_XN},
  {"Reset Data",        0x9FFDD000, 0x00004000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED_XN},
  {"RSRV3",             0x9FFE1000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"Capsule Header",    0x9FFE2000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED_XN},
  {"RSRV2",             0x9FFE3000, 0x00014000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"Log Buffer",        0x9FFF7000, 0x00008000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"Info Blk",          0x9FFFF000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"DXE Heap",          0xA0000000, 0x03C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"RAM Partition",     0xA3C00000, 0x15D00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

  // Memory Hole: 0xB9900000 -> 0xC0000000 (0x06700000)

  {"MPSS_EFS",          0xC0000000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN},

  // Other Regions
  {"AOP_SS_MSG_RAM",    0x0C300000, 0x00100000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
  {"IMEM Base",         0x14680000, 0x00040000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},

  // Register Regions
  {"GCC_CLK_CTL",       0x00100000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MMCX_CPR3",         0x00630000, 0x00004000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SECURITY CONTROL",  0x00780000, 0x00007000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QUPV3_0_GSI",       0x00800000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QUPV3_1_GSI",       0x00A00000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QUPV3_2_GSI",       0x00C00000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PRNG_CFG_PRNG",     0x00790000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"UFS2 UFS REGS",     0x01D60000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"UFS UFS REGS",      0x01D80000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"CRYPTO0 CRYPTO",    0x01DC0000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TCSR_TCSR_REGS",    0x01FC0000, 0x00030000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GPU_GMU_CX_BLK",    0x02C7D000, 0x00002000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GPU_CC",            0x02C90000, 0x0000A000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GPU_CPR",           0x02C9A000, 0x00004000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_WEST",         0x03100000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_EAST",         0x03500000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_NORTH",        0x03900000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TLMM_SOUTH",        0x03D00000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QUPV3_SSC_GSI",     0x05A00000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PERIPH_SS",         0x08800000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MCCC_MCCC_MSTR",    0x090B0000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"NPU_CC",            0x09910000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB30_PRIM",        0x0A600000, 0x0011B000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB_RUMI",          0x0A720000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB30_SEC",         0x0A800000, 0x0011B000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB30_MP",          0x0A400000, 0x0011B000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB_MP_RUMI1",      0x0A520000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB_MP_RUMI2",      0x0A522000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"VIDEO_CC",          0x0AB00000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TITAN_SS_TITAN_1",  0x0AC00000, 0x0004A000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TITAN_A_CCI",       0x0AC4A000, 0x00004000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TITAN_SS_TITAN_2",  0x0AC4E000, 0x000B2000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TITAN_CAM_CC",      0x0AD00000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"DISP_CC",           0x0AF00000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PDC_DISPLAY",       0x0B290000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PDC_DISP_SEQ",      0x0B490000, 0x00020000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"RPMH_BCM_BCM_TOP",  0x0BA00000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"RPMH_CPRF_CPRF",    0x0C200000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SLP_CNTR",          0x0C221000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TSENS0",            0x0C222000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TSENS1",            0x0C223000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TSENS0_TM",         0x0C263000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PSHOLD",            0x0C264000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"TSENS1_TM",         0x0C265000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PMIC ARB SPMI",     0x0C400000, 0x02800000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SILVER_CLK_CTL",    0x18280000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GOLD_CLK_CTL",      0x18282000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"L3_CLK_CTL",        0x18284000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GOLDPLUS_CLK_CTL",  0x18286000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SILVER_ACD",        0x18290000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GOLD_ACD",          0x18292000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"L3_ACD",            0x18294000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GOLDPLUS_ACD",      0x18296000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_RSC_APPS_RSCC",0x18200000, 0x00030000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_ACTPM_WRAP",   0x18300000, 0x000B0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_GIC500_GICD",  0x17A00000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_GIC500_GICR",  0x17A60000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_IPC_INT",      0x17C00000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"APSS_WDT_TMR1",     0x17C10000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"QTIMER",            0x17C20000, 0x00110000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_0_WRAPPER_AXI",0x60000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_1_WRAPPER_AXI",0x40000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_2_WRAPPER_AXI",0x68000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_3_WRAPPER_AXI",0x70000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_0_WRAPPER_AHB",0x01C00000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_1_WRAPPER_AHB",0x01C08000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_2_WRAPPER_AHB",0x01C10000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PCIE_3_WRAPPER_AHB",0x01C18000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"REFGEN_GEN3X2_AHB", 0x088E5000, 0x00004000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MDSS",              0x0AE00000, 0x00134000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SMMU",              0x15000000, 0x000D0000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},

  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}