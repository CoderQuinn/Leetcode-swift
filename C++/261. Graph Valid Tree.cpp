class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(m != n - 1) return false;

        vector<vector<int>> g = vector<vector<int>>(n, vector<int>());
        for(auto &v : edges) {
            auto &a = v.front(), &b = v.back();
            g[b].push_back(a);
            g[a].push_back(b);
        }

        unordered_set<int> seen;
        auto dfs = [&](this auto &&dfs, int root) -> void {
            seen.insert(root);
            for(auto &e : g[root]) {
                if(seen.contains(e)) continue;
                dfs(e);
            }
        };
        dfs(0);
        return seen.size() == n;
    }
};