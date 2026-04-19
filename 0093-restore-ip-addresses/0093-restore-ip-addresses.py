class Solution:
    def restoreIpAddresses(self, s: str):
        result = []

        def backtrack(start, path):
            
            if len(path) == 4 and start == len(s):
                result.append(".".join(path))
                return
            
          
            if len(path) == 4 or start == len(s):
                return
            
           
            for length in range(1, 4):
                if start + length > len(s):
                    break
                
                segment = s[start:start + length]
                
               
                if len(segment) > 1 and segment[0] == '0':
                    continue
                
               
                if int(segment) > 255:
                    continue
                
                backtrack(start + length, path + [segment])

        backtrack(0, [])
        return result