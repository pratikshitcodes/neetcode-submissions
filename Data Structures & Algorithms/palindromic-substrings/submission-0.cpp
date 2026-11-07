class Solution {
public:
    vector<vector<bool>> palindrome;
    int countSubstrings(string s) {
        int n=s.length();
        palindrome.resize(n,vector<bool>(n,false));
        palindrome[n-1][n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        palindrome[i][j]=true;
                    }
                    else{
                        palindrome[i][j]=palindrome[i+1][j-1];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(palindrome[i][j]){
                    ans++;
                }
            }
        }
        return ans;      
    }
};