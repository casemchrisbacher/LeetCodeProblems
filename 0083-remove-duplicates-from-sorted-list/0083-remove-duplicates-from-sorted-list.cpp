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
    // In place removal of duplicates from linked list
    ListNode* deleteDuplicates( ListNode* head )
    {
        // Passing in a nullptr is not chill
        if ( head == nullptr )
        {
            return head;
        }
        
        ListNode* slow_iter = head;         // turtle ptr
        ListNode* fast_iter = head->next;   // hare ptr

        // Entire linked list
        while ( slow_iter != nullptr )
        {
            // skip over all duplicate values
            while ( fast_iter != nullptr && slow_iter->val == fast_iter->val )
            {
                fast_iter = fast_iter->next;
            }
            slow_iter->next = fast_iter;
            slow_iter = slow_iter->next;
        }
        return head;    // return beginning of list
    } // end of deleteDuplicates
}; // end of Solution class