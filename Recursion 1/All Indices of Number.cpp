// All Indices of Number
// Given an array of length N and an integer x, you need to find 
//all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.

// Input Format :
// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

// Output Format :
// indexes where x is present in the array (separated by space)

// Constraints :
// 1 <= N <= 10^3

// Sample Input :
// 5
// 9 8 10 8 8
// 8

// Sample Output :
// 1 3 4
// Important : 
// I've done this using two methods. You can try both. allIndexes2 is comparitively easier

#include<iostream>
using namespace std;
int allIndexes1(int input[], int size, int x, int output[]) {
 if(size == 0) return 0;
    int ans = allIndexes1(input+1, size-1, x, output);
    for(int i=0; i<ans; i++) output[i] += 1;
    if(input[0] == x){
        for(int i=ans-1; i>=0; i--) output[i+1] = output[i]; 
        output[0] = 0;
        return ans + 1;
    }
    else return ans;
}
int allIndexes2(int input[], int size, int x, int output[]){
    if(size == 0) return 0;
    int ans = allIndexes2(input, size-1, x, output);
    if(input[size - 1] == x){
        output[ans] = size - 1;
        return ans + 1;
    }
    else return ans;
}
int main(){
    int n,x;
    cin>>n;
    int *input = new int[n], *output = new int[n];
    for(int i=0; i<n; i++) cin>>input[i];
    cin>>x;
    int size = allIndexes1(input, n, x, output);
    for(int i=0; i<size; i++) cout<<output[i]<<" "; cout<<endl;
    size = allIndexes2(input, n, x, output);
    for(int i=0; i<size; i++) cout<<output[i]<<" "; cout<<endl;
    delete [] input;
    delete [] output;
    return 0;
}