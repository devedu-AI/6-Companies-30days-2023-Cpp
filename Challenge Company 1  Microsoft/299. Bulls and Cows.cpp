class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cows = 0;
        unordered_map<char,int> map;
        for(int i=0;i<guess.length();i++){
            if(secret[i]==guess[i]){
                bull++;
                guess[i]='#';
            }
            else{
                map[secret[i]]++;
            }
        }
        for(int i=0;i<guess.length();i++){
            if(guess[i]=='#') continue;
            if(map.count(guess[i])>0){
                cows++;
                map[guess[i]]--;
                if(map[guess[i]]==0) map.erase(guess[i]);
            }
        }
        string ans = "";
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        
        return ans;
    }
};
