cmake -B build -S . -DCMAKE_INSTALL_PREFIX=bin -DBUILD_32BIT=ON
cmake --build build -j`nproc`
cmake --install build
rm -rf build
