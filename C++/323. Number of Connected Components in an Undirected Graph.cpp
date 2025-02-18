class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        auto g = vector<vector<int>> (n, vector<int>());
        for(auto &v : edges) {
            auto &a = v.front(), &b = v.back();
            g[a].push_back(b);
            g[b].push_back(a);
        }

        unordered_set<int> seen;
        auto dfs = [&](this auto &&dfs, int u) -> void {
            seen.insert(u);
            for(auto &e : g[u]){
                if(seen.contains(e)) continue;
                dfs(e);
            }
        };

        for(size_t i = 0; i < n; ++i) {
            if(!seen.contains(i)) {
                ans++;
                dfs(i);
            }
        }

        return ans;
    }
};