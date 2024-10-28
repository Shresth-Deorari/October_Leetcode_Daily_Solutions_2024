class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        nums.assign(uniqueElements.begin(), uniqueElements.end());
        sort(nums.begin(), nums.end());

        vector<bool> visited(nums.size(), false);
        int maxLength = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            int count = 1;
            long long current = nums[i];
            while (true) {
                long long nextSquare = current * current;
                auto it = lower_bound(nums.begin(), nums.end(), nextSquare);
                
                if (it == nums.end() || *it != nextSquare) break;
                int index = it - nums.begin();
                visited[index] = true;

                current = nextSquare;
                count++;
            }
            maxLength = max(maxLength, count);
        }

        return maxLength < 2 ? -1 : maxLength;
    }
};
