class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int N=word1.size(),M=word2.size();
        string StoringList;
        int i=0,j=0;

        while(i < N || j < M){
            if(i<N) StoringList+=word1[i++];
            if(j<M) StoringList+=word2[j++];
        }
        return StoringList;

    }
};