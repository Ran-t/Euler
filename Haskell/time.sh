#!/bin/bash
compile="ghc solution.hs -o solution.bin $1 $2 $3 $4 $5"


echo $compile > time.txt
$compile >> time.txt
echo -e "\ntime ./solution.bin" >> time.txt
(time ./solution.bin) &>> time.txt


cat time.txt
