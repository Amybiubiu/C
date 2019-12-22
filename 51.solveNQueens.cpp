class Solution {
public:
    void resolution(int n,int row,vector<bool>& col,vector<bool>& diag1,vector<bool>& diag2,vector<vector<string>>& res,vector<string>& temp){
        if(n == row ){
            res.push_back(temp);
            return;
        }
       
        for(auto col_ = 0;col_<n;col_++){
             int ll = row + col_;
             int rr = row - col_+n-1;
        
        if(col[col_] && diag1[ll] && diag2[rr]){
                temp[row][col_] = 'Q';
                col[col_] = false;
                diag1[ll] = false;
                diag2[rr] = false;

                resolution(n, row+1, col, diag1, diag2, res, temp);

                temp[row][col_] = '.';
                col[col_] = true;
                diag1[ll] = true;
                diag2[rr] = true;
    
        }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        vector<bool> cols_(n, true);
        vector<bool> diag1s_(n, true);
        vector<bool> diag2s_(2*n-1, true);
        
        resolution(n,0,cols_,diag1s_,diag2s_,res,temp);
        return res;
    }
};