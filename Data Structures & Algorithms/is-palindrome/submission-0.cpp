
class Solution{
    public:
    bool isPalindrome(string S){
        string temperary = "";
        for (char c:S){
            if(isalnum(c)){
                temperary += tolower(c);
            }
        }
        return equal(temperary.begin(), temperary.end(), temperary.rbegin());

    }
};