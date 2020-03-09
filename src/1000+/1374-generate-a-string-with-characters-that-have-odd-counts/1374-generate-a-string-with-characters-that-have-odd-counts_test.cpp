#include <iostream>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string result = "a";
        char nextChar = 'a';
        if (n % 2 == 0) {
            nextChar = 'b';
        }
        for (int i = 1; i < n; i++) {
            result += nextChar;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.generateTheString(10) << endl;
    return 0;
}