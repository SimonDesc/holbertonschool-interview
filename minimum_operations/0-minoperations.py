#!/usr/bin/python3
"""
Ce script permet de résoudre le challenge Minimum Operations
"""


def minOperations(n):
    """
    The function `minOperations` calculates the minimum number of operations
    required to reduce a given number `n` to 1 by repeatedly dividing it by
    its smallest prime factor.
    :param n: The parameter `n` represents a positive integer for which
    we want to find the minimum number of operations required to reduce
    it to 1
    :return: the total number of operations required to reduce the given
    number 'n'
    to 1.
    """
    if n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        # On regarde si on a un reste
        while n % factor == 0:
            # Sinon on ajoute le nombre d'operations
            operations += factor
            # On réduit n en le divisant par ses facteurs
            n //= factor
        factor += 1

    return operations
