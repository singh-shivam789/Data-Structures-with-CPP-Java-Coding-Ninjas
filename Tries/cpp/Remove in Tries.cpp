/*
Search in Tries

Implement the function SearchWord for the Trie class.
For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.
Note : main function is given for your reference which we are using internally to test the code.
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
  Trie()
  {
    root = new TrieNode('\0');
  }

  void remove(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'a';
    if (root->children[index] != NULL)
    {
      TrieNode *child = root->children[index];
      remove(child, word.substr(1));

      if (child->isTerminal == false)
      {
        for (int i = 0; i < 26; i++)
        {
          if (child->children[i] != NULL)
            return;
        }
        delete child;
        root->children[index] = NULL;
      }
    }
  }

  void remove(string word)
  {
    remove(root, word);
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

  bool search(TrieNode *root, string word)
  {
    if (root != NULL)
    {
      if (word.length() == 0)
      {
        return root->isTerminal;
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
    return search(this->root, word);
  }
};
