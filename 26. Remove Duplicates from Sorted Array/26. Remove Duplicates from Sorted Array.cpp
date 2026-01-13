#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int arr_size = nums.size();
        int k{ 1 };  // уникальные числа

        for (int i{ 1 }; i < arr_size; i += 1) {    // перебор по nums
            if (nums[i] != nums[k - 1]) {   // значит уникальный
                nums[k] = nums[i];
                k += 1; // увеличиваем счетчик уникальных
            }
        }

        return k;
    }
};

int main() {	// для проверки 
	std::setlocale(LC_ALL, "");
    Solution solution;

    vector<int> vect1 = { 1,1,2 };
    std::cout << solution.removeDuplicates(vect1) << '\n';
    
    for (int& now : vect1) {    // вывод получившегося
        std::cout << now << ' ';
    }
}