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
    // TC : O(N(logN))
    // SC : O(N)
    void deleteNode(ListNode* delNode)
    {
        auto nxt = delNode -> next;
        *delNode  = *(delNode -> next);
        delete(nxt);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first = head;
        auto second = head;
        ListNode* prv = NULL;
        while(n--) {
            first = first -> next;
        }
        while(first) {
            first = first -> next;
            prv = second ;
            second = second -> next;
        }
        if(second -> next)
            deleteNode(second);
        else if (prv)
            prv -> next = NULL;
        else 
            return NULL;
       
        return head;
        
    }
};