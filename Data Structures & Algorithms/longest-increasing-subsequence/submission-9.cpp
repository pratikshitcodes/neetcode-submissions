class Solution {
public:
    int solve(vector<int>& temp,int target){
        int n=temp.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            if(temp[mid]<target){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(temp.empty()||temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int idx=solve(temp,nums[i]);
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};
