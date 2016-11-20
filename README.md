# HammingDistanceLib
\cond [![MIT license](http://img.shields.io/badge/license-MIT-brightgreen.svg)](http://opensource.org/licenses/MIT) [![Build Status](https://travis-ci.org/kartikkumar/cppbase.svg?branch=master)](https://travis-ci.org/kartikkumar/cppbase)[![Coverity Scan Build Status](https://scan.coverity.com/projects/3686/badge.svg)](https://scan.coverity.com/projects/3686) [![Coverage Status](https://coveralls.io/repos/github/kartikkumar/cppbase/badge.svg?branch=master)](https://coveralls.io/github/kartikkumar/cppbase?branch=master) \endcond

Library to calculate Hamming distance between 2 binary blobs

Features
------
  - Templated calculation function. Could be run for any fundamental C++ datatypes blobs.
  - Automatic API documentation ([Doxygen](http://www.doxygen.org "Doxygen homepage"))

Requirements
------

To install this project, please ensure that you have installed the following (install guides are provided on the respective websites):
  - [Git](http://git-scm.com)
  - A C++ compiler, e.g., [GCC](https://gcc.gnu.org/), [Visual Studio](https://www.visualstudio.com/)
  - [CMake](http://www.cmake.org "CMake homepage")
  - [Boost](http://www.boost.org "Boost homepage") (unit testing)
  - [Doxygen](http://www.doxygen.org "Doxygen homepage") (optional)

Installation
------

Run the following commands to download, build, and install this project. 

    git clone https://github.com/serge-koshelev/HammingDistanceLib.git
    cd HammingDistanceLib
    mkdir build && cd build
    cmake .. && cmake --build .
    make install
    
Build options
-------------

You can pass the following, general command-line options when running CMake:

  - `-DCMAKE_INSTALL_PREFIX[=$install_dir]`: set path prefix for install script (`make install`); if not set, defaults to usual locations
  - `-DBUILD_SHARED_LIBS=[ON|OFF (default)]`: build shared libraries instead of static
  - `-DBUILD_DOXYGEN_DOCS[=ON|OFF (default)]`: build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation ([LaTeX](http://www.latex-project.org/) must be installed with `amsmath` package)
  - `-DBUILD_TESTS[=ON|OFF (default)]`: build tests (execute tests from build-directory using `ctest -V`)
