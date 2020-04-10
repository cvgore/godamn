# godamn

## __new macro

Since while in debugging mode we're using memory leak detector, we need to use 
now `__new` instead of `new` when dynamically allocating memory.

```c++
int* m = __new int(2);
```

## Adding new files (*.cpp/*.h)

When creating new file remember to include it into folder-scoped file `CMakeLists.txt` like that:
(i.e: if creating file within `Entities`, add it into `Entities/CMakeLists.txt`)

```cmake
target_sources(GodamnLib
    PRIVATE
        ... [other files] ...
        MyFile.cpp
        MyFile.h
)
```

## Building

1. Download SFML library (_2.5.1, VC15 32-bit_) from https://www.sfml-dev.org/files/SFML-2.5.1-windows-vc15-32-bit.zip.
Then unpack contents to `C:/SFML-2.5.1` folder.

2. Make sure, that your Visual Studio installation supports CMake projects nad contains CMake tools
(if you can make CMake project within Project Wizard window, it's ok)

## License

GPLv2
