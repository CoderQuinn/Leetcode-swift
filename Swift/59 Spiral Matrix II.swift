class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
        var ans: [[Int]] = .init(repeating: .init(repeating: -1, count: n), count: n)
        let k = n * n
        let dx: [Int] = [0, 1, 0, -1], dy: [Int] = [1, 0, -1, 0]
        var x = 0, y = 0, d = 0
        for val in 1 ... k {
            ans[x][y] = val

            var i = x + dx[d], j = y + dy[d]
            if i < 0 || i >= n || j < 0 || j >= n || ans[i][j] != -1 {
                d = (d + 1) % 4
                i = x + dx[d]
                j = y + dy[d]
            }
            x = i
            y = j
        }

        return ans
    }
}
