class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            int take=nums[i]+(i+2>=n?0:dp[i+2]);
            int not_take=i+1>=n?0:dp[i+1];
            dp[i]=max(take,not_take);
        }
        return dp[0];
    }
};
