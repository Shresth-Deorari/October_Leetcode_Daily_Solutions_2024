class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = 0;
        for(auto i : skill)sum += i;
        if((sum*2)%n !=0)return -1;
        int d = (sum*2)/n;
        sort(skill.begin(),skill.end());
        int i = 0,j = n-1;
        long long ans = 0;
        while(i<=j){
            if(skill[i]+skill[j]  != d)return -1;
            ans += ((skill[i++]*1ll)*skill[j--]);
        }
        return ans;
    }
};