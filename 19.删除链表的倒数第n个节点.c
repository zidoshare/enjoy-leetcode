/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (40.45%)
 * Likes:    1088
 * Dislikes: 0
 * Total Accepted:    275.1K
 * Total Submissions: 680.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 *
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 *
 * 你能尝试使用一趟扫描实现吗？
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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *pre = head;
    struct ListNode *current = head;
    int i = 1;
    while (current->next != NULL)
    {
        if (i++ > n)
        {
            pre = pre->next;
        }
        current = current->next;
    }
    if (i == n)
    {
        return head->next;
    }
    pre->next = pre->next->next;
    return head;
}
// @lc code=end
