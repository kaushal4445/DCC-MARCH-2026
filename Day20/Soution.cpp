class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
         int m=grid.size(),n=grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int> (n-k+1));
        for(int i=0;i<=m-k;i++) {
            for(int j=0;j<=n-k;j++) {
                set<int> values;
                for(int r=i;r<i+k;r++) {
                    for(int c=j;c<j+k;c++) {
                        values.insert(grid[r][c]);
                    }
                } 
                int minDiff=INT_MAX;
                if(values.size()==1) minDiff=0;
                auto prev=values.begin();
                auto curr=next(prev);
                while(curr!=values.end()) {
                    minDiff=min(minDiff,abs(*curr - *prev));
                    prev=curr;
                    curr=next(prev);
                }
                ans[i][j]=minDiff;
            }
        }
        return ans;
    }
};
