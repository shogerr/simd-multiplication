final: arraymult
test: test_arraymult

simd.p4.o: src/simd.p4.cpp
	g++ -c src/simd.p4.cpp -o simd.p4.o
arraymult: src/arraymult.cpp simd.p4.o
	g++ -o arraymult src/arraymult.cpp simd.p4.o -lm -fopenmp -DSIMD
test_arraymult: src/arraymult.cpp
	g++ -o test_arraymult src/arraymult.cpp -lm -fopenmp
