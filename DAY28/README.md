🧩 2573. Find the String with LCP
📌 Problem Statement

You are given a 2D matrix lcp of size n x n, where:

lcp[i][j] represents the length of the longest common prefix between the suffixes of a string word starting at indices i and j.

Your task is to construct the lexicographically smallest string word such that its LCP matrix matches the given matrix.

If no such string exists, return an empty string "".

💡 Intuition
The lcp[i][j] tells how many characters match starting from positions i and j.
If lcp[i][j] > 0, then:
word[i] == word[j]
If lcp[i][j] == 0, then:
word[i] != word[j]

We use this information to construct the string greedily.

🚀 Approach
Step 1: Initialize Result String
Create a string word of size n filled with placeholder $.
Step 2: Build the String

For each position i:

Try to match with any previous index j < i:

If lcp[j][i] != 0, assign:

word[i] = word[j]
If no such match exists:
Mark characters that cannot be used.
Pick the smallest valid character ('a' → 'z').
Step 3: Validate the Constructed String
Recompute LCP values using the constructed string.
Ensure:
If characters match → lcp[i][j] = 1 + lcp[i+1][j+1]
Else → lcp[i][j] = 0
Step 4: Return Result
If valid → return word
Else → return ""
🧠 Key Observations
LCP matrix must be symmetric.

Diagonal values:

lcp[i][i] = n - i
Greedy works because we always choose the smallest valid character.
⏱️ Complexity Analysis
Operation	Complexity
String Build	O(n²)
Validation	O(n²)
Total	O(n²)
🧾 C++ Solution
class Solution {
public:
    bool checkLCP(string &word, vector<vector<int>>& lcp) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            if(word[i] != word[n-1]) {
                if(lcp[i][n-1] != 0) return false;
            } else {
                if(lcp[i][n-1] != 1) return false;
            }
        }

        for(int j = 0; j < n; j++) {
            if(word[n-1] != word[j]) {
                if(lcp[n-1][j] != 0) return false;
            } else {
                if(lcp[n-1][j] != 1) return false;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(word[i] == word[j]) {
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]) return false;
                } else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }

            if(word[i] == '$') {
                vector<bool> forbidden(26, false);

                for(int j = 0; j < i; j++) {
                    if(lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                for(int idx = 0; idx < 26; idx++) {
                    if(!forbidden[idx]) {
                        word[i] = idx + 'a';
                        break;
                    }
                }

                if(word[i] == '$')
                    return "";
            }
        }

        return checkLCP(word, lcp) ? word : "";
    }
};
🔍 Example
Input:
lcp = [[3,2,1],
       [2,2,1],
       [1,1,1]]

Output:
"aaa"
🏁 Summary
Construct string using LCP constraints.
Use greedy + validation.
Ensure correctness with a reverse LCP check.
