// 1980. Find Unique Binary String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

// Constraints:

// n == nums.length
// 1 <= n <= 16
// nums[i].length == n
// nums[i] is either '0' or '1'.



//Solution: 

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
            string ans="";
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i][i]=='1')     // What is nums[i][i]nums[i] → ith string[i] → ith character ofthestring
// Example Walkthrough
// Input
// nums = ["01","10"]
// Step 1
// n = 2
// ans = ""
// Iteration 1 (i = 0)

// Check:

// nums[0][0] = '0'

// Flip:

// ans += "1"

// Now

// ans = "1"
// Iteration 2 (i = 1)

// Check:

// nums[1][1] = '0'

// Flip:

// ans += "1"

// Now

// ans = "11"
// Final Output
// "11"

// Check if it exists:

// nums = ["01","10"]

// 11 does not exist, so it is valid.

            ans.append("0");          
            else ans.append("1");
        }
        return ans;
    }
};
All the strings of nums are unique.
