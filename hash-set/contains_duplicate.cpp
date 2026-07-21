/**
 * PROBLEM: 217. Contains Duplicate (Easy)
 * LINK: https://leetcode.com/problems/contains-duplicate/
 *
 * CORE CONCEPT: Hashing / Set membership
 * - Use an `unordered_set` to detect duplicates in a single linear pass.
 *
 * APPROACH:
 * 1. Iterate through each number in `nums`.
 * 2. If the number is already present in the set, return `true` (duplicate found).
 * 3. Otherwise insert the number into the set and continue.
 * 4. If the loop completes with no duplicates, return `false`.
 *
 * COMPLEXITY:
 * - Time: O(n) average-case
 * - Space: O(n)
 */

#include <vector>
#include <unordered_set>

class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> seen;
    for (int num : nums)
    {
      if (seen.count(num) > 0)
        return true;
      seen.insert(num);
    }
    return false;
  }
};