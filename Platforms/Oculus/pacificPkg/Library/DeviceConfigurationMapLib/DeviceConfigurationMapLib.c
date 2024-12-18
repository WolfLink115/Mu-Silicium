#include <Library/DeviceConfigurationMapLib.h>

STATIC
CONFIGURATION_DESCRIPTOR_EX
gDeviceConfigurationDescriptorEx[] = {
  // Configuration Map
  {"SerialPortBufferSize", 0x8000},
  {"NumCpusFuseAddr", 0x5C04C},
  {"EnableShell", 0x1},
  {"SharedIMEMBaseAddr   ", 0x066BF000},
  {"MassStorageCookieAddr", 0x007B3000},
  {"MassStorageCookieOffset", 0x0},
  {"MassStorageCookieSize", 0x4},
  {"MemoryCaptureModeOffset", 0x1C},
  {"AbnormalResetOccurredOffset", 0x24},
  {"NumCpus", 4},
  {"NumActiveCores", 2},
  {"MaxLogFileSize", 0x800000},
  {"USBHS1_Config", 0x0},
  {"UsbFnIoRevNum", 0x00010001},
  {"PwrBtnShutdownFlag", 0x0},
  {"Sdc1GpioConfigOn", 0x1E92},
  {"Sdc2GpioConfigOn", 0x1E92},
  {"Sdc1GpioConfigOff", 0xA00},
  {"Sdc2GpioConfigOff", 0xA00},
  {"EnableSDHCSwitch", 0x1},
  {"RpmbHalfSectorGranularity", 2},
  {"PSHoldOffset", 0xB000},
  {"PSHoldSHFT", 0x0},
  {"GCCResetValueAddress", 0x066BF028},
  {"PCIeRPNumber", 0x0101},
  {"SecurityFlag", 0x00},
  {"HaltBootOnFuseBlown", 0x0},

  // Terminator
  {"Terminator", 0xFFFFFFFF}
};

CONFIGURATION_DESCRIPTOR_EX*
GetDeviceConfigurationMap ()
{
  return gDeviceConfigurationDescriptorEx;
}
