# AndroidNdkBuildWithCmakelist
Android Ndk Build With Cmakelist


                mkdir build
                cd build 

                /home/dunp/Android/Sdk/cmake/3.22.1/bin/cmake ..
                /home/dunp/Android/Sdk/cmake/3.22.1/bin/cmake --build .

                will get libandroidtestsharedobject.so



# copy libc++_shared.so and built your prj..so (libandroidtestsharedobject.so)

libc++_shared.so

                /home/dunp/Android/Sdk/ndk-bundle/sources/cxx-stl/llvm-libc++/libs/arm64-v8a/libc++_shared.so

                ./android/app/src/main/jniLibs/
                ............................../arm64-v8a/libandroidtestsharedobject.so
                ............................../arm64-v8a/libc++_shared.so
                ............................../armeabi-v7/....
                ............................../x86_x64/....
                ............................../x86/....

                set (ANDROID_STL "c++_shared")
                set (CMAKE_ANDROID_STL_TYPE "c++_shared")
                #/home/dunp/Android/Sdk/ndk-bundle/sources/cxx-stl/llvm-libc++/libs/arm64-v8a/libc++_shared.so


# code c/c++ sample


most important for every function: extern "C" __attribute__((visibility("default"))) __attribute__((used))


                extern "C" __attribute__((visibility("default"))) __attribute__((used))

                char *dunp_test_stdString(char *text)
                {
                    size_t sizeA = strlen(text);
                    char *b = " PONG ";
                    size_t sizeB = strlen(b);
                    size_t size = sizeof(char) * (sizeA + sizeB + 1); // Size of our new memory block large enough to contain both a and b.
                                                                    // Leave additional space for null terminator
                    char *c = (char *)malloc(size);

                    memcpy(c, text, sizeA);      // Copy a into the first half of c
                    memcpy(c + sizeA, b, sizeB); // Copy b into the second half
                    c[sizeA + sizeB] = '\0';     // Assign null terminator to last character
                    // free(c);
                    return c;
                }

# code dart , flutter sample in android

ffi load .so lib


                ffi.DynamicLibrary dylibtest_init({String dirInterop = ""}) {
                if (dirInterop == "") {
                    dirInterop = Directory.current.path;
                }

                var libraryPath = path.join(dirInterop, 'dunpserialport', 'libandroidtestsharedobject.so');

                if (Platform.isMacOS) {
                    libraryPath =
                        path.join(dirInterop, 'dunpserialport', 'libandroidtestsharedobject.dylib');
                } else if (Platform.isWindows) {
                    libraryPath =
                        path.join(dirInterop, 'dunpserialport', 'Debug', 'libandroidtestsharedobject.dll');
                } else if (Platform.isLinux) {
                    libraryPath = path.join(dirInterop, 'dunpserialport', 'libandroidtestsharedobject.so');
                } else {
                    //flutter, android
                    libraryPath = "libandroidtestsharedobject.so";
                }
                print("ffi.DynamicLibrary file: $libraryPath");
                final dylib = ffi.DynamicLibrary.open(libraryPath);

                return dylib;
                }

usage 

                typedef FfiStringFuncString = ffi.Pointer<Utf8> Function(
                    ffi.Pointer<Utf8> str, ffi.Int32 length);
                typedef DartStringFuncString = ffi.Pointer<Utf8> Function(
                    ffi.Pointer<Utf8>, int);


                var dylib = usbseriallibs.dylibtest_init();
                print("dlib--------------OK");
                print(dylib);

                DartStringFuncString testStdString = dylib
                    .lookup<ffi.NativeFunction<FfiStringFuncString>>('dunp_test_stdString')
                    .asFunction();

                var toTest = "Nguyen Phan Du".toNativeUtf8();
                var ressult = testStdString(toTest, toTest.length).toDartString();

                print("dlib--------------testStdString: $ressult");
                            
