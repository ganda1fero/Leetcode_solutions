#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int prev{ 0 };
        for (const int& num : nums) {
            prev = prev ^ num;
        }

        return prev;
    }
};

int main() {    // для проверки
    Solution solution;

    vector<int> arr1 = { 4,1,2,1,2 };
    vector<int> arr2 = { 1 };

    cout << solution.singleNumber(arr1) << std::endl << solution.singleNumber(arr2);
}