auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        for(auto i : s){
            if(i=='['){
                count++;
            }
            else{
            if(count)count--;
            }
        }
        return (count+1)/2;
    }
};