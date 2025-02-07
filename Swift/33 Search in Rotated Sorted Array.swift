class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var n = nums.count
        var k = n - 1

        func binary(_ left: Int, _ right: Int) -> Int {
            var l = left, r = right
            while l < r {
                var mid = (l + r) >> 1
                if target <= nums[mid] {
                    r = mid
                } else {
                    l = mid + 1
                }
            }
            return l
        }

        if nums[0] < nums[k] {
            let x = binary(0, k)
            if nums[x] == target {
                return x
            }
        } else {
            var l = 0, r = k
            while l < r {
                let mid = (l + r) / 2
                if nums[0] > nums[mid] {
                    r = mid
                } else {
                    l = mid + 1
                }
            }

            var idx: Int = -1
            if nums[0] <= target {
                idx = binary(0, l - 1)
            } else {
                idx = binary(l, k)
            }
            if nums[idx] == target {
                return idx
            }
        }
        return -1
    }
}
