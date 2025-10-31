class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> copy = board;
        vector<int> dir = {-1, 0, 1};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int dx : dir)
                    for (int dy : dir)
                        if (!(dx == 0 && dy == 0)) {
                            int x = i + dx, y = j + dy;
                            if (x >= 0 && x < m && y >= 0 && y < n && copy[x][y] == 1) live++;
                        }
                if (copy[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 0;
                if (copy[i][j] == 0 && live == 3) board[i][j] = 1;
            }
    }
};
