#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <math.h>

/*
Output: Sum is 142913828922
Time taken by program is : 0.790487 sec (It may vary)
*/
// Simple brute force solution. However it can be solved by
// using maps & bits.
using namespace std;
bool isPrime(int n);

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	
	unsigned long long sum = 0; // avoiding overflow
	for(int i = 3;i<2000000; i+=2) {
		if(isPrime(i)) {
			sum += i;
		}
	}
	cout << "Sum is " << sum+2 << endl; // sum+2 since we started from 3 in for loop.		
	
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}

bool isPrime(int n) {
	
	if(n==2){
		return true;
	}
	else if(n % 2 == 0) {
		return false;
	}
	
	for(int i = 3; i<=sqrt(n); i+=2) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
