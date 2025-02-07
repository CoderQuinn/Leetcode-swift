using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            if (seen.find(x) != seen.end())
            {
                return {i, seen[x]};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};