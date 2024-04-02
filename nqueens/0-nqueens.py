#!/usr/bin/python3
import sys


def input_validation():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)


def solve_n_queens(n):
    def is_safe(board, row, col):
        for i in range(row):
            if board[i] == col or \
               board[i] - i == col - row or \
               board[i] + i == col + row:
                return False
        return True

    def solve(board, row):
        if row == n:
            solutions.append([[i, board[i]] for i in range(n)])
            return
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                solve(board, row + 1)
                board[row] = -1  # Backtrack

    solutions = []
    solve([-1] * n, 0)
    return solutions


def print_solutions(solutions):
    for solution in solutions:
        print(solution)


def main():
    input_validation()
    n = int(sys.argv[1])
    solutions = solve_n_queens(n)
    print(f"Found {len(solutions)} solutions for {n} Queens:")
    print_solutions(solutions)


if __name__ == "__main__":
    main()
