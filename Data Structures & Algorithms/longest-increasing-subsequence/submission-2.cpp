class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int i,int prev){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int take=0;
        if(prev==0||nums[i]>nums[prev-1]){
            take=1+solve(nums,i+1,i+1);
        }
        int not_take=solve(nums,i+1,prev);
        return dp[i][prev]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n,-1));
        return solve(nums,0,0); 
    }
};
