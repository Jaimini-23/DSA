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
                int newRow = row + delrow;                             // if(abs(delRow) + abs(delCol) != 1) continue;   add this line for 4 directions (horizontal and verticle only) not 8
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


int rottenOranges(vector<vector<int>>& grid) {
    // TC: O(n * m) and SC: O(n * m)
    // 0 -> no orange, 1 -> fresh orange, 2 -> rotten orange
    int time = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis = grid;
    int cntFresh = 0;
    
    // {{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(grid[row][col] == 2) {
                q.push({{row,col},0});
            }

            if(grid[row][col] == 1) cntFresh++;
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time,t);

        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                if(abs(delrow) + abs(delcol) != 1) continue;
                int nrow = r + delrow;
                int ncol = c + delcol;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && vis[nrow][ncol] == 1) {
                        vis[nrow][ncol] = 2;
                        q.push({{nrow,ncol},t + 1});
                        cnt++;
                    }
            }
        }
    }
    // check if all oranges get converted or not
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
    //     }
    // }
    if(cntFresh != cnt) return -1;
    return time;
}


bool bfsDetect(int src,vector<int> adj[], int vis[]) {
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacency: adj[node]) {
            if(!vis[adjacency]) {
                vis[adjacency] = 1;
                q.push({adjacency,node});
            }
            else if(parent != adjacency) return true;     // if already visited, check if node's neighbour and parent is not equal (they should be two different nodes otherwise parent and node (these two) will get treated as cycle)
        }                                                    // if not equal that means cycle detected
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]) {     // in an undirected graph
    // TC: O(n) + O(2E) + O(n) and SC: O(n) + O(n)
    int vis[n] = {0};
    for(int i = 0 ; i < n; i++) {
        if(!vis[i]) {  
            if(bfsDetect(i, adj, vis)) return true;       // cannot use detect(adj[0], adj, vis) because there can be disconnected components of graph
        }
    }
    return false;
}


bool dfsDetect(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) {
            if(dfsDetect(adjacentNode, node, vis, adj) == true) return true;         // if one dfs return true, return true for all remaining recursive dfs or say question
        }
        else if(adjacentNode != parent) return true;
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]) {
    // TC: O(n) + O(2E) + O(n) and SC: O(n) + O(n)
    int vis[n] = {0};
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfsDetect(i, -1, vis, adj) == true) return true;
        }
    }
    return false;
}


vector<vector<int>> distanceOfNearest_cellHaving1(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    vector<vector<int>> dist = grid;
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < n; i++) {          // Multi Source BFS
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                if(abs(delrow) + abs(delcol) != 1) continue;
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow,ncol},steps + 1});
                    }
            }
        }
    }
    return dist;
}


void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat) {
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();
    for(int delrow = -1; delrow <= 1; delrow++) {
        for(int delcol = -1; delcol <= 1; delcol++) {
            if(abs(delrow) + abs(delcol) != 1) continue;
            int nrow = row + delrow;
            int ncol = col + delcol;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
}
void surroundedRegions(int n, int m, vector<vector<char>> &mat) {        // mark O's surrounded by X's
    // start from the border O's and mark them that they cannot be converted and convert the remaining O's
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // First and last row
    for(int j = 0; j < m; j++) {
        if(!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat);
        if(!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, vis, mat);
    }
    // First and last column
    for(int i = 0; i < n; i++) {
        if(!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat);
        if(!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, vis, mat);
    }

    // Convert surrounded O into X
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mat[i][j] == 'O') {
                mat[i][j] = 'X';
            }
        }
    }
}


int noOfEnclaves(vector<vector<int>> &grid) {
    queue<pair<int,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // first row, first col, last row, and last col
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
        }
    }
    return cnt;
}


void dfsIslands(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &vec, int row0, int col0) {
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});
    int n = grid.size();
    int m = grid[0].size();

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};
    for(int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfsIslands(nrow, ncol, vis, grid, vec, row0, col0);
            }
    }
}
int countDistinctIslands(vector<vector<int>> &grid) {
    // TC: O(n * m) * log(set length)_setInsert + O(n * m *4)_dfs
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int,int>>> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int,int>> vec;
                dfsIslands(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}


// Bipartite graph: can divide all vertices into two disjoint sets such that no two adjacent vertices belong to the same set
// Non cyclic and even cyclick graph is always bipartite and odd cyclic is not bipartite
bool check(int start, int v, vector<int> adj[], int color[]) {          // by bfs
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(color[it] == -1) {
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}
bool dfsBipartite(int node, int col, vector<int> adj[], int color[]) {             // by dfs
    color[node] = col;
    for(auto it: adj[node]) {
        if(color[it] == -1) {
            if(dfsBipartite(it, !col, adj, color) == false) return false;
        }
        else if(color[it] == col) return false;
    }
    return true;
}
bool isBipartite(int v, vector<int> adj[]) {
    int color[v];
    for(int i = 0; i < v; i++) color[i] = -1;
    for(int i = 0; i < v; i++) {
        if(color[i] == -1) {
            if(check(i, v, adj, color) == false) return false;         // by bfs
            if(dfsBipartite(i, 0, adj, color) == false) return false;         // by dfs
        }
    }
    return true;
}


bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis) == true) return true;
        }
        // if the node has been previously visited but it has to be visited on the same path
        else if(pathVis[it]) return true;
    }
    pathVis[node] = 0;    // Once DFS finishes exploring all neighbours of the current node, remove it from the current recursion path. This is called backtracking.
    return false;
}
bool isCyclic(int n, vector<int> adj[]) {            // in an directed graph
    int vis[n] = {0};
    int pathVis[n] = {0};                              // can also do in one array by let marking vis as 1 and for pathVis as 2
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfsCheck(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}   


bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis, check) == true) {
                check[node] = 0;
                return true;
            }
        }
        // if the node has been previously visited but it has to be visited on the same path
        else if(pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;    // Once DFS finishes exploring all neighbours of the current node, remove it from the current recursion path. This is called backtracking.
    return false;
}
vector<int> eventualSafeNodes(int n, vector<int> adj[]) {            // in an directed graph
    int vis[n] = {0};
    int pathVis[n] = {0};
    int check[n] = {0};
    vector<int> safeNodes;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == 1) safeNodes.push_back(i);
    }
    return safeNodes;
} 


void dfsTopo(int node, int vis[], vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) dfsTopo(it, vis, adj, st);
    }
    st.push(node);
}
vector<int> topoSort(int n, vector<int> adj[]) {                  // TopoSort is valid for DAG(Directed Acyclic Grapgh)
    int vis[n] = {0};
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfsTopo(i, vis, adj, st);
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


vector<int> topologicalSort(int n, vector<int> adj[]) {           // Kahn's Algorithm
    // only for DAG(Directed Acyclic Grapgh)
    // insert all elements with indegree 0 in queue and take them out of the queue and then reduce the indegree of the adjcent nodes
    int indegree[n] = {0};
    for(int i = 0; i < n; i++) {
         for(auto it: adj[i]) {
            indegree[it]++;
         }
    } 
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);            // Because these nodes have no prerequisites and can be processed immediately.
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
    
    // Cycle detection using Kahn's algo: if(topo.size() == n) cycle does not exist
    // else cycle exists
}




