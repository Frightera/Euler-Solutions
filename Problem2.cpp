#include <iostream>
#include <sys/time.h>
#include <iomanip> 

using namespace std;
  
// Driver code 
int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	
	
	long long int f1 = 0, f2 = 2; 
    long long int sum = f1 + f2; 
  	
  	// F2 - F5 - F8 and so on should be calculated
  	// Calculating non-even numbers are not necessary
    while (f2 <= 4000000){ 
        // next even number of Fibonacci series 
        long long int f3 = 4*f2 + f1; // Fnext = 4*F5 + F2 
  										 // Fnext = 4*8 + 2 
        if (f3 > 4000000) {
            break; 
	} 
        f1 = f2; 
        f2 = f3; 
        sum += f2; 
    } 
   
    cout << sum << endl;
	
	
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}
