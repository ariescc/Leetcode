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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;

        if(head == NULL) {
            return NULL;
        }

        while(p != NULL && p -> next != NULL) {
            // 当前结点为p，一直删除到 p -> next的值与p的值不同为止
            while(p -> next != NULL && p -> val == p -> next -> val) {
                cout << "p -> val: " << p -> val << endl;
                ListNode *tmp = p -> next;
                p -> next = p -> next -> next;
                delete tmp;
            }
            p = p -> next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    int n;
    int head_val;

    cin >> head_val;

    ListNode *head = new ListNode(head_val);

    cin >> n;

    ListNode *p = head;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode *nxt = new ListNode(val);
        p -> next = nxt;
        p = p -> next;
    }

    cout << "print linked list: ";

    p = head;
    while(p != NULL) {
        cout << p -> val << " ";
        p = p -> next;
    }

    cout << "\n-----------\n";

    p = sol.deleteDuplicates(head);

    cout << "result: ";

    while(p != NULL) {
        cout << p -> val << " ";
        p = p -> next;
    }

    cout << endl;

    return 0;
}