**Readme.md**

First, install freeimage
(on Ubuntu: sudo apt install libfreeimage3)
(on Manjaro: sudo pacman -S freeimage)

Then:

```
mkdir build
cd build
conan install .. --build missing
cmake ..
make
./cppa
```
