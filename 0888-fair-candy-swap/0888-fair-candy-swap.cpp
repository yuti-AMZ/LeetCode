class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sumA = 0, sumB = 0;
    for (int x : A) sumA += x;
    for (int x : B) sumB += x;

    int delta = (sumA - sumB) / 2; 

    unordered_set<int> setB(B.begin(), B.end());

    for (int x : A) {
        int y = x - delta;
        if (setB.count(y)) {
            return {x, y};
        }
    }

    return {}; 
}

};