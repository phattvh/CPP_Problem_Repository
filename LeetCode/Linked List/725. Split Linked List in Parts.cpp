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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        ListNode *nextp = nullptr;
        int n = 0;

        while(curr != nullptr){
            curr = curr->next;
            n += 1;
        }

        int base = n / k;
        int extra = n % k;

        vector<ListNode*> result(k, nullptr);

        curr = head;

        for(int i = 0; i < k && curr != nullptr; i += 1){
            result[i] = curr;

            int part = base + (i < extra ? 1 : 0);

            for(int i = 0; i < part - 1; i += 1) curr = curr->next;

            nextp = curr->next;
            curr->next = nullptr;
            curr = nextp;
        }

        return result;

    }
};

// idea: dem' tong? so' node N, sau do' chia deu` vao` k phan`, phan` du (N % k) se~ duoc. cong. them^ 1 node vao` cac' phan` dau`

// Cac' buoc'
// 1. Duyet. danh sach' de? dem' so' phan` tu? n
// 2. Tinh kich thuoc moi phan: base = n / k, so phan dau tien duoc cong them: extra = n % k.
// 3. Khoi tao mang ket qua result gom k phan tu nullptr.
// 4. Duyet lan luot tung phan i (tu 0 den k - 1):
//      Gan node dau tien cua phan hien tai vao result[i].
//      Tinh kich thuoc: part = base + (i < extra ? 1 : 0).
//      Di chuyen curr toi node cuoi cua part.
//      Ngat lien ket duoi va tro voi phan ke

