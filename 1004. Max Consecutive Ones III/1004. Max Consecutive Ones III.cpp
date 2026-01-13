#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int arr_size = nums.size();
        int left{ 0 }, right{ 0 }, zero_count{ 0 }, max_len{ 0 }, tmp_len{ 0 };

        while (right < arr_size) {
            zero_count += reverse(nums[right]); // плюсуем '0' в счетчик если есть

            while (zero_count > k) {    // если слишком много '0'
                zero_count -= reverse(nums[left]);
                left += 1;  // сдвигаем
            }

            tmp_len = right - left + 1;
            if (max_len < tmp_len) {
                max_len = tmp_len;
            }

            right += 1;
        }

        return max_len;
    }
private:
    int reverse(int& numb) {
        return 1 - numb;
    }
};

int main() {	// для проверки
}