/*
  Space Optimized (O(1))
*/

/*

  PROBLEM: 234. Palindrome Linked List (Easy)
  LINK: https://leetcode.com/problems/palindrome-linked-list/

  CORE CONCEPT: Two-Pointer Technique (Fast & Slow Pointers / Tortoise & Hare)
  - Fast-Slow Pointers: A strategy where two pointers traverse a linear structure
    at different speeds (usually 2x and 1x). It is highly efficient for finding
    cycles or finding the exact midpoint of a list in a single pass.
  - Why it's used here: Since we cannot access elements by index in a singly
    linked list, moving the 'fast' pointer 2 steps and 'slow' 1 step guarantees
    that when 'fast' reaches the end, 'slow' will point exactly to the middle.

  APPROACH:
  1. Use a fast/slow pointer to find the middle of the linked list.
  2. Reverse the second half of the list in-place.
  3. Compare the first half and the reversed second half.

  COMPLEXITY:
  - Time: O(n) -> Single pass to find middle, reverse, and compare.
  - Space: O(1) -> Modified the list in-place without extra structures.

*/

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
  }
};