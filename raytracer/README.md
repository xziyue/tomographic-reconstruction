# CT Ray Tracer

## Building

- This project is built with [cmake](https://cmake.org/).
- If you clone the repository, the submodules in `library/` are not downloaded by default. In order to download them, use:
  ```
  git submodule update --init --recursive
  ```
- To build the project, create a new building directory and build with cmake. The binaries will be put in `bin/`.
  ```
  $ mkdir build
  $ cd build
  $ cmake ..
  $ cmake --build . --target ct_raytracer --config Release
  ```

## Usage

The binary `ct_raytracer` takes two arguments: `<input JSON filename>` and `<output JSON filename>`. An example of input JSON file can be found [here](https://raw.githubusercontent.com/xziyue/tomographic-reconstruction/master/script/config.json). This program is called in the Jupyter notebook [file](https://github.com/xziyue/tomographic-reconstruction/blob/master/script/ct.ipynb).

