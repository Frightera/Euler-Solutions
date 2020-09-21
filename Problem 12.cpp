#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <vector>
#include <math.h>

/*
Output: 76576500
Time taken by program is : 0.523509 sec
*/

using namespace std;


int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
	int MaxDivisors = 502; // We are looking for 501 divisors

	vector<int> smallest;
  	// n = 1 --> 1 
  	// n = 4 --> 10
    // ...
    int n = 0;
    int triangular = 0; // n(n+1)/2
    while (smallest.size() < MaxDivisors) {
    	n++;
    	triangular += n;

    	int divisors = 0;
    	int i = 1;
    	while (i < sqrt(triangular)){
      		if (triangular % i == 0) {
        		divisors += 2;
        	}
      		i++;
    	}
    		if(i*i == triangular) {
      			divisors++;
  			}
 
    	while (smallest.size() <= divisors){
      		smallest.push_back(triangular);
      	}
  	}
  	cout << smallest[501] << endl;

	

	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}
