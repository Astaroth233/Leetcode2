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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow -> next;
        while(curr != NULL)
        {
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        slow -> next = NULL;

        ListNode* first = head;
        ListNode* second = prev;
        while(second)
        {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};