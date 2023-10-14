class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));

    int left = 0, top = 0, right = n - 1, bottom = n - 1;
    int cnt = 1;

    while (left <= right && top <= bottom){

        // upper row
        for (int i = left; i <= right; ++i){
            m[top][i] = cnt++;
        }
        top++;

        // right col
        for (int i = top; i <= bottom; ++i){
            m[i][right] = cnt++;
        }
        right--;

        // bottom row
        for (int i = right; i >= left; --i){
            m[bottom][i] = cnt++;
        }
        bottom--;

        // left col
        for (int i = bottom; i >= top; --i){
            m[i][left] = cnt++;
        }
        left++;

      }
    return m;
        
    }
};