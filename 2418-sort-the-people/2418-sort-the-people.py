class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        people = list(zip(heights, names))
        
        # Sort by height (descending)
        people.sort(reverse=True)
        
        return [name for _, name in people]