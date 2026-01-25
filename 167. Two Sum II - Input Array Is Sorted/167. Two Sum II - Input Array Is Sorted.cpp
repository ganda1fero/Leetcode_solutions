#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left_p{ 0 }, right_p = numbers.size() - 1, tmp;

        while (left_p < right_p) {
            if ((tmp = numbers[left_p] + numbers[right_p]) == target) {
                return { left_p + 1, right_p + 1 };
            }
            else if (tmp < target) {    //
                ++left_p;
            }
            else {  // '>'
                --right_p;
            }
        }

        return { 0, 0 };    // if sum == targent not exists (cant be by the description)
    }
};

int main() {    // for tests
    Solution solution;  

    vector<int> arr = { 3,24,50,79,88,150,345 };
    int target = 200;

    for (const int& num : solution.twoSum(arr, target)) {
        cout << num << ' ';
    }

    return 0;
}