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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp = head;
        int list_len{0};
        while ( temp != nullptr )
        {
            list_len++;
            temp = temp->next;
        }
        n = list_len - n;

        if ( n == 0 )
        {
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
        while ( temp->next != nullptr && n > 1 )
        {
            temp = temp->next;
            n--;
        }
        if ( temp->next == nullptr ) return nullptr;
        
        ListNode* delete_me = temp->next;
        temp->next = temp->next->next;
        delete delete_me;
        return head;

    }
};