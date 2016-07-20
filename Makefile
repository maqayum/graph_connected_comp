all: main
	g++ -o bin main.o graph_loader.o
	
main: libs
	clang-omp -c -fopenmp main.cpp

libs:
	clang-omp -c lib/graph_loader.cpp lib/find_components.cpp