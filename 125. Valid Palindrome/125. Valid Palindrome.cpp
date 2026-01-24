#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left_p{ 0 }, right_p = s.length() - 1;
        seek_pointers(s, left_p, right_p);

        while (left_p < right_p) {
            if (std::tolower(s[left_p]) != std::tolower(s[right_p])) {
                return false;
            }
            ++left_p;
            --right_p;
            seek_pointers(s, left_p, right_p);
        }

        return true;
    }
private:
    void seek_pointers(const string& str, int& left_p, int& right_p) {
        while (std::isalnum(str[left_p]) == false && left_p < str.length() - 1) {
            ++left_p;
        }
        while (std::isalnum(str[right_p]) == false && right_p > 0) {
            --right_p;
        }
    }
};

int main() {    // для проверок
    Solution solution;

    string text = " ";

    cout << std::boolalpha << solution.isPalindrome(text);
}