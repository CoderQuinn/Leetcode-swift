class Solution {
    func canFinish(_ numCourses: Int, _ prerequisites: [[Int]]) -> Bool {
        let n = numCourses
        var g: [[Int]] = .init(repeating: [], count: n)
        for (idx, val) in prerequisites.enumerated() {
            if let a = val.first, let b = val.last {
                g[b].append(a)
            }
        }

        var colors: [Int] = .init(repeating: 0, count: n)
        func dfs(_ u: Int) -> Bool {
            colors[u] = 1
            for item in g[u] {
                if colors[item] == 1 || colors[item] == 0 && dfs(item) {
                    return true
                }
            }
            colors[u] = 2
            return false
        }

        for item in 0 ..< n {
            if colors[item] == 0 && dfs(item) {
                return false
            }
        }

        return true
    }
}
