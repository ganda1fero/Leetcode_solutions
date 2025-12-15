#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        answer.resize(2);   // создали память

        unordered_map<int, int> memory;   // ключ - значение | знач - id в массиве
        memory.emplace(nums[0], 0); // сохранили первый эл.

        int tmp;    // переменная для подсчетов

        for (int i{ 1 }; i < nums.size(); i++) {
            tmp = target - nums[i];

            if (memory.count(tmp) == 0) {
                memory.emplace(nums[i], i);
            }
            else {  // значит нашли
                answer[0] = memory[tmp];    // обратно вернули индекс по значению
                answer[1] = i;

                i = nums.size();    // для выхода
            }
        }

        return answer;
    }
};



// -------------------
int main() {
    // начальные данные
    vector<int> vect({ 3, 2, 2, 6 });
    int target{ 8 };

    // решение
    Solution solution;

    vector<int> answer = solution.twoSum(vect, target);

    // вывод ответа
    std::cout << '[' << answer[0] << ',' << answer[1] << ']' << std::endl;
}