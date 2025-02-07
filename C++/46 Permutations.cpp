class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> flags(n, false);
        auto dfs = [&](this auto &&dfs, int cnt) -> void
        {
            if (cnt == nums.size())
            {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (!flags[i])
                {
                    flags[i] = true;
                    path.push_back(nums[i]);
                    dfs(cnt + 1);
                    path.pop_back();
                    flags[i] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};