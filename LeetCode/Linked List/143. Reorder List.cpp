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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        ListNode *nextnode = nullptr;

        while(second != nullptr){
            nextnode = second->next;
            second->next = prev;
            prev = second;
            second = nextnode;
        }

        ListNode *curr = head;
        ListNode *curr2 = prev;
        ListNode *nextnode2 = nullptr;

        while(curr2 != nullptr){
            nextnode = curr->next;
            nextnode2 = curr2->next;

            curr->next = curr2;
            curr2->next = nextnode;
            
            curr = nextnode;
            curr2 = nextnode2;
        }

    }
};

//1. dung 2 con tro slow & fast de tim diem giua
//2. dat bien second de bat dau list 2 va tach 2 list ra
//3. dao nguoc list B
//3. noi node list A qua list B va nguoc lai
