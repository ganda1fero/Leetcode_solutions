#include <iostream>
#include <vector>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int arr_size_minus_2 = nums.size() - 2;
        sort(nums.begin(), nums.end());

        int abs_target = abs(target);
        int closest = INT_MAX;
        int answer;

        int i{ 0 }, left, right, sum, tmp;
        for (int i{ 0 }; i < arr_size_minus_2; ++i) {
            left = i + 1;
            right = arr_size_minus_2 + 1;

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                tmp = abs(target - sum);
                if (tmp < closest) {
                    closest = tmp;
                    answer = sum;
                }
                if (sum < target) { // сдвигаем левый указатель
                    ++left;
                }
                else {    // сдвигаем правый указатель
                    --right;
                }
            }
        }

        return answer;
    }
};

int main() {

}