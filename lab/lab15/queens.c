#include<stdio.h>
#include<string.h>
int n;
int safe(int row,int col,int usedcols[],int useddiags1[],int useddiags2[]){
    if(usedcols[col] || useddiags1[row+col] || useddiags2[n-1+row-col]){
        return 0;
    }
    return 1;
}
void place_queen(int board[n][n],int row,int col,int usedcols[],int useddiags1[],int useddiags2[]){
    board[row][col]=1;
    usedcols[col]=1;
    useddiags1[row+col]=1;
    useddiags2[n-1+row-col]=1;
}
void remove_queen(int board[n][n],int row,int col,int usedcols[],int useddiags1[],int useddiags2[]){
    board[row][col]=0;
    usedcols[col]=0;
    useddiags1[row+col]=0;
    useddiags2[n-1+row-col]=0;
}
int solve(int board[n][n],int row,int usedcols[],int useddiags1[],int useddiags2[]){
    if(row==n){
        return 1;
    }
    int count=0,i;
    for(i=0;i<n;i++){
        if(safe(row,i,usedcols,useddiags1,useddiags2)){
            place_queen(board,row,i,usedcols,useddiags1,useddiags2);
            count+=solve(board,row+1,usedcols,useddiags1,useddiags2);
            remove_queen(board,row,i,usedcols,useddiags1,useddiags2);
        }
    }
    return count;
}
int solve_queen(int board[n][n]){
    int used_cols[n], used_diags1[2*n], used_diags2[2*n];
    memset(used_cols,0,sizeof(used_cols));
    memset(used_diags1,0,sizeof(used_diags1));
    memset(used_diags2,0,sizeof(used_diags2));
    return solve(board,0,used_cols,used_diags1,used_diags2);
}
int main(){
    int i,j;
    printf("Enter the size of the board: ");
    scanf("%d",&n);
    int board[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    printf("The solution exists: %d\n",solve_queen(board));
}