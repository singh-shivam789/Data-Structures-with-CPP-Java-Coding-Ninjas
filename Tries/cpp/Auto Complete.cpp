/*
Auto complete

Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.

Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.

Output Format :
Print all possible words in separate lines.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
7
do dont no not note notes den
no

Sample Output 2 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de

Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom

Sample Output 3 :
(Empty) There is no word which starts with "nom"
*/

#include <bits/stdc++.h>
using namespace std;
