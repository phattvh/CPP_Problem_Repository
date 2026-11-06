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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *prev = nullptr;
        ListNode *nextnode = nullptr;

        while (slow != nullptr){
            nextnode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextnode;
        }  

        ListNode *start = head;

        while (prev != nullptr){
            if (start->val != prev->val) return false;

            start = start->next;
            prev = prev->next;
        }

        return true;

    }
};

//dung 2 con tro (slow-fast) tim chinh giua, sau do tu chinh giua dung them con tro prev de reverse lai, roi dung start va prev de so sanh trai-phai
