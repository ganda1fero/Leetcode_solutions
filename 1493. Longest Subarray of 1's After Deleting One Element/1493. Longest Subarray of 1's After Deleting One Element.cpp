#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int nums_len = nums.size();
        int left_p{ 0 }, right_p{ 0 }, max_len{ 0 }, now_len{ 0 };
        bool zero{ false };
        while (right_p != nums_len) {
            switch (nums[right_p])
            {
            case 1: // просто ++ в счетчик
                ++now_len;
                maxLen(max_len, now_len);
                break;
            case 0:
                if (zero) { // 0 уже был (очищаем до него)
                    while (nums[left_p] != 0) {
                        --now_len;
                        ++left_p;
                    }
                    ++left_p;
                }
                else {  // 0 еще не было, просто считаем
                    ++now_len;
                    maxLen(max_len, now_len);
                    zero = true;
                }
                break;
            }

            ++right_p;
        }

        return max_len - 1;
    }
private:
    void maxLen(int& max, int& now) {
        if (max < now) {
            max = now;
        }
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = { 0 };
    std::cout << solution.longestSubarray(arr1) << std::endl;
}