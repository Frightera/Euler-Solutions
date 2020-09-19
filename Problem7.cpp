#include <iostream>
#include <sys/time.h>
#include <iomanip>

/*
Output: 10001th prime is 104743
Time taken by program is : 0.020990 sec (It may vary)
*/
// Brute force the question 7, however sieve of eratosthenes algorithm
// can be implemented. 

bool isPrime(int n);

using namespace std;

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
	
	int counter = 1, i = 3; 
	
	while(1) {
		if(isPrime(i)) {
			counter++;
		}
		if(counter == 10001) {
			break;
		}
		i+=2;
	}
	cout << "10001th prime is " << i << endl;
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
