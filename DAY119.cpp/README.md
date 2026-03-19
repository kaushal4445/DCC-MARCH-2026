# 📌 LeetCode 3212 – Number of Submatrices with Equal X and Y

---

## 🧩 Problem Statement

You are given a 2D grid consisting of characters `'X'` and `'Y'`.

Your task is to **count the number of submatrices** such that:

* The number of `'X'` and `'Y'` characters are **equal**
* And the count is **greater than 0**

---

## 💡 Intuition

To efficiently count such submatrices, we use the concept of **2D Prefix Sum (Cumulative Sum)**.

### 🔑 Key Idea:

* Maintain two prefix sum matrices:

  * `cumSumX[i][j]` → number of `'X'` from `(0,0)` to `(i,j)`
  * `cumSumY[i][j]` → number of `'Y'` from `(0,0)` to `(i,j)`

* At each cell `(i, j)`:

  * If `cumSumX[i][j] == cumSumY[i][j]`
  * And count > 0 → valid submatrix found

---

## ⚙️ Approach

1. Initialize two 2D arrays:

   * `cumSumX` for counting `'X'`
   * `cumSumY` for counting `'Y'`

2. Traverse the grid:

   * Update prefix sums using:

     ```
     top + left - diagonal + current cell
     ```

3. At each cell:

   * Check if:

     ```
     cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0
     ```
   * If true → increment count

---

## 🧠 Algorithm

```
For each cell (i, j):
    Count X and Y at current cell

    Add values from:
        top (i-1, j)
        left (i, j-1)
        subtract overlap (i-1, j-1)

    If X count == Y count and > 0:
        increment result
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(m × n)   |
| Space | O(m × n)   |

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
   
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                if(j-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }
                
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
            }
        }

        return count; 
    }
};
```

---

## 🎯 Key Takeaways

* 2D Prefix Sum helps in **constant-time submatrix queries**
* Track multiple conditions (X and Y) using separate prefix arrays
* Avoid brute-force (O(n⁴)) → optimized to **O(n²)**

---

## 🚀 Tip

This pattern is very useful in:

* Submatrix sum problems
* Equal frequency problems
* Binary matrix optimizations

---

⭐ If you found this helpful, consider starring your repo!
