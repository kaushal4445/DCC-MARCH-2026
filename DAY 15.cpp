// 1622. Fancy Sequence
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Write an API that generates fancy sequences using the append, addAll, and multAll operations.

// Implement the Fancy class:

// Fancy() Initializes the object with an empty sequence.
// void append(val) Appends an integer val to the end of the sequence.
// void addAll(inc) Increments all existing values in the sequence by an integer inc.
// void multAll(m) Multiplies all existing values in the sequence by an integer m.
// int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 

// Example 1:

// Input
// ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
// [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
// Output
// [null, null, null, null, null, 10, null, null, null, 26, 34, 20]

// Explanation
// Fancy fancy = new Fancy();
// fancy.append(2);   // fancy sequence: [2]
// fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
// fancy.append(7);   // fancy sequence: [5, 7]
// fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
// fancy.getIndex(0); // return 10
// fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
// fancy.append(10);  // fancy sequence: [13, 17, 10]
// fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
// fancy.getIndex(0); // return 26
// fancy.getIndex(1); // return 34
// fancy.getIndex(2); // return 20
 

// Constraints:

// 1 <= val, inc, m <= 100
// 0 <= idx <= 105
// At most 105 calls total will be made to append, addAll, multAll, and getIndex.


//solution: 

class Fancy {
    long long a = 1; 
    long long b = 0; 
    vector<long long> nums;
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val) {
        long long inverseA = modInverse(a);
        long long transformedVal = ((val - b + MOD) % MOD * inverseA) % MOD;
        nums.push_back(transformedVal);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (a * nums[idx] + b) % MOD;
    }
};
