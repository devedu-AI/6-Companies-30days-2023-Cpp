class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> map;
        int ans = 0;
        int left = 0;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
            while(map.size()==3){
                ans+=1;
                ans+=(s.length()-1-i);
                map[s[left]]--;
                if(map[s[left]]==0) map.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
