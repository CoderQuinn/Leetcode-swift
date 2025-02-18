class Solution {
    func findCircleNum(_ isConnected: [[Int]]) -> Int {
        let n = isConnected.count
        var g: [[Int]] = .init(repeating: [], count: n)
        for i in 0 ..< n {
            for j in i + 1 ..< n {
                if isConnected[i][j] == 1 {
                    g[i].append(j)
                    g[j].append(i)
                }
            }
        }

        var seen = Set<Int>()
        func dfs(_ root: Int) {
            seen.insert(root)
            for x in g[root] {
                if !seen.contains(x) {
                    dfs(x)
                }
            }
        }

        var ans = 0
        for i in 0 ..< n {
            if !seen.contains(i) {
                ans += 1
                dfs(i)
            }
        }
        return ans
    }
}
