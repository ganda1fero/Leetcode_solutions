#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

/// само решение



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_len{ 0 };  // будет записана длина всего list
        ListNode* head_copy = head;
        while (head_copy != nullptr) {
            ++list_len;
            head_copy = head_copy->next;
        }

        ListNode* tmp_node;
        if (n == list_len) {    // значит просто сдвигаем head
            tmp_node = head;
            head = head->next;
            delete tmp_node;
        }
        else {  // нужно сделать смещение (ищем до указателя до самого нужного)
            tmp_node = head;
            for (int i{ 0 }, tmp_len = list_len - n - 1; i < tmp_len; ++i) {
                tmp_node = tmp_node->next;
            }

            ListNode* for_del = tmp_node->next;
            tmp_node->next = tmp_node->next->next;
            delete for_del;
        }

        return head;
    }
};

int main() {	// для проверки решения
    Solution solution;

    ListNode* head = new ListNode(1, new ListNode(2));

    ListNode* answer = solution.removeNthFromEnd(head, 2);
    ListNode* tmp;
    
    while (answer != nullptr) {
        std::cout << answer->val << ' ';
        tmp = answer;
        answer = answer->next;
        delete tmp;
    }
}