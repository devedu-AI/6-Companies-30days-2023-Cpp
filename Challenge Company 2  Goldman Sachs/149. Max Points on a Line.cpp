class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int Max = 1;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> map;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                double ans;
                double dely = points[j][1]-points[i][1];
                double delx = points[j][0]-points[i][0];
                ans=dely/delx;
                map[ans]++;
            }
            for(auto i:map){
              Max=max(Max,(i.second+1));
            }
        }
        return Max;
    }
};
