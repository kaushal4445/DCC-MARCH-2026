// 1536. Minimum Swaps to Arrange a Binary Grid
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

// A grid is said to be valid if all the cells above the main diagonal are zeros.

// Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

// The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

// Example 1:
// Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
// Output: 3
  
// Example 2:
// Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
// Output: -1
  
// Explanation: All rows are similar, swaps have no effect on the grid.
// Example 3:
// Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
// Output: 0




// solution 
//Approach (Siilar to Bubble Sort - Find best candidate and swap)
//T.C : O(n^2)
//S.C : O(n)


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
         int n = grid.size();           // rows == columns
         vector<int> endZeroes(n, 0);       //endZeros[i] = count of consecutive 0s from the end of ith row
        for(int i =0; i<n; i++){
            int j = n-1;   //start from end
            int count =0;
            while(j >=0 && grid[i][j] == 0){
                count++;
                j--;

            }
            endZeroes[i] = count;
        }
        int steps =0;
        for(int i =0 ; i<n; i++){
            int need = n-i-1;
            int j =i;
            while(j < n && endZeroes[j] < need){
                j++;
            }
            if(j == n){
                return -1;
            }
            steps += j-i;
           
           while(j > i){
            swap(endZeroes[j], endZeroes[j-1]);
            j--;
           }
        }
        return steps;
    }
};
