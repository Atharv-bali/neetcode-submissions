class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> mpp;
    CountSquares() {
    }
    
    void add(vector<int> point) {
        mpp[point[0]][point[1]]++; //O(1)
    }
    
    int count(vector<int> point) { //O(n)
        int res = 0;
        int x1 = point[0], y1 = point[1];
        for(auto &it:mpp[x1]) {
            int y2 = it.first;
            int cnt = it.second;
            int side = y2-y1;
            if(side == 0) continue;
            int x3 = x1+side;
            int x4 = x1-side;
            res += cnt*mpp[x3][y1]*mpp[x3][y2];
            res += cnt*mpp[x4][y1]*mpp[x4][y2];
        }
        return res;
    }
};
//Time complexity :O(n)
//Space complexity :O(n)