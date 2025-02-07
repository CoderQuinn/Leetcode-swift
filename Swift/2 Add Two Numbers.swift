/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var p = l1, q = l2
        var dummy: ListNode = .init(-1)
        var cur = dummy
        var t = 0
        while p != nil || q != nil || t > 0 {
            if let tmp = p {
                p = tmp.next
                t += tmp.val
            }
            if let tmp = q {
                q = tmp.next
                t += tmp.val
            }

            var tmp: ListNode? = .init(t % 10)
            cur.next = tmp
            cur = tmp!
            t /= 10
        }
        return dummy.next
    }
}
