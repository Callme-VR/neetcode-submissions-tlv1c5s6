class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        long long l=0;
        long long r=people.size()-1;
        long long boatcarray=0;

        while(l<=r){
            long long sum=people[l]+people[r];
            if(sum<=limit){
                l++;
            }
            r--;
            boatcarray++;
        }
        return boatcarray;

    }
};