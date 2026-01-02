### Computer graphics programming in OpenGL with C++

1. Getting started
2. [The OpenGL Pipeline](https://github.com/emelyantsev/computer_graphics_programming_in_opengl_with_cpp/tree/main/03_edition/ch02)



#### Build GLM

```bash
cmake \
    -DGLM_BUILD_TESTS=OFF \
    -DBUILD_SHARED_LIBS=OFF \
    -B build .cmake \
    -DGLM_BUILD_TESTS=OFF \
    -DBUILD_SHARED_LIBS=OFF \
    -B build .

cmake --build build -- all
cmake --build build -- install
```




