class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack; // Fixed: consistent naming (was stringstack)
        string currentString = ""; // Fixed: consistent naming (was currentstring)
        long long k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } 
            else if (c == '[') { // Fixed: added 'if' (was else(c=='['))
                countStack.push(k);
                stringStack.push(currentString); // Fixed: variable name (was stringBack)
                currentString = ""; // Fixed: variable name (was countstring)
                k = 0;
            } 
            else if (c == ']') {
                string lastString = stringStack.top(); // Fixed: naming
                stringStack.pop();
                int repeatTimes = countStack.top(); // Fixed: naming (stack is case-sensitive)
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