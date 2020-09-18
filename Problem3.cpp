#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <math.h> 

/*
Output: Largest is 6857
Time taken by program is : 0.016228 sec
*/

using namespace std;

bool isPrime(int n);

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 

	for(int i = sqrt(600851475143);; i-- ) {
		if((600851475143 % i == 0) && isPrime(i)) {
			cout << "Largest is " << i << endl;
			break;
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

