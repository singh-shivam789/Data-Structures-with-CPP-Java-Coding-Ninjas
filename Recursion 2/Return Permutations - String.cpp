/*
Return Permutations - String

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba */

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.length() == 0){
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int r = returnPermutations(input.substr(1), smallOutput);
    int k = 0;
    for(int i=0; i<smallOutput[0].length()+1; i++){
        for(int j=0; j<r; j++){
            string temp = smallOutput[j];
            output[k++] = temp.insert(i, input.substr(0,1));
        }
    }
    return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

