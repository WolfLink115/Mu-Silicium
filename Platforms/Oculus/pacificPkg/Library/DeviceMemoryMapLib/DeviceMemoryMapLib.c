STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceAttribute, ArmAttributes, ResourceType, MemoryType

  // DDR Regions
  {"DBI Dump",          0x80010000, 0x00014000,         NoHob,  MMAP_IO, INITIALIZED,   Conv,   NS_DEVICE},
  {"HLOS 0",            0x80100000, 0x00100000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK},
  {"UEFI FD",           0x80200000, 0x00100000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"MPPark Code",       0x80300000, 0x00080000,         AddMem, MEM_RES, UNCACHEABLE,   RtCode, UNCACHED_UNBUFFERED},
  {"FBPT Payload",      0x80380000, 0x00001000,         AddMem, SYS_MEM, SYS_MEM_CAP,   RtData, UNCACHED_UNBUFFERED},
  {"DBG2",              0x80381000, 0x00004000,         AddMem, SYS_MEM, SYS_MEM_CAP,   LdData, UNCACHED_UNBUFFERED},
  {"Capsule Header",    0x80385000, 0x00001000,         AddMem, SYS_MEM, SYS_MEM_CAP,   RtData, UNCACHED_UNBUFFERED},
  {"TPM Control Area",  0x80386000, 0x00003000,         AddMem, SYS_MEM, SYS_MEM_CAP,   RtData, UNCACHED_UNBUFFERED},
  {"UEFI Info Block",   0x80389000, 0x00001000,         AddMem, SYS_MEM, SYS_MEM_CAP,   RtData, UNCACHED_UNBUFFERED},
  {"Reset Data",        0x8038A000, 0x00003000,         AddMem, SYS_MEM, SYS_MEM_CAP,   RtData, UNCACHED_UNBUFFERED},
  {"Reser. Uncached 0", 0x8038D000, 0x00073000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, UNCACHED_UNBUFFERED},
  {"Display Reserved",  0x80400000, 0x00800000,         AddMem, MEM_RES, WRITE_THROUGH, MaxMem, WRITE_THROUGH},
  {"UEFI Stack",        0x80C00000, 0x00040000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"CPU Vectors",       0x80C40000, 0x00010000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"Reserved Cached 0", 0x80C50000, 0x000B0000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"HLOS 1",            0x80D00000, 0x03300000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"HLOS 2",            0x84000000, 0x01800000,         AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK},
  {"HYP",               0x85800000, 0x00600000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"MPSS_EFS",          0x85E00000, 0x00180000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"ADSP_EFS",          0x85F80000, 0x00020000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"HLOS 3",            0x85FA0000, 0x00060000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK},
  {"SMEM",              0x86000000, 0x00200000,         AddMem, MEM_RES, UNCACHEABLE,   Reserv, UNCACHED_UNBUFFERED},
  {"TZ_STAT",           0x86200000, 0x00100000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"TAGS",              0x86300000, 0x00100000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"TZ",                0x86400000, 0x00200000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"TZ Apps",           0x86600000, 0x00E00000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"Stargate",          0x87400000, 0x01400000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"PIL_REGION",        0x88800000, 0x08700000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"CNSS_DEBUG",        0x90F00000, 0x00300000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Reserv, NS_DEVICE},
  {"HLOS 4",            0x91200000, 0x0EE00000,         AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK},

  // Other memory regions
  {"IMEM Base",         0x06680000, 0x00040000,         NoHob,  MMAP_IO, INITIALIZED,   Conv,   NS_DEVICE},
  {"IMEM Cookie Base",  0x066BF000, 0x00001000,         AddDev, MMAP_IO, INITIALIZED,   Conv,   NS_DEVICE},

  // Register regions
  {"RPM MSG RAM",       0x00068000, 0x00008000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"Security Ctrl",     0x00070000, 0x00010000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"PRNG_CFG_PRNG",     0x00080000, 0x00010000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"GCC CLK CTL",       0x00300000, 0x000A0000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"MPM2 MPM",          0x004A0000, 0x00040000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"UFS UFS REGS",      0x00620000, 0x00020000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"CRYPTO0 CRYPTO",    0x00640000, 0x00040000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"CORE_TOP_CSR",      0x00700000, 0x00100000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"MMSS",              0x00800000, 0x00800000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"TLMM CSR",          0x01000000, 0x00310000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"PMIC ARB SPMI",     0x04000000, 0x01C00000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"HMSS_QLL",          0x06400000, 0x00200000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"USB30_PRIM",        0x06A00000, 0x00200000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE
  {"COPSS_ISTARI",      0x07400000, 0x00400000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"HMSS",              0x09800000, 0x00800000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"PCIE WRAPPER AXI",  0x0C000000, 0x04000000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"PCIE WRAPPER AHB",  0x00600000, 0x00018000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},
  {"PCIE PHY",          0x00034000, 0x00004000,         AddDev, MMAP_IO, UNCACHEABLE,   MmIO,   NS_DEVICE},

  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}
