/*
    Remove Duplicates: 
    
    Given an unsorted array of integers, print the array after removing the duplicate elements from it. 
    We need to print distinct array elements according to their first occurrence.

    Example: 
    Input : arr[] = { 1, 2, 5, 1, 7, 2, 4, 2}
    Output : 1 2 5 7 4
    Explanation : {1, 2} appear more than one time.
    
    Time Complexity – O(N)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *arr, int n) {
	unordered_map<int, bool> myMap;
	vector<int> input;
	for(int i=0; i<n; i++){
	    if(myMap.count(arr[i]) < 1){
	        myMap[arr[i]] = true;
	        input.push_back(arr[i]);
	    }
	}
	return input;
}

int main() {
	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; i++) {
	    cin>>arr[i];
	}
	vector<int> v = removeDuplicates(arr, n);
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" ";
    }
}
