# 🧩 3546. Equal Sum Grid Partition I

🔗 **Problem Link:** https://leetcode.com/problems/equal-sum-grid-partition-i/

---

## 🧠 Problem Statement

Given a 2D grid of integers, determine whether it is possible to partition the grid into two parts using:

- A **horizontal cut** OR  
- A **vertical cut**

such that the **sum of elements in both parts is equal**.

👉 Return `true` if such a partition exists, otherwise return `false`.

---

## 💡 Approach

### 🔍 Key Idea:
We need to check if we can split the grid into two parts with **equal sum**.

### ⚡ Steps:

1. **Compute Total Sum**
   - Traverse the grid and calculate the total sum.
   - If total sum is **odd**, return `false` (cannot divide equally).

2. **Store Row & Column Sums**
   - Create:
     - `row[]` → sum of each row  
     - `col[]` → sum of each column  

3. **Try Horizontal Partition**
   - Keep adding row sums from top.
   - At each step:
     - Check if `upper_sum == total - upper_sum`

4. **Try Vertical Partition**
   - Keep adding column sums from left.
   - At each step:
     - Check if `left_sum == total - left_sum`

5. **Return Result**
   - If any valid partition found → `true`
   - Else → `false`

---

## ⚙️ Algorithm

1. Calculate total sum of grid  
2. If total is odd → return false  
3. Compute row-wise and column-wise sums  
4. Check horizontal cut  
5. Check vertical cut  
6. Return final result  

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long total = 0;
        vector<long long> row(m, 0), col(n, 0);

        // Calculate total, row sums, and column sums
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        // If total sum is odd, partition is not possible
        if(total % 2 != 0) return false;

        // Check horizontal partition
        long long upper = 0;
        for(int i = 0; i < m - 1; i++) {
            upper += row[i];
            if(upper == total - upper) return true;
        }

        // Check vertical partition
        long long left = 0;
        for(int j = 0; j < n - 1; j++) {
            left += col[j];
            if(left == total - left) return true;
        }

        return false;
    }
};
⏱️ Complexity Analysis
Time Complexity: O(m × n)
Traversing the grid once
Space Complexity: O(m + n)
For storing row and column sums
📊 Example

Input:

grid = [[1, 2, 3],
        [3, 2, 1]]

Output:

true

Explanation:

Total sum = 12
Horizontal cut after first row → sum = 6
Remaining = 6 → Equal partition possible ✅
