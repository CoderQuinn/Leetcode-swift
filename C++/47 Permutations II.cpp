class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<bool> state(n, false);
        auto dfs = [&](this auto &&dfs, int cnt) -> void
        {
            if (cnt == n)
            {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (state[i])
                    continue;
                if (i > 0 && nums[i] == nums[i - 1] && state[i - 1])
                    continue;
                state[i] = true;
                path.push_back(nums[i]);
                dfs(cnt + 1);
                path.pop_back();
                state[i] = false;
            }
        };
        dfs(0);
        return ans;
    }
};