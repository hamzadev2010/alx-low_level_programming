#!/usr/bin/python3
"""Function island_perimeter"""


def island_perimeter(grid):
"""return all param of island that was decribed in grid

Args:grid list: the grid
    """
k, c = len(grid), len(grid[0])
island, house = 0, 0
for i in range(k):
for j in range(c):
if grid[i][j] == 1:
island += 1
if i < k - 1 and grid[i+1][j] == 1:
house += 1
if j < c - 1 and grid[i][j + 1] == 1:
house += 1
return island * 4 - 2 * house
