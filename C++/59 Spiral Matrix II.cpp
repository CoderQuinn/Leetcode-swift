class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<bool>> st(n, vector<bool>(n, false));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for (int k = 1; k <= n * n; k++)
        {
            ans[x][y] = k;
            st[x][y] = true;

            int i = x + dx[d];
            int j = y + dy[d];
            if (i < 0 || i >= n || j < 0 || j >= n || st[i][j])
            {
                d = (d + 1) % 4;
                i = x + dx[d];
                j = y + dy[d];
            }
            x = i, y = j;
        }

        return ans;
    }
};