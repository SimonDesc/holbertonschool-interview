#!/usr/bin/python3
def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize the DP table with a large value (total + 1 is a safe large value)
    dp = [total + 1] * (total + 1)
    dp[0] = 0  # Base case: no coins needed to make a total of 0

    # Fill the DP table
    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If dp[total] is still total + 1, it means it's not possible to make the total
    return dp[total] if dp[total] != total + 1 else -1
