#include <iostream>
#include <vector>

using namespace std;

/*
Основные значения:
    I - 1
    V - 5
    X - 10
    L - 50
    C - 100
    D - 500
    M - 1000
Также есть до значения, например:
1) Вычитающие из меньшего десятка
    IV, IX, XL, XC, CD, CM
*/

class Solution {    // само решение
public:
    string GetRomeDigit(const int digit, const int& tens) {
        switch (digit)
        {
        case 1:
            switch (tens)
            {
            case 0:
                return "I";
                break;
            case 1:
                return "X";
                break;
            case 2:
                return "C";
                break;
            case 3:
                return "M";
                break;
            }
            break;
        case 5:
            switch (tens)
            {
            case 0:
                return "V";
                break;
            case 1:
                return "L";
                break;
            case 2:
                return "D";
                break;
            }
            break;
        }

        return "!"; // заглушка (чтобы компилятор не выебывался)
    }

    string intToRoman(int num) {
        string answer;
        vector<int> digits;
        digits.reserve(4);

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        for (int i = digits.size() - 1; i >= 0; i--) {  // проходим по цифрам
            switch (digits[i])
            {
            case 4: // уменьшаемое (через 5)
                answer += GetRomeDigit(1, i) + GetRomeDigit(5, i);
                break;
            case 9: // уменьшаемое (через 10)
                answer += GetRomeDigit(1, i) + GetRomeDigit(1, i + 1);
                break;
            default:    // увеличиваемая
                if (digits[i] / 5 == 1) {
                    digits[i] %= 5;
                    answer += GetRomeDigit(5, i);
                }
                while (digits[i] > 0) {
                    answer += GetRomeDigit(1, i);
                    digits[i]--;
                }
               
                break;
            }
        }

        return answer;
    }
};

int main() {	// для проверок
    Solution solution;

    int num1 = 15;
    int num2 = 4;
    int num3 = 41;
    int num4 = 191;
    int num5 = 94;

    std::cout << num1 << " = " << solution.intToRoman(num1) << std::endl;
    std::cout << num2 << " = " << solution.intToRoman(num2) << std::endl;
    std::cout << num3 << " = " << solution.intToRoman(num3) << std::endl;
    std::cout << num4 << " = " << solution.intToRoman(num4) << std::endl;
    std::cout << num5 << " = " << solution.intToRoman(num5) << std::endl;
}