# MinGW has a Make program, "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\mingw32-make.exe"
# To use it on this makefile:
# cd C:\mystuff\cpp\makefile_test
# mingw32-make
CC = g++

all: class_test.exe

class_test.exe: myclass.o main.o
	$(CC) -o class_test myclass.o main.o

myclass.o: myclass.h myclass.cpp
	$(CC) -c myclass.cpp

main.o: myclass.h main.cpp
	$(CC) -c main.cpp
