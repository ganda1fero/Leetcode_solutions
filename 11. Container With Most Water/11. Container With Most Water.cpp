#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_volume{ 0 }, tmp_volume{ 0 };
        int index_f{ 0 }, index_l = height.size() - 1;

        while (index_l > index_f) {
            tmp_volume = min(height[index_f], height[index_l]) * (index_l - index_f);
            if (tmp_volume > max_volume) {
                max_volume = tmp_volume;
            }

            if (height[index_f] < height[index_l]) {
                index_f++;
            }
            else {
                index_l--;
            }
        }

        return max_volume;
    }
};

int main() { // для провреки
    Solution solution;

    vector<int> height = { 1,8,6,2,5,4,8,3,7 };

    std::cout << solution.maxArea(height) << std::endl;
}