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
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *ptr = head;
        int size = 0;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            size++;
        }
        k = k % size;
        ListNode *prev = head;
        ListNode *curr = head;
        
        for(int i = 0 ; i < k ; i++)
        {
            curr = curr->next;
        }
        while(curr->next != NULL)
        {
            curr= curr->next;
            prev= prev->next;
        }
        
        curr->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;
    }
};