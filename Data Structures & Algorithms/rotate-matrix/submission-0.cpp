class Solution {
public:
    void transpose(vector<vector<int>> &matrix) {
        for(int i=0;i<matrix.size();i++) {
            for(int j=i+1;j<matrix[0].size();j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int i=0,j=matrix.size()-1,k=0;
        while(i<j) {
            for(int k=0;k<m;k++) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = temp;
            }
            i++;
            j--;
        }
        return transpose(matrix);
    }
};
//Time complexity: O(n*m)
//Space complexity: O(1)