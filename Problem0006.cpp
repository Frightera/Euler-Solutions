#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <math.h>
/*
Output: Result is 25164150
Time taken by program is : 0.000308 sec (It may vary)
*/

/*

1 + 2 + 3 + ... + n = n(n+1)/2
1^2 + 2^2 + 3^2 + ... + n^2 = n(n+1)(2n+1)/6

So, [n(n+1)/2]^2 - [n(n+1)(2n+1)/6)] is asked.
*/
long long sumOfsquares(int n);
long long squareOfSum(int n);

using namespace std;

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	
	cout << "Result is " << abs(squareOfSum(100) - sumOfsquares(100)) << endl;
	
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}

long long sumOfsquares(int n) {
	long long result = 0;
	for(int i = 1; i<=n; i++) {
		result += i*i;
	}
	return result;
}

long long squareOfSum(int n) {
	long long result = 0;
	for(int i = 1; i<=n; i++) {
		result += i;
	}
	return result*result;
}
