#!/usr/bin/python3
def makeChange(coins, total):
    """
    The `makeChange` function uses dynamic programming to find the minimum number of coins needed to
    make a given total amount using a given set of coin denominations.
    
    :param coins: Coins is a list of coin denominations available for making change. Each element in the
    list represents the value of a coin that can be used. For example, if coins = [1, 2, 5], it means
    you have coins of denominations 1, 2, and
    :param total: The `total` parameter in the `makeChange` function represents the total amount of
    money that needs to be made using the available coins. The function aims to find the minimum number
    of coins needed to make the total amount specified
    :return: The function `makeChange(coins, total)` returns the minimum number of coins needed to make
    the given `total` amount using the provided `coins`. If it is not possible to make the total amount
    with the given coins, the function returns -1.
    """
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
