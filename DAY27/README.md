🧩 2946. Matrix Similarity After Cyclic Shifts
🟢 Difficulty: Easy
📘 Problem Statement

You are given an m x n integer matrix mat and an integer k.

The following process happens k times:

🔹 Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left
🔹 Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right

👉 Return true if after k operations the matrix becomes identical to the original matrix, otherwise return false.

🧠 Intuition

Instead of actually performing k shifts (which would be inefficient), we observe:

A cyclic shift repeats every n steps (where n = number of columns)

So we can reduce:

k = k % n;
If k == 0, matrix remains unchanged ✅
⚙️ Approach
🔍 Key Idea:

Check whether each element remains at its original position after k shifts.

🧮 For each row:

If row index is even → left shift

new_index = (j + k) % n

If row index is odd → right shift

new_index = (j - k + n) % n
✅ Condition:

If for any element:

mat[i][j] != mat[i][new_index]

→ return false

Otherwise → return true

💻 Code (C++)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = (k % n);

        if(k == 0) { // no shifting
            return true;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) { // even index -> left shift
                    finalIdx = (j + k) % n;
                } else { // odd index -> right shift
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }
            }
        }

        return true;
    }
};
⏱️ Complexity Analysis
Type	Complexity
⏳ Time	O(m × n)
🧠 Space	O(1)
📊 Example Walkthrough
Example:
mat = [[1,2,3],
       [4,5,6],
       [7,8,9]]
k = 4
Effective shifts: k % n = 4 % 3 = 1
Apply shifts:
Row 0 → left shift
Row 1 → right shift
Row 2 → left shift

Matrix changes ❌ → Not same as original

👉 Output: false
