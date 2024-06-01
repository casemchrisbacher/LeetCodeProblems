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
    bool isPalindrome( ListNode* head )
    {
        ListNode* fast{ head };
        ListNode* slow{ head };
        
        // Get the halfway point with turtle and hare
        while ( fast->next != nullptr && fast->next->next != nullptr )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev{ nullptr };
        ListNode* curr{ slow };
        ListNode* next_node{ nullptr };

        // Reverse half of the linked list
        while ( curr != nullptr )
        {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        // compare first half with reversed second half
        while ( prev != nullptr && head != nullptr )
        {
            if ( prev->val != head->val )
            {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    } // end of isPalindrome
}; // end of Solution class