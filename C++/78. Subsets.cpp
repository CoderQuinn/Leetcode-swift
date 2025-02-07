using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto &&dfs, int u) -> void
        {
            if (u == n)
            {
                ans.push_back(path);
                return;
            }

            dfs(u + 1);
            path.push_back(nums[u]);
            dfs(u + 1);
            path.pop_back();
        };

        dfs(0);
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;
        vector<vector<int>> ans;
        for (int i = 0; i < total; i++) {
            vector<int> path;
            for(int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    path.push_back(nums[j]);
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};