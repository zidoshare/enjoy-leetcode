/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <malloc.h>
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *self = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *current = head;
  self->val = 0;
  self->next = NULL;
  struct ListNode *n1 = l1;
  struct ListNode *n2 = l2;
  int carry = 0;
  while (current != NULL)
  {
    current->val = n1->val + n2->val + carry;
    carry = 0;
    if (current->val >= 10)
    {
      current->val = current->val % 10;
      carry = 1;
    }
    n1 = (n1->next == NULL ? self : n1->next);
    n2 = (n2->next == NULL ? self : n2->next);
    if (n1 == self && n2 == self)
    {
      if (carry == 1)
      {
        current = current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current->val = 1;
        current->next = NULL;
      }
      break;
    }
    else
    {
      current = current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      current->next = NULL;
    }
  }
  return head;
}
