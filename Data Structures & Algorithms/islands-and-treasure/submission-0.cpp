class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                    cout<<"hepjlkns"<<endl;
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            auto [dist,info]=pq.top();
            auto [row,col]=info;
            pq.pop();
            if(dist>grid[row][col]){
                continue;
            }
            for(int i=0;i<4;i++){
                int new_r=row+dr[i];
                int new_c=col+dc[i];
                if(new_r<m&&new_r>=0&&new_c<n&&new_c>=0&&grid[new_r][new_c]!=-1
                &&dist+1<grid[new_r][new_c]){
                    grid[new_r][new_c]=dist+1;
                    pq.push({dist+1,{new_r,new_c}});
                }
            }
        }
    }
};
