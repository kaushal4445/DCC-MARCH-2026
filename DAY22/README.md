🧩 LeetCode 1886
🔄 Determine Whether Matrix Can Be Obtained By Rotation
📌 Problem Statement

Given two n x n binary matrices mat and target, return true if mat can be rotated (in 90° increments) to match target. Otherwise, return false.

You can rotate the matrix in the following ways:

90° clockwise
180° (two rotations)
270° (three rotations)
360° (back to original)
💡 Approach
🔁 Key Idea:

We try all 4 possible rotations of the matrix and check if any of them matches the target.

⚙️ Steps:
Loop 4 times (for 0°, 90°, 180°, 270° rotations)
For each rotation:
Compare mat with target
If equal → ✅ return true
If not equal:
Rotate the matrix by 90° clockwise
If no match found after all rotations → ❌ return false
🔄 Matrix Rotation Logic

To rotate a matrix by 90° clockwise:

Step 1: Transpose the matrix
mat[i][j] ↔ mat[j][i]
Step 2: Reverse each row
[1 2 3] → [3 2 1]
🧠 Algorithm
for 4 rotations:
    if mat == target:
        return true
    rotate(mat)
return false
⏱️ Complexity Analysis
Time Complexity: O(4 * n^2) → O(n^2)
Space Complexity: O(1) (in-place rotation)
💻 C++ Solution
class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat) {
        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        for(int c = 1; c <= 4; c++) {
            bool equal = true;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal) break;
            }

            if(equal) return true;

            rotate(mat);
        }

        return false;
    }
};
✅ Example
Input:
mat = [[0,1],
       [1,0]]

target = [[1,0],
          [0,1]]
Output:
true
🚀 Key Takeaways
Matrix rotation can be done efficiently using transpose + reverse
Only 4 rotations are needed (cycle repeats)
In-place operations help achieve O(1) space
