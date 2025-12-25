#include <iostream>
#include <vector>

using namespace std;

void CheackMaxPalindrom(int& now_start_index, int& now_len, const int new_start_index, const int new_len) {
    if (now_len < new_len) {
        now_start_index = new_start_index;
        now_len = new_len;
    }
}

class Solution {
public:
    string longestPalindrome(string s) {
        const int str_len = s.length();

        int palindr_start_index{ 0 }, palindr_len{ 1 };

        int tmp_owset;
        for (int i{ 0 }; i < str_len - 1; i++) {    // перебор индекса центраы
            // центр = эл.
            tmp_owset = 1;

            while (i - tmp_owset >= 0 && i + tmp_owset < str_len && s[i - tmp_owset] == s[i + tmp_owset]) {
                tmp_owset++;
            }   // будет идти до тех пор, пока не выйдем за пределы или не будет равно (закончится палиндром)
            tmp_owset--;

            CheackMaxPalindrom(palindr_start_index, palindr_len, i - tmp_owset, tmp_owset * 2 + 1);

            // центр = между элементами
            tmp_owset = 0;

            while (i - tmp_owset >= 0 && i + 1 + tmp_owset < str_len && s[i - tmp_owset] == s[i + 1 + tmp_owset]) {
                tmp_owset++;
            }
            tmp_owset--;

            if (tmp_owset >= 0) {
                CheackMaxPalindrom(palindr_start_index, palindr_len, i - tmp_owset, tmp_owset * 2 + 2);
            }
        }

        return s.substr(palindr_start_index, palindr_len);
    }
};

int main() {// для провреки 
    Solution solution;

    std::string s1{ "babad" };
    std::string s2{ "cbbd" };
    std::string s3{ "abacdgdcy" };

    //std::cout << solution.longestPalindrome(s1) << std::endl;
    //std::cout << solution.longestPalindrome(s2) << std::endl;
    std::cout << solution.longestPalindrome(s3);
}