🧩 2840. Check if Strings Can be Made Equal With Operations II
📌 Problem Statement

Given two strings s1 and s2 of equal length, determine whether you can make them equal by performing any number of operations.

🔄 Allowed Operation:
Swap characters at even indices among themselves.
Swap characters at odd indices among themselves.

👉 In simple terms:

You can rearrange characters at even positions independently
And rearrange characters at odd positions independently
💡 Key Insight

To make both strings equal:

The frequency of characters at even indices must match in both strings.
The frequency of characters at odd indices must match in both strings.

If both conditions are satisfied → ✅ Strings can be made equal
Otherwise → ❌ Not possible

🚀 Approach
Create two frequency arrays:
even[26] → for characters at even indices
odd[26] → for characters at odd indices
Traverse both strings:
For even index i:
Increment count for s1[i]
Decrement count for s2[i]
For odd index i:
Do the same in odd array
Finally:
If all values in both arrays are 0, return true
Else return false
🧠 Intuition

Since swapping is only allowed within:

even positions
odd positions

👉 We are essentially checking if both strings have:

Same multiset of characters at even indices
Same multiset of characters at odd indices
⏱️ Complexity Analysis
Type	Complexity
Time	O(n)
Space	O(1) (fixed size arrays of 26)
💻 C++ Solution
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26,0);
        vector<int> odd(26,0);
        int n = s1.size();

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            } 
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0) 
                return false;
        }

        return true;
    }
};
✅ Example
Input:
s1 = "abcd"
s2 = "cdab"
Explanation:
Even indices → a, c and c, a ✔️ match
Odd indices → b, d and d, b ✔️ match
Output:
true
🏁 Summary

✔ Separate even & odd positions
✔ Compare frequency counts
✔ If both match → strings are transformable
