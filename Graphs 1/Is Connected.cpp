/*
Code : Is Connected ?
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Time Limit: 1 second

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <iostream>
#include <queue>
using namespace std;

void DFS(int n, bool ** graph, bool * visited, int s){
    visited[s] = true;
    for(int i=0; i<n; i++){
        if(s == i) continue;
        if(graph[s][i] && !visited[i]){
            DFS(n, graph, visited, i);
        }
    }
}

bool isConnected(int n, int e, bool ** graph, int s){
    bool * visited = new bool[n]();
    DFS(n, graph, visited, s);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool ** graph = new bool * [n];
    for(int i=0; i<n; i++){
        graph[i] = new bool[n]();
    }

    int f, s;
    for(int i=0; i<e; i++){
        cin >> f >> s;
        graph[s][f] = true;
        graph[f][s] = true;
    }

    if(isConnected(n, e, graph, f)){
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}
