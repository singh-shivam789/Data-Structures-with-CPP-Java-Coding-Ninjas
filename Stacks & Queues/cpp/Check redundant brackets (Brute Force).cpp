/*
Check redundant brackets

For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
1. Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

2. Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second

Sample Input 1:
a+(b)+c 

Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.

Sample Input 2:
(a+b)

Sample Output 2:
false


-----------------------------------------------------------  Solved using Brute Force approach  -----------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;
bool checkRedundantBrackets(string s) {
   	for(auto i = 0, j=0; i<s.length(); i++){
        int c = 0;
        if(s[i] == ')'){
            for(j=i-1; s[j] != '('; j--){
                if(j == 0 && c <= 1){
                    return true;
                }
                else if(s[j] != 0 && s[j] != ')'){
                    s[j] = 0;
                    c++;
                }
            }
            if(s[j] == '('){
                s[j] = 0;
            }
            if(c <= 1) return true;
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
