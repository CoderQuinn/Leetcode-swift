class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto &&dfs, int u) -> void
        {
            if (u == n)
            {
                ans.push_back(path);
                return;
            }

            int x = nums[u];
            path.push_back(x);
            dfs(u + 1);
            path.pop_back();

            int k = u + 1;
            while (k < n && nums[k] == x)
            {
                k++;
            }

            dfs(k);
        };

        dfs(0);
        return ans;
    }
};