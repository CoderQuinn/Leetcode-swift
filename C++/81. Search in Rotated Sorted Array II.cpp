class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size(), k = n - 1;
        while (k > 0 && nums[0] == nums[k])
            k--;
        auto search = [&](vector<int> &nums, int target, int l, int r) -> int
        {
            while (l < r)
            {
                int mid = l + r >> 1;
                if (target <= nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return l;
        };

        if (nums[0] <= nums[k])
        {
            int idx = search(nums, target, 0, k);
            if (nums[idx] == target)
            {
                return true;
            }
        }
        else
        {
            int l = 0, r = k;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (nums[0] > nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            int idx = -1;
            if (nums[0] <= target)
            {
                idx = search(nums, target, 0, l - 1);
            }
            else
            {
                idx = search(nums, target, l, k);
            }
            if (nums[idx] == target)
            {
                return true;
            }
        }
        return false;
    }
};