#!/bin/bash

# Build an Android kernel that is actually UEFI disguised as the Kernel
cat ./BootShim/AARCH64/BootShim.bin "./Build/pacificPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/PACIFIC_UEFI.fd" > "./Build/pacificPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/PACIFIC_UEFI.fd-bootshim"||exit 1
gzip -c < "./Build/pacificPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/PACIFIC_UEFI.fd-bootshim" > "./Build/pacificPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/PACIFIC_UEFI.fd-bootshim.gz"||exit 1
cat "./Build/pacificPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/PACIFIC_UEFI.fd-bootshim.gz" ./Resources/DTBs/pacific.dtb > ./Resources/bootpayload.bin||exit 1

# Create bootable Android boot.img
python3 ./Resources/Scripts/mkbootimg.py \
  --kernel ./Resources/bootpayload.bin \
  --ramdisk ./Resources/ramdisk \
  --kernel_offset 0x00008000 \
  --ramdisk_offset 0x01000000 \
  --tags_offset 0x00000100 \
  --os_version 7.1.1 \
  --os_patch_level "$(date '+%Y-%m')" \
  --header_version 1 \
  -o Mu-Pacific.img \
  ||_error "\nFailed to create Android Boot Image!\n"
