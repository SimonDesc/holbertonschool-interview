#!/usr/bin/python3
"""
0-rain
"""
# [0, 1, 0, 2, 0, 3, 0, 4]


def rain(walls):
    """Return: Integer indicating total amount of rainwater retained."""
    sum = 0
    total_sum = 0
    for i in range(0, len(walls)):
        if walls[i] != 0:
            sum = sum + walls[i]
        if (i+1 < len(walls)):
            if walls[i+1] != 0:
                total_sum += sum
                sum = 0
    return total_sum
