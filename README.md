C Primer Plus 5th 代码
=========================

C Primer Plus 5th 的源代码，使用 cmake 组织编译。

使用的工具：cmake、make、CC

windows 上使用 msys2 ，在 msys2 中安装 make、gcc、gdb、cmake

外部构建方法：

    # 创建 build 目录，避免污染原代码目录
    mkdir build
    # 在 build 目录里面运行 cmake 生成 makefile
    cd build
    cmake ..
    # 进行 make
    make
