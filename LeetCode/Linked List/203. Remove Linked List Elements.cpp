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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = nullptr;
        
        while (head != nullptr && head->val == val){
            temp = head;
            head = head->next;
            delete temp; 
        }

        if (head == nullptr) return head; 

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != nullptr){      
            if (curr->val == val){
                temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            } 
            else {
                curr = curr->next;
                prev = prev->next;
            }
            
        }

        return head;

    }
};

//y tuong: kiem tra toan bo cac node phia truoc, neu node phia truoc co thi remove het
//dung bien prev & curr de luu lai, neu gap curr->val == val thi xoa, cong thuc xoa: A->B->C => A->C, nghia la dung bien temp luu tru temp = node B, keo nut A qua nut C roi xoa temp
