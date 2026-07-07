/*
  Space Optimized (O(1))
  "Tortoise and the Hare" algorithm
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

  NOTES:
  - For odd-length lists, slow lands on the middle node, and reversing from there still works because the middle element is compared with itself.
  - The code is functionally correct for both odd and even lengths.

  COMPLEXITY:
  - Time: O(n) -> Single pass to find middle, reverse, and compare.
  - Space: O(1) -> Modified the list in-place without extra structures.

*/

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return true;

    // Step 1: Find the middle of the linked list (Fast & Slow Concept)
    ListNode *slow = head;
    ListNode *fast = head;
    // while (fast && fast->next)
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list in-place
    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr != nullptr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // Step 3: Standard Two-Pointer convergence comparison
    ListNode *firstHalf = head;
    ListNode *secondHalf = prev;
    while (secondHalf)
    {
      if (firstHalf->val != secondHalf->val)
      {
        return false;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return true;
  }
};