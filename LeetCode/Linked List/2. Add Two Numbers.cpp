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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0){
            if (l1){
                carry += l1->val;
                l1 = l1->next;
            } 
            
            if (l2){
                carry += l2->val;
                l2 = l2->next;
            } 

            if (carry >= 10){
                curr->next = new ListNode(carry - 10);
                carry = 1;
            } else {
                curr->next = new ListNode(carry);
                carry = 0;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};

//do day~ so' dao? nguoc. nen^ phong cach' giong' dat. phep' cong. va` tinh' bang` tay

//1. Neu con l1 hoac l2, cong don val vao carry va dich node = node->next
//2. Do tong <= 19 nen ta co:
//      Neu carry >= 10: Tao node moi voi (carry - 10), giu carry = 1 cho vong sau
//      Neu carry < 10: Tao node moi voi carry, reset carry = 0
// 3. Noi' node vao sau curr, dich curr = curr->next
