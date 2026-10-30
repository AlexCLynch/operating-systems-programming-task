README.template

## Project Number/Title 

* Authors: Alexander Lynch, Samuel Siew
* Group name: Group-98

## Overview

The program implements parallel merge sort in C using threads. It sorts a 
randomly generated array of integers by recursively splitting the array 
into two and creating a new thread for each half. The number of levels 
created is determined by the user input, as well as the number of elements to 
be sorted and the seed to be used for the random number generator. 

## Manifest

mergesort.h: Public declarations, shared data, and the thread argument structure used by the merge-sort implementation.
mergesort.c: Parallel merge sort, sequential merge sort, merging logic, thread argument creation, and memory management.
test-mergesort.c: Command-line test and benchmark driver that generates input, runs the sort, checks the result, and reports elapsed time.
Makefile: Build and clean targets for the test executable.

## Building the project

Build the code from this directory by using the "make" command.
Delete the generated files by using the "make clean" command.

## Features and usage

This program generates an array of random integers from a supplied seed, and sorts 
them using a multi-threaded merge sort algorithm. The program has three inputs. 
'input size' specifies the number of elements in the array and must be at least 2. 
'cutoff level' specifies how many levels create new threads. 'seed' specifies the 
random seed used to generate the elements of the array. Once the program has 
finished it will ouput the ellapsed sorting time.

Run it with:

```sh
./test-mergesort <input size> <cutoff level> <seed>
```

## Testing

The test driver checks the complete output array for nondecreasing order and
returns a failure status if sorting is unsuccessful. The project was tested by
building with `make` and running the executable with:

```sh
./test-mergesort 2 0 0
./test-mergesort 5 0 0
./test-mergesort 10 1 0
./test-mergesort 11 1 0
./test-mergesort 100000 5 0
./test-mergesort 100000 5 123
./test-mergesort 4 5 0
```

These cases cover the smallest valid input, an odd number of elements,
using multiple threads, inputs smaller than the cutoff, and using a different
seed.

```sh
./test-mergesort 100000000 0 1234
./test-mergesort 100000000 1 1234
./test-mergesort 100000000 2 1234
./test-mergesort 100000000 3 1234
./test-mergesort 100000000 4 1234
./test-mergesort 100000000 5 1234
./test-mergesort 100000000 6 1234
./test-mergesort 100000000 7 1234
./test-mergesort 100000000 8 1234
```

The tests above also assessed the effectiveness of different cuttoffs. The
results were respectively:

```sh
Sorting 100000000 elements took 15.15 seconds.
Sorting 100000000 elements took 7.92 seconds.
Sorting 100000000 elements took 4.65 seconds.
Sorting 100000000 elements took 2.83 seconds.
Sorting 100000000 elements took 2.15 seconds.
Sorting 100000000 elements took 2.13 seconds.
Sorting 100000000 elements took 2.21 seconds.
Sorting 100000000 elements took 2.21 seconds.
Sorting 100000000 elements took 2.22 seconds.
```

Note that results may vary depending on system specifications.

## Known Bugs

The command-line arguments are parsed with `atoi`, so malformed or 
out-of-range numeric arguments are not reported separately.
Segmentation fault when sorting ~1,100,000,000 elements, likely due to integer overflow

## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your own?
What kinds of errors did you get? How did you fix them?

What parts of the project did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this project? How well
did the development and testing process go for you?

Implementing standard mergesort in the my_mergesort function did not take much additional research, while implementing parallel_mergesort required additional readings on top of the textbook chapters on threads. 
A small issue when testing my_mergesort was missing parenthesis when calculating the midpoint, causing a segmentation fault on arrays larger than n = 2. 
The second issue faced was a return NULL in parallel_mergesort at the start of the function, causing the function to exit early, with the testing reporting that sorting had failed on all tests run. 

## Sources Used
GeeksforGeeks, 2025. Thread Management Functions in C. [Online] 
Available at: https://www.geeksforgeeks.org/c/thread-functions-in-c-c/
[Accessed 29 October 2026].
GeeksforGeeks, 2026. Merge Sort. [Online] 
Available at: https://www.geeksforgeeks.org/dsa/merge-sort/
[Accessed 27 October 2026].


