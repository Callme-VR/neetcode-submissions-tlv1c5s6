class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        
        for(const string& op : operations) {
            if(op == "+") {
                int last = scores.back();
                int secondlast = scores[scores.size() - 2];
                // Fix 1: Add them together before pushing!
                scores.push_back(last + secondlast);
            }
            // Fix 2: Use "else if" here
            else if(op == "D") {
                scores.push_back(scores.back() * 2);
            }
            else if(op == "C") {
                scores.pop_back();
            }
            else {
                scores.push_back(stoi(op));
            }
        }
        
        // Fix 3: Add up all the numbers in the notebook for the final score
        int totalSum = 0;
        for(int s : scores) {
            totalSum += s;
        }
        return totalSum;
    }
};