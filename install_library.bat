git clone https://github.com/lfreist/hwinfo lib/hwinfo 
cd lib/hwinfo
mkdir build
cmake -B build -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE 
cmake --build build
cmake --install build