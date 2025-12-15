#include <iostream>

// по условию
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// само решение

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list_1, ListNode* list_2) {
        // переменные
        ListNode* tmp_ptr_1{ list_1 }, * tmp_ptr_2{ list_2 }, *answer_ptr, *answer_tmp_ptr;
        int now_numb{ 0 };
        bool remainder{ false };    // так как 9 + 9 = 18 => всегда может остаться только 1 на перенос
        
        // делаем (нулевую операцию)
        now_numb += tmp_ptr_1->val + tmp_ptr_2->val;    // посчитали сумму
        tmp_ptr_1 = tmp_ptr_1->next;
        tmp_ptr_2 = tmp_ptr_2->next;
        
        answer_ptr = new ListNode(now_numb % 10);   // записываем остаток (гарантирует < 10)
        answer_tmp_ptr = answer_ptr;
        remainder = now_numb / 10;  // будет 1, если есть целая часть

        // просчитываем все возможные остальные
        while (tmp_ptr_1 != nullptr || tmp_ptr_2 != nullptr || remainder == true) {
            now_numb = remainder;   // "обнуляем"

            if (tmp_ptr_1 != nullptr) { // приплюсовали + сместили (если можно)
                now_numb += tmp_ptr_1->val;
                tmp_ptr_1 = tmp_ptr_1->next;
            }

            if (tmp_ptr_2 != nullptr) { // приплюсовали + сместили (если можно)
                now_numb += tmp_ptr_2->val;
                tmp_ptr_2 = tmp_ptr_2->next;
            }

            // записываем
            answer_tmp_ptr->next = new ListNode(now_numb % 10); // записываем остаток (гарантирует < 10)
            answer_tmp_ptr = answer_tmp_ptr->next;
            remainder = now_numb / 10;  // будет 1 если есть целая часть
        }

        return answer_ptr;
    }
};



// чисто для отладки
int main() {
    ListNode* list_1_3 = new ListNode(3);
    ListNode* list_1_2 = new ListNode(4, list_1_3);
    ListNode* list_1_1 = new ListNode(2, list_1_2);

    ListNode* list_2_3 = new ListNode(4);
    ListNode* list_2_2 = new ListNode(6, list_2_3);
    ListNode* list_2_1 = new ListNode(5, list_2_2);

    Solution solution;

    // проверка решения
    ListNode* answer = solution.addTwoNumbers(list_1_1, list_2_1), *answer_tmp = answer;
    
    std::cout << '[';
    while (answer_tmp != nullptr) {
        std::cout << answer_tmp->val;
        if (answer_tmp->next != nullptr) {
            std::cout << ',';
        }

        answer_tmp = answer_tmp->next;
    }
    std::cout << ']';

    // очистка
    ListNode* tmp_ptr;
    while (list_1_1 != nullptr) {
        tmp_ptr = list_1_1;
        list_1_1 = list_1_1->next;

        delete tmp_ptr;
    }

    while (list_2_1 != nullptr) {
        tmp_ptr = list_2_1;
        list_2_1 = list_2_1->next;

        delete tmp_ptr;
    }

    while (answer != nullptr) {
        tmp_ptr = answer;
        answer = answer->next;

        delete tmp_ptr;
    }

}