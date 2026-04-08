class Solution {
public:
    bool isValid(string s) {
        // Use std::stack for LIFO behavior
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        }; // Added missing semicolon

        for (char c : s) {
            // If the character is a closing bracket
            if (closeToOpen.count(c)) {
                // Check if stack isn't empty and the top matches the opening bracket
                if (!st.empty() && st.top() == closeToOpen[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                // If it's an opening bracket, push to stack
                st.push(c);
            }
        }
        
        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};