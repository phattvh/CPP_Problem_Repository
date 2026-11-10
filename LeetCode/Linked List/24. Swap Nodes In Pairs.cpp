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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        ListNode *prev = &dummy;
        
        dummy.next = head;

        while(prev->next && prev->next->next){
            ListNode *first = prev->next;
            ListNode *second = first->next;

            
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            prev = first;
        }
        
        return dummy.next;

    }
};

// dung` Dummy Node lam` diem? tua. de^ hoan' doi? con tro? theo tung` cap. 2 nut'
// phia' sau prev khong^ con` du? 2 nut' de? swap thi` dung`

// 1. first->next = second->next  first nhay? qua second, tro? den' nut' thu' 3
// 2. second->next = first        second quay dau` tro? nguoc. lai. first
// 3. prev->next = second         prev noi' vao` second de? giu~ mach. chuoi~
// 4. prev = first                dich prev len^ hai nut' lam` diem? tua. moi'

