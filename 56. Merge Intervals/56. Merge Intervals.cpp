#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
            });
        const int intervals_count = intervals.size();
        vector<vector<int>> merged_intervals;
        
        int first_val, last_val;
        int left_p{ 0 }, right_p{ 1 };
        while (left_p < intervals_count) {
            first_val = intervals[left_p][0];
            last_val = intervals[left_p][1];

            right_p = left_p + 1;
            while (right_p < intervals_count && intervals[right_p][0] <= last_val) {
                if (last_val < intervals[right_p][1]) {
                    last_val = intervals[right_p][1];
                }
                ++right_p;
            }

            merged_intervals.push_back({ first_val, last_val });
            left_p = right_p;
        }

        return merged_intervals;
    }
};

int main() {	// для проверок
    Solution solution;

    vector<vector<int>> intervals = { {1, 9}, {2, 4}, {5, 7}, {9, 11}, {11, 13}, {14, 16}, {16, 17} };

    for (const vector<int>& interval : solution.merge(intervals)) {
        std::cout << '[' << interval[0] << ", " << interval[1] << "]\n";
    }
}