// source : https://leetcode.com/problems/add-two-numbers/
/*********************************************************************
*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
*
*You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
*Example 1:
*           Input: l1 = [2,4,3], l2 = [5,6,4]
*           Output: [7,0,8]
*           Explanation: 342 + 465 = 807.
**
*Example 2:
*          Input: l1 = [0], l2 = [0]
*          Output: [0]
**
*Example 3:
*          Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
*          Output: [8,9,9,9,0,0,0,1]
**
************************************************************************/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
      // initialize the new Linked List.
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=NULL||l2!=NULL||sum>0)
        {
            if(l1!=NULL)
            { // the val of l1 and l2 of of same node is add to sum.
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
          //Now store the value in sum to the new node.
            (*node)=new ListNode(sum%10);
          // To add the carry to sum for the next value. 
            sum/=10;
            node=&((*node)->next);
        }        
        return l3;
       
    }
};
