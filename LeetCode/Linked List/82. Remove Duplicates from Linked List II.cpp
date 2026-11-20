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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        ListNode *dummy = new  ListNode(0, head);
        ListNode *prev = dummy;
        int dem = 0;

        while(curr != nullptr && curr->next != nullptr){
            if (curr->val == curr->next->val){
                int dup = curr->val;
                while(curr != nullptr && curr->val == dup){
                    ListNode *temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
            
        }
        
        return dummy->next;
    }
};

// y tuong: giong prob 83, neu gt1 = gt2 thi luu gia tri dup, sau do xoa het cac gia tri = dup, sau khi xoa het tro prev->next = val
 
