class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans = 0;
        for(auto i : nums)pq.push(i);
        for(int i = 0;i<k;i++){
            int curr = pq.top();
            pq.pop();
            pq.push(((curr+2)/3));
            ans += curr;
        }
        return ans;
    }
};