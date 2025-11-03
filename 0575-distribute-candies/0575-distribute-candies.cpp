class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        int n = candyType.size() / 2;
        return min(n, (int)uniqueCandies.size());
    }
};