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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> st1, st2;
        int c = 0, sum;
        ListNode *curr = nullptr;

        while(l1 != nullptr){
            st1.push_back(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr){
            st2.push_back(l2->val);
            l2 = l2->next;
        }

        while((!st1.empty() || !st2.empty()) || c != 0){
            sum = c;
            
            if (!st1.empty()){
                sum += st1.back();
                st1.pop_back();
            }

            if (!st2.empty()){
                sum += st2.back();
                st2.pop_back();
            }
            
            c = sum / 10;
            
            ListNode *temp = new ListNode(sum % 10);
            temp->next = curr;
            curr = temp;
        }

        return curr;
    }
};

//idea: day^? 2 linkedlist vao` vector, stack,..., cong. r add vao` linkedlist moi' (tuong tu prob 2.)
