pushd %~dp0
rmdir /S /Q CMakeFiles 2>nul
rmdir /S /Q Debug 2>nul
rmdir /S /Q Dependencies 2>nul
rmdir /S /Q Downloads 2>nul
rmdir /S /Q prefix 2>nul
rmdir /S /Q Release 2>nul
rmdir /S /Q Win32 2>nul
del CMakeCache.txt 2>nul
del *.vcxproj* 2>nul
del cmake_install.cmake 2>nul
del Project.sln 2>nul
popd
