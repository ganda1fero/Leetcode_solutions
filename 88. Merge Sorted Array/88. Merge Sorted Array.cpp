#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {   // просто переносим num2 => num1
            nums1 = nums2;
            return;
        }
        else if (n == 0) {  // значит ничего не делаем
            return;
        }

        for (int i{ m + n - 1 }; i >= n; --i) { // смещаем все вправо
            nums1[i] = nums1[i - n];
        }

        int f_index{ n }, s_index{ 0 }, main_index{ 0 };
        while (s_index < n) {
            if (f_index < n + m && nums1[f_index] < nums2[s_index]) {
                nums1[main_index++] = nums1[f_index++];
            }
            else {
                nums1[main_index++] = nums2[s_index++];
            }
        }
    }
};

int main() {	// для проверок
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 }, nums2 = { 2, 5, 6 };
    int m = 3, n = 3;

    solution.merge(nums1, m, nums2, n);

    cout << '[';
    for (const int& num : nums1) {
        cout << num << ',';
    }
    cout << "\b]";
}