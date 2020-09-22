#include <iostream>
#include <sys/time.h>
#include <iomanip>

/*
Output: 232792560
Time taken by program is : 0.000311 sec (It may vary)
*/

using namespace std;

int lcm(int k, int n);
int gcd(int k, int n);

int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	
    int sMultiple = 1;
    for (int i = 2; i <= 20; i++) {
		sMultiple = lcm(sMultiple, i);
	}

    cout << "Result is " << sMultiple << endl;
	
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
	 
    return 0; 
}

int gcd(int k, int n) {
  int m;
  while (k != 0) {
    m = k;
    k = n % k;
    n = m;
  }
  return n;
}
 
int lcm(int k, int n) {
  return k * (n / gcd(k, n));
}
