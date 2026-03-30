class Solution:
    def restoreIpAddresses(self, s: str):
        result = []

        def backtrack(start, path):
            # If we have 4 parts and used all characters
            if len(path) == 4 and start == len(s):
                result.append(".".join(path))
                return
            
            # Invalid case
            if len(path) == 4 or start == len(s):
                return
            
            # Try 1 to 3 digits
            for length in range(1, 4):
                if start + length > len(s):
                    break
                
                segment = s[start:start + length]
                
                # Leading zero check
                if len(segment) > 1 and segment[0] == '0':
                    continue
                
                # Range check
                if int(segment) > 255:
                    continue
                
                backtrack(start + length, path + [segment])

        backtrack(0, [])
        return result