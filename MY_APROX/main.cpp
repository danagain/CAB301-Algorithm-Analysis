#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

    int main() {
        ofstream avg ("predictionAverages.txt");
        double nMax = 3000, sum = 0;
        for(double n = 50; n <= nMax; n+=50){
            sum = 0;
            for(double i = (2*n - ceil(n/2) + 1); i <=
                    (((3*n*n)/2) + (n/2)); i++){
                sum += i;
            }
            double result = sum / ((((3*(n*n))/2) + n/2) - (2*n - ceil(n/2) + 1));
            std::cout << result << "\n";
            avg << n << " " << result << "\n";
        }
        avg.close();
        return 0;
    }


//For n starting at 2
//int main() {
  //  double nMax = 10, sum = 0;
    //for(double n = 2; n <= nMax; n+=1){
        //sum = 0;
      //  for(double i = (2*n - ceil(n/2) + 1); i <=
          //                                    (((3*n*n)/2) + (n/2)); i++){
           // sum += i;
        //}
        //double result = sum / ((((3*(n*n))/2) + n/2) - (2*n - ceil(n/2) + 1));
        //std::cout << result << "\n";
    //}
    //return 0;
//}
