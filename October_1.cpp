class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for(auto &i : arr){
            i = (i%k +k) % k;
        }        
        unordered_map<int,int>mp;
        for(auto i : arr)mp[i]++;
        if(mp[0]&1)return false;
        for(int i = 1;i<=k/2;i++){
            if(mp[i]!=mp[k-i])return false;
        }
        return true;
    }
};