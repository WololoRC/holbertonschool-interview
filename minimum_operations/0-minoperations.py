#!/usr/bin/python3
"""Minimum operatios"""

if __name__ != "__main__":
    def divisors(n):
        """Get a list of divisors"""

        return [item for item in range(2, n) if n % item == 0]

    def minOperations(n):
        """
        Calulates number of operations to reach 'n'
        """

        try:
            cnt = divisors(n)[1]
        except IndexError:
            cnt = divisors(n)[0]

        return cnt + (n // cnt)
