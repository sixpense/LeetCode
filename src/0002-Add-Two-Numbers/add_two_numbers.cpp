                                                                       /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* p = l3;
        int carry = 0;          //进位
        int sum = 0;
        while(l1 || l2 || carry)    //l1,l2,进位皆不为空
        {
            sum = (l1? l1->val : 0) + (l2? l2->val : 0) + carry;   //l1不为空，取当前val值，否则取0
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1? l1->next : l1;     //l1不空往下
            l2 = l2? l2->next : l2;
            
        }
        return l3->next;
    }
};
