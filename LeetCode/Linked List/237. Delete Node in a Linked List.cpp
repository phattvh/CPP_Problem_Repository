//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

//do chi? co' the? truy cap. vao` node can` xoa' va` khong^ co' con tro? head
//nen^ ta bien' node do' thanh` node phia' sau (nghia~ la` node->next), sau do' tro? node vao node->next->next
