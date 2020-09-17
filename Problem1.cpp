#include <iostream>
#include <sys/time.h>
#include <iomanip>

using namespace std;

unsigned long long sum(unsigned long long x);
void solution1();
void solution2();
 
int main() {
 solution1();
 solution2();
 return 0;
}

void solution1() {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
	 
    int sum3 = 3 * sum(999/3); // 3(1+2+3+...) = 3+6+9+...
    int	sum5 = 5 * sum(999/5); // 5(1+2+3+...) = 5+10+15...
 
    // Remove duplicates
    int sum15 = 15 * sum(999/15); // 15 = 3*5, so 15 30.. and so on counted twice.
    cout << (sum3 + sum5 - sum15) << endl;
    
	clock_gettime(CLOCK_MONOTONIC, &end); 

	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
}

void solution2() {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false); 
    
	int sum = 0;	
	 
	for(int i = 0;i<1000;i++) {
		if(i%3 == 0 || i%5 == 0)
			sum += i;
	} 
    cout << "Sum is " << sum << endl;
 	clock_gettime(CLOCK_MONOTONIC, &end); 
	
	double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
}

unsigned long long sum(unsigned long long x) {
  return x * (x + 1) / 2;
}

