/**
 * PROBLEM: 234. Palindrome Linked List (Easy)
 * LINK: https://leetcode.com/problems/palindrome-linked-list/
 *
 * CORE CONCEPT: Two-Pointer Technique (Converging Pointers via Array Copying)
 * - Two-Pointer Convergence: A strategy where two indices ('front' and 'rear')
 *   start at opposite ends of a linear sequence and move inward toward the center.
 * - Why it's used here: Singly linked lists cannot be easily traversed backward.
 *   By copying the list values into a dynamic array (vector), we can seamlessly
 *   deploy standard array two-pointer logic to cross-examine matching elements.
 *
 * APPROACH:
 * 1. Traverse the entire linked list and copy each node's value into a vector.
 * 2. Setup a 'front' pointer at index 0 and a 'rear' pointer at the last index.
 * 3. Loop inward, comparing the elements. If any mismatch occurs, it's not a palindrome.
 *
 * COMPLEXITY:
 * - Time: O(n) -> Linear time to copy the nodes and iterate up to the midpoint.
 * - Space: O(n) -> Requires extra memory to store the node values in the vector.
 *
 * DIFFERENTIATION:
 * - Unlike the space-optimized version (fast/slow pointer + reverse),
 *   this approach trades space for simplicity by using a vector.
 * - Space-optimized: O(1) space, more complex logic with in-place reversal.
 * - Vector approach: O(n) space, simpler and more intuitive logic.
 */

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    vector<int> arr;

    ListNode *temp = head;

    // Copy linked list values into vector
    while (temp != nullptr)
    {
      arr.push_back(temp->val);
      temp = temp->next;
    }

    int front = 0;
    int rear = arr.size() - 1;

    // Compare from both sides
    while (front < rear)
    {
      if (arr[front] != arr[rear])
      {
        return false;
      }

      front++;
      rear--;
    }

    return true;
  }
};