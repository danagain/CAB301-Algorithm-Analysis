#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

//Function Prototype
int bruteForceMedian(int array[],int n);
void permute(int k,int size, int A[]);
void swapElement(int x, int y, int A[]);
int factorial(int n);

//Constants
int ARRAY_SIZE = 10;
int NUM_TESTS = 500;

//Globals
int counter = 0;
long basicOperations;
double avgBasicOps;

int main() {
int A[10] = {};

for(int i = 0; i < ARRAY_SIZE; i++){
    A[i] = i + 1;
}
permute(ARRAY_SIZE, ARRAY_SIZE, A);
cout << "Average = " << basicOperations / factorial(ARRAY_SIZE);

}

int bruteForceMedian(int A[],int n){
    int k = ceil(n/2.0);
    counter = 0;
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
            std::cout<< counter << " \n";
            basicOperations += counter;
            return A[i];
        }
    }
    return 0;
}

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


void swapElement(int x, int y, int A[]){
    int temp = A[x];
    A[x]=A[y];
    A[y]=temp;
}

void permute(int k,int size, int A[]){
    int i;
    if (k==0){
        bruteForceMedian(A, size);
    }
    else{
        for (i=k-1;i>=0;i--){
            swapElement(i,k-1,A);
            permute(k-1,size,A);
            swapElement(i,k-1,A);
        }
    }
    return;
}
