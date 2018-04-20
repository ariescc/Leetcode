#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0; // 链表的长度

        ListNode *p = head;

        // 计算链表的长度
        while(p != NULL) {
            len++;
            p = p -> next;
        }

        if(!(len - n)) {
            head = head -> next;
            return head;
        }

        //cout << "length of linked List: " << len << endl;

        ListNode *delNode;
        int q = 0;
        p = head;

        while(p != NULL) {

            if(q == len - n - 1) {

                delNode = p -> next;
                p -> next = p -> next -> next;

                delete delNode;

                //cout << "delete successfully !" << endl;
            }

            q++;
            p = p -> next;
        }

        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *pp = head;
    int n;

    cin >> n; // 输入链表长度

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ListNode *nex = new ListNode(num);
        pp -> next = nex;
        pp = pp -> next;
    }

    ListNode *pt = head;

    while(pt != NULL) {
        cout << pt -> val << " ";
        pt = pt -> next;
    }

    cout << endl;

    ListNode *res = sol.removeNthFromEnd(head, 1);
    pt = res;

    while(pt != NULL) {
        cout << pt -> val << " ";
        pt = pt -> next;
    }

    cout << endl;

    return 0;
}
