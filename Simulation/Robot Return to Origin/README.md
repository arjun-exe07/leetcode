# 657. Robot Return to Origin

## Difficulty
**Easy**

---

## Problem Statement

There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot **ends up at `(0, 0)`** after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its $i^{th}$ move. Valid moves are:
*   `'R'` (Right)
*   `'L'` (Left)
*   `'U'` (Up)
*   `'D'` (Down)

Return `true` *if the robot returns to the origin after it finishes all of its moves, or* `false` *otherwise*.

> **Note:** The way that the robot is "facing" is irrelevant. `'R'` will always make the robot move to the right once, `'L'` will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

### Examples

**Example 1:**
*   **Input:** `moves = "UD"`
*   **Output:** `true`
*   **Explanation:** The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return `true`.

**Example 2:**
*   **Input:** `moves = "LL"`
*   **Output:** `false`
*   **Explanation:** The robot moves left twice. It ends up two "moves" to the left of the origin. We return `false` because it is not at the origin at the end of its moves.

### Constraints
*   $1 \le \text{moves.length} \le 2 \times 10^4$
*   `moves` only contains the characters `'U'`, `'D'`, `'L'`, and `'R'`.

---

## Approach & Intuition

The problem requires tracking the robot's net movement relative to its starting coordinates `(0, 0)`. Instead of tracking the exact path or storing visited coordinates, we can simply simulate the process using two counters representing the $X$ and $Y$ axes.

1.  Initialize `x = 0` (for horizontal displacement) and `y = 0` (for vertical displacement).
2.  Iterate linearly through the given `moves` string:
    *   Increment `x` for `'U'` and decrement `x` for `'D'`.
    *   Increment `y` for `'R'` and decrement `y` for `'L'`.
3.  Once the instruction processing loop completes, check if both coordinates are back to their equilibrium position (`x == 0 && y == 0`). If they are, it means net displacement is zero and the robot returned home.

---

## Complexity Analysis

*   **Time Complexity:** $O(n)$ — Where $n$ is the length of the string `moves`. We make a single linear iteration through the array.
*   **Space Complexity:** $O(1)$ — No supplemental structures are used; the state is maintained purely via two primitive integers.