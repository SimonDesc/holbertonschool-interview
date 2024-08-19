#!/usr/bin/python3
""" Module for Pascal's triangle """


def pascal_triangle(numRows):
    """ Returns list of lists of ints representing Pascal triangle of n """

    result = []
    if numRows == 0:
        return result

    first_row = [1]
    result.append(first_row)

    for i in range(1, numRows):
        prev_row = result[i - 1]
        current_row = [1]

        for j in range(1, i):
            current_row.append(prev_row[j - 1] + prev_row[j])

        current_row.append(1)
        result.append(current_row)

    return result
