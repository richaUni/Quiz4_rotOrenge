class Solution {
public:
    int orangesRotting(vector<vector<int>>& A) {
        queue<array<int,3>> q;
        int m = A.size(), n = A[0].size();
        bool fresh = false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 2) q.push({i, j, 0});
                if(A[i][j] == 1) fresh = true;
            }
        if(fresh && q.empty()) return -1;
        int mx = 0;
        int dir[5] = {1, 0, -1, 0, 1};
        while(!q.empty()) {
            auto [xi, yi, time] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = dir[i] + xi, y = dir[i+1] + yi;
                if(x < m && y < n && x >= 0 && y >=0 && A[x][y] == 1) {
                    mx = max(mx, time+1);
                    q.push({x, y, time+1});
                    A[x][y] = 2;
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                if(A[i][j] == 1) return -1;
        return mx;
    }
};
