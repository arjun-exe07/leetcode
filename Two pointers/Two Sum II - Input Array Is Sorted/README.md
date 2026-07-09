# [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## Difficulty
**Medium**

---

## Problem Statement

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the indices of the two numbers, `index1` and `index2`, each incremented by one, as an integer array `[index1, index2]` of length 2.*

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

### Examples

**Example 1:**
* **Input:** `numbers = [2, 7, 11, 15]`, `target = 9`
* **Output:** `[1, 2]`
* **Explanation:** The sum of 2 and 7 is 9. Therefore, `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

**Example 2:**
* **Input:** `numbers = [2, 3, 4]`, `target = 6`
* **Output:** `[1, 3]`
* **Explanation:** The sum of 2 and 4 is 6. Therefore `index1 = 1`, `index2 = 3`. We return `[1, 3]`.

**Example 3:**
* **Input:** `numbers = [-1, 0]`, `target = -1`
* **Output:** `[1, 2]`
* **Explanation:** The sum of -1 and 0 is -1. Therefore `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

### Constraints
* `2 <= numbers.length <= 3 * 10^4`
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in **non-decreasing order**.
* `-1000 <= target <= 1000`
* The tests are generated such that there is **exactly one solution**.

---

## Approach & Intuition

Since the input array is already sorted, we can avoid the nested loops of a brute-force approach ($O(n^2)$) or the hash map lookup approach ($O(n)$ space) by using a **Two-Pointer Approach**.

1. Initialize two pointers: `left` at the beginning (`0`) and `right` at the end (`numbers.size() - 1`) of the array.
2. In a loop, calculate the sum of the elements at these pointers: `current_sum = numbers[left] + numbers[right]`.
3. Compare the `current_sum` with the `target`:
   * If `current_sum == target`: We have found our solution. Since LeetCode expects a 1-indexed result, return `{left + 1, right + 1}`.
   * If `current_sum < target`: Because the array is sorted, the only way to increase our sum is to move the `left` pointer to the right (`left++`).
   * If `current_sum > target`: Similarly, the only way to decrease our sum is to move the `right` pointer to the left (`right--`).
4. Since the problem guarantees that there is exactly one solution, the pointers will always meet at the correct pair.

This allows us to find the pair in a single pass while using zero extra space.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — We process each element at most once by moving either the `left` or `right` pointer inward at each step.
* **Space Complexity:** $O(1)$ — Only two pointers (`left` and `right`) are used, complying with the constant extra space constraint.

---

## Code Walkthrough

The solution implements the scanning of boundaries inwards:
* `left` begins at index `0` and `right` begins at the final element (`numbers.size() - 1`).
* Inside the `while` loop, `current_sum` tracks the addition of values at both pointers.
* If `current_sum` matches the target, the 1-based indices are constructed and returned immediately.
* If `current_sum` is too small, `left++` moves the lower boundary up to search for a larger value.
* If `current_sum` is too large, `right--` moves the upper boundary down to search for a smaller value.