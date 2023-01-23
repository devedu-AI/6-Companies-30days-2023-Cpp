class Solution {
public:
    string customSortString(string order, string s) {
        map<int,char> mp1;
        map<char,int> mp2;
        
        for(int i=0;i<order.length();i++){
            mp1[i]=order[i];
            mp2[order[i]]=i;
        }
        
        int custom = 27;
        vector<int> vec;
        for(int i=0;i<s.length();i++){
            if(mp2.count(s[i])>=1) vec.push_back(mp2[s[i]]);
            else{
                mp1[custom]=s[i];
                mp2[s[i]]=custom;
                vec.push_back(custom);
                custom++;
            }
        }
        
        sort(vec.begin(),vec.end());
        
        string ans;
        for(auto it:vec){
            ans+=mp1[it];
        }
        
        return ans;
        
    }
};
