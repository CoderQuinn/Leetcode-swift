class Solution {
    func subsetsWithDup(_ nums: [Int]) -> [[Int]] {
        let res = nums.sorted()
        var ans: [[Int]] = []
        var path: [Int] = []
        let n = nums.count
        func dfs(_ u: Int) {
            if u == n {
                ans.append(path)
                return
            }

            let x = res[u]
            path.append(x)
            dfs(u + 1)
            path.popLast()

            var k = u + 1
            while k < n, res[k] == x {
                k += 1
            }
            dfs(k)
        }
        dfs(0)
        return ans
    }
}
