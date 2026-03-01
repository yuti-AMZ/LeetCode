class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        
        prev2 = 1  # dp[0]
        prev1 = 1  # dp[1]
        
        for i in range(1, len(s)):
            current = 0
            
            # Single digit check
            if s[i] != '0':
                current += prev1
            
            # Two digit check
            two_digit = int(s[i-1:i+1])
            if 10 <= two_digit <= 26:
                current += prev2
            
            prev2 = prev1
            prev1 = current
        
        return prev1