/*
Palindrome Pair

Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Input Format :
The first line of the test case contains an integer value denoting 'n'.
The following contains 'n' number of words each separated by a single space.

Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.

Constraints:
0 <= n <= 10^5

Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba

Sample Output 1 :
true

Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def

Sample Output 2 :
false

Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode **children;
  bool isTerminal;
  int childCount;

  TrieNode(char data)
  {
    this->data = data;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
    childCount = 0;
  }
};

class Trie
{
  TrieNode *root;

public:
  int count;

  Trie()
  {
    this->count = 0;
    root = new TrieNode('\0');
  }

  bool search(TrieNode *root, string word)
  {
    if (root != NULL)
    {
      if (word.length() == 0)
      {
        return true;
      }
      else
      {
        TrieNode *child = root->children[word[0] - 'a'];
        return search(child, word.substr(1));
      }
    }
    else
      return false;
  }

  void insertWord(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
    }
    else
    {
      int index = word[0] - 'a';
      TrieNode *child = root->children[index];
      if (child == NULL)
      {
        child = new TrieNode(word[0]);
        root->children[index] = child;
      }
      insertWord(child, word.substr(1));
    }
  }

  void insertWord(string word)
  {
    insertWord(root, word);
  }

  /*..................... Palindrome Pair................... */

  bool isPalindrome(string s)
  {
    for (int i = 0, j = s.length() - 1; i <= j;)
    {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }

  bool isPalindromePair(vector<string> vect)
  {
    for (string s : vect)
    {
      string temp = s;
      while (temp.length() != 0)
      {
        this->insertWord(temp);
        temp = temp.substr(1, temp.length());
      }
    }

    for (string s : vect)
    {
      if (isPalindrome(s))
        return true;
      else
      {
        reverse(s.begin(), s.end());
        if (search(root, s))
          return true;
      }
    }
  }
};