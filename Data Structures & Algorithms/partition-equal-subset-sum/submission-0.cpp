class Solution {
public:
    vector<vector<int>> dp; 
    bool solve(vector<int>& nums,int target,int i,int n){
        if(i==n){
            return false;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=false;
        if(nums[i]<=target){
            take=solve(nums,target-nums[i],i+1,n);
        }
        bool not_take=solve(nums,target,i+1,n);
        return dp[i][target]=take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;
        dp.resize(n,vector<int>(target+1,-1));
        return solve(nums,target,0,n);
    }
};
