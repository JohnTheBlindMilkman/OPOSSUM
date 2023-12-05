# OPOSSUM ౿ᓕ ̤Ꜥ·⦣ - Object Programming Oriented Sub-Standard Utility Multitool

lorem ipsum

## Table of Contents
* [General Info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Usage](#usage)
* [Bugs](#bugs)
* [To-Do](#to-do)

## General Info


## Technologies

The OPOSSUM ౿ᓕ ̤Ꜥ·⦣ has been build using:
- Used OS: Ubuntu 20.04 LTS
- C++ version: 9.4.0
- CERN ROOT version: 6.26/00
- Black Magic (most likely)

The code includes the following repositories: 
- [JSON for Modern C++](https://github.com/nlohmann/json)
- [Activity Indicators for Modern C++](https://github.com/p-ranav/indicators)
- [Argument Parser for Modern C++ ](https://github.com/p-ranav/argparse)

## Setup

Enter the main directory and do:
```
$ mkdir build
$ cd build
$ cmake ../.
$ make
```
The program, by default, does not build the doxygen documentation. If you wish to enable it, add flag to the `cmake` command when building the project:

```
$ cmake ../. -DBUILD_DOC=ON
``` 

**_Note:_**  In order to be able to generate documentation, make sure you have Doxygen and Graphviz installed.

## Usage

Currently, the presented usage is contained within small programs in each subdirectory: base, femto, readers, selection, and utils.

To use the OPOSSUM ౿ᓕ ̤Ꜥ·⦣ in your own ways, I have prepared shared libraries which need to be loaded to your program.

## Bugs

## To-Do

- Finish femtoscopic analysis
- Add other analysis types
- Create writers
- Add the option to work in converter mode
- Add install folder with all .so and .h files
- Add thread safety
- Add documentation