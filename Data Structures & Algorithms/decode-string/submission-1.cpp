class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        long long k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } 
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } 
            else if (c == ']') {
                string lastString = stringStack.top();
                stringStack.pop();
                int repeatTimes = countStack.top();
                countStack.pop();

                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentString;
                }
                currentString = lastString + temp;
            } 
            else {
                currentString += c;
            }
        }
        return currentString;
    }
};