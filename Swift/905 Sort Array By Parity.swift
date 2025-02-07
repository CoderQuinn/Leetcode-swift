class Solution {
    func sortArrayByParity(_ nums: [Int]) -> [Int] {
        var i = 0, j = nums.count - 1
        var tmps: [Int] = nums
        while i < j {
            if tmps[i] % 2 == 0 {
                i += 1
            } else if tmps[j] % 2 == 1 {
                j -= 1
            } else {
                tmps.swapAt(i, j)
                i += 1
                j -= 1
            }
        }
        return tmps
    }
}
