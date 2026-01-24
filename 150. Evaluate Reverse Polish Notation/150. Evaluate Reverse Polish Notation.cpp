#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> memory;
        int num1, num2;

        for (const string& token : tokens) {    // O(n)
            if (fast_isdigit(token.back())) {
                memory.push(fast_stoi(token));
            }
            else {  // it's gonna be some operator
                num2 = memory.top();   // O(1)
                memory.pop();  // O(1)
                num1 = memory.top();   // O(1)
                memory.pop();  // O(1)

                switch (token[0])   // O(2)
                {
                case '+':
                    memory.push(num1 + num2);  // O(1)
                    break;
                case '-':
                    memory.push(num1 - num2);  // O(1)
                    break;
                case '*':
                    memory.push(num1 * num2);  // O(1)
                    break;
                case '/':
                    memory.push(num1 / num2);  // O(1)
                    break;
                }
            }
        }

        return memory.top();
    }
private:
    inline int fast_stoi(const string& str) {
        int num{ 0 }, multiply{ 1 };
        auto it = str.end() - 1;

        while (it >= str.begin()) {
            if (*it == '-') {
                num = -num;
            }
            else {
                num += (*it - '0') * multiply;
                multiply *= 10;
            }
            --it;
        }

        return num;
    }
    inline bool fast_isdigit(const char& symbol) {
        return (symbol - '0' < 10 && symbol - '0' >= 0) ? true : false;
    }
};

int main() {    // for tests
    Solution solution;

    vector<string> arr = { "4","13","5","/","+" };   // equals ""

    cout << solution.evalRPN(arr);
}