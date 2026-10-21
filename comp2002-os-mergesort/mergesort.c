/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
    // initialise indexes for the left and right side as well as the array itself
    int l = leftstart; // left index
    int r = rightstart; // right index
    int i = leftstart; // main index

    while (l <= leftend && r <= rightend){
        if (A[l] <= A[r]){
            B[i] = A[l];
            l++;
        } else {
            B[i] = A[r];
            r++;
        }
        i++;
    }

    // copy over any leftover elements from left and right sections
    while (l <= leftend){
        B[i] = A[l];
        l++;
        i++;
    }
    while (r <= rightend){
        B[i] = A[r];
        r++;
        i++;
    }

    // copy elements from extra array to main array
    int j;
    for (j = leftstart; j <= rightend; j++){
        A[j] = B[j];
    }

    return;
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
    // specify the input arg uses arguement structure
    struct argument *args = arg;

    // calculate midpoint and use merge function
    int mid = (args->left + args->right) / 2;
        return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
    struct argument * arg = (struct argument *) malloc(sizeof(struct argument));
    arg->left = left;
    arg->right = right;
    arg->level = level;
	return arg;
}

