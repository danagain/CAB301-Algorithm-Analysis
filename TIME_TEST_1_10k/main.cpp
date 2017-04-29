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
std::ofstream avg("data.txt");

// Constants
int ARRAY_SIZE = 3000;
int STEP_SIZE = 50;
int NUM_TESTS = 500;

int main() {
    srand((unsigned  int)time(NULL));
    int count = 0;
    double av = 0.0;

    int A[ARRAY_SIZE]; // Declare array for 3k elements
    for(int i = STEP_SIZE; i <= ARRAY_SIZE; i+=STEP_SIZE){ // Start array size at 50, increments of 50
        for(int p = 0; p < NUM_TESTS; p++){ // Test each array size 500 times
            for(int k = 0; k < i; k++){ // Generate random numbers for every test
                A[k] = rand() % 10000; // Random numbers 0-10000
            }
            count++; // Count loop iterations for the average calc
            clock_t start = clock(); // Start the clock
            bruteForceMedian(A,i); // Find median algorithm
            clock_t end = clock(); // End the clock
            double time = (double) (end-start) / CLOCKS_PER_SEC*1000; // Record running time in ms
            av += time;
            if(count % NUM_TESTS == 0){ //when 500 tests is reached
                avg << i << " " << av/NUM_TESTS << "\n"; //write the average to file
                av = 0; //reset average total
            }
        }
    }
    avg.close();
    return 0;
}


int bruteForceMedian(int A[],int n){
    int k = ceil(n/2.0);
    for(int i = 0; i < n; i++){
        int numsmaller = 0, numequal = 0;
        for(int j = 0; j < n; j++){
            if(A[j] < A[i]){
                numsmaller++;
            }
            else if(A[j] == A[i]){
                numequal++;
            }
        }
        if((numsmaller < k) && (k<= (numsmaller + numequal))){
            return A[i];
        }
    }
    return 0;
}
