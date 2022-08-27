/*Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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

int keypad(int num, string output[]){

    if(num == 0){
        output[0] = "";
        return 1;
    }
    
    int sav = num % 10;
    int ans = keypad(num/10, output);
    
    string s = getString(sav);
    
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<ans; j++){
            output[(i*ans) + j] = output[j];
        }
    }
     for(int i=0; i<s.length(); i++){
        for(int j=0; j<ans; j++){
            output[(i*ans) + j] += s[i];
        }
    }
    return ans * s.length();
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
