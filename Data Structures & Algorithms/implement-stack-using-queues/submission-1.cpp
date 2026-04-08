class MyStack {
public:
    // Standard C++ uses std::queue (lowercase 'q')
    
    std::queue<int> q1;
    std::queue<int> q2;

    MyStack() {}

    /** * Push element x onto stack.
     * Complexity: O(n)
     */

    void push(int x) {
        // 1. Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // 2. Push the new element into q1
        q1.push(x);

        // 3. Move everything back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    /** * Removes the element on top of the stack and returns it.
     * Complexity: O(1)
     */
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    /** * Get the top element.
     * Complexity: O(1)
     */
    int top() { 
        return q1.front(); 
    }

    /** * Returns whether the stack is empty.
     */
    bool empty() { 
        return q1.empty(); 
    }
};