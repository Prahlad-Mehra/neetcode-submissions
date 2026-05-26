class Solution {
public:
    int checkBoxNum(int i,int j){
        int ans=-1;
        if(i<=2){
            if(j<=2) ans= 0;
            else if(j<=5) ans= 1;
            else ans= 2;
        } 
        else if(i>2 && i<=5){
            if(j<=2) ans= 3;
            else if(j<=5) ans= 4;
            else ans= 5;
        }
        else{
            if(j<=2) ans= 6;
            else if(j<=5) ans= 7;
            else ans= 8;
        }
        return ans;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,bool>> row(9);
        vector<unordered_map<char,bool>> col(9);
        vector<unordered_map<char,bool>> box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char curr=board[i][j];
                if(curr=='.') continue;
                int boxNum= checkBoxNum(i,j);
                if(row[i][curr]) return false;
                if(col[j][curr]) return false;
                if(box[boxNum][curr]) return false;
                row[i][curr]= true;
                col[j][curr]= true;
                box[boxNum][curr]= true;
            }
        }
        return true;
    }
};