#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Ќа ввод даетс€ массив из чисел (int)
    1) длина от 3-х до 3000
    2) числа от -100тыс до 100тыс
Ќужно найти уникальные тройки (пор€док не имеет значени€)
    “акже индексы не должны пересекатьс€ (внутри одной тройки)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        const int arr_len_minus_2 = nums.size() - 2;
        sort(nums.begin(), nums.end()); // отсортировали массив

        int left, right, sum, gg, i{ 0 };
        while (i < arr_len_minus_2) {
            left = i + 1;
            right = arr_len_minus_2 + 1;
            while (left < right) {  // сближаем пока не пересукетс€
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) { // добав€лем в ответ
                    answer.push_back({ nums[i], nums[left], nums[right] });
                    gg = 0;
                    do {
                        ++gg;
                    } while (left + gg < arr_len_minus_2 + 2 && nums[left + gg] == nums[left]);
                    left += gg;
                }
                else if (sum < 0) { // получилось отрицательное - смещаем левый край
                    ++left;
                }
                else {  // получилось положительное - смещаем правый край
                    --right;
                }
            }

            gg = 0;
            do {
                ++gg;
            } while (i + gg < arr_len_minus_2 && nums[i + gg] == nums[i]);
            i += gg;
        }

        return answer;
    }
};

int main() {	// дл€ провреки решени€
    Solution solution;

    vector<int> arr1 = { -1,0,1,2,-1,-4 };

    vector<vector<int>> answer1 = solution.threeSum(arr1);

    for (vector<int>& some : answer1) {
        for (int& num : some) {
            std::cout << num << ' ';
        }
        std::cout << endl;
    }
}