class Solution {
public:
     int distanceM(int x1, int y1, int x2, int y2)
      {
          return pow(x2 - x1, 2) + pow(y2 - y1, 2);
     }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>points{p1,p2,p3,p4};
        unordered_set<int> s;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                s.insert(distanceM(points[i][0],points[i][1],points[j][0],points[j][1]));
            }
        }
        return !s.count(0)&&s.size()==2;
        
        
    }
};
