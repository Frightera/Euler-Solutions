#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <string>
#include <vector> 

/*
Output:Max is 906609
Time taken by program is : 0.004794 sec
*/

/*
if abcde is palindrome then it can expressed as abcba
abcba = 10000a + 1000b + 100c+ 10b + a = 10001a +1010b + 100c gcd = 1

it can be abcdef 6 digit number which can be written as abccba,
with same same method it is equal to abccba = 11(9091a+910b+10c)

So let's say k * n = m which is the largest palindrome we're looking for.
Since 11 is prime and k*n =  11(9091a+910b+10c)
Let's assume k/11 = is an integer
*/

using namespace std;
bool isPalindrome(string n);


int main() {
	
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    
	int max = 0, bound = 900;
	n:    
	for(int i = bound;i<1000;i++) {
		for(int j = bound;j<1000;j++){
			if((i % 11 == 0) && isPalindrome(to_string(i*j))) {
				if(max < i*j) {
					max = i*j;
				}
				
			}
		}
	} if(max == 0) {
		bound -= 100; // if not found i and j will start 100 less.
		goto n;
	} else {
		cout << "Max is " << max << endl;
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

bool isPalindrome(string n) {
	int len = n.length();
	if(len % 2 == 1){
		for(int i = 0; i<len/2;i++ ) { // len= 5 // 0 1 2 3 4 i = 0
			if(n[i] != n[len-1]) {		//len/2 = 2
				return false;
			}
			len--;
		}
	}
	
	if(len % 2 == 0){
		for(int i = 0; i<=len/2;i++ ) { // len= 6 // 0 1 2 3 4 5 i = 0
			if(n[i] != n[len-1]) {		//len/2 = 3
				return false;
			}
			len--;
		}
	}
	
	return true;
}
