#include <bits/stdc++.h>
using namespace std;

// Graph : Directed(edges with specific directions) and Undirected(edges without directions)
// Graph : Weighted(assigns a weight or cost to each edge) and Unweighted(all edges are considered to have equal weight (usually 1))
// Graph : Cyclic(if it contains at least one cycle) and Acyclic(if it does not contain any cycle)
// Every tree is an acyclic graph, but every acyclic graph is NOT necessarily a tree

// Connected graph: Every pair of vertices has a path between them
// Component: A maximal connected part of a graph
// Degree: Number of edges connected to a vertex in an undirected graph
// Indegree: Number of incoming edges in a directed graph
// Outdegree: Number of outgoing edges in a directed graph
// Path: contains nodes and each pf node is reachable(adjacent nodes must have an edge)


// To represent graph: Adjacency Matrix, Adjacency List, Edge List.
// Adjacency Matrix (SC: O(n^2))
int main() {
    int n, m;
    cin >> n >> m;
    int adj[n + 1][m + 1];
    // graph here
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}


// Adjacency List (SC: O(2 * edge) for Undirected and O(egde) for Directed)
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);           // for weighted graph push pair<int,int> instead of int, one is for adjacent node and another one is for weight
        adj[v].push_back(u);           // no need of this for directed graph
    }
    return 0;
}


// Connected Components: maximal connected subgraph of an undirected graph
// How to find connected components using DFS? : Create a visited array initialized with false. Traverse all vertices using a loop.
void dfs(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, adj, vis);
    }
}
int countComponent(int v, vector<int> adj[]) {
    vector<int> vis(v,0);
    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            count++;
            dfs(i, adj, vis);
        }
    }
    return count;
}


vector<int> bfs(int n, vector<int> adj[]) {
    // TC: O(n) + O(2 * edge) and SC: O(n)
    vector<int> ans;
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}




