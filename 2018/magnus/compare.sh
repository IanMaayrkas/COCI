#!/bin/bash

PROBLEM=$1

for i in 1 2 3
do
    diff $PROBLEM.dummy.out.$i $PROBLEM.out.$i
done
