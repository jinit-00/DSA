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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        

        vector<int> answer;
        int first = -1;
        int last = -1;
        int dist_min = INT_MAX;
        int dist_max = INT_MIN;
        ListNode* temp = head->next;
        int i = 1;
        int count = 0;
        int value = head->val;
        while(temp->next)
        {
            i++;
            if((value < temp->val && temp->val > temp->next->val) || (value > temp->val && temp->val < temp->next->val))
            {
                if(first == -1)
                    first = i;
                if(last != -1)
                    dist_min = min(dist_min , i - last);
                last = i;
                dist_max = max(dist_max , i - first);
                count ++;
            }
            value = temp->val;
            temp = temp->next;
        }
        if(count < 2)
        return {-1,-1};
    return {dist_min , dist_max};
    }
};