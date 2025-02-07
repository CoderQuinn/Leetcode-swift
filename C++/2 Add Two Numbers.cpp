/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        auto cur = dummy;
        auto p = l1, q = l2;
        int t = 0;
        while (p || q || t > 0)
        {
            if (p)
            {
                t += p->val;
                p = p->next;
            }
            if (q)
            {
                t += q->val;
                q = q->next;
            }
            cur->next = new ListNode(t % 10);
            cur = cur->next;
            t /= 10;
        }
        return dummy->next;
    }
};