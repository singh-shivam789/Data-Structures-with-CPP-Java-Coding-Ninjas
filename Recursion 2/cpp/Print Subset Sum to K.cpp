// Print Subset Sum to K

// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. 
// But the order of elements should remain same as in the input array.

// Note : The order of subsets are not important. Just print them in different lines.

// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 

// Sample Input:
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6

// Sample Output:
// 3 3
// 5 1

#include<bits/stdc++.h>
using namespace std;

void helper(int input[], int n, int output[], int s, int k){
    if(n == 0){
        int sum = 0;
        for(int i=0; i<s; i++){
            sum += output[i];
        }
        if(sum == k){
            for(int i=0; i<s; ++i){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
    }

    else{
        output[s] = input[0];
        helper(input+1, n-1, output, s+1, k);
        helper(input+1, n-1, output, s, k);
    }
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[1000] = {0};
    helper(input, size, output, 0, k);
}

int main() {
    int input[1000],length,k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    cin>>k;
    printSubsetSumToK(input, length,k);
}
