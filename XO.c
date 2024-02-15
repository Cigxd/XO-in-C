#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
void printingbackground(char array[3][3],int rows_or_collumns,int rows,int collumns){
    for(int i=0;i<=rows_or_collumns-1;i++){
        for(int j=0;j<=rows_or_collumns-1;j++){
            printf("|%c|", array[i][j]);
        }
        printf("\n");
        if(i<2){
        printf("---------\n");
        }
    }
}
void makingmove1(char array[3][3],int rows_or_collumns,int rows,int collumns){
    array[rows][collumns] = 'X';
}
void makingmove2(char array[3][3],int rows_or_collumns,int rows,int collumns){
    array[rows][collumns] = 'O';
}
int main(){
    int counter = 0;
    bool playerdone = 0;
    bool gameover = 0;
    char array[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int size = sizeof(array)/sizeof(array[0][0]);
    int rows_or_collumns = sizeof(array)/sizeof(array[0]);
    int rows,collumns;
    
badmove:
    printingbackground(array,rows_or_collumns,rows,collumns);
next:///careful
    printf("enter the row : ");
    scanf("%i", &rows);
    printf("enter the collumn : ");
    scanf("%i", &collumns);

    if((rows<=3)&&(collumns<=3)&&array[rows][collumns] == ' '){
        printf("your move was (%i,%i)\n", rows, collumns);
        if(playerdone == 0){
        makingmove1(array,rows_or_collumns,rows,collumns);
        }
        else if(playerdone == 1){
        makingmove2(array,rows_or_collumns,rows,collumns);
        }
        counter++;
    }else{
        system("cls");
        printf("invalid move, try again\n");
        goto badmove;
    }
    system("cls");
    printingbackground(array,rows_or_collumns,rows,collumns);
        if(playerdone == 0){
            playerdone = 1;
        }else{
            playerdone = 0;
        }
        
        
        ///checking if the game is done
        if((array[0][0] == 'X'&&array[0][1] == 'X'&&array[0][2] == 'X') ^ (array[0][0] == 'O'&&array[0][1] == 'O'&&array[0][2] == 'O') ^ ///XXX or OOO
           (array[0][0] == 'X'&&array[1][1] == 'X'&&array[2][2] == 'X') ^ (array[0][0] == 'O'&&array[1][1] == 'O'&&array[2][2] == 'O') ^ ///leftX midX bot X
           (array[0][2] == 'X'&&array[1][1] == 'X'&&array[2][0] == 'X') ^ (array[0][2] == 'O'&&array[1][1] == 'O'&&array[2][0] == 'O') ^
           (array[2][0] == 'X'&&array[2][1] == 'X'&&array[2][2] == 'X') ^ (array[2][0] == 'O'&&array[2][1] == 'O'&&array[2][2] == 'O') ^
           (array[0][0] == 'X'&&array[1][0] == 'X'&&array[2][0] == 'X') ^ (array[0][0] == 'O'&&array[1][0] == 'O'&&array[2][0] == 'O') ^
           (array[0][2] == 'X'&&array[1][2] == 'X'&&array[2][2] == 'X') ^ (array[0][2] == 'O'&&array[1][2] == 'O'&&array[2][2] == 'O') ^
           (array[0][1] == 'X'&&array[1][1] == 'X'&&array[2][1] == 'X') ^ (array[0][1] == 'O'&&array[1][1] == 'O'&&array[2][1] == 'O') ^
           (array[1][0] == 'X'&&array[1][1] == 'X'&&array[1][2] == 'X') ^ (array[1][0] == 'O'&&array[1][1] == 'O'&&array[1][2] == 'O') ^
           (counter == 9)){
            
            gameover = 1;
            
        }
        ///end game when it's over
        if(gameover == 1){
            if(counter == 9){
                printf("draw");
            }
            else if(playerdone == 1){
                printf("gameover!! X wins\n");
            }else{
                printf("gameover!! O wins\n");
            }
            system("pause");
            goto end;
        }
    goto next;

    end:
    



    
    return 0;
}
