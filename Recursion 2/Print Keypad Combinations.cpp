/*Print Keypad Combinations Code
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf */

#include <iostream>
#include <string>
using namespace std;

string getString(int n){
    if(n == 0 || n == 1) return " ";
    else if(n == 2) return "abc";
    else if(n == 3) return "def";
    else if(n == 4) return "ghi";
    else if(n == 5) return "jkl";
    else if(n == 6) return "mno";
    else if(n == 7) return "pqrs";
    else if(n == 8) return "tuv";
    else if(n == 9) return "wxyz";
}

void helper(int num, string output){
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    
    int n = num/10;
    int m = num%10;
    string small = getString(m);
    for(int i=0; i<small.length(); i++){
        helper(n, small[i] + output);
    }
}

void printKeypad(int num){
    
    string output="";
    helper(num, output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
