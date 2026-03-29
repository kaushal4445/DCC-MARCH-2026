# 🧩 LeetCode 2839 – Check if Strings Can be Made Equal With Operations I

## 📝 Problem Statement

You are given two strings `s1` and `s2`, both of length **4**.

You are allowed to perform the following operation any number of times:

* Swap characters at indices `(0, 2)` or `(1, 3)`.

Return `true` if you can make `s1` equal to `s2`, otherwise return `false`.

---

## 💡 Intuition

The key observation is:

* You can only swap **even indices** among themselves → `(0 ↔ 2)`
* And **odd indices** among themselves → `(1 ↔ 3)`

So effectively:

* Characters at indices `0` and `2` form one group
* Characters at indices `1` and `3` form another group

👉 You just need to check whether:

* Even indexed characters in `s1` can match those in `s2`
* Odd indexed characters in `s1` can match those in `s2`

---

## 🚀 Approach

1. Check if characters at **even indices (0, 2)** match:

   * Either directly `(s1[0] == s2[0] && s1[2] == s2[2])`
   * Or swapped `(s1[0] == s2[2] && s1[2] == s2[0])`

2. Check if characters at **odd indices (1, 3)** match:

   * Either directly `(s1[1] == s2[1] && s1[3] == s2[3])`
   * Or swapped `(s1[1] == s2[3] && s1[3] == s2[1])`

3. Return `true` only if **both conditions are satisfied**

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(1)`
  (Only fixed number of comparisons)
* **Space Complexity:** `O(1)`
  (No extra space used)

---

## 🧾 C++ Solution

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool evenIndex = (s1[0]==s2[0] && s1[2]==s2[2]) || 
                         (s1[0]==s2[2] && s1[2]==s2[0]);

        bool oddIndex = (s1[1]==s2[1] && s1[3]==s2[3]) || 
                        (s1[1]==s2[3] && s1[3]==s2[1]);

        return evenIndex && oddIndex;
    }
};
```

---

## 📌 Example

### Input:

```
s1 = "abcd"
s2 = "cdab"
```

### Explanation:

* Swap `s1[0] ↔ s1[2]` → `"cbad"`
* Swap `s1[1] ↔ s1[3]` → `"cdab"`

✅ Now `s1 == s2` → return `true`

---

## 🎯 Key Takeaways

* Focus on **index grouping** rather than brute force swapping
* Recognize **independent swappable groups**
* Leads to a clean and optimal `O(1)` solution

---

## 🏁 Conclusion

This problem is a great example of simplifying constraints into **independent groups**, avoiding unnecessary operations, and achieving constant time complexity.

Happy Coding! 🚀
