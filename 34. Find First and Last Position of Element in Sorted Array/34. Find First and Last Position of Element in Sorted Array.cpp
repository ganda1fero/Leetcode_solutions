#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);

        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && (*it) == target) {
            answer[0] = it - nums.begin();

            it = upper_bound(nums.begin(), nums.end(), target);
            answer[1] = it - nums.begin() - 1;
        }

        return answer;
    }
};

int main() {	// для проверки
    setlocale(LC_ALL, "");
    Solution solution;
    vector<int> arr1 = { };

    for (int& i : solution.searchRange(arr1, 8)) {
        std::cout << i << ' ';
    }
}