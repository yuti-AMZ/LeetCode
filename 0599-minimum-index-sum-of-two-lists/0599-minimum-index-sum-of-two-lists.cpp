class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        for (int i = 0; i < list1.size(); i++) {
            indexMap[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int i = 0; i < list2.size(); i++) {
            if (indexMap.find(list2[i]) != indexMap.end()) {
                int sumIndex = i + indexMap[list2[i]];
                if (sumIndex < minSum) {
                    result.clear();
                    result.push_back(list2[i]);
                    minSum = sumIndex;
                } else if (sumIndex == minSum) {
                    result.push_back(list2[i]);
                }
            }
        }

        return result;
    }
};