class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        auto g = vector<vector<int>>(n, vector<int>());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        unordered_set<int> seen;
        auto dfs = [&](this auto && dfs, int root) -> void {
            seen.insert(root);
            for(auto &e : g[root]) {
                if(seen.contains(e)) continue;
                dfs(e);
            }
        };

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!seen.contains(i)) {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};