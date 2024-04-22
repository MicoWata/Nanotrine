# Hello triangle in C, using bare win32 and OpenGL

This project is about :
* creating a win32 window with an opengl 3.3 context to draw a triangle in minimal, easy to read, plain C.
* learning to build graphic engines from the bare operating system level.
* providing a learnopengl.com ready project away from dependency driven development.

Included files :
* triangle.exe, to run and test the program before reading.
* run.cmd, a command file to compile and run the project in a simple console command.
* main.c, a single C file which :
  * opens a window then draws a triangle in it twice per second,
  * answers mouse and keyboard inputs,
  * requires no dependency outside the operating system.

Requirements :
* A Windows operating system, like Windows 10.
* Any C compiler, but GCC is required to use the included run file.
* Experience in at least another typed programming language.

Links :
* Download GCC https://sourceforge.net/projects/mingw-w64/
* Learn opengl https://learnopengl.com/Getting-started/Hello-Triangle

References
* Learn opengl Hello triangle source code https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.1.hello_triangle/hello_triangle.cpp
* Triangle from scratch in Rust https://rust-tutorials.github.io/triangle-from-scratch/
