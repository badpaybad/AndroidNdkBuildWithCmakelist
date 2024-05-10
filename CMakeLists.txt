cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME "androidtestsharedobject")
# project(${PROJECT_NAME} LANGUAGES CXX)

set (CMAKE_SYSTEM_NAME "Android")
set (ANDROID_NDK "/home/dunp/Android/Sdk/ndk/23.1.7779620")
set (CMAKE_ANDROID_NDK "/home/dunp/Android/Sdk/ndk/23.1.7779620") 
set (CMAKE_TOOLCHAIN_FILE "/home/dunp/Android/Sdk/ndk/26.2.11394342/build/cmake/android.toolchain.cmake")
set (ANDROID_ABI "arm64-v8a")
set (CMAKE_ANDROID_ARCH_ABI "arm64-v8a")  # Set the architecture
set (ANDROID_PLATFORM "android-26")
set (ANDROID_TOOLCHAIN "clang")

set (ANDROID_STL "c++_shared")
set (CMAKE_ANDROID_STL_TYPE "c++_shared")
#/home/dunp/Android/Sdk/ndk-bundle/sources/cxx-stl/llvm-libc++/libs/arm64-v8a/libc++_shared.so


set (ANDROID_CPP_FEATURES "rtti exceptions")
set (CMAKE_EXPORT_COMPILE_COMMANDS "ON")
# Set the C++ standard
# set(CMAKE_CXX_STANDARD 11)

# set (TOOLCHAIN "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64")
# set (TARGET "aarch64-linux-android")
# set (TARGET_ARCH 
# set (API "26")


set (CMAKE_C_COMPILER "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang")
set (CMAKE_CXX_COMPILER "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang++")

# set (AR "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ar") 
set (CMAKE_AR "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ar") 
# set (RANLIB "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ranlib")
set (CMAKE_RANLIB "/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-ranlib")

# Set additional compiler flags if needed
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -pedantic -Wmissing-prototypes -Wshadow")

set (CMAKE_BUILD_TYPE "Release")
set (BUILD_SHARED_LIBS "1")
# set (CMAKE_CXX_FLAGS "-std=c++11 -frtti -fexceptions")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
# set (CMAKE_C_FLAGS "-O3")
#set ("CMAKE_PREFIX_PATH=../../")

add_library(${PROJECT_NAME} SHARED
    "libtest.cpp"
)

# STRIP_PATH="/home/dunp/Android/Sdk/ndk/26.2.11394342/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android-strip" "/work/AndroidNdkBuildWithCmakelist/build/libandroidtestsharedobject.so"

# /home/dunp/Android/Sdk/cmake/3.22.1/bin/cmake
# cd build
# /home/dunp/Android/Sdk/cmake/3.22.1/bin/cmake ..
# /home/dunp/Android/Sdk/cmake/3.22.1/bin/cmake --build .

