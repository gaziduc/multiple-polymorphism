# Readme.md

## Prerequisites
First, install freeimage:

Ubuntu:
```
sudo apt install libfreeimage3
```

Manjaro:

```
sudo pacman -S freeimage
```

## Build and launch

Then:
```
mkdir build
cd build
conan install .. --build missing
cmake ..
make
./cppa
```
