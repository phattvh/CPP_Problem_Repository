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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    //cach 1:
        // ListNode *v1 = list1;
        // ListNode *v2 = list1;
        // ListNode *tail2 = list2;

        // // if (a > 1) for(int i = 0; i < a - 1; i += 1) v1 = v1->next;
        // // for(int i = 0; i < b + 1; i += 1) v2 = v2->next;

        // // while(tail2->next != nullptr) tail2 = tail2->next;
        
        // // v1->next = list2;
        // // tail2->next = v2;
        
        ListNode *v1 = list1;

        if (a > 1) for(int i = 0; i < a - 1; i += 1) v1 = v1->next;
        ListNode *curr1 = v1;

        for(int i = 0; i < b - a + 2; i += 1) v1 = v1->next;
        ListNode *curr2 = v1;

        curr1->next = list2;

        while(list2->next != nullptr) list2 = list2->next;

        list2->next = curr2;
        

        return list1;
    }
};

/*
CACH 1: Dung cac con tro doc lap xuat phat tu dau danh sach de tim tung diem noi.
  + B1: Khoi tao v1 = list1, v2 = list1, tail2 = list2.
  + B2: Di chuyen v1 tien (a - 1) buoc de dung ngay truoc doan bi xoa.
  + B3: Di chuyen v2 tu dau list1 tien (b + 1) buoc de dung ngay sau doan bi xoa.
  + B4: Duyet tail2 den nut cuoi cung cua list2 (tail2->next == nullptr).
  + B5: Noi v1->next = list2 va tail2->next = v2. Tra ve list1.


CACH 2: Tan dung vi tri da tim duoc o buoc truoc de di tiep, khong quay lai tu dau.
  + B1: Khoi tao v1 = list1.
  + B2: Di chuyen v1 tien (a - 1) buoc va luu lai diem cat dau (curr1 = v1).
  + B3: Xuat phat tu v1, di tiep (b - a + 2) buoc den vi tri (b + 1) va luu diem noi duoi (curr2 = v1).
  + B4: Noi curr1->next = list2.
  + B5: Tan dung bien list2 de chay toi nut cuoi cung, sau do noi list2->next = curr2. Tra ve list1.
*/
