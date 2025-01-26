#include<vector>
#include<iostream>

using namespace std;

class GameOfLife 
{
public:
    void init(vector<vector<int>>& board) 
    {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> copy_board(rows,vector<int>(cols));
        for(int i = 0; i < rows;i++)
        {    
            for(int j = 0; j < cols; j++)
            {
                int count_neighbors = (i-1>=0?board[i-1][j]:0) + (i+1<rows?board[i+1][j]:0)+
                             (j-1>=0?board[i][j-1]:0) + (j+1<cols?board[i][j+1]:0) +
                             ((i-1>=0 && j-1>=0)?board[i-1][j-1]:0) + 
                             ((i-1>=0 && j+1<cols)?board[i-1][j+1]:0) +
                             ((i+1<rows && j-1>=0)?board[i+1][j-1]:0) + 
                             ((i+1<rows && j+1<cols)?board[i+1][j+1]:0);
                cout<<count_neighbors<<" ";
                if(board[i][j]==1)
                {
                    if(count_neighbors < 2)
                        copy_board[i][j] = 0;

                    else if(count_neighbors == 2 or count_neighbors == 3)
                        copy_board[i][j] = 1;

                    else if(count_neighbors > 3)
                        copy_board[i][j] = 0;
                }
                
                else if(count_neighbors == 3 and board[i][j]==0)
                    copy_board[i][j] = 1;                  
            }   
        }
        board=move(copy_board);
    }
};