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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        if(head == nullptr || head->next == nullptr)
        return head;
        while(temp->next)
        {
            int one = temp->val;
            int two = temp->next->val;
            int value = gcd(one,two);
            ListNode* next_one = new ListNode(value);
            ListNode* store = temp->next;
            temp->next = next_one;
            next_one->next = store;
            temp = temp->next->next;
        }
        return head;
    }
};