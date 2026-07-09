# [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

## Difficulty
**Easy**

---

## Problem Statement

Given the head of a singly linked list, return `true` if the linked list is a palindrome and `false` otherwise.

### Examples

**Example 1:**
- **Input:** `1 -> 2 -> 2 -> 1`
- **Output:** `true`

**Example 2:**
- **Input:** `1 -> 2`
- **Output:** `false`

---

## Approach Overview

This problem can be solved in two main ways:

1. **Vector / Array Approach**
   - Copy the list values into a vector.
   - Use two pointers from both ends of the array to compare values.
   - This is simple but uses extra space.

2. **Space-Optimized Approach**
   - Use the **fast and slow pointer** technique.
   - Find the middle of the list.
   - Reverse the second half.
   - Compare the first half with the reversed second half.
   - This uses only constant extra space.

This folder contains both implementations:
- [palindrome-linked-list-vector.cpp](palindrome-linked-list-vector.cpp)
- [palindrome-linked-list-space_optimized.cpp](palindrome-linked-list-space_optimized.cpp)

---

## Intuition

A palindrome reads the same forwards and backwards. In a linked list, we cannot directly access the middle or previous nodes efficiently, so the fast/slow pointer technique helps us find the midpoint in one pass.

Once the second half is reversed, comparing it against the first half becomes straightforward.

---

## Complexity Analysis

### Vector Approach
- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(n)$

### Space-Optimized Approach
- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$

---

## Key Idea for the Optimized Solution

- `slow` moves one step at a time.
- `fast` moves two steps at a time.
- When `fast` reaches the end, `slow` is at the middle.
- The second half is reversed and compared with the first half.

This makes the solution efficient and elegant for linked lists.
