class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1>len2)return false;
        vector<int>a1(26,0);
        vector<int>a2(26,0);
        for(auto i : s1){
            a1[i-'a']++;
        }
        int j = 0;
        int window_size=0;
        for(int i= 0;i<len2;i++){
                a2[s2[i]-'a']++;
                window_size++;
            if(window_size==len1){
                if(a1==a2)return true;
                a2[s2[j]-'a']--;
                j++;
                window_size--;
            }
        }
        if(window_size == len1){
                if(a1==a2)return true;
            }
            return false;
    }
};