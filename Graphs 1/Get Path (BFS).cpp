/*
Code : Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists).
Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
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
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> *getPathBFS(int n, int **graph, bool *visited, int s, int e)
{
    queue<int> q;
    unordered_map<int, int> map;
    vector<int> *v = new vector<int>();
    visited[s] = true;
    pair<int, int> p(s, -1);
    map.insert(p);
    q.push(s);
    bool pathFound = false;
    while (!q.empty() && !pathFound)
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (front == i)
                continue;
            if (graph[i][front] == 1 && !visited[i])
            {
                visited[i] = true;
                pair<int, int> p(i, front);
                map.insert(p);
                q.push(i);
                if (i == e)
                {
                    pathFound = true;
                    break;
                }
            }
        }
    }

    if (pathFound)
    {
        v->push_back(e);
        int current = e;
        while (current != s)
        {
            current = map[current];
            v->push_back(current);
        }
        return v;
    }
    else
        return NULL;
}

vector<int> *getPath(int n, int **graph, int s, int d)
{
    bool *visited = new bool[n]();
    return getPathBFS(n, graph, visited, s, d);
    delete[] visited;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int **graph = new int *[v];

    for (int i = 0; i < v; ++i)
    {
        graph[i] = new int[v]();
    }

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int start, end;
    cin >> start >> end;

    vector<int> *output = getPath(v, graph, start, end);

    if (output != NULL)
    {
        for (int i = 0; i < output->size(); ++i)
        {
            cout << output->at(i) << " ";
        }
        delete output;
    }
}
