#! /bin/sh

for j in 'a', 'b', 'c', 'd'
do
	for i in 1 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
	do
		./arraymult $i $j
	done
done
