class Solution {
public:
    int n;
    vector<int> curr;
    vector<int> next;
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        curr.resize(n+1,0);
        next.resize(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i;prev>=0;prev--){
                int take=0;
                if(prev==0||nums[i]>nums[prev-1]){
                    take=1+next[i+1];
                }
                int not_take=next[prev];
                curr[prev]=max(take,not_take);
            }
            next=curr;
        }
        return next[0]; 
    }
};
