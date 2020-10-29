/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (64.60%)
 * Likes:    1346
 * Dislikes: 0
 * Total Accepted:    398.6K
 * Total Submissions: 617.1K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = NULL;
    struct ListNode *head = pre;
    struct ListNode *tmp = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1 != NULL)
    {
        pre->next = l1;
    }
    if (l2 != NULL)
    {
        pre->next = l2;
    }
    return head->next;
}
// @lc code=end
