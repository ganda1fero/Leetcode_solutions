#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }

        const int num1_len = num1.length(), num2_len = num2.length();
        vector<int> buffer(num1_len + num2_len, 0); // init arr (i + y) elems with 0 (zeros)

        for (int i{ num1_len - 1 };  i >= 0; i -= 1) {
            for (int g{ num2_len - 1 }; g >= 0; g -= 1) {
                buffer[(num1_len - i - 1) + (num2_len - g - 1)] += (num1[i] - '0') * (num2[g] - '0');
            }
        }

        // собираем строку
        string answer;
        int tmp_arr_len = buffer.size();
        buffer.push_back(0);
        for (int i{ 0 }; i < tmp_arr_len; i += 1) {
            answer.push_back(buffer[i] % 10 + '0');
            buffer[i] /= 10;
            buffer[i + 1] += buffer[i]; // переносим на десяток выше
        }
        if (buffer[tmp_arr_len] > 0) {
            answer += to_string(buffer[tmp_arr_len]);
        }
        
        if (answer.back() == '0') {
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {	// для провекрок
	setlocale(LC_ALL, "");

    Solution solution;
    string str1_1{ "123" }, str1_2{ "456" };

    cout << solution.multiply(str1_1, str1_2);
}