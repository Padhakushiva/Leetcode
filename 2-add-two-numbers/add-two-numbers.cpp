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
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        while(l1 || l2 || carry){
            int x=(l1 != NULL) ? l1->val : 0;

            int y=(l2 != NULL) ? l2->val : 0;
            if(l1) l1 = l1->next;

            if(l2) l2 = l2->next;

            int sumofxy=x+y+carry;
            int finalvalue=sumofxy%10;
            carry=sumofxy/10;

            temp->next=new ListNode(finalvalue);
            temp=temp->next;
        }
        if(l1==NULL && l2){
            temp->next=l2->next;
        }
        if(l2==NULL && l1){
            temp->next=l1->next;
        }
        return dummy->next;
    }
};