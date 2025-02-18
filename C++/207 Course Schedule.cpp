class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> g(n, vector<int>());
        for(auto &v : prerequisites) {
            auto a = v.front(), b = v.back();
            g[b].push_back(a);
        }

        vector<int> colors(n, 0);
        auto dfs = [&](this auto &&dfs, int u) -> bool {
            colors[u] = 1;
            for(auto &v : g[u]) {
                if(colors[v] == 1 || colors[v] == 0 && dfs(v)) return true;
            }
            colors[u] = 2;
            return false;
        };

        for(int i = 0; i < n; i++) {
            if(colors[i] == 0 && dfs(i)) return false;
        }
        return true;
    }
};