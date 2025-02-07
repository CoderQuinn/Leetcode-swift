class Solution {
    func isPalindrome(_ s: String) -> Bool {
        var str = s.filter { $0.isLetter || $0.isNumber }
        var res: [String] = []
        for e in str {
            if e.isUppercase {
                res.append(e.lowercased())
            } else {
                res.append(String(e))
            }
        }

        let n = res.count
        var i = 0, j = n - 1
        while i < j {
            if res[i] != res[j] {
                return false
            }
            i += 1
            j -= 1
        }
        return true
    }
}
