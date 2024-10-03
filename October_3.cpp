class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) return 0;  // Already divisible by p, no need to remove any subarray
        
        unordered_map<int, int> prefixMap; // To store prefix mod p and its last index
        prefixMap[0] = -1;  // Edge case to handle subarrays starting from index 0
        int currentPrefix = 0;
        int minLength = nums.size();
        int targetRemainder = totalSum;  // We want to find subarray with this remainder
        
        for (int i = 0; i < nums.size(); i++) {
            currentPrefix = (currentPrefix + nums[i]) % p;
            int desiredPrefix = (currentPrefix - targetRemainder + p) % p;
            
            // If this desired prefix has been seen before, we found a valid subarray
            if (prefixMap.find(desiredPrefix) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[desiredPrefix]);
            }
            
            // Update the map with the current prefix
            prefixMap[currentPrefix] = i;
        }
        
        return (minLength == nums.size()) ? -1 : minLength;  // If not found, return -1
    }
};
