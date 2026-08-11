class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int N=word1.size(),M=word2.size();
        string StoringList;
        int i=0,j=0;

        while(i<n || j<m){
            if(i<n) StoringList+=word1[i++];
            if(i<m) StoringList+=word2[i++];
        }
        return StoringList;
    }
};