#! /bin/sh

for j in 'a', 'b', 'c', 'd'
do
	for i in 1000 100000 10000000 100000000 500000000 1000000000 1500000000 1750000000 2000000000
	do
		./arraymult $i $j
	done
done
