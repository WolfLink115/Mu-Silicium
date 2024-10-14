#ifndef _DEVICE_CONFIGURATION_MAP_LIB_H_
#define _DEVICE_CONFIGURATION_MAP_LIB_H_

#include <PiPei.h>

#define CONFIGURATION_NAME_MAX_LENGTH 64

typedef struct {
  CHAR8  Name[CONFIGURATION_NAME_MAX_LENGTH];
  UINT64 Value;
} CONFIGURATION_DESCRIPTOR_EX, *PCONFIGURATION_DESCRIPTOR_EX;

CONFIGURATION_DESCRIPTOR_EX*
GetDeviceConfigurationMap ();

#endif /* _DEVICE_CONFIGURATION_MAP_LIB_H_ */
