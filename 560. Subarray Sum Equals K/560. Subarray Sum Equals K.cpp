#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int arr_size = nums.size();
        int count{ 0 };
        vector<int> dp_nums(arr_size);
        dp_nums[0] = nums[0];
        for (int i{ 1 }; i < arr_size; ++i) {
            dp_nums[i] = nums[i] + dp_nums[i - 1];
        }

        unordered_map<int, int> mp;
        for (int i{ 0 }; i < arr_size; ++i) {
            if (dp_nums[i] == k) {
                ++count;
            }
            if (mp.find(dp_nums[i] - k) != mp.end()) {
                count += mp[dp_nums[i] - k];
            }

            mp[dp_nums[i]] += 1;
        }

        return count;
    }
};

// для проверок
int main() {
    Solution solution;

    vector<int> arr1 = { 1,1,1 };   // k = 2
    std::cout << solution.subarraySum(arr1, 2) << std::endl;
}