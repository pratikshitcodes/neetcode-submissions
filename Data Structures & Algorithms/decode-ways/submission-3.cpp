class Solution {
public:
    int n;
    vector<int> dp;
    int solve(string& s,int i,string temp,set<string>& st){
        if(i>=n){
            if(st.find(temp)==st.end()){
                st.insert(temp);
                return 1;
            }
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]!='0'){
            temp+=('A'+(s[i]-'0')-1);
            int take_one=solve(s,i+1,temp,st);
            temp.pop_back();
            int take_two=0;
            int offset=stoi(s.substr(i,2))-1;
            if(i+1<n&&offset<26){
                temp+=('A'+offset);
                take_two=solve(s,i+2,temp,st);
                temp.pop_back();
                temp.pop_back();
            }
            return dp[i]=take_one+take_two;
        }
        return dp[i]=0;
    }
    int numDecodings(string s) {
        n=s.length();
        set<string> st;
        dp.resize(n,-1);
        return solve(s,0,"",st);
    }
};
