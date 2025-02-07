class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var seen: [Int: Int] = [:]
        for (idx, val) in nums.enumerated() {
            let y = target - val
            let next = seen[y]
            if let j = next {
                return [j, idx]
            }
            seen[val] = idx
        }
        return [-1, -1]
    }
}
