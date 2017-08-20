INC=-I/usr/lib/llvm-3.8/include

FindDeclarations: FindDeclarations.cpp
	clang++-3.9 -std=c++11 -Wall $(INC) -o $@ $^ /usr/lib/llvm-3.8/lib/libclang.so

clean:
	rm -f FindDeclarations.o FindDeclarations
