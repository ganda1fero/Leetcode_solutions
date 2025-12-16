#include <iostream>
#include <unordered_map>
using namespace std;

//сам решение
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // переменные
        int max_len{ 0 }, calculate_max_len{ 0 };
        int substr_start_index{ 0 }, now_index{0};    // начинается с 0
        const int string_len = s.length();
        unordered_map<char, int> char_memory;   // словарь: ключ - char | значение - индекс char значения 

        while (now_index < string_len) {
            if (char_memory.count(s[now_index]) == 0) {
                // значит такого символа еще не было
                char_memory.emplace(s[now_index], now_index); // записали значение | индекс значения
            }
            else {
                // такой символ уже был! (возможно)
                if (char_memory[s[now_index]] < substr_start_index) { // этот индекс был "удален" - просто перезаписываем значение
                    char_memory[s[now_index]] = now_index;  // обновили значение индекса этого символа
                }
                else { // значит повторяется в нынешней substr
                    calculate_max_len = now_index - substr_start_index;
                    if (max_len < calculate_max_len) {
                        max_len = calculate_max_len;
                    }

                    // обновляем указатель начала новой substr
                    substr_start_index = char_memory[s[now_index]] + 1;

                    // обновляем значение символа
                    char_memory[s[now_index]] = now_index;
                }
            }

            now_index++;
        }

        // считаем что получилось в конце (не было пересечений)
        calculate_max_len = now_index - substr_start_index;
        if (max_len < calculate_max_len) {
            max_len = calculate_max_len;
        }

        return max_len;
    }
};


// для отладки -------
int main() {
    std::setlocale(LC_ALL, "");

    Solution solution;

    string s1 = "abcabcbb";
    string s2 = "pwwkew";
    string s3 = "";
    string s4 = "f  ";

    cout << s1 << " | " << solution.lengthOfLongestSubstring(s1) << std::endl;
    cout << s2 << " | " << solution.lengthOfLongestSubstring(s2) << std::endl;
    cout << s3 << " | " << solution.lengthOfLongestSubstring(s3) << std::endl;
    cout << s4 << " | " << solution.lengthOfLongestSubstring(s4) << std::endl;
}