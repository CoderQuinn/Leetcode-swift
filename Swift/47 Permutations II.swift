class Solution {
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        var ans: [[Int]] = []
        var path: [Int] = []
        let res = nums.sorted()

        let n = res.count
        var state: [Bool] = .init(repeating: false, count: n)
        func dfs(_ cnt: Int) {
            if cnt == res.count {
                ans.append(path)
                return
            }

            for i in 0 ..< res.count {
                if state[i] {
                    continue
                }

                if i > 0, res[i - 1] == res[i], state[i - 1] {
                    continue
                }

                state[i] = true
                path.append(res[i])
                dfs(cnt + 1)
                path.popLast()
                state[i] = false
            }
        }
        dfs(0)
        return ans
    }
}
