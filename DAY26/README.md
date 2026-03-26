🚀 LeetCode 3548: Equal Sum Grid Partition II
🧩 Problem Statement

Given a 2D grid of integers, determine whether it is possible to partition the grid into two parts such that:

The sum of elements in both parts is equal.
The partition can be made using:
A horizontal cut, or
A vertical cut
Additionally, removing at most one element from either side is allowed to balance the sums.
💡 Intuition

We want to split the grid into two parts where:

sum(top/left part) == sum(bottom/right part)

If not exactly equal, we are allowed to remove one element to make them equal.

⚙️ Approach
🔹 Step 1: Compute Total Sum
Calculate the total sum of the grid.
🔹 Step 2: Try Horizontal Cuts
Traverse row by row and maintain:
top → sum of upper part
bottom = total - top
At each cut:
If top == bottom → ✅ valid partition

Else check if removing one element can fix:

diff = top - bottom
If diff equals any element in the considered region → ✅
🔹 Step 3: Reverse Grid
Reverse rows and repeat the same logic
👉 Covers cases where removal is needed from bottom part
🔹 Step 4: Handle Vertical Cuts
Transpose the grid
Apply the same horizontal logic
🔹 Step 5: Reverse Transposed Grid
Again check for reverse case
🧠 Key Observations
Instead of writing separate logic for vertical cuts, we transpose the grid
Use a hash set (unordered_set) to quickly check if a value exists
Only one element removal is allowed
⏱️ Complexity Analysis
Operation	Complexity
Traversing grid	O(m * n)
Checking cuts	O(m * n)
Total	O(m * n)

Space Complexity: O(n) (for set usage)

🧾 C++ Solution
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for(int i = 0; i <= m-2; i++) {

            for(int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = top - bottom;

            if (diff == 0) return true;

            if (diff == (ll)grid[0][0])   return true;
            if (diff == (ll)grid[0][n-1]) return true;
            if (diff == (ll)grid[i][0]) return true;

            if(i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // Horizontal cuts
        if(checkHorCuts(grid)) return true;

        reverse(begin(grid), end(grid));
        if(checkHorCuts(grid)) return true;

        reverse(begin(grid), end(grid));

        // Vertical cuts via transpose
        vector<vector<int>> transposeGrid(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorCuts(transposeGrid)) return true;

        reverse(begin(transposeGrid), end(transposeGrid));
        if(checkHorCuts(transposeGrid)) return true;

        return false;
    }
};
🔥 Summary
Try all possible horizontal & vertical cuts
Use prefix sum idea
Allow one element removal to fix imbalance
Optimize using set lookup + transpose trick
