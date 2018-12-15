#!/bin/bash

PROBLEM=$1

for i in 1 2 3
do
    cat $PROBLEM.dummy.in.$i | python $PROBLEM.py > $PROBLEM.out.$i
done
