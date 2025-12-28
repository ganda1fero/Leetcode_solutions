#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Ввод:
    1) массив чисел (int)
    2) число (int) k
Условие:
    Найти подмассив (срез), где:
        1) срез содержит больше 2-х чисел
        2) (сумма чисел среза) % k == 0
    Если такой подмассив найден - вернуть tue (иначе false)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int arr_len = nums.size();
        int prefix_mod{ 0 };
        unordered_map<int, int> memory; // ключ - остаток от деления | значение - индекс в изнач массиве
        memory[0] = -1;

        for (int i{ 0 }; i < arr_len; ++i) {
            prefix_mod = (prefix_mod + nums[i]) % k;

            if (memory.count(prefix_mod) > 0) { // найдено в хеше
                if (i - memory[prefix_mod] > 1)
                    return true;
            }
            else {
                memory[prefix_mod] = i;
            }
        }

        return false;   // если ничего не было найдено
    }
};

int main() {	// для проверок
    Solution solution;

    vector<int> nums1 = { 23,2,6,4,7 }; // k = 13
    vector<int> nums2 = { 23, 2, 6, 4, 7 }; // k = 6

    std::cout << "nums1 | 13 = " << solution.checkSubarraySum(nums1, 13) << std::endl;
    std::cout << "nums2 | 6 = " << solution.checkSubarraySum(nums2, 6) << std::endl;
}