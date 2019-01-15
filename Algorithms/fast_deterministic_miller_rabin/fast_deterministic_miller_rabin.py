def is_prime(n):
    """
    Deterministic variant of the Miller-Rabin primality test to determine
    whether a given number is prime.

    Parameters
    ----------
    n : int
        n >= 0, an integer to be tested for primality.

    Returns
    -------
    bool
        False if n is composite, otherwise True.
    """
    if n in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        return True

    if (n in [0, 1]) or (any((n % p) == 0 for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37])):
        return False

    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1

    def try_composite(x):
        if pow(x, d, n) == 1:
            return False
        for i in range(s):
            if pow(x, 2**i * d, n) == n - 1:
                return False
        return True

    return not any(try_composite(w) for w in [2, 325, 9375, 28178, 450775, 9780504, 1795265022])
    
