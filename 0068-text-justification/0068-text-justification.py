class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        i = 0
        
        while i < len(words):
            line_len = len(words[i])
            j = i + 1
            
            while j < len(words) and line_len + 1 + len(words[j]) <= maxWidth:
                line_len += 1 + len(words[j])
                j += 1
            
            num_words = j - i
            line = ""
            
            if j == len(words) or num_words == 1:
                line = " ".join(words[i:j])
                line += " " * (maxWidth - len(line))

            else:
                total_spaces = maxWidth - sum(len(word) for word in words[i:j])
                spaces_between = num_words - 1
                space = total_spaces // spaces_between
                extra = total_spaces % spaces_between
                
                for k in range(spaces_between):
                    line += words[i + k]
                    line += " " * (space + (1 if k < extra else 0))
                
                line += words[j - 1]
            
            res.append(line)
            i = j
        
        return res
