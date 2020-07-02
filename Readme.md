# CPPA Project

## Prerequisites

### Install freeimage

Ubuntu:
```
sudo apt install libfreeimage3
```

Manjaro:

```
sudo pacman -S freeimage
```

### Add the Pylene repository in your conan remotes

```
conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public
```

## Clone

```
git clone --recurse-submodules https://github.com/gaziduc/cppa
```

## Build

```
mkdir build
cd build
conan install .. --build missing
cmake ..
make
```
