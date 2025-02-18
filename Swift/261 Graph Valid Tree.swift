class Solution {
    func validTree(_ n: Int, _ edges: [[Int]]) -> Bool {
        if n != edges.count + 1 {
            return false
        }
        var g = [[Int]](repeating: [], count: n)
        for item in edges {
            if let a = item.first, let b = item.last {
                g[a].append(b)
                g[b].append(a)
            }
        }

        var seen = Set<Int>()
        func dfs(_ root: Int) {
            seen.insert(root)
            for item in g[root] {
                if !seen.contains(item) {
                    dfs(item)
                }
            }
        }
        dfs(0)
        return seen.count == n
    }
}
