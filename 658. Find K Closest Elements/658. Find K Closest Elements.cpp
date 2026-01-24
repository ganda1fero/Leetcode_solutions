#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left_p, right_p;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it != arr.end()) {
            if (*it != x && it != arr.begin()) {
                if (!(abs(*(it - 1) - x) > abs(*it - x))) {
                    --it;
                }
            }
        }
        else {
            --it;
        }
        // now iterator points on closest (to x) elem
        left_p = right_p = it - arr.begin();

        while (right_p - left_p + 1 < k) {
            if (right_p == arr.size() - 1) {    // cant move to right
                --left_p;
                continue;
            }
            else if (left_p == 0) {    // cant move to left
                ++right_p;
                continue;
            }
            
            if (abs(arr[right_p + 1] - x) < abs(arr[left_p - 1] - x)) {
                ++right_p;
            }
            else {
                --left_p;
            }
        }

        return vector<int>(left_p + arr.begin(), right_p + arr.begin() + 1);
    }
};

int main() {    // for tests
    Solution solution;

    vector<int> arr = { 1,1,2,3,4,5 };

    cout << '[';
    for (const int& num : solution.findClosestElements(arr, 4, -1)) {
        cout << num << ',';
    }
    cout << "\b]\n";

    return 0;
}