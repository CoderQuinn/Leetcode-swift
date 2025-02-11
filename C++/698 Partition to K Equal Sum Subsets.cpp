class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        
        int len = sum / k;
        vector<bool> used(nums.size(), false);
        auto dfs = [&](this auto &&dfs, int start, int path, int k, int len) -> bool {
            if(k == 0 ) return true;
            if(path == len) return dfs(0, 0, k - 1, len);

            for(int i = start; i < nums.size(); i++) {
                if(used[i]) continue;
                if(path + nums[i] <= len) {
                    used[i] = true;
                    if(dfs(i + 1, path + nums[i], k, len)) {
                        return true;
                    }
                    used[i] = false;
                }
                while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
                if(path == 0 || path + nums[i] == len) return false;
            }
            return false;
        };

        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, k, len);
    }
};