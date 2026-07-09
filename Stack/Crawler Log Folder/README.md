# [1598. Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/description/)

## Difficulty
**Easy**

---

## Problem Statement

The Leetcode file system keeps a log each time some user performs a *change folder* operation.

The operations are described below:
* `"../"` : Move to the parent folder of the current folder (If you are already in the main folder, remain in the same folder).
* `"./"` : Remain in the same folder.
* `"x/"` : Move to the child folder named `x` (This folder is guaranteed to always exist).

You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `i`th step.

The file system starts in the main folder, then the operations in `logs` are performed.

Return *the minimum number of operations needed to go back to the main folder after the change folder operations*.

### Examples

**Example 1:**
* **Input:** `logs = ["d1/","d2/","../","d21/","./"]`
* **Output:** `2`
* **Explanation:** Use the change folder operation `"../"` 2 times to go back to the main folder.

**Example 2:**
* **Input:** `logs = ["d1/","d2/","./","d3/","../","d31/"]`
* **Output:** `3`

**Example 3:**
* **Input:** `logs = ["d1/","../","../","../"]`
* **Output:** `0`

### Constraints
* `1 <= logs.length <= 10^3`
* `2 <= logs[i].length <= 10`
* `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.
* `logs[i]` follows the format described in the statement.
* `folder names` consist of lowercase English letters and digits.

---

## Approach & Intuition

The problem only cares about **how deep** into the folder structure we end up, not the actual folder names. So instead of building a stack of folder names, we can track just a single integer — `top` — representing the current depth from the main folder.

1. Initialize `top = 0` to represent the current depth (starting at the main/root folder).
2. Iterate through each entry in `logs`:
   * If the operation is `"../"` (go to parent): only decrement `top` if it's not already `0` — since we can't go above the main folder, this guards against going negative.
   * If the operation is `"./"` (stay in place): do nothing — depth is unchanged.
   * Otherwise, it must be a **move into a child folder** (`"x/"`): increment `top`, since we've gone one level deeper.
3. After processing all operations, `top` holds the final depth from the main folder — which is also exactly the minimum number of `"../"` operations needed to get back to it.

The key insight is that the *number of operations to return to main* is just the current depth itself, since each `"../"` moves up exactly one level — so tracking depth as a simple counter is sufficient; there's no need to know *which* folders were visited.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass through the `logs` array, with constant-time work per entry.
* **Space Complexity:** $O(1)$ — Only a single integer counter (`top`) is used, bypassing the memory overhead of an actual stack structure.

---

## Code Walkthrough

The solution replaces a full folder-name stack with a simple depth counter:
* `top` starts at `0`, representing the main folder, and `len` stores the total number of log entries.
* The `for` loop checks each `logs[i]` against the three possible operation types:
  * `logs[i] == "../"` decrements `top`, but only if `top != 0` (evaluated via truthiness), preventing the depth from going below the main folder.
  * `logs[i] == "./"` skips directly to the next loop iteration via `continue`, explicitly keeping depth unchanged.
  * The final `else` branch handles moving into a child folder, incrementing `top`.
* After the loop finishes, `top` directly represents the minimum number of `"../"` operations needed to return to the main folder, and is returned as the answer.