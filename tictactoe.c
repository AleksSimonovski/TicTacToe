#include <stdio.h>
#include <stdlib.h>

void InitializeBoard(int m,int n,char board[][n]){
    int c=1,i,j;
    for (i=0;i<m;i++){
        for(j=0;j<n;j++){
            board[i][j]=c+'0';
            c++;
        }
    }
}

//fucntion that creates the base grid for your tic-tac-toe game
void PrintBoard(int m,int n,char board[][n]){
    int i,j;
    for (i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf(" %c ",board[i][j]);
            if(j==n-1){
                printf("\n");
            }
            else{
                printf("|");
            }
        }
        if(i!=m-1){
            printf("___|___|___\n");
        }
    }
}

//function that takes your inputs into the board
void CreateBoard(int m,int n,char board[][n]){
    int choice=1,cell=0;
    char input='X';
    while(choice){
        printf("Enter the cell you want to enter X or O :");
        scanf(" %d",&cell);
        while(cell>10 || cell<0){
            printf("Enter a valid input :");
            scanf(" %d",&cell);
        }
        printf("Enter X or O : ");
        scanf(" %c",&input);
        while(!(input=='X' || input=='O')){
            printf("Enter a valid input :");
            scanf(" %c",&input);
        }

        if(cell==1)
        board[0][0]=input;
        
        if(cell==2)
        board[0][1]=input;
        
        if(cell==3)
        board[0][2]=input;

        if(cell==4)
        board[1][0]=input;

        if(cell==5)
        board[1][1]=input;

        if(cell==6)
        board[1][2]=input;

        if(cell==7)
        board[2][0]=input;

        if(cell==8)
        board[2][1]=input;

        if(cell==9)
        board[2][2]=input;

        printf("Do you want to add more?(1 for yes, 0 for no) : ");
        scanf("%d",&choice);
        while(!(choice==0 || choice==1)){
            printf("Enter a valid input :");
            scanf(" %d",&choice);
        }
    }
}

//function that check whether you board is valid or not
int IsValidBoard(int m,int n,char board[][n]){
    int countx=0,counto=0,i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(board[i][j]=='X'){
                countx+=1;
            }
            if(board[i][j]=='O'){
                counto+=1;
            }
        }
    }
    int diff=countx-counto;
    if(abs(diff)==0 || abs(diff)==1){
        return 1;
    }
    else{
        return 0;
    }
}

//function that checks all possible winning scenarios
void ListWinningCells(int m,int n,char board[][n]){

    if(board[0][0]==board[0][1] && board[0][2]=='3')
    printf("%c %c\n",board[0][1],board[0][2]);
    if(board[1][0]==board[1][1] && board[1][2]=='6')
    printf("%c %c\n",board[1][1],board[1][2]);
    if(board[2][0]==board[2][1] && board[2][2]=='9')
    printf("%c %c\n",board[2][1],board[2][2]);
    
    if(board[0][2]==board[0][1] && board[0][0]=='1')
    printf("%c %c\n",board[2][1],board[2][2]);
    if(board[1][2]==board[1][1] && board[1][0]=='4')
    printf("%c %c\n",board[2][1],board[2][2]);
    if(board[2][2]==board[2][1] && board[2][0]=='7')
    printf("%c %c\n",board[2][1],board[2][2]);
    
    if(board[0][0]==board[0][2] && board[0][1]=='2')
    printf("%c %c\n",board[0][2],board[0][1]);
    if(board[1][0]==board[1][2] && board[1][1]=='5')
    printf("%c %c\n",board[1][2],board[1][1]);
    if(board[2][0]==board[2][2] && board[2][1]=='8')
    printf("%c %c\n",board[2][2],board[2][1]);
    
    if(board[0][0]==board[1][0] && board[2][0]=='7')
    printf("%c %c\n",board[1][0],board[2][0]);
    if(board[0][1]==board[1][1] && board[2][1]=='8')
    printf("%c %c\n",board[1][1],board[2][1]);
    if(board[0][2]==board[1][2] && board[2][2]=='9')
    printf("%c %c\n",board[1][2],board[2][2]);
    
    if(board[0][0]==board[2][0] && board[1][0]=='5')
    printf("%c %c\n",board[2][0],board[1][0]);
    if(board[0][1]==board[2][1] && board[1][1]=='6')
    printf("%c %c\n",board[2][1],board[1][1]);
    if(board[0][2]==board[2][2] && board[1][2]=='7')
    printf("%c %c\n",board[2][2],board[1][2]);
    
    if(board[1][0]==board[2][0] && board[0][0]=='1')
    printf("%c %c\n",board[1][0],board[0][0]);
    if(board[1][1]==board[2][1] && board[0][1]=='2')
    printf("%c %c\n",board[1][1],board[0][1]);
    if(board[1][2]==board[2][2] && board[0][2]=='3')
    printf("%c %c\n",board[1][2],board[0][2]);
    
    if(board[0][0]==board[1][1] && board[2][2]=='9')
    printf("%c %c\n",board[1][1],board[2][2]);
    if(board[2][0]==board[1][1] && board[0][2]=='3')
    printf("%c %c\n",board[1][1],board[0][2]);
    
    if(board[2][2]==board[1][1] && board[0][0]=='1')
    printf("%c %c\n",board[1][1],board[0][0]);
    if(board[0][2]==board[1][1] && board[2][0]=='7')
    printf("%c %c\n",board[1][1],board[2][0]);
    
    if(board[0][0]==board[2][2] && board[1][1]=='5')
    printf("%c %c\n",board[2][2],board[1][1]);
    if(board[2][0]==board[0][2] && board[1][1]=='5')
    printf("%c %c\n",board[0][2],board[1][1]);

}

//implementing all functions into a main for the user to play tic-tac-toe
int main(){
    int m=3,n=3,test;
    char board[m][n],choice='a';
    InitializeBoard(m,n,board);
    while(choice!='e'){
        printf("press 'p' to print the tic-tac-toe board\n");
        printf("press 'c' to create a tic-tac-toe board with some X and O cells\n");
        printf("press 't' to test if a tic-tac-toe board is valid or invalid board\n");
        printf("press 'w' to predict winning cell for player X or O\n");
        printf("press 'e' to exit\n");
        scanf(" %c",&choice);
        
        switch(choice){
            
        case 'p': PrintBoard(m,n,board);
        break;
        case 'c': CreateBoard(m,n,board);
        break;
        case 't': test = IsValidBoard(m,n,board);
        if(test)
        printf("Valid board!!\n");
        else
        printf("Invalid board!!\n");
        break;
        case 'w': ListWinningCells(m,n,board);
        break;
        case 'e': break;
        default: printf("Enter a valid input: ");
        
        }
        printf("\n");
    }
}