#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        const int str_len = s.length();
        int left{ 0 };

        for (int right{ 0 }; right < str_len; right += 1) {
            if (s[right] == ' ') {
                swapSubstr(s, left, right);
                left = right + 1;
            }
        }
        swapSubstr(s, left, str_len);

        return s;
    }
private:
    void swapSubstr(string& str, const int& left, const int& right) {
        char buffer;

        for (int i{ 0 }, len = (right - left) / 2; i < len; i += 1) {
            buffer = str[left + i];
            str[left + i] = str[right - i - 1];
            str[right - i - 1] = buffer;
        }
    }
};

int main() {	// для прверки
    Solution solution;

    string s1 = "Let's take LeetCode contest";
    std::cout << solution.reverseWords(s1);
}