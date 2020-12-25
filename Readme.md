# Multiple polymorphism

Genericity offers a programming paradigm that reconciles polymorphism (static) and performance in order to define algorithms operating on data of different types without additional costs. In C++, this polymorphism is based on templates. Generic and high-performance C++ libraries build on therefore intensively on this paradigm.

While C++ is a language of choice for the development of final scientific applications, it remains too restrictive during the analysis and prototyping phases, for which we prefer generally interactive languages (Python / R / Matlab); this is why many C++ libraries have chosen to export their functionalities through bindings.

The problem remains that the static/generic polymorphism (where each functionality = 1 type) cooperates
wrong with dynamic polymorphism (1 type = multiple features).

This project aims to establish a practical solution to this problem.

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
