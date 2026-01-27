#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head{ nullptr };
        ListNode* now_ptr = head;

        while (now_ptr != nullptr) {
            ListNode* next_ptr = now_ptr->next;
            now_ptr->next = new_head;
            new_head = now_ptr;
            now_ptr = next_ptr;
        }

        return new_head;
    }
};