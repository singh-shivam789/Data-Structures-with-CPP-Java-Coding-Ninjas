/*
Print Permutations

Given an input string (STR), find and return all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:
The only input line contains a string (STR) of alphabets in lower case

Output Format:
Print each permutations in a new line

Note:
You do not need to print anything, it has already been taken care of. Just implement the function.  

Constraint:
1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:
cba

Sample Output 1:
abc
acb
bac
bca
cab
cba

*/

#include <bits/stdc++.h>
using namespace std;

void helper(string s, string output){
    if(s.length() <= 0){
        cout<<output<<endl;
        return;
    }
    
	for(int i=0; i<s.length(); ++i){
        string temp = s;
        rotate(temp.begin(), temp.begin()+i, temp.end());
        helper(temp.substr(1), output+temp[0]);
    }
}

void printPermutations(string input){
    string output = "";
	helper(input, output);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
