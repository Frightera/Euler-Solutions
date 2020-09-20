#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <math.h>

/*
Output: The triplet product: 31875000
Time taken by program is : 0.021757 sec (It may vary)
*/
// Simple brute force solution.
using namespace std;

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	
	int k, n, m;
	for (k=1; k<=500; k++) { // 500 is the max value that they can have
		for (n=1; n<=500; n++) { // even if they are equal.
			m=1000-k-n;
			if (pow(k,2)+pow(n,2) == pow(m,2) && k<n ) {
				cout<<"The triplet product: " << k*n*m << endl;
			}
		}
	}		
	
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}
