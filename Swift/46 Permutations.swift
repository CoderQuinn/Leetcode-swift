class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var ans: [[Int]] = .init()
        var path: [Int] = .init()
        let n = nums.count
        var st: [Bool] = .init(repeating: false, count: n)
        func dfs(_ cnt: Int) {
            if cnt == n {
                ans.append(path)
                return
            }

            for (i, _) in nums.enumerated() {
                if !st[i] {
                    st[i] = true
                    path.append(nums[i])
                    dfs(cnt + 1)
                    path.popLast()
                    st[i] = false
                }
            }
        }
        dfs(0)
        return ans
    }
}
