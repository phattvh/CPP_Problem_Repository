//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head;
        for(int i = 0; i < k - 1; i += 1) first = first->next;

        ListNode *slow = head;
        ListNode *fast = first;
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        int temp = first->val;
        first->val = slow->val;
        slow->val = temp;

        return head;

    }
};

/*y tuong
1. duyet first den node vi tri k
2. khoi tao slow va fast (luc nay first dung ngay k nen khi fast->next == nullptr thi slow = n-k node)
3. doi gia tri cho nhau
*/
