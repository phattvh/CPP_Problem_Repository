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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        

        for(int i = 0; i < n; i += 1) fast = fast->next;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delnode = slow->next;
        slow->next = delnode->next;
        delete delnode;

        return dummy.next;
    }
};

// Y tuong: dung 2 con tro fast-slow giu khoang cach co dinh la n; ket hop Dummy Head de xu ly xoa node dau 

// Cac buoc thuc hien:
// 1. Tao dummy noi vao head (dummy.next = head).
// 2. Dat 2 con tro slow va fast tai dummy.
// 3. Cho fast chay truoc n buoc de tao khoang cach n voi slow.
// 4. Cho ca fast va slow cung tien den khi ffast->next == nullptr thi slow dung' ngay truoc' node can xoa.
// 5. Ngat lien ket va xoa node


