#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """Return: Integer indicating total amount of rainwater retained."""
    n = len(walls)
    if n == 0:
        return 0

    left = [0] * n
    right = [0] * n

    # Fill left array
    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    # Fill right array
    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    # Calculate trapped water
    trappedWater = 0
    for i in range(n):
        trappedWater += min(left[i], right[i]) - walls[i]

    return trappedWater
