class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i;prev>=0;prev--){
                int take=0;
                if(prev==0||nums[i]>nums[prev-1]){
                    take=1+dp[i+1][i+1];
                }
                int not_take=dp[i+1][prev];
                dp[i][prev]=max(take,not_take);
            }
        }
        return dp[0][0]; 
    }
};
