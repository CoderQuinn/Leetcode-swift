class Solution {
    func isPalindrome(_ s: [String], _ l: Int, _ r: Int) -> Bool {
        var i = l, j = r
        while i < j {
            if s[i] != s[j] {
                return false
            }
            i += 1
            j -= 1
        }
        return true
    }

    func validPalindrome(_ s: String) -> Bool {
        var res: [String] = []
        for e in s {
            res.append(String(e))
        }

        var i = 0, j = res.count - 1
        while i < j {
            if res[i] != res[j] {
                return isPalindrome(res, i + 1, j) || isPalindrome(res, i, j - 1)
            }
            i += 1
            j -= 1
        }
        return true
    }
}
