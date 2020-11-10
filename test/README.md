### Tests for ft_containers
###### _By Sam Kortekaas (skorteka)_

###### _Powered by Catch2_


##### Project structure:

In Makefile, include the directories that contain the includes you need for you containers to work. 

For the example file structure below you have to change INCLUDE in the ft_containers_tests Makefile to:

_INCLUDE = -I../List -I../Vector -I../Vector/Whatever_

    ft_containers/
    │
    └── List/
    │   └── List.hpp
    │
    └── Vector/
    │   ├── Vector.hpp
    │   │   ...
    │   │   ...
    │   └── Whatever/
    │       ├── Extra.hpp
    │       └── Utils.hpp
    │
    └── ft_containers_tests/

##### Usage:
- cd to ft_containers/ft_containers_tests/

Normal test run:
- make run (will run all tests)

Check for memory problems (better on Linux, but works on Mac)
- make run asan=1

