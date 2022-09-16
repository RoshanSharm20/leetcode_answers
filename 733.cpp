// question is solved using recursion

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int init)
    {
        if (sr == image.size() || sc == image[0].size() || sr < 0 || sc < 0 || image[sr][sc] == color)
            return;
        if (image[sr][sc] != init)
            return;
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, color, init);
        dfs(image, sr - 1, sc, color, init);
        dfs(image, sr, sc - 1, color, init);
        dfs(image, sr, sc + 1, color, init);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};