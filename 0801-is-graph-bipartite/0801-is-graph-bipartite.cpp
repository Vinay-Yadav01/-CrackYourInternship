class Solution {
    bool bfs(int start, vector<int>& color, vector<vector<int>>& graph) {
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }

    bool dfs(int start, int col, vector<int>& color,
             vector<vector<int>>& graph) {
        color[start] = col;
        for (auto it : graph[start]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, graph) == false)
                    return false;
            }
            else if(color[it]==color[start]) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        // int V = graph.size();
        // vector<int> color(V, -1);
        // for (int i = 0; i < V; i++) {
        //     if (color[i] == -1) {
        //         if (bfs(i, color, graph) == false)
        //             return false;
        //     }
        // }
        // return true;

        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};