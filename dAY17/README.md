# 🚀 LeetCode 1727 — Largest Submatrix With Rearrangements

## 🧩 Problem Overview

You are given a binary matrix `matrix` of size `m x n`.

You are allowed to **rearrange the columns of each row in any order**.

Return the **area of the largest submatrix consisting only of `1`s** after rearranging columns optimally.

---

## 💡 Intuition

* Treat each row as a **histogram**
* Build heights of consecutive `1`s column-wise
* Sort each row in **descending order**
* Try forming maximum rectangle using width × height

👉 Sorting helps because we can group taller columns together after rearranging.

---

## 🚀 Approach

### 🔹 Step 1: Build Heights

If a cell has `1`, add value from the previous row:

```cpp
if(matrix[row][col] == 1 && row > 0) {
    matrix[row][col] += matrix[row-1][col];
}
```

---

### 🔹 Step 2: Sort Each Row

* Copy current row
* Sort in **descending order**

---

### 🔹 Step 3: Calculate Area

For each column:

* Width = `col + 1`
* Height = `currRow[col]`

```cpp
area = width * height;
```

Keep updating the maximum area.

---

## ⏱ Complexity Analysis

| Complexity       | Value            |
| ---------------- | ---------------- |
| Time Complexity  | `O(m * n log n)` |
| Space Complexity | `O(n)`           |

---

## 💻 C++ Solution (Your Code)

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        for(int row = 0; row < m; row++) {
            
            for(int col = 0; col < n; col++) {
                
                if(matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
                
            }
            
            
            vector<int> currRow = matrix[row];
            sort(begin(currRow), end(currRow), greater<int>());
            for(int col = 0; col < n; col++) {
                int base   = (col+1); // width
                int height = currRow[col];
                
                result = max(result, base*height);
            }
            
        }
        
        return result;
    }
};
```

---

## 📌 Example

### Input

```
matrix =
[[0,0,1],
 [1,1,1],
 [1,0,1]]
```

### Output

```
4
```

---

## 🔑 Key Concepts

* Histogram approach
* Greedy sorting
* Matrix preprocessing
* Maximum rectangle logic

---

## 🏷 Tags

* Matrix
* Greedy
* Sorting
* Dynamic Programming
* Medium

---

## ⭐ Final Thoughts

This problem is a **twist on Largest Rectangle in Histogram**.

✔ Build heights
✔ Sort rows
✔ Maximize area

---

🔥 Keep practicing DSA!
