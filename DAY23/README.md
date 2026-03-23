📌 1594. Maximum Non Negative Product in a Matrix
🧩 Problem Statement

You are given an m x n grid filled with integers. You need to find a path from the top-left cell (0,0) to the bottom-right cell (m-1,n-1).

👉 You can only move:

Right ➡️
Down ⬇️
🎯 Goal:

Return the maximum non-negative product of all numbers along the path.

If the maximum product is negative, return -1
Otherwise, return result modulo (10⁹ + 7)
💡 Key Insight

Because the grid contains negative numbers, the product can flip signs:

Negative × Negative = Positive ✅
Positive × Negative = Negative ❌

👉 So, at each cell we must track:

Maximum product so far
Minimum product so far (important for future negatives)
🧠 Approach (Dynamic Programming)

We use Bottom-Up DP.

🔹 State Definition:
t[i][j] = {maxProduct, minProduct}

Where:

maxProduct → maximum product to reach (i,j)
minProduct → minimum product to reach (i,j)
🔹 Initialization:
Start at (0,0):
t[0][0] = {grid[0][0], grid[0][0]}
🔹 First Row:

Only move from left:

t[0][j] = t[0][j-1] * grid[0][j]
🔹 First Column:

Only move from top:

t[i][0] = t[i-1][0] * grid[i][0]
🔹 Transition:

At each cell (i,j):

We consider all possibilities:

upMax, upMin
leftMax, leftMin

Then:

maxVal = max(all 4 possibilities × current cell)
minVal = min(all 4 possibilities × current cell)
🔹 Final Answer:
If maxProduct < 0 → return -1
Else → return maxProduct % MOD
⏱️ Complexity
Type	Complexity
Time	O(m × n)
Space	O(m × n)
🧾 C++ Solution
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // DP table: {maxProduct, minProduct}
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));

        // Base case
        t[0][0] = {grid[0][0], grid[0][0]};

        // First row
        for(int j = 1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first  * grid[0][j];
            t[0][j].second = t[0][j-1].second * grid[0][j];
        }

        // First column
        for(int i = 1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first  * grid[i][0];
            t[i][0].second = t[i-1][0].second * grid[i][0];
        }

        // Fill DP table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first = max({
                    upMax * grid[i][j],
                    upMin * grid[i][j],
                    leftMax * grid[i][j],
                    leftMin * grid[i][j]
                });

                t[i][j].second = min({
                    upMax * grid[i][j],
                    upMin * grid[i][j],
                    leftMax * grid[i][j],
                    leftMin * grid[i][j]
                });
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
🔥 Summary
Track both max and min at each cell
Handle negative numbers carefully
Use DP grid of pairs
Final answer depends on sign of max product
