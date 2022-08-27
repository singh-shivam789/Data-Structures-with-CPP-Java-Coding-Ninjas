// Check Palindrome (recursive)
// Check whether a given String S is a palindrome using recursion. Return true or false.

// Input Format :
// String S

// Output Format :
// 'true' or 'false'

// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.

// Sample Input 1 :
// racecar

// Sample Output 1:
// true

// Sample Input 2 :
// ninja

// Sample Output 2:
// false

#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(char input[]) {
	if(strlen(input) == 1 || strlen(input) == 0) return true;
	if(input[0] == input[strlen(input) - 1]){
        input[strlen(input) - 1] = '\0';
        return checkPalindrome(input+1);
    }
    else return false;
}

int main(){
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
