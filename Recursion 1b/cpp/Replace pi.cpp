// Replace pi (recursive)
// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

// Sample Input 1 :
// xpix

// Sample Output :
// x3.14x

// Sample Input 2 :
// pipi

// Sample Output :
// 3.143.14

// Sample Input 3 :
// pip

// Sample Output :
// 3.14p

#include<bits/stdc++.h>
using namespace std;
void replacePi(char input[]) {
    if(strlen(input) <= 1) return;
    if(input[0] == 'p' && input[1] == 'i'){
        for(int i=strlen(input); i>=2; i--) input[i+2] = input[i];
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        return replacePi(input + 4);
    } 
    else return replacePi(input + 1);
}
int main(){
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

