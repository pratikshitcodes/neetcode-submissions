class Solution {
public:
    int solve(int n,int at_step,vector<int>& cost,vector<int>& dp){
        if(at_step==n){
            return 0;
        }
        if(dp[at_step]!=-1){
            return dp[at_step];
        }
        int one_step=INT_MAX;
        if(at_step+1<=n){
            one_step=cost[at_step]+solve(n,at_step+1,cost,dp);
        }
        int two_step=INT_MAX;
        if(at_step+2<=n){
            two_step=cost[at_step]+solve(n,at_step+2,cost,dp);
        }
        return dp[at_step]=min(one_step,two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return min(solve(n,0,cost,dp2),solve(n,1,cost,dp2));
    }
};
