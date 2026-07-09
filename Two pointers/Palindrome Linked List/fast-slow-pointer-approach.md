# Fast and Slow Pointer Approach for Palindrome Linked List

The fast and slow pointer technique is a very common pattern for linked list problems. It is especially useful when we need to find the middle of a list, detect cycles, find the start of a circular linked list, or compare two halves of a linked structure without using indexes.

## Why it works

In a singly linked list, we cannot directly jump to the middle node by index. The fast pointer moves twice as fast as the slow pointer, so when the fast pointer reaches the end, the slow pointer lands exactly at the middle.

This is why the approach is used here: we do not need the exact length of the list to solve the problem. We only need a way to split the list into two halves and compare them.

## Step-by-step idea

1. Initialize:
   - `slow = head`
   - `fast = head`

2. Move both pointers:
   - `slow` moves one step
   - `fast` moves two steps

3. When `fast` reaches the end, `slow` points to the middle of the list.

4. Reverse the second half of the list starting from `slow`.

5. Compare the first half and the reversed second half.

6. If all values match, the list is a palindrome.

## Example

For the list:

`1 -> 2 -> 3 -> 2 -> 1`

- `slow` and `fast` move until `fast` reaches the end.
- `slow` ends at the middle node `3`.
- The second half becomes `2 -> 1` reversed to `1 -> 2`.
- Now the values can be compared directly.

## Important note

The exact length of the list is not really required. The pointer movement itself is enough to locate the middle and compare the two halves.

For odd-length lists, the middle node is compared with itself, which is fine. The algorithm still works correctly.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$

This is why the fast and slow pointer approach is considered the optimal solution for this problem.
