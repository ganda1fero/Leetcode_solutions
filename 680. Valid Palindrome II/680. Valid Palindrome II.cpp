#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left_p{ 0 }, right_p = s.length() - 1;
        while (left_p < right_p) {
            if (s[left_p] != s[right_p]) {  // not palindrome => try to del smth
                if (isPalindrome(s, left_p + 1, right_p)) { // trying to del left size
                    return true;
                }
                if (isPalindrome(s, left_p, right_p - 1)) { // trying to del right size
                    return true;
                }
                return false;
            }

            ++left_p;
            --right_p;
        }

        return true;
    }
private:
    bool isPalindrome(const string& s, int left_p, int right_p) {
        while (left_p < right_p) {
            if (s[left_p] != s[right_p]) {  // not palindrome
                return false;
            }
            ++left_p;
            --right_p;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string str = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";

    for (int i{ 0 }; i < str.length() / 2; ++i) {
        cout << '[' << i << "] = " << str[i] << " |and| [" << str.length() - 1 - i << "] = " << str[str.length() - 1 - i] << '\n';
    }
    cout << std::endl;

    //cout << "aba   | " << std::boolalpha << solution.validPalindrome("aba") << '\n';
    //cout << "abca  | " << std::boolalpha << solution.validPalindrome("abca") << '\n';
    //cout << "abc   | " << std::boolalpha << solution.validPalindrome("abc") << '\n';
    //cout << "abcca | " << std::boolalpha << solution.validPalindrome("abcca") << '\n';
    //cout << "eccer | " << std::boolalpha << solution.validPalindrome("eccer") << '\n';
    cout << "... | " << std::boolalpha << solution.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << '\n';    
}