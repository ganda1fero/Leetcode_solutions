#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        list<node> list_path;
        
        int start_index{ 1 };
        for (int i{ 1 }, str_len = path.length(); i < str_len; ++i) {
            if (path[i] == '/') {  // встретили '\'
                if (int tmp_len = i - start_index) { // значит есть содержимое
                    if (path[start_index] == '.') {
                        switch (tmp_len) {
                        case 1: // ничего
                            break;
                        case 2: // '..'
                            if (path[start_index + 1] == '.') {
                                if (!list_path.empty()) {
                                    list_path.pop_back();
                                }
                            }
                            else {
                                list_path.push_back(node(start_index, tmp_len));
                            }
                            break;
                        default:    // '......'
                            list_path.push_back(node(start_index, tmp_len));
                            break;
                        }
                    }
                    else {
                        list_path.push_back(node(start_index, tmp_len));
                    }
                }

                start_index = i + 1;    // сдвигаем на след
            }
        }
        if (int tmp_len = path.length() - start_index) { // значит есть содержимое
            if (path[start_index] == '.') {
                switch (tmp_len) {
                case 1: // ничего
                    break;
                case 2: // '..'
                    if (path[start_index + 1] == '.') {
                        if (!list_path.empty()) {
                            list_path.pop_back();
                        }
                    }
                    else {
                        list_path.push_back(node(start_index, tmp_len));
                    }
                    break;
                default:    // '......'
                    list_path.push_back(node(start_index, tmp_len));
                    break;
                }
            }
            else {
                list_path.push_back(node(start_index, tmp_len));
            }
        }

        string simplified_path;
        while (!list_path.empty()) {
            simplified_path += '/' + path.substr(list_path.front().start_index, list_path.front().len);
            list_path.pop_front();
        }

        return (simplified_path.empty() ? "/" : simplified_path);
    }
private:
    class node
    {
    public:
        node(int start_index, int len) : len(len), start_index(start_index) {}
        int start_index;
        int len;
    };
};

int main() {	// для проверок
    Solution solution;

    cout << solution.simplifyPath("/home/");

	return 0;
}