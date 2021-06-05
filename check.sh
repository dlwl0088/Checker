#!/usr/bin/bash

for query in n1 n3 n5 n8 s1 s3 s5 s8
do
    printf "lcc_yeast_$query " >> result.txt
    ./build/main/program ./data/lcc_yeast.igraph ./query/lcc_yeast_$query.igraph ./embedding/embedding_yeast_$query.txt >> result.txt
done

for query in n1 n3 n5 n8 s1 s3 s5 s8
do
    printf "lcc_human_$query " >> result.txt
    ./build/main/program ./data/lcc_human.igraph ./query/lcc_human_$query.igraph ./embedding/embedding_human_$query.txt >> result.txt
done

for query in n1 n3 n5 n8 s1 s3 s5 s8
do
    printf "lcc_hprd_$query " >> result.txt
    ./build/main/program ./data/lcc_hprd.igraph ./query/lcc_hprd_$query.igraph ./embedding/embedding_hprd_$query.txt >> result.txt
done