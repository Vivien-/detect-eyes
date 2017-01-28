# detect-eyes
Detect eyes from persons in an input image

# Install DLIB

http://dlib.net/compile.html

How to compile
Compiling C++ Example Programs on Any Operating System Using CMake

The best way to compile a program that uses dlib is to use CMake. For example, the following commands will compile the example programs on any operating system:


`cd examples`

`mkdir build`

`cd build`

`cmake ..`

`cmake --build . --config Release`


Note that you also need to have a C++11 compiler installed on your system. There are free C++11 compilers for most operating systems. For example, Visual Studio is free on Windows and GCC is free and works well on Mac OS X and Linux systems. If you have multiple compilers/IDEs installed then you can tell CMake which one you want it to use via the -G option.


The examples/CMakeLists.txt file tells CMake how to build the examples. You can create your own projects by starting with this file and editing it however you like. You can also perform additional configuration of a cmake project using the cmake-gui or ccmake tool. For example, if you are using dlib's face detector then you should turn on either SSE4 or AVX instructions since this makes it run much faster (also see this FAQ[http://dlib.net/faq.html#Whyisdlibslow]).


Finally, note that when using Visual Studio, CMake will by default generate a 32bit executable. This means the programs you compile will only be able to use 2GB of RAM. To avoid this, you need to tell CMake to generate a 64bit executable. You do this by using a command like


`cmake -G "Visual Studio 14 2015 Win64" ..`

instead of

`cmake ..`

You can see the list of valid arguments to -G by running cmake with no options.
