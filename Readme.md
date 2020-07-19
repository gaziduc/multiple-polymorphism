# CPPA Project

## Prerequisites

### Install freeimage and boost via your package manager

```
sudo apt install libfreeimage3 libboost-all-dev # Ubuntu
sudo pacman -S freeimage boost # Manjaro
```

### Install conan

```
pip install conan
```

### Add the Pylene repository in your conan remotes

```
conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public
```

## Clone

```
git clone https://github.com/gaziduc/cppa
```

## Build

```
mkdir build
cd build
conan install .. --build=missing -s compiler.cppstd=20
cmake ..
make
```

## Launch testsuite

```
make test
```
