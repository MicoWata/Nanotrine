@echo off

gcc main.c^
 -lgdi32 -lkernel32 -lopengl32 -luser32 -lwinmm^
 -o triangle && triangle
