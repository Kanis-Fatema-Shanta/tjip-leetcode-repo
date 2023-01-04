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
    // TC : O(N)
    // SC : O(N)
    ListNode* reverseList(ListNode* head) {
        auto CurrNode = head;
        ListNode* prvNode = NULL;
        while(CurrNode) {
            auto nextNode = CurrNode -> next;
            CurrNode -> next = prvNode;
            prvNode = CurrNode;
            CurrNode = nextNode;
        }
        return prvNode;
        
    }
};