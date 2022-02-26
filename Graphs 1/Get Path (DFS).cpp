/*
Code : Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.

Find the path using DFS and print the first path that you encountered.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1

Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> *getPathHelper(int n, int **edges, bool *visited, int s, int d)
{
  if (s == d)
  {
    vector<int> *v = new vector<int>;
    v->push_back(s);
    return v;
  }

  visited[s] = true;
  for (int i = 0; i < n; i++)
  {
    if (s == i)
      continue;
    if (edges[s][i] == 1 && !visited[i])
    {
      vector<int> *recAns = getPathHelper(n, edges, visited, i, d);
      if (recAns != NULL)
      {
        recAns->push_back(s);
        return recAns;
      }
    }
  }
  return NULL;
}

vector<int> *getPath(int n, int **edges, int s, int d)
{
  bool *visited = new bool[n]();
  return getPathHelper(n, edges, visited, s, d);
  delete[] visited;
}

int main()
{
  int n, e, v1, v2, a, b;
  cin >> n >> e;

  int **edges = new int *[n];
  for (int i = 0; i < n; i++)
  {
    edges[i] = new int[n]();
  }

  for (int i = 0; i < e; i++)
  {
    cin >> a >> b;
    edges[a][b] = 1;
    edges[b][a] = 1;
  }

  cin >> v1 >> v2;

  vector<int> *ans = getPath(n, edges, v1, v2);

  if (ans != NULL)
  {
    for (int i = 0; i < ans->size(); i++)
    {
      cout << ans->at(i) << " ";
    }
  }
}