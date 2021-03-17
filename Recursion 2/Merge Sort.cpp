// Merge Sort Code
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.

// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)

// Output format :
// Array elements in increasing order (separated by space)

// Constraints :
// 1 <= n <= 10^3

// Sample Input 1 :
// 6 
// 2 6 8 5 4 3

// Sample Output 1 :
// 2 3 4 5 6 8

// Sample Input 2 :
// 5
// 2 1 5 2 3

// Sample Output 2 :
// 1 2 2 3 5 

#include<iostream>
using namespace std;

void mergeArray(int input[], int s, int e){
    int size = (e - s) + 1;
    int mid = (s + e) / 2;
    int *output = new int [size];
    int i = s;
    int j = mid + 1;
    int k = 0;
    while(i<=mid&&j<=e){
        if(input[i] >= input[j]){
            output[k++] = input[j++];
        }
        else{
            output[k++] = input[i++];
        }
    }
    while(i<=mid){
        output[k++] = input[i++];
    }
    while(j<=e){
        output[k++] = input[j++];
    }
    int m = 0;
    for(int i=s; i<=e; i++){
        input[i] = output[m];
        m++;
    }
    delete [] output; 
}

void helper(int input[], int s, int e){
    if(s >= e){
        return;
    }
    else{
        int mid = (s+e) / 2;
        helper(input, s, mid);
        helper(input, mid+1, e);
        mergeArray(input, s, e);
    }
}

void mergeSort(int input[], int size){
    helper(input, 0, size-1);
}

int main() {
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}
