#include <iostream>
#include <vector>
using namespace std;

/*
    [0,1,2,4,5,6,7] -(относ. index = 3)-> [4,5,6,7,0,1,2]
    1) => nums[0] - показывает число с которог идет счисление => все меньше находится в другой части
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{ 0 }, right = nums.size() - 1, center;
        
        while (left <= right) {
            center = (right - left + 1) / 2 + left;

            if (nums[center] == target) {
                return center;
            }

            if (nums[center] < nums[0]) {
                if (target < nums[0]) {
                    if (target < nums[center]) {
                        toLeft(right, center);
                    }
                    else {
                        toRight(left, center);
                    }
                }
                else {
                    toLeft(right, center);
                }
            }
            else {
                if (target < nums[0]) {
                    toRight(left, center);
                }
                else {
                    if (target < nums[center]) {
                        toLeft(right, center);
                    }
                    else {
                        toRight(left, center);
                    }
                }
            }
        }
        
        return -1;  // не нашли
    }
private:
    void toRight(int& left, const int& center) {
        left = center + 1;
    }
    void toLeft(int& right, const int& center) {
        right = center - 1;
    }
};

int main() {	// для првоверки
    setlocale(LC_ALL, "");
    Solution solution;

    vector<int> arr1 = { 9,1,2,3,4,5,6,7,8 };

    std::cout << solution.search(arr1, 5) << std::endl;

    /*
    for (int& now : arr1) {
        std::cout << solution.search(arr1, now)  << " | " << now << std::endl;
    }
    */
}