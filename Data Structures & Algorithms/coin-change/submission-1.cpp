class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& coins,int amount,int i){
        if(i>=n){
            return INT_MAX;
        }
        if(amount==0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=INT_MAX;
        if(coins[i]<=amount){
            take=solve(coins,amount-coins[i],i);
            take=take==INT_MAX?INT_MAX:take+1;
        }
        int skip=solve(coins,amount,i+1);
        return dp[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,0);
        return ans==INT_MAX?-1:ans;
    }
};
