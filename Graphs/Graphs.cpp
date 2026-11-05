#include <bits/stdc++.h>
using namespace std;

// Graph : Directed(edges with specific directions) and Undirected(edges without directions)
// Graph : Weighted(assigns a weight or cost to each edge) and Unweighted(all edges are considered to have equal weight (usually 1))
// Graph : Cyclic(if it contains at least one cycle) and Acyclic(if it does not contain any cycle)
// Every tree is an acyclic graph, but every acyclic graph is NOT necessarily a tree

// Connected graph: Every pair of vertices has a path between them
// Component: A maximal connected part of a graph
// Degree: Number of edges connected to a vertex in an undirected graph (total in graph = 2 * edges)
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


vector<vector<int>> matrixToList(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> adjList(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
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
        ans.push_back(node);
    }
    return ans;
}


void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    // TC: O(n) + O(2 * edge)_for Undirected graph and SC: O(n) + O(n) + O(n) = O(n)
    vis[node] = 1;
    ls.push_back(node);
    // traversal all its neighbours
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, adj, vis, ls);
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    int vis[n] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
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


void bfSearch(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        // traverse in the neighbours and mark them if its a land
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int newRow = row + delrow;
                int newCol = col + delcol;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow,newCol});
                    }
            }
        }
    }
}
int numsIsLands(vector<vector<char>> &grid) {
    // TC: O(n^2) + O(n^2) and SC: O(n^2) + O(n^2)
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                bfSearch(row, col, vis,grid);
            }
        }
    }
    return cnt;
}


void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor,
         int delRow[], int delCol[], int iniColor) {

    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
           image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {

            dfs(nrow, ncol, ans, image, newColor,
                delRow, delCol, iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}




