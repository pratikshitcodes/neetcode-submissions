class Solution {
public:
    int n;
    vector<int> dp;
    int solve(string& s,int i){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]!='0'){
            int take_one=solve(s,i+1);
            int take_two=0;
            int offset=stoi(s.substr(i,2))-1;
            if(i+1<n&&offset<26){
                take_two=solve(s,i+2);
            }
            return dp[i]=take_one+take_two;
        }
        return dp[i]=0;
    }
    int numDecodings(string s) {
        n=s.length();
        dp.resize(n,-1);
        return solve(s,0);
    }
};
