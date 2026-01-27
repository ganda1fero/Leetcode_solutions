#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int len = s.length();
        vector<char> ANSI_arr(256, 0); // 0 - (ANSI table) null
        vector<bool> usedANSI(256, false);
        
        for (int i{ 0 }; i < len; ++i) {
            if (ANSI_arr[s[i]] == 0) {
                if (usedANSI[t[i]] == true) {
                    return false;
                }
                ANSI_arr[s[i]] = t[i];
                usedANSI[t[i]] = true;
            }
            if (ANSI_arr[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {    // for tests
    Solution solution;
    char tmp{ 0 };

    string test_1_1 = "egg", test_1_2 = "add";
    string test_2_1 = "foo", test_2_2 = "bar";
    string test_3_1 = "paper", test_3_2 = "title";
    string test_4_1 = "aaad", test_4_2 = "aaaa";

    cout << test_1_1 << " and " << test_1_2 << " | " << std::boolalpha << solution.isIsomorphic(test_1_1, test_1_2) << '\n';
    cout << test_2_1 << " and " << test_2_2 << " | " << std::boolalpha << solution.isIsomorphic(test_2_1, test_2_2) << '\n';
    cout << test_3_1 << " and " << test_3_2 << " | " << std::boolalpha << solution.isIsomorphic(test_3_1, test_3_2) << '\n';
    cout << test_4_1 << " and " << test_4_2 << " | " << std::boolalpha << solution.isIsomorphic(test_4_1, test_4_2) << '\n';

    return 0;
}