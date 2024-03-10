# Install script for directory: /__w/mcu-rs-f303k8/mcu-rs-f303k8/mbed-os/connectivity/nanostack/sal-stack-nanostack

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/opt/mbed-os-toolchain/gcc-arm-none-eabi-10.3-2021.07/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/6LoWPAN/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/BorderRouter/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/Common_Protocols/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/Core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/DHCPv6_Server/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/DHCPv6_client/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/MAC/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/MLE/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/MPL/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/NWK_INTERFACE/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/RPL/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/Security/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/Service_Libs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/configs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/ipv6_stack/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/libDHCPv6/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/__w/mcu-rs-f303k8/mcu-rs-f303k8/cmake_build/NUCLEO_F303K8/release/GCC_ARM/mbed-os/connectivity/nanostack/sal-stack-nanostack/source/libNET/cmake_install.cmake")
endif()

