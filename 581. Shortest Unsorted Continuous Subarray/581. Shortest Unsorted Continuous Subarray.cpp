#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int end_index = nums.size() - 1;
        int start{ 0 }, end{ -1 };
        int max{ nums[0] }, min{ nums[end_index] };

        for (int i{ 1 }; i <= end_index; ++i) {
            if (max > nums[i]) {
                end = i;
            }
            else {
                max = nums[i];
            }
        }

        for (int i{ end_index - 1 }; i >= 0; --i) {
            if (min < nums[i]) {
                start = i;
            }
            else {
                min = nums[i];
            }
        }

        return end - start + 1;
    }
};

int main() {	// для проверки
    Solution solution;

    vector<int> arr1 = { 2,6,4,8,10,9,15 };
    vector<int> arr2 = { 1,2,3,4 };
    vector<int> arr3 = { 1,2,4,5,3 };

    std::cout << solution.findUnsortedSubarray(arr1) << '\n' << solution.findUnsortedSubarray(arr2) << '\n' << solution.findUnsortedSubarray(arr3) << std::endl;
}