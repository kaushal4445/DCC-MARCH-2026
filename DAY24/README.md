🚀 LeetCode 2906: Construct Product Matrix
🧩 Problem Statement

Given a 2D matrix grid, construct a new matrix p such that:

Each element p[i][j] is equal to the product of all elements in the matrix except grid[i][j]
The result should be taken modulo 12345
💡 Key Idea

Instead of calculating the product for every cell separately (which would be very slow ❌), we use an optimized approach using:

🔹 Prefix Product
Product of all elements before current cell
🔹 Suffix Product
Product of all elements after current cell
⚙️ Approach
Step 1: Initialize Result Matrix
Create a matrix p of same size as grid
Step 2: Compute Suffix Product
Traverse from bottom-right → top-left
Store product of all elements after current cell
Step 3: Compute Prefix Product
Traverse from top-left → bottom-right
Multiply prefix with stored suffix
🧠 Why This Works?

For each cell:

p[i][j]=(product of elements before)×(product of elements after)

This avoids recomputation and gives an efficient solution.

⏱️ Complexity Analysis
Type	Complexity
Time	O(n × m)
Space	O(1) (excluding output matrix)
🧾 C++ Solution
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> p(n, vector<int>(m)); // result matrix

        // Step 1: Suffix product
        long long suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        // Step 2: Prefix product
        long long prefix = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                p[i][j] = (prefix * p[i][j]) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return p;
    }
};
🔍 Example
Input
grid = [[1,2],
        [3,4]]
Output
[[24,12],
 [8,6]]
🏁 Summary
Avoid brute force ❌
Use prefix + suffix trick ✅
Efficient and optimal solution 💯
