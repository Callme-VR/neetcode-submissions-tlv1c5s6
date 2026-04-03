class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long minprofit=LLONG_MAX;
        long long maxprofit=0;

        for(int price:prices){
            if(price<minprofit){
                minprofit=price;
            }
            else{
                long long profit=price-minprofit;
                maxprofit=max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};
