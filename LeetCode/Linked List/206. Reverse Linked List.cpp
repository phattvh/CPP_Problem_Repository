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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextn = nullptr;

        while (curr != nullptr){
            nextn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextn;
        }
        
        return prev;
    }
};

// co the dung stack de luu tru, sau do lay ra r tra ve
