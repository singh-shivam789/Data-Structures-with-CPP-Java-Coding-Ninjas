/*
Pattern Matching

Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.

Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.

Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
de

Sample Output 1 :
true

Sample Input 2 :
4
abc def ghi hg
hi

Sample Output 2 :
true

Sample Input 3 :
4
abc def ghi hg
hif

Sample Output 3 :
false
*/

#include <string>
#include <vector>
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
  Trie()
  {
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

  bool search(string word)
  {
    return search(root, word);
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

  bool patternMatching(vector<string> vect, string pattern)
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
    return search(pattern);
  }
};