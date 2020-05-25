/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * list1 = l1;
        ListNode * list2 = l2;
    
        ListNode * pre1;
        ListNode * pre2;
        
        int carry = 0;
        
        int cl1 = 0;
        int cl2 = 0;
        while(l1 && l2)
        {
            l1->val = l1->val + l2->val + carry;
            carry = 0;
            if(l1->val >= 10)
            {
                carry = l1->val/10;
                l1->val =  l1->val % 10;
            }
            l2->val = l1->val;
            pre1 = l1;
            pre2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            l1->val = l1->val + carry;
            carry = 0;
            if(l1->val >= 10)
            {
                carry = l1->val/10;
                l1->val =  l1->val % 10;
            }
            pre1 = l1;
            l1 = l1->next;
            cl1++;
        }
        
        while(l2)
        {
            l2->val = l2->val + carry;
            carry = 0;
            if(l2->val >= 10)
            {
                carry = l2->val/10;
                l2->val =  l2->val % 10;
            }
            pre2 = l2;
            l2 = l2->next;
            cl2++;
        }
        if(carry > 0)
        {
            if(cl1 > cl2)
            {
                ListNode *temp = new ListNode(carry); //(ListNode *)malloc(sizeof(ListNode));
                
                temp->next = NULL;
                
                pre1->next = temp;
                
                return list1;
            }
            else{
                ListNode *temp = new ListNode(carry); //(ListNode *)malloc(sizeof(ListNode));
                
                temp->next = NULL;
                
                pre2->next = temp;
                
                return list2;
            }
        }
        
         if(cl1 > cl2)
            {
                
                return list1;
            }
            else{
                return list2;
            }
    }
};