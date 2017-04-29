#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;

// Function Prototype
int bruteForceMedian(int array[],int n);

// Globals
long avg = 0;

// Constants
int ARRAY_SIZE = 3000;
int STEP_SIZE = 50;
int NUM_TESTS = 500;

int main() {
    std::ofstream average("data.txt"); // Output file stream
    srand((unsigned  int)(NULL));
    int count = 0;
    int A[ARRAY_SIZE]; // Declare array for 3k elements
    for(int i = STEP_SIZE; i <= ARRAY_SIZE; i+=STEP_SIZE){ // Start array size at 50, increments of 50
        for(int p = 0; p < NUM_TESTS; p++){ // Test each array size 500 times
            for(int k = 0; k < i; k++){ // Generate random numbers for every test
                A[k] = rand() % 10000; // Random numbers 0-10,000
            }
            count++; // Count loop iterations
            bruteForceMedian(A,i); // Find median algorithm
            if(count % NUM_TESTS == 0){ // when 500 tests is reached
               average  << i << " " << avg/NUM_TESTS << "\n"; // Write the array size and avg count to file
                avg = 0; // Reset average total
                count = 0; // Reset count total
            }
        }
    }
    average.close(); // Close Stream
return 0;
}

int bruteForceMedian(int A[],int n){
    int k = ceil(n/2.0);
    int counter = 0;
    for(int i = 0; i < n; i++){
        int numsmaller = 0, numequal = 0;
        for(int j = 0; j < n; j++){
            counter+=2;
            if(A[j] < A[i]){
                numsmaller++;
                counter-=1;
            }
            else if(A[j] == A[i]){
                numequal++;
            }
        }
        if((numsmaller < k) && (k<= (numsmaller + numequal))){
            avg += counter; //
            return A[i];
        }
    }
    return 0;
}
