// https://leetcode.com/problems/surrounded-regions/


class Solution {
	public:
		void dfs(vector<vector<char>> &board,int row,int col)
    {
	//to check if the current position is inside the board and is an 'O'
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 'O') return;
		// if current is an 'O' , we change it to 'T' to mark
		//it as member of non-surrounded region
        board[row][col] = 'T';
		
		//recursive call to dfs for up,down,left and right
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
		
		//checking on left and right
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][m-1] == 'O') dfs(board,i,m-1);
        }
        
		//checking on up and down
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i] == 'O') dfs(board,0,i);
            if(board[n-1][i] == 'O') dfs(board,n-1,i);
        }
        
		
		//changing every 'T' to 'O' and every 'O' to 'X'
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        
    }
		
};
