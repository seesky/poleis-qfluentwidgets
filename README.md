# qfluentwidgets

Qt6/C++ Fluent Widgets library for Poleis.

## Build Requirements

- CMake 3.21+
- vcpkg
- Qt 6 from vcpkg: `qtbase`, `qtsvg`, `qtmultimedia`
- jsoncpp from vcpkg

Windows should use the native MSVC toolchain. Linux/macOS use the platform compiler selected by the CMake generator.

## Configure

Set `VCPKG_ROOT` to your existing vcpkg checkout so this project reuses the same vcpkg instance as Poleis.

```powershell
$env:VCPKG_ROOT = "D:\vcpkg"
cmake --preset windows-msvc
```

Equivalent explicit command:

```powershell
cmake -S . -B build\windows-msvc -G "Visual Studio 17 2022" -A x64 `
  -DCMAKE_TOOLCHAIN_FILE=D:\vcpkg\scripts\buildsystems\vcpkg.cmake `
  -DVCPKG_TARGET_TRIPLET=x64-windows
```

The build directory is local to this repo (`build/windows-msvc`), so it will not collide with the Poleis build directory.

## Build

```powershell
cmake --build build\windows-msvc --config Release --target qfluentwidgets
```

Examples/tests are optional:

```powershell
cmake -S . -B build\windows-msvc -G "Visual Studio 17 2022" -A x64 `
  -DCMAKE_TOOLCHAIN_FILE=D:\vcpkg\scripts\buildsystems\vcpkg.cmake `
  -DVCPKG_TARGET_TRIPLET=x64-windows `
  -DQFLUENTWIDGETS_BUILD_EXAMPLES=ON
cmake --build build\windows-msvc --config Release
```

## Use From Poleis

Install or add this repo as a subdirectory.

Installed package usage:

```cmake
find_package(qfluentwidgets CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE qfluentwidgets::qfluentwidgets)
```

Subdirectory usage:

```cmake
add_subdirectory(path/to/poleis-qfluentwidgets)
target_link_libraries(your_target PRIVATE qfluentwidgets::qfluentwidgets)
```

## Notes

- The library target is a shared library.
- On Windows, public symbols are exported with `WINDOWS_EXPORT_ALL_SYMBOLS`.
- The vcpkg manifest keeps QtBase features minimal to avoid pulling unrelated SQL backends such as PostgreSQL/libpq.
