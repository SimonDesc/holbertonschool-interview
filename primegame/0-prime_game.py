#!/usr/bin/python3
"""
This module contains the solution for the Prime Game problem.
"""

def isWinner(x, nums):
    """
    Determine the winner of multiple rounds of the Prime Game.

    Args:
        x (int): The number of rounds to play.
        nums (list of int): A list of n values for each round.

    Returns:
        str or None: The name of the player who won the most rounds
                     ("Maria" or "Ben"), or None if it's a tie.
    """
    def sieve_of_eratosthenes(n):
        primes = [True] * (n + 1)
        primes[0] = primes[1] = False
        for i in range(2, int(n**0.5) + 1):
            if primes[i]:
                for j in range(i*i, n + 1, i):
                    primes[j] = False
        return primes

    def play_game(n):
        primes = sieve_of_eratosthenes(n)
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            if primes[i]:
                dp[i] = dp[i-1] + 1
            else:
                dp[i] = dp[i-1]
        return dp[n] % 2 == 1

    if not nums or x <= 0:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n <= 1:
            ben_wins += 1
        elif play_game(n):
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
