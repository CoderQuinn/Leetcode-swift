class Solution {
    func canPartitionKSubsets(_ nums: [Int], _ k: Int) -> Bool {
        var sum = 0
        for val in nums {
            sum += val
        }

        if sum % k != 0 {
            return false
        }

        let n = nums.count
        var len = sum / k
        var used: [Bool] = .init(repeating: false, count: n)
        let res = nums.sorted {
            $0 >= $1
        }
        func dfs(_ start: Int, _ path: Int, _ k: Int, _ len: Int) -> Bool {
            if k == 0 {
                return true
            }

            if path == len {
                return dfs(0, 0, k - 1, len)
            }

            var prev: Int = -1
            var i: Int = start
            while i < n {
                if used[i] {
                    i += 1
                    continue
                }
                let x = res[i]
                if path + x <= len {
                    used[i] = true
                    if dfs(i + 1, path + x, k, len) {
                        return true
                    }
                    used[i] = false
                }

                while i + 1 < n && res[i] == res[i + 1] {
                    i += 1
                }

                if path == 0 || path + x == len {
                    return false
                }

                i += 1
            }

            return false
        }

        return dfs(0, 0, k, len)
    }
}
