/*
Array Intersection

You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, 
when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains an integer 'N' representing the size of the first array/list.
The second line contains 'N' single space separated integers representing the elements of the first the array/list.
The third line contains an integer 'M' representing the size of the second array/list.
The fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output format :
For each test case, print the intersection elements in a row, separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6
Time Limit: 1 sec 

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10

Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 2 2

Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. 
The first '2' of first array matches with the first '2' of the second array. 
Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/


#include <bits/stdc++.h>
using namespace std;

void fun(int arr1[], int arr2[], int n, int m){
    if(n == 0 || m == 0){
        return;
    }
    if(arr1[0] == arr2[0]){
        cout<<arr1[0]<<" ";
    	fun(arr1+1, arr2+1, n-1, m-1);
    }
    else{
        if(arr1[0] < arr2[0]){
            fun(arr1+1, arr2, n-1, m);
        }
        else{
            fun(arr1, arr2+1, n, m-1);
        }
    }
}

void intersection(int *arr1, int *arr2, int n, int m) {
	sort(arr1, arr1+n);
    sort(arr2, arr2+m);
	fun(arr1, arr2, n, m);
}

int main(){
	int t;
	cin >> t;
	while (t--){

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
