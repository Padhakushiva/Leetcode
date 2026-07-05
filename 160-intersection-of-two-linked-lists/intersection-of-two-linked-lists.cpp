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
        int count1=0;
        int count2=0;
        ListNode* temp1=headA;
        ListNode* temp2= headB;
        while(temp1!=NULL){
            count1++;
            temp1=temp1->next;
        }
        temp1=headA;
        while(temp2!=NULL){
            count2++;
            temp2=temp2->next;
        }
        temp2=headB;
        int lengthdifference=abs(count1-count2);
        if(count2>count1){
            for(int i=0; i<lengthdifference; i++){
                temp2=temp2->next;
            }
        }
        else{
            for(int i=0; i<lengthdifference; i++){
                temp1=temp1->next;
            }
        }

        while(temp1){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        cout<<"No intersection";
        return NULL;
    }
};