#!/usr/bin/python3

""" Module that returns perimeter of the island """


def island_perimeter(grid):
    """
    calculate the perimeter of the island

    Args: grid(list[list[int]])

    Returns: int
    """
    if not grid or not grid[0]:
        return 0
    rws = len(grid)
    cols = len(grid[0])
    per = 0

    for rw in range(rws):
        for col in range(cols):
            if grid[rw][col] == 1:
                per = per + 4

                if rw > 0 and grid[rw - 1][col] == 1:
                    per = per - 1
                if rw < rws - 1 and grid[rw + 1][col] == 1:
                    per = per - 1
                if col > 0 and grid[rw][col - 1] == 1:
                    per = per - 1
                if col < cols - 1 and grid[rw][col + 1] == 1:
                    per = per - 1
    return per
