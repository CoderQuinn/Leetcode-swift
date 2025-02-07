class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
        var ans: [[Int]] = []
        var path: [Int] = []

        let n = nums.count
        func dfs(_ u: Int) {
            if u == n {
                ans.append(path)
                return
            }
            dfs(u + 1)
            path.append(nums[u])
            dfs(u + 1)
            path.popLast()
        }
        dfs(0)
        return ans
    }
}
