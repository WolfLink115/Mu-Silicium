##
#
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = pacific
  PLATFORM_GUID                  = 884C6AE8-3127-4426-AF52-0A7B6AD96495
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/pacificPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = pacificPkg/pacific.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0
  # Set this to 1 If your Device is A/B Device
  AB_SLOT_SUPPORT                = 1
  HAS_BUILD_IN_KEYBOARD          = 0

# If your SoC has multiple variants keep these Build Options
# If not don't add "-DSOC_TYPE=$(SOC_TYPE)" to the Build Options.
[BuildOptions]
  *_*_*_CC_FLAGS = -DAB_SLOT_SUPPORT=$(AB_SLOT_SUPPORT) -DHAS_BUILD_IN_KEYBOARD=$(HAS_BUILD_IN_KEYBOARD)

[LibraryClasses]
  DeviceMemoryMapLib|pacificPkg/Library/DeviceMemoryMapLib/DeviceMemoryMapLib.inf
  DeviceConfigurationMapLib|pacificPkg/Library/DeviceConfigurationMapLib/DeviceConfigurationMapLib.inf

[PcdsFixedAtBuild]
  # DDR Start Address
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000

  # Device Maintainer
  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"WolfLink115"

  # CPU Vector Address
  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x80C40000

  # UEFI Stack Addresses
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x80C00000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Oculus"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Pacific"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"Pacific"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Oculus_Pacific"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Pacific"

  # Simple FrameBuffer
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|2560
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|1440
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferColorDepth|32

  # Dynamic RAM Start Address
  gQcomPkgTokenSpaceGuid.PcdRamPartitionBase|0xA0000000

  # SD Card Slot
  gQcomPkgTokenSpaceGuid.PcdSDCardSlotPresent|FALSE             # If your Phone has no SD Card Slot, Set it to FALSE.
  
  # USB Controller
  gQcomPkgTokenSpaceGuid.PcdStartUsbController|TRUE            # This should be TRUE unless your UsbConfigDxe is Patched to be Dual Role.

[PcdsDynamicDefault]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|2560
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1440
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|2560
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1440
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|320
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|76
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|320
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|76

!include MSM8996Pkg/MSM8996Pkg.dsc.inc
