#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left_p{ 0 }, right_p = nums.size() - 1, center_p;

        while (left_p < right_p) {
            center_p = (right_p - left_p + 1) / 2 + left_p;

            if (center_p == left_p) {   // cant move to left
                if (nums[center_p] < nums[center_p + 1]) {  // to left
                    right_p = center_p;
                }
                else {  // to right
                    right_p = left_p = center_p + 1;
                }
            }
            else if (center_p == right_p) { // cant move to right
                if (nums[center_p] < nums[center_p - 1]) {  // to right
                    left_p = center_p;
                }
                else {  // to left
                    right_p = left_p = center_p - 1;
                }
                left_p = center_p + 1;
            }
            else {  
                if (nums[center_p] < nums[center_p - 1] && nums[center_p] < nums[center_p + 1]) {
                    left_p = right_p = center_p;
                    break;
                }

                if (nums[center_p - 1] < nums[center_p + 1]) {  // to left
                    right_p = center_p - 1;
                }
                else {  // to right
                    left_p = center_p + 1;
                }
            }
        }

        return nums[left_p];
    }
};

int main() {    // for tests
    Solution solution;

    vector<int> arr = { 3,4,5,1,2 };

    cout << solution.findMin(arr);
}