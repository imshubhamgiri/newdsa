# Majority Element

| Attribute | Value |
| :--- | :--- |
| **Difficulty** | `EASY` |
| **Language** | `C++` |
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(1)` |
| **Runtime** | `1 ms` |
| **Memory** | `42 MB` |
| **Problem Link** | [LeetCode — Majority Element](https://leetcode.com/problems/majority-element/) |

---

### 💡 Intuition
The majority element appears more than ⌊n/2⌋ times. Using Boyer‑Moore voting we can cancel out different elements; the element that survives is a potential majority.

### 🛠️ Approach
1. **First pass (Boyer‑Moore):** Keep a `candidate` and a `count`. When the next number equals the candidate, increment `count`; otherwise decrement. If `count` becomes zero, adopt the current number as the new candidate.
2. **Second pass:** Count how many times the candidate actually occurs to confirm it appears at least `n/2` times.
3. Return the candidate if it satisfies the condition; otherwise return `-1`.

### ⚡ Complexity
- **Time:** O(n) – two linear scans.
- **Space:** O(1) – only a few integer variables.

### 🎯 Key Takeaway
Boyer‑Moore voting reduces the problem to constant extra space by pairing different elements against each other; a final verification pass guarantees correctness.
