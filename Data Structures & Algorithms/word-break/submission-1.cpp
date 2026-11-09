class Solution {
public:
    vector<int> dp;
    bool solve(string& s,set<string>& st,int i,int n){
        if(i>=n){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp="";
        for(int j=i;j<n;j++){
            temp+=(s[j]);
            if(st.find(temp)!=st.end()){
                if(solve(s,st,j+1,n)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        int n=s.length();
        dp.resize(n,-1);
        return solve(s,st,0,n);
    }
};
