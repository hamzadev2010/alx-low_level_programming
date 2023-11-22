#!/usr/bin/python3
""" Function island_perimeter """


def island_perimeter(grid):
    """
    returns the perimeter of island that was described in grid
    """
    era = 0
    """ 0 describe the specific era.  1 represents a land era"""
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i < len(grid) - 1 and grid[i + 1][j]:
                    era += 1
                if i > 0 and grid[i - 1][j]:
                    era += 1
                if j < len(grid[i]) - 1 and grid[i][j + 1]:
                    era += 1
                if j > 0 and grid[i][j - 1]:
                        era += 1
                era -= 4
    era = era * - 1
    return era
