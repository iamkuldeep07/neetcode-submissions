class Solution {
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = 1;
        for(int neigh : adjList[node]) {
            if(!visited[neigh]) dfs(neigh, adjList, visited);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        int totalComponents = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adjList, visited);
                totalComponents++;
            }
        }
        return totalComponents;
    }
};
