// Count Zeros
// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

// Input Format :
// Integer N

// Output Format :
// Number of zeros in N

// Constraints :
// 0 <= N <= 10^9

// Sample Input 1 :
// 10204

// Sample Output 1 :
// 2

// Sample Input 2 :
// 708000

// Sample Output 2 :
// 4

#include<iostream>
using namespace std;
int countZeros(int n) {
	if(n/10 == 0 && n%10 == 0) return 1;
    else if(n/10 == 0) return 0;
    int ans = countZeros(n/10);
    if(n%10 == 0){
        return ans + 1;
    }
    else return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<countZeros(n)<<endl;
	return 0;
}

