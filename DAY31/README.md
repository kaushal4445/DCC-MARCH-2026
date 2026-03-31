# 🧩 3474. Lexicographically Smallest Generated String

## 📌 Problem Summary

You are given two strings:

* `str1` of length `n`, consisting of characters `'T'` and `'F'`
* `str2` of length `m`

Your goal is to construct a string `word` of length `n + m - 1` such that:

* If `str1[i] == 'T'`, then the substring of `word` starting at index `i` **must match** `str2`
* If `str1[i] == 'F'`, then the substring of `word` starting at index `i` **must NOT match** `str2`

Among all valid strings, return the **lexicographically smallest** one.
If no valid string exists, return an empty string `""`.

---

## 💡 Approach

### Step 1: Initialize

* Let `N = n + m - 1`
* Create a string `word` of size `N` filled with `'$', indicating unassigned positions`
* Maintain a `canChange` array to track which positions can still be modified

---

### Step 2: Process `'T'` Constraints

* For every index `i` where `str1[i] == 'T'`:

  * Force the substring `word[i...i+m-1]` to match `str2`
  * If a conflict occurs (existing character ≠ required character), return `""`

---

### Step 3: Fill Remaining Positions

* Replace all `'$', with `'a'` (smallest lexicographical character)
* Mark these positions as `canChange = true`

---

### Step 4: Process `'F'` Constraints

* For every index `i` where `str1[i] == 'F'`:

  * Check if substring `word[i...i+m-1]` equals `str2`
  * If it does:

    * Try to modify one character in this range (prefer rightmost changeable index)
    * Change it to `'b'` to break equality
    * If no modification is possible → return `""`

---

### Step 5: Return Result

* If all constraints are satisfied, return the constructed `word`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n * m)`
* **Space Complexity:** `O(n + m)`

---

## 🧠 Key Insight

* First, **force valid matches (`T`)**
* Then, **minimize lexicographically by filling `'a'`**
* Finally, **break invalid matches (`F`) carefully using minimal changes**

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    bool isSame(string &word, string &str2, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(word[i] != str2[j]) {
                return false;
            }
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        // Step 1: Process 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                int i_ = i;
                for(int j = 0; j < m; j++) {
                    if(word[i_] != '$' && word[i_] != str2[j]) {
                        return "";
                    }
                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for(int i = 0; i < N; i++) {
            if(word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // Step 3: Process 'F'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {

                if(isSame(word, str2, i, m)) {

                    bool changed = false;
                    for(int k = i + m - 1; k >= i; k--) {
                        if(canChange[k]) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(!changed) {
                        return "";
                    }
                }
            }
        }

        return word;
    }
};
```

---

## 🎯 Example

```
Input:
str1 = "TFT"
str2 = "ab"

Output:
"abab"
```

---

## 🚀 Final Thoughts

* This problem is a great mix of **greedy + string construction**
* The trick is to:

  * Respect forced constraints first
  * Then ensure forbidden patterns are broken efficiently
* Always aim for **minimum lexicographical order**

---

