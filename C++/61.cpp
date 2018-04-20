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
    // 循环次数，旋转长度大于链表长度，只需要旋转 k % len 次
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode *pt = head;
        if(head == NULL) {
            return head;
        }

        // 计算链表长度
        int len = 1;
        while(pt -> next != NULL) {
            len++;
            pt = pt -> next;
        }

        int n = k % len; // 循环次数

        // 将倒数第 n 位到最后的链表放到头部
        pt -> next = head;

        int q = 0;
        while(q < len - n) {
            pt = pt -> next;
            q++;
        }

        head = pt -> next;
        pt -> next = NULL;

        return head;

    }
};
