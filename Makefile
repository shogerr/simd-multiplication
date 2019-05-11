arraymult: src/arraymult.cpp simd.p4.o
	g++ -o arraymult src/arraymult.cpp simd.p4.o -lm -fopenmp

simd.p4.o: src/simd.p4.cpp
	g++ -c src/simd.p4.cpp -o simd.p4.o

clean:
	rm *.o
	rm arraymult
