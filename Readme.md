# Multiple polymorphism

Genericity offers a programming paradigm that reconciles polymorphism (static) and performance in order to define algorithms operating on data of different types without additional costs. In C++, this polymorphism is based on templates. Generic and high-performance C++ libraries are intensively based on this paradigm.

While C++ is a language of choice for the development of final scientific applications, it remains too restrictive during the analysis and prototyping phases, for which we prefer generally interactive languages (Python / R / Matlab); this is why many C++ libraries have chosen to export their functionalities through bindings.

The problem remains that the static/generic polymorphism (where each functionality = 1 type) cooperates
wrong with dynamic polymorphism (1 type = multiple features).

This project aims to establish a practical solution to this problem.

## Prerequisites

### Install freeimage and boost via your package manager

```shell
sudo apt install libfreeimage3 libboost-all-dev # Ubuntu
# or
sudo pacman -S freeimage boost # Manjaro
```

### Install conan

```shell
pip install conan
```

### Add the Pylene repository in your conan remotes

```shell
conan remote add lrde-public https://artifactory.lrde.epita.fr/artifactory/api/conan/lrde-public
```

## Clone

```shell
git clone https://github.com/gaziduc/multiple-polymorphism
cd multiple-polymorphism
```

## Build

```shell
mkdir build
cd build
conan install .. --build=missing -s compiler.cppstd=20
cmake ..
make
```

## Launch testsuite

```shell
make test
```

## Usage

```python
import pylene as pln

se = pln.se.disc(10)
# se = pln.se.rectangle(width=5, height=5)

# image is a numpy image
out1 = pln.morpho.dilation(image, se) 
out2 = pln.morpho.erosion(image, se)
out3 = pln.morpho.opening(image, se)
out4 = pln.morpho.closing(image, se)
```
