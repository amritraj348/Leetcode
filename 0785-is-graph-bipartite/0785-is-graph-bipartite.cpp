class Solution {
public:

    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {

        queue<int> q;
        q.push(start);

        color[start] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto adjacentNode : graph[node]) {

                // If the adjacent node is not colored
                if (color[adjacentNode] == -1) {

                    color[adjacentNode] = !color[node];
                    q.push(adjacentNode);
                }

                // If the adjacent node has the same color
                else if (color[adjacentNode] == color[node]) {

                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> color(V, -1);

        // Handle disconnected components
        for (int i = 0; i < V; i++) {

            if (color[i] == -1) {

                if (!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};