# [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

## Difficulty
**Easy**

---

## Problem Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a palindrome, or* `false` *otherwise*.

### Examples

**Example 1:**
* **Input:** `s = "A man, a plan, a canal: Panama"`
* **Output:** `true`
* **Explanation:** `"amanaplanacanalpanama"` is a palindrome.

**Example 2:**
* **Input:** `s = "race a car"`
* **Output:** `false`
* **Explanation:** `"raceacar"` is not a palindrome.

**Example 3:**
* **Input:** `s = " "`
* **Output:** `true`
* **Explanation:** `s` is an empty string `""` after removing non-alphanumeric characters. Since an empty string reads the same forward and backward, it is a palindrome.

### Constraints
* `1 <= s.length <= 2 * 10^5`
* `s` consists only of printable ASCII characters.

---

## Approach & Intuition

The problem requires us to verify if a string reads the same forward and backward while completely ignoring non-alphanumeric characters and casing. Instead of creating a brand new filtered string (which takes extra memory), we can optimize this by utilizing a **Two-Pointer Approach** directly on the input string.

1. Initialize two pointers: `front` at the beginning (`0`) and `rear` at the end (`s.length() - 1`).
2. Move the pointers toward each other inside a `while` loop:
   * If the character at `front` is not alphanumeric, skip it by incrementing `front`.
   * If the character at `rear` is not alphanumeric, skip it by decrementing `rear`.
   * Once both pointers land on valid alphanumeric characters, standardize them to lowercase using `tolower()` and compare them.
3. If the characters do not match, the string is not a palindrome; return `false`.
4. If the pointers meet or cross without any mismatch, every valid pair matches perfectly; return `true`.

By handling the filtering on the fly, we achieve maximum space efficiency.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single linear pass over the string where `n` is the length of `s`. Each character is visited at most twice.
* **Space Complexity:** $O(1)$ — Only a couple of primitive pointers (`front`, `rear`) are maintained, requiring no extra memory overhead.

---

## Code Walkthrough

The implementation scans inward from both boundaries while filtering out invalid characters:
* `front` and `rear` serve as boundary trackers tracking our comparison window.
* Inside the main loop, independent nested loops skip any symbols, spaces, or punctuation from both ends using `!isalnum()`.
* The safety condition `front < rear` is strictly included within these nested loops to prevent pointers from overshooting past each other during runs of non-alphanumeric characters.
* Once isolated, the two valid elements are transformed to lowercase and cross-checked. A mismatch breaks early with `false`.
* If a match occurs, both trackers step inward (`front++`, `rear--`) to evaluate the remaining inner bounds.