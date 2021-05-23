/*
Print all Codes - String
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void helper(string input, string output){
    if(input[0] == '\0'){
        cout<<output<<endl;
        return;
    }

    int s1 = input[0] - '0' + 'a' - 1;
    helper(input.substr(1), output + (char)s1);
    if(input[1]!='\0'){
      	int s2 = ((input[0] - '0') * 10) + (input[1] - '0');
        if(s2>=10 && s2<=26){
            s2 = s2 + 'a' - 1;
            helper(input.substr(2), output + (char)s2);
        }
    }
}

void printAllPossibleCodes(string input) {
    string output = "";
    helper(input, output);
}

int main(){
    string input;
    cin >> input;
    printAllPossibleCodes(input);
    return 0;
}
