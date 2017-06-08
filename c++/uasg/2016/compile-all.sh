#!/bin/bash

for d in task-*/; do
    DIR="$d/main.cpp"
    eval "g++ $DIR"
done
