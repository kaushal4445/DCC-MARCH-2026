🔁✨ Reverse Submatrix (LeetCode 3643)
<div align="center">

🚀 Master in-place matrix manipulation with a clean two-pointer approach!

</div>
🧩 Problem Overview

Given a 2D matrix grid (m x n), you need to:

🔹 Select a k × k submatrix starting at position (x, y)
🔹 Reverse it vertically (top ↔ bottom rows)
🔹 Return the updated matrix

🎯 Visual Idea

Before 👇

1  2  3
4  5  6
7  8  9

After reversing submatrix (k = 3) 👇

7  8  9
4  5  6
1  2  3
💡 Intuition

Think of it like:

🔄 Reversing rows inside a square window of the matrix

We swap top and bottom rows, then move inward — just like reversing an array!

⚙️ Approach

✨ Use Two Pointers Technique

i → Top row of submatrix
j → Bottom row of submatrix
Steps:

Start with:

i = x
j = x + k - 1
While i < j:
Swap elements column-wise
Move inward (i++, j--)
Done ✅
🧠 Algorithm
Repeat until top meets bottom:
    For each column in submatrix:
        Swap grid[top][col] with grid[bottom][col]
⏱️ Complexity
Type	Complexity
🕒 Time	O(k²)
💾 Space	O(1)

✔️ In-place operation (no extra memory!)

💻 C++ Solution
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x, j = x + k - 1;

        while(i < j) {
            for(int a = y; a < y + k; a++) {
                swap(grid[i][a], grid[j][a]);
            }
            i++;
            j--;
        }

        return grid;
    }
};
🧪 Example
📥 Input
grid = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};
x = 0, y = 0, k = 3;
📤 Output
{
  {7, 8, 9},
  {4, 5, 6},
  {1, 2, 3}
};
🚀 Key Highlights

✨ Clean & simple logic
✨ Efficient in-place swapping
✨ No extra memory needed
✨ Classic two-pointer pattern

🏁 Final Thoughts

This problem is a great example of:

✔️ Matrix manipulation
✔️ Subgrid processing
✔️ Two-pointer optimization
