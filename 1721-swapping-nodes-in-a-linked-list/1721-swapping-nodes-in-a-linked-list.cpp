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
    ListNode* swapNodes(ListNode* head, int k) {
       if(head==NULL)
           return NULL;
        
        ListNode *ptr1=head;
        ListNode *ptr2=head;
        ListNode *ptr3=head;
        
        int i=1;
        while(i!=k)
        {
           ptr1=ptr1->next;
           ptr2=ptr2->next;
            i++;
        }
        // cout<<ptr1->val<<endl;
        while(ptr2->next!=NULL)
        {
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        // cout<<ptr3->val<<endl;
        int num=ptr3->val;
        ptr3->val=ptr1->val;
        ptr1->val=num;
        return head;
    }
};