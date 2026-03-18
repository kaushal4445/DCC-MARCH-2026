# 📊 3070. Count Submatrices with Top-Left Element and Sum ≤ k

## 🧩 Problem Statement

You are given a **0-indexed integer matrix** `grid` and an integer `k`.

Your task is to **count the number of submatrices** that:

* **Include the top-left element** `(0, 0)`
* Have a **sum less than or equal to `k`**

---

## 🧪 Examples

### Example 1

```
Input:
grid = [[7,6,3],
        [6,6,1]]
k = 18

Output:
4
```

### Example 2

```
Input:
grid = [[7,2,9],
        [1,5,0],
        [2,6,6]]
k = 20

Output:
6
```

---

## ⚙️ Constraints

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 1000`
* `0 <= grid[i][j] <= 1000`
* `1 <= k <= 10^9`

---

## 🚀 Approach

### 💡 Key Idea: Prefix Sum (2D)

We use a **2D Prefix Sum technique** to efficiently compute the sum of submatrices.

### 🔍 Steps:

1. Traverse the matrix row by row.
2. Convert each cell into a **prefix sum**:

   * Add value from **top**
   * Add value from **left**
   * Subtract **top-left overlap**
3. Each `grid[i][j]` now represents the sum of submatrix from `(0,0)` to `(i,j)`
4. If this sum is `<= k`, increment count
5. If it exceeds `k`, break the inner loop (optimization 🚀)

---

## 🧠 Why Break Early?

Since prefix sums **increase as we move right**, once the sum exceeds `k`,
all further elements in that row will also exceed `k`.

---

## 🧮 Algorithm

```
for each cell (i, j):
    grid[i][j] = grid[i][j]
                 + top value
                 + left value
                 - top-left overlap

    if grid[i][j] <= k:
        count++
    else:
        break
```

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i > 0) 
                    grid[i][j] += grid[i - 1][j];

                if (j > 0) 
                    grid[i][j] += grid[i][j - 1];

                if (i > 0 && j > 0) 
                    grid[i][j] -= grid[i - 1][j - 1];

                if (grid[i][j] <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(1)` (in-place modification)

---

## 🎯 Summary

* Convert grid into **prefix sum matrix**
* Each cell represents sum from `(0,0)` to `(i,j)`
* Count valid submatrices with sum ≤ `k`
* Use **early break optimization** for efficiency

---

## 🏁 Conclusion

This problem becomes simple once you realize:

> Every valid submatrix must start at `(0,0)`

So instead of checking all submatrices, we just compute prefix sums and count valid ones efficiently 🚀

---
