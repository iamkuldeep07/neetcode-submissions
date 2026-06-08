class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int coursesTaken = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            coursesTaken++;

            for (int nbr : adjList[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }

        }

        return coursesTaken == numCourses;
    }
};
