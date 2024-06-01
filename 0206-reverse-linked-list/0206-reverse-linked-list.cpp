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
    // Reverse a linked list 
    ListNode* reverseList( ListNode* head )
    {
        ListNode* prev{ nullptr };
        ListNode* curr{ head };
        ListNode* next_node{ nullptr };

        while ( curr != nullptr )
        {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    } // end of reverseList
}; // end of Solution class