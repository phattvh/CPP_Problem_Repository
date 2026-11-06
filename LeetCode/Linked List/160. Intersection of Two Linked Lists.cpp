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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        //cach 1:
        while(pA != pB){

            if (pA == nullptr) pA = headB;
                else pA = pA->next;

            if (pB == nullptr) pB = headA;
                else pB = pB->next;

        }

        return pA;

        //cach 2:
        // int a = 0, b = 0;

        // while(pA != nullptr){
        //     a += 1;
        //     pA = pA->next;
        // }

        // while(pB != nullptr){
        //     b += 1;
        //     pB = pB->next;
        // }

        // pA = headA;
        // pB = headB;
        // int du = abs(a - b);

        // if (a > b) while(du > 0) {
        //     pA = pA->next;
        //     du -= 1;
        // } else if (b > a) while(du > 0) {
        //     pB = pB->next;
        //     du -= 1;
        // }

        // while (pA != nullptr){
        //     if (pA == pB) return pA;
            
        //     pA = pA->next;
        //     pB = pB->next;
        // }

        // return pA;

    }
};

//dung 2 con tro

//cach 1: cho 2 con tro chay het danh sach cua minh roi doi sang nhanh ben kia, khi di cung 1 quang duong thi 2 con tro se gap nhau: hoac la giao tai nullptr, hoac giao tai 1 diem bat ky (A + C) + B = (B + C) + A

//cach 2 (de hon): vi doan chung co do dai bang nhau nen danh sach nao dai hon thi cho di truoc, den khi ca 2 con tro bang nhau thi cung nhau di

