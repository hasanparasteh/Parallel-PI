#!/bin/sh

# check type of build
if [ "$1" = "parallel" ]; then
    echo "Parallel build"
    echo "Building..."
    echo "Fix the thread count to -> 4"
    export OMP_NUM_THREADS=4
    clang -Xpreprocessor -fopenmp parallelpi.c -lomp -o build/parallelpi
    echo "Done"
    exit 1;
fi

if [ "$1" = "serial" ]; then
    echo "Serial build"
    echo "Building..."
    clang -Xpreprocessor -fopenmp serialpi.c -lomp -o build/serialpi
    echo "Done"
    exit 1;
fi

echo "ERROR: No build type specified..."