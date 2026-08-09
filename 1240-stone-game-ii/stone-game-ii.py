from functools import lru_cache
from typing import List

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        # suffix[i] = sum of piles[i:]
        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        @lru_cache(None)
        def dp(i, M):
            # We can take all remaining piles
            if i + 2 * M >= n:
                return suffix[i]

            ans = 0

            for X in range(1, 2 * M + 1):
                next_M = max(M, X)

                # Total remaining - what the opponent can get
                current = suffix[i] - dp(i + X, next_M)

                ans = max(ans, current)

            return ans

        return dp(0, 1)