#include <iostream>
using namespace std;
// (по условию)
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// само решение

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr && list2 == nullptr) {
			return nullptr;
		}

		ListNode* head = ((list1 == nullptr) ? list2 : ((list2 == nullptr) ? list1 : ((list1->val < list2->val) ? list1 : list2)));
		if (head == list1) {
			list1 = list1->next;
		}
		else {
			list2 = list2->next;
		}
		ListNode* answer = head;

		while (list1 != nullptr || list2 != nullptr) {
			if (list1 == nullptr) {
				merge(head, list2);
			}
			else if (list2 == nullptr) {
				merge(head, list1);
			}
			else {
				if (list1->val < list2->val) {
					merge(head, list1);
				}
				else {
					merge(head, list2);
				}
			}
		}

		return answer;
	}
private:
	void merge(ListNode*& head, ListNode*& list) {
		head->next = list;
		head = head->next;
		list = list->next;
	}
};

int main() {	// для провреки

}