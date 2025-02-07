class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
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

        int n = nums.size();
        if (nums[0] < nums[n - 1])
        {
            int x = search(nums, target, 0, n - 1);
            if (nums[x] == target)
            {
                return x;
            }
        }
        else
        {
            int l = 0, r = n - 1;
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
            if (target >= nums[0])
            {
                idx = search(nums, target, 0, l - 1);
            }
            else
            {
                idx = search(nums, target, l, n - 1);
            }
            if (nums[idx] == target)
            {
                return idx;
            }
        }

        return -1;
    }
};