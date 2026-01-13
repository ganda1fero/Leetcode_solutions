#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_q;
        for (char& symbol : s) {
            switch (symbol)
            {
            case '(':   // открывающий
                stack_q.push(')');
                break;
            case '[':   // открывающий
                stack_q.push(']');
                break;
            case '{':   // открывающий
                stack_q.push('}');
                break;
            default:
                if (stack_q.size() == 0) {
                    return false;
                }
                if (stack_q.top() != symbol) {
                    return false;
                }
                stack_q.pop();
                break;
            }
        }
        
        if (stack_q.size() > 0) {   // значит осталась еще незакрытая скобка
            return false;
        }

        return true;
    }
};

int main() {	// для проверки
    std::setlocale(LC_ALL, "");

    Solution solution;

    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "([])";
    string s4 = "([)]";

    std::cout << "1-я строка: " << solution.isValid(s1) << std::endl;
    std::cout << "2-я строка: " << solution.isValid(s2) << std::endl;
    std::cout << "3-я строка: " << solution.isValid(s3) << std::endl;
    std::cout << "4-я строка: " << solution.isValid(s4) << std::endl;
}