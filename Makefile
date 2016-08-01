all: main
	g++ main.o graph_loader.o find_components.o -o find_comps.out -fopenmp
	
main: libs
	clang-omp -c -fopenmp main.cpp

libs:
	clang-omp -c -fopenmp lib/graph_loader.cpp lib/find_components.cpp