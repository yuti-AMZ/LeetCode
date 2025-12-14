class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        result = []
        
        for word in words:
            if not result:
                result.append(word)
            else:
                if sorted(word) != sorted(result[-1]):
                    result.append(word)
        
        return result
