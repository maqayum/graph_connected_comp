all: main
	g++ -o bin main.o graph_loader.o
	
main: libs
	clang-omp -c -fopenmp main.cpp

libs:
	g++ -c lib/graph_loader.cpp