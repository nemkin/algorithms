#!/bin/bash
for in_file in $(find $2 -name '*.in')
do
    etalon_file=${in_file%.in}.ans
    out_file=${in_file%.in}.out
    
    ./$1 <$in_file >$out_file && diff -w $etalon_file $out_file && echo "$in_file : AC" || echo "$in_file : WA"
done
