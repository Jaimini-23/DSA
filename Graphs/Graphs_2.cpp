#include <bits/stdc++.h>
using namespace std;


int wordLadder_1(string startWord, string targetWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) return steps;
        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}


vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {        // word Ladder 2
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({startWord});

    if (!st.count(targetWord)) return ans;
    vector<string> usedOnLevel;                        // Stores words discovered at the current level
    usedOnLevel.push_back(startWord);
    int level = 0;

    while(!q.empty()) {
        vector<string>  vec = q.front();
        q.pop();
        
        // erase all words which has been used in the previous level to transform
        if(vec.size() > level) {
            level++;
            for(auto it: usedOnLevel) st.erase(it);
             usedOnLevel.clear();
        }

        string word = vec.back();                        // have to apply changes to the last word in vector to get next
        // store the answers
        if(word == targetWord) {
            if(ans.size() == 0) ans.push_back(vec);                          // The first sequence reaching the target is guaranteed to be shortest because BFS explores level by level
            else if(ans[0].size() == vec.size()) ans.push_back(vec);            // Because we need all shortest sequences, not longer ones
            continue;
        }

        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(st.count(word) > 0) {       // Words discovered while processing paths of the same level are not erased until the next level begins
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back();                     // remove to get another vector (sequence)
                }
            }
            word[i] = original;
        }
    }
    return ans;
}


class Solution {                                // Optimal approach for Leetcode of word Ladder 2
    vector<vector<string>> ans;
    string b;
    unordered_map<string, int> mp;

private:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];
        int sz = word.size();
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();       // It removes the last word that we added to the current sequence, so we can explore other possible paths
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;

        int sz = beginWord.size();
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word == endWord) break;
            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord, seq);
        }
        return ans;
    }
};


vector<int> dijkstra(int n, vector<vector<int>> adj[], int s) {             // Dijkstra's Algorithm
    // Dijkstra does not work correctly with negative edge weights. For those, consider Bellman-Ford
    // using Priority Queue, because edge weights can differ and we need the minimum distance first (to remove unnecessary iterations)
    // TC: O(E * logn)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n);
    for(int i = 0; i < n; i++) dist[i] = 1e9;
    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;


    // using Set, can remove the previously stored distance whenever a shorter path is found, ensuring that only the updated distance remains and avoiding unnecessary processing of outdated entries
    set<pair<int,int>> st;
    vector<int> d(n,1e9);
    st.insert({0,s});
    d[s] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it: adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(dis + edgeWeight < d[adjNode]) {
                st.erase({d[adjNode],adjNode});
                d[adjNode] = dis + edgeWeight;
                st.insert(d[adjNode],adjNode);
            }
        }
    }
    return d;
}


vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int,int>> adj[n + 1];
    // Build adjacency list
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;
    pq.push({0, 1});

    // Dijkstra
    while(!pq.empty()) {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;
            if(dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                parent[adjNode] = node;
            }
        }
    }

    // If destination is unreachable
    if(dist[n] == 1e9)
        return {-1};

    // Reconstruct path
    vector<int> path;
    int node = n;
    while(parent[node] != node) {               // Stops when we reach the source node (1)
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);          // Add the source node separately
    reverse(path.begin(), path.end());     // Reverse to get source-to-destination order

    return path;
}




