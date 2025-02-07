class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        var ans: [Int] = []
        let n = matrix.count, m = matrix[0].count
        let k = n * m

        var state: [[Bool]] = .init(repeating: .init(repeating: false, count: m), count: n)
        let dx: [Int] = [0, 1, 0, -1], dy: [Int] = [1, 0, -1, 0]
        var x = 0, y = 0, d = 0
        for _ in 0 ..< k {
            let val = matrix[x][y]
            ans.append(val)
            state[x][y] = true

            var i = x + dx[d], j = y + dy[d]
            if i < 0 || i >= n || j < 0 || j >= m || state[i][j] {
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
