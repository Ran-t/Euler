#!/bin/bash
compile="g++ solution.cpp $1 $2 $3 $4 $5"

echo $compile > time.txt
$compile >> time.txt

echo "time ./a.out" >> time.txt
(time ./a.out) &>> time.txt

cat time.txt
