class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;
    
    for (int num : arr) {
        // Check if double or half exists in the set
        if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}
};