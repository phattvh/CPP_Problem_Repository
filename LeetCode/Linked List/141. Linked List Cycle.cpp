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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        //ListNode *fast = head;

        if (head == nullptr) return false;
        
        //while (fast != nullptr && fast->next != nullptr) {
        //    fast = fast->next->next;
        //    slow = slow->next;
        //    if (fast == slow) return true;
        //}

        
        
        while(slow->val != 99999){
            slow->val = 99999;
            slow = slow->next;
            if (slow == nullptr) return false;
        }

        return true;
    }
};

//cach 1: thuat toan rua va tho (2 con tro nhanh va cham), slow = 2, fast = 1, neu slow va fast gap nhau -> co cycle, neu fast gap nullptr thi khong co cycle
//cach 2 (ta` dao.): duyet. toi' dau^ doi^ so^ thanh` 9999 toi do', neu^ gap = co' cycle
