// Geometric Sum
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) using recursion.

// Input format :
// Integer k

// Output format :
// Geometric sum

// Constraints :
// 0 <= k <= 1000

// Sample Input 1 :
// 3

// Sample Output 1 :
// 1.875

// Sample Input 2 :
// 4

// Sample Output 2 :
// 1.93750

#include<bits/stdc++.h>
using namespace std;
double geometricSum(int k) {
    // Write your code here
	if(k == 0.0) return double(1);
    int ans = pow(2,k);
    return (double)(1.0 / ans) + geometricSum(--k);
}
int main(){
    double n;
    cin>>n;
    cout<<fixed<<setprecision(5);
    cout<<geometricSum(n)<<endl;
    return 0;
}
