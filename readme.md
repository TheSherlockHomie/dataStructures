# Data Structures in C++

Implementation of various data structures in C++ for practice.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine. Be sure to see how the project is structured down below.

### Prerequisites

```
> A modern C++ compiler
> Visual Studio 2019 (comes with MSVC Compiler as part of the Desktop Development for C++ module)
```

The project and the solution files were made for Visual Studio 2019. However, the code is standard C++ and any compiler should work.

### Running

-   Clone the repo

```
git clone https://github.com/TheSherlockHomie/dataStructures.git
cd dataStructures
```

-   Open the solution file in Visual Studio
-   Choose the project you want to run. Right click and select 'build'
-   Run the compiled executable

## How the repo is structured

### Directory Structure

You'll find directories for various data structures (Graphs, Binary Search Trees etc) in the root of the repository. Navigating to a directory might lead to several subdirectories containing various different implementations of said data structure OR a cpp and various VS specific peoject files.
The cpp files can directly be compiled into an executable regardless of platform. However, to use the project files, Visual Studio is required.

### Visual Studio Solution Structure

There is a `.sln` file at the root of the repository. This solution file contains several different projects for implementations of the data structures. To work with a particular data structure, select the respective project and open the source `.cpp` file. (Make sure to select the `show all files` button in the solution explorer to actually see the directories in the project)
Visual Studio is currently set to store all compiled binaries in `$(Project Directory)/bin`, and all intermediate files in `$(Project Directory)/bin-int`. If you add a new project, make sure they follow these guidelines.

_This above is how the repository is structured for now. Suggestions for better structuring are welcomed. Also, support for a build system like premake or cmake is planned. Kindly open an issue or see [contributing.md](./contributing.md) for suggestions/contributions._

## Contributing

Please read [contributing.md](./contributing.md) for details.

## Authors

_Initial work_ - [TheSherlockHomie](https://github.com/TheSherlockHomie)

See also the list of [contributors](https://github.com/your/project/contributors).

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments and Thanks

Problem statements have been taken from some websites. In such cases, full credit and copyright for that part of the file goes to their respective owners.
