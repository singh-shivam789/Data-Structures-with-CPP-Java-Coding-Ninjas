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
class TrieNode
{
public:
  char data;
  TrieNode **children;
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
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
    insertWord(this->root, word);
  }

  void print(TrieNode *root, string op)
  {
    if (root->isTerminal == true)
    {
      cout << op << "\n";
    }

    for (int i = 0; i < 26; i++)
    {
      if (root->children[i] != NULL)
      {
        TrieNode *child = root->children[i];
        print(child, op + child->data);
      }
    }
  }

  void helper(TrieNode *root, string pattern, string op)
  {
    if (pattern.length() == 0)
    {
      // pattern found
      print(root, op);
    }
    else
    {
      int index = pattern[0] - 'a';
      TrieNode *child = root->children[index];
      if (child != NULL)
      {
        op.push_back(pattern[0]);
        helper(child, pattern.substr(1), op);
      }
    }
  }

  void autoComplete(vector<string> input, string pattern)
  {
    // find if pattern even exists
    for (string s : input)
    {
      insertWord(s);
    }

    helper(root, pattern, "");
  }
};