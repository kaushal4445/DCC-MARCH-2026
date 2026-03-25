class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
         int m=grid.size(),n=grid[0].size();
        long long total=0;
        vector<long long> row(m,0);
        vector<long long> col(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                total+=grid[i][j];
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        if(total%2!=0) return false;
        // Horizontal cut
        long long upper=0;
        for(int i=0;i<m-1;i++) {
            upper+=row[i];
            if(upper==total-upper) return true;
        }

        long long left=0;
        for(int j=0;j<n-1;j++) {
            left+=col[j];
            if(left==total-left) return true;
        }
        return false;
    }
};
