class Solution {
public:
    vector<int> ans;
    void SieveOfEratosthenes(int m,int n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
     
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
     
        // Print all prime numbers
        for (int p = m; p <= n; p++) if (prime[p]==true) ans.push_back(p);
    }   
    vector<int> closestPrimes(int left, int right) {
        if(left==1) left++;
        SieveOfEratosthenes(left,right);
        int mini = INT_MAX;
        pair<int,int> p = {-1,-1};
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]-ans[i-1] < mini){
                mini = ans[i]-ans[i-1];
                p.first = ans[i-1];
                p.second = ans[i];
            }
        }
        
        return {p.first,p.second};
    }
};
