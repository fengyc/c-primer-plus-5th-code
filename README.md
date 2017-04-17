C Primer Plus 5th 代码
=========================

C Primer Plus 5th 的源代码，使用 cmake 组织编译。

使用的工具：cmake、make、CC

外部构建方法：

    # 创建 build 目录，避免污染原代码目录
    mkdir build
    # 在 build 目录里面运行 cmake 生成 makefile
    cd build
    cmake ..
    # 进行 make
    make
