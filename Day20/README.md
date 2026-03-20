📊 Minimum Absolute Difference in K×K Submatrix (LeetCode 3567)
🧩 Problem Statement

Given a 2D integer matrix grid of size m × n and an integer k,
you need to compute a new matrix ans of size (m - k + 1) × (n - k + 1).

Each element ans[i][j] represents the minimum absolute difference between any two distinct values inside the k × k submatrix starting at (i, j).

💡 Approach
🔍 Key Idea:

For every k × k submatrix:

Extract all elements.

Store them in a sorted structure (set in C++).

Compute the minimum difference between consecutive elements.

⚙️ Steps:

Traverse all possible k × k submatrices.

Use a set<int> to:

Automatically sort elements

Remove duplicates

If all elements are the same → answer is 0.

Otherwise:

Iterate through sorted values

Compute minimum difference between adjacent elements

🧠 Algorithm
For each (i, j) as top-left of submatrix:
    Create empty set values
    
    For r in i → i+k:
        For c in j → j+k:
            Insert grid[r][c] into set
    
    If set size == 1:
        minDiff = 0
    Else:
        Traverse sorted set
        Find minimum difference between consecutive elements
    
    Store result in ans[i][j]
⏱️ Complexity Analysis

Time Complexity:

For each submatrix → O(k² log(k²))

Total → O((m-k+1)(n-k+1) * k² log k)

Space Complexity:

O(k²) for storing elements in set

💻 C++ Solution
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> values;

                // Collect elements of k x k submatrix
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        values.insert(grid[r][c]);
                    }
                }

                int minDiff = INT_MAX;

                // If all values are same
                if (values.size() == 1) {
                    minDiff = 0;
                } else {
                    auto prev = values.begin();
                    auto curr = next(prev);

                    while (curr != values.end()) {
                        minDiff = min(minDiff, abs(*curr - *prev));
                        prev = curr;
                        curr = next(prev);
                    }
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};
✨ Example
Input:
grid = [[1,3,6],
        [4,8,2],
        [7,5,9]]
k = 2
Output:
[[2,1],
 [1,1]]
🚀 Key Takeaways

Using a set simplifies sorting + uniqueness.

Minimum difference always lies between adjacent sorted elements.

Straightforward brute-force works well for moderate constraints.
