class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int>merged(len1+len2);

        copy(nums1.begin(),nums1.end(),merged.begin());
        copy(nums2.begin(),nums2.end(),merged.begin()+len1);

        sort(merged.begin(),merged.end());

        int totalLength=merged.size();

        if(totalLength%2==0){
            return (merged[totalLength/2-1]+merged[totalLength/2])/2.0;
        }else{
            return merged[totalLength/2];
        }

    }
};
