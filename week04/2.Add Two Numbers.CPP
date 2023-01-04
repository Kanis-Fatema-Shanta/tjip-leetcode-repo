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
    // TC: O(n+m + max(n+m)) SC: O(1)
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto node = l1;
        int c1 = 0, c2 = 0; // Length of l1 and l2 respectively

        while (node) {
            c1++;
            node = node->next;
        }

        node = l2;
        while (node) {
            c2++;
            node = node->next;
        }

        // swap if the length of l2 is greater than l1
        if (c2 > c1)
            swap(l1, l2);

        auto head = l1; // head of the result list
        int carry = 0;

        while (l1 || l2) {
            int val = l2 ? l2->val : 0; // if l2 is null, then val is 0
            l1->val = l1->val + val + carry;

            // if there is overflow, i.e sum becomes 2 digits
            if (l1->val > 9) {
                carry = l1->val / 10;
                l1->val = l1->val % 10;
            }
            else {
                carry = 0; // reset value to 0 if there is no overflow
            }

            // If there is still carry remaining at the last element, then add a new node with value as carry
            if (!l1->next && carry > 0) {
                node = new ListNode(carry);
                l1->next = node;
                break; // break is required as there will be an unnecessary iteration due to addition of new node
            }

            l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head; // return the head of the result list
    }
};