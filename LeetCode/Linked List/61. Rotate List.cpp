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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        ListNode *tail = head;
        int n = 1;

        while(tail->next != nullptr){
            n += 1;
            tail = tail->next;
        }

        k = k % n;

        tail->next = head;
        for(int i = 0; i < n - k; i += 1) tail = tail->next;

        head = tail->next;
        tail->next = nullptr;

        return head;

    }
};

//1. cho con tro tail chay ve phia duoi & dem so luong phan tu co trong ll
//2. k = k % n vi chay bao nhieu buoc du thi cung ve k buoc
//3. noi vong va chay
//4. dat head la tail next, vi tail dang o node cuoi, sau do ngat va tra ve head
