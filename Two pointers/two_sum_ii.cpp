/*
  Space Optimized (O(1))
  Two-Pointer Convergence Technique
*/

/*

  PROBLEM: 167. Two Sum II - Input Array Is Sorted (Medium)
  LINK: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

  CORE CONCEPT: Two-Pointer Technique (Left & Right Pointers)
  - Left-Right Pointers: A strategy where two pointers start at opposite ends
  of a sorted linear structure and converge inward toward each other.
  - Why it's used here: Because the input array is sorted, we can adjust our
    search window logically. Moving the left pointer rightward increases the
    sum, while moving the right pointer leftward decreases the sum.

  APPROACH:
  1. Initialize 'left' at the beginning (index 0) and 'right' at the end of the array.
  2. Compute the sum of the elements at 'left' and 'right'.
  3. If the sum matches the target, return their 1-based indices.
  4. If the sum is smaller than the target, increment 'left' to increase the sum.
  5. If the sum is larger than the target, decrement 'right' to decrease the sum.

  NOTES:
  - Since the problem guarantees exactly one solution and prohibits using the
    same element twice, the pointers will always meet at the correct pair.
  - The solution uses 1-based indexing for the output as required.

  COMPLEXITY:
  - Time: O(n) -> Single linear pass as the pointers converge inward.
  - Space: O(1) -> Only uses two primitive pointers, avoiding any extra data structures.

*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
      int current_sum = numbers[left] + numbers[right];

      if (current_sum == target)
      {
        return {left + 1, right + 1}; // 1-based indexing
      }
      else if (current_sum < target)
      {
        left++; // Need a larger sum
      }
      else
      {
        right--; // Need a smaller sum
      }
    }
    return {}; // Fallback Case
  }
};
