/**
 * PROBLEM: 1598. Crawler Log Folder (Easy)
 * LINK: https://leetcode.com/problems/crawler-log-folder/
 *
 * CORE CONCEPT: Simulation / Counter-Based Stack Tracking
 * - Distance Tracking: Instead of maintaining an actual stack data structure to store
 *   folder names, we only care about the *depth* relative to the main folder.
 * - Why it's used here: By using a simple integer counter (`count`), we simulate
 *   stack push/pop actions in O(1) space, avoiding the memory allocation overhead
 *   of a dynamic container.
 *
 * APPROACH:
 * 1. Initialize a `count` tracker to 0, representing the root directory.
 * 2. Loop through each log:
 *    - "../" moves up one level: Decrement `count` only if `count > 0` (cannot go past root).
 *    - "./" remains in the same folder: Do nothing (continue).
 *    - "x/" moves into a child folder: Increment `count`.
 * 3. Return the final value of `count`, which represents the minimum steps to return to root.
 *
 * COMPLEXITY:
 * - Time: O(n) -> Linear time complexity, processing each log string exactly once.
 * - Space: O(1) -> Constant space complexity; uses only two primitive integer trackers.
 */

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    int top = 0;
    int len = logs.size();

    for (int i = 0; i < len; i++)
    {
      if (logs[i] == "../")
      {
        if (top)
        {
          top--;
        }
      }
      else if (logs[i] == "./")
      {
        continue; // Remain in the same folder, do nothing
      }
      else
      {
        top++; // Move to a child folder
      }
    }
    return top;
  }
};