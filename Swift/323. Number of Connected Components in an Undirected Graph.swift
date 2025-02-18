class Solution {
    func countComponents(_ n: Int, _ edges: [[Int]]) -> Int {
        var g: [[Int]] = .init(repeating: [], count: n)
        for e in edges {
            if let a = e.first, let b = e.last {
                g[a].append(b)
                g[b].append(a)
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
