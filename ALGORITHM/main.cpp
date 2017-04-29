#include <iostream>
#include <math.h>


int BruteForceMedian(int A[], int n);


int main() {
    int A[] ={8,6,1,2,3,4,5,9,10};
    BruteForceMedian(A, 10);
    return 0;
}


int BruteForceMedian(int A[], int n){
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
}
