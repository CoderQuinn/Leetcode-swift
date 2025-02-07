class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for (int k = 0; k < n * m; k++)
        {
            int val = matrix[x][y];
            ans.push_back(val);
            st[x][y] = true;

            int i = x + dx[d];
            int j = y + dy[d];
            if (i < 0 || i >= n || j < 0 || j >= m || st[i][j])
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