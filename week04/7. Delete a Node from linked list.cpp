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
    // TC : N(logN)
    // SC : O(N)
    void deleteNode(ListNode* delNode) {
        auto nxt = delNode -> next;
        //delNode -> val = delNode -> next -> val;
        //delNode -> next = delNode -> next next
        *(delNode) = *(delNode -> next);
        delete(nxt);

        
    }
};