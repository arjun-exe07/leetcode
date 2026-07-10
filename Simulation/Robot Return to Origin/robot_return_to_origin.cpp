/*
  Space Optimized (O(1))
  Coordinate-based Simulation
*/

/*

  PROBLEM: 657. Robot Return to Origin (Easy)
  LINK: https://leetcode.com/problems/robot-return-to-origin/

  CORE CONCEPT: Coordinate Grid Simulation
  - Simulation: A strategy where we track the virtual position of an object on a 2D
    plane by modifying coordinate variables based on an explicitly given set of instructions.
  - Why it's used here: The robot starts at position (0, 0). Every move alters either the
    horizontal or vertical axis. To see if it returns to the starting point, we only need
    to track the net displacements on the x and y axes.

  APPROACH:
  1. Initialize two position tracking coordinates `x = 0` and `y = 0`.
  2. Iterate through each character movement command in the given `moves` string:
     - 'U' (Up) increases the vertical position `x`.
     - 'D' (Down) decreases the vertical position `x`.
     - 'R' (Right) increases the horizontal position `y`.
     - 'L' (Left) decreases the horizontal position `y`.
  3. After processing all commands, check if both coordinates are back to zero (`x == 0 && y == 0`).

  NOTES:
  - This approach avoids storing history or path arrays, running in constant memory.
  - The loop assumes only valid inputs ('U', 'D', 'R', 'L') are supplied.

  COMPLEXITY:
  - Time: O(n) -> Where n is the length of the string `moves`. We scan the string once.
  - Space: O(1) -> Only uses two primitive integer tracking counters.

*/

class Solution
{
public:
  bool judgeCircle(string moves)
  {
    int len = moves.length();
    int x = 0, y = 0;

    for (int i = 0; i < len; i++)
    {
      if (moves[i] == 'U')
        x++;
      else if (moves[i] == 'D')
        x--;
      else if (moves[i] == 'R')
        y++;
      else
        y--; // Assumes moves only contain 'U', 'D', 'L', 'R'
    }

    return x == 0 && y == 0;
  }
};