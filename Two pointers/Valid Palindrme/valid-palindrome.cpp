/**
 * PROBLEM: 125. Valid Palindrome (Easy)
 * LINK: https://leetcode.com/problems/valid-palindrome/
 *
 * CORE CONCEPT: Two-Pointer Technique (Converging Boundaries)
 * - Two-Pointer Convergence: A memory-optimal strategy where a left pointer ('front')
 *   and a right pointer ('rear') start at opposite ends of a string and march inward
 *   toward the center to verify structural symmetry.
 * - Why it's used here: By skipping non-alphanumeric characters dynamically inside the
 *   main loop, we avoid the overhead of copying or modifying the original string,
 *   allowing the algorithm to execute with absolute zero extra memory buffers.
 *
 * APPROACH:
 * 1. Initialize 'front' at index 0 and 'rear' at the last index (s.length() - 1).
 * 2. Advance 'front' if it encounters spaces or punctuation, and decrement 'rear' similarly
 *    using C++'s built-in `isalnum()`.
 * 3. Once both pointers land on valid alphanumeric characters, transform them to lowercase
 *    via `tolower()` and compare. Mismatches instantly return false.
 * 4. Stop when the pointers meet or cross in the middle.
 *
 * COMPLEXITY:
 * - Time: O(n) -> Linear time complexity, as every character is evaluated at most once.
 * - Space: O(1) -> Constant space complexity; references and modifies indices in-place.
 */

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int front = 0;
    int rear = s.length() - 1;

    while (front < rear)
    {
      // Step 2: Skip non-alphanumeric characters from the left
      while (front < rear && !isalnum(s[front]))
      {
        front++;
      }
      // Step 2: Skip non-alphanumeric characters from the right
      while (front < rear && !isalnum(s[rear]))
      {
        rear--;
      }

      // Step 3: Standardize to lowercase and compare characters
      if (tolower(s[front]) != tolower(s[rear]))
      {
        return false;
      }

      // Step 4: Step inward
      front++;
      rear--;
    }

    return true;
  }
};