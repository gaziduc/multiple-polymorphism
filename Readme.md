# CPPA Project

## Prerequisites

### freeimage
First, install freeimage:

Ubuntu:
```
sudo apt install libfreeimage3
```

Manjaro:

```
sudo pacman -S freeimage
```

### Add the repository in your conan remotes

```
conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public
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
