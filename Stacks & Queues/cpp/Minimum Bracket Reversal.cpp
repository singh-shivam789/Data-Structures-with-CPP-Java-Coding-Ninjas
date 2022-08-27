/*
Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{

Sample Output 1:
-1

Sample Input 2:
{{{{}}

Sample Output 2:
1
*/

#include<stack>
#include<string>
#include<iostream>
using namespace std;
int countBracketReversals(string s) {
    stack<char> myStack;
    int count = 0;
    if(s.length() == 0) return -1;
    if (s.length() % 2 == 0) {
        for(int i=0; i<s.length(); i++){
            char currentChar = s[i];
            if(currentChar == '{'){
                myStack.push(currentChar);
            }
            else{
                if(myStack.size() != 0 && myStack.top() == '{'){
                    myStack.pop();
                }
                else{
                    myStack.push(currentChar);
                }
            }
        }

        while (myStack.size() != 0) {
            char s1 = myStack.top();
            myStack.pop();
            char s2 = myStack.top();
            myStack.pop();
            if (s1 == s2) {
                count += 1;
            }
            else{
                count += 2;
            }
        }
        return count;
    }
    else return -1;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
