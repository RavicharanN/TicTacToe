// Tic-tac-toe with an inteliigent computer
// ~Ravicharan

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char a[3][3];
int i,j,tempi,tempj;
int win()       //This function checks for the winning move of the computer
{
    if((a[0][0]=='X'||(a[0][2]=='X'&&a[1][2]=='X')||(a[2][0]=='X'&&a[2][1]=='X'))&&a[2][2]==' ')
    {
        j=2;i=2;
        a[i][j]='X';
        return 1;
    }
    else if((a[2][2]=='X'||(a[0][1]=='X'&&a[0][2]=='X')||(a[1][0]=='X'&&a[2][0]=='X'))&&a[0][0]==' ')
    {
        i=0;j=0;
        a[i][j]='X';
        return 1;
    }
    else if((a[2][0]=='X'||(a[0][0]=='X'&&a[0][1]=='X')||(a[2][2]=='X'&&a[1][2]=='X'))&&a[0][2]==' ')
    {
        i=0;j=2;
        a[i][j]='X';
        return 1;
    }
    else if((a[0][2]=='X'||(a[0][0]=='X'&&a[1][0]=='X')||(a[2][2]=='X'&&a[2][1]=='X'))&&a[2][0]==' ')
    {
        i=2;j=0;
        a[i][j]='X';
        return 1;
    }
    else if((a[2][1]=='X'||(a[0][0]=='X'&&a[0][2]=='X'))&&a[0][1]==' ')
    {
        i=0;j=1;
        a[i][j]='X';
        return 1;
    }
    else if((a[1][2]=='X'||(a[0][0]=='X'&&a[2][0]=='X'))&&a[1][0]==' ')
    {
        i=1;j=0;
        a[i][j]='X';
        return 1;
    }
    else if((a[1][0]=='X'||(a[0][2]=='X'&&a[2][2]=='X'))&&a[1][2]==' ')
    {
        i=1;j=2;
        a[i][j]='X';
        return 1;
    }
    else if((a[0][1]=='X'||(a[2][0]=='X'&&a[2][2]=='X'))&&a[2][1]==' ')
    {
        i=2;j=1;
        a[i][j]='X';
        return 1;
    }
    else
    return 0;
}

int block()   //If there is no such winning move the computr blocks the winning moves of te player.
{
    srand(0);
    
    if((a[tempi][0]=='O'&&a[tempi][1]=='O')||(a[tempi][0]=='O'&&a[tempi][2]=='O')||(a[tempi][1]=='O'&&a[tempi][2]=='O'))
    {
        for(j=0;j<3;j++)
        {
            if(a[tempi][j]==' ')
            {
                i=tempi;
                
                j=j;
            	a[i][j]='X';
            }
        }
    }
    else if((a[0][tempj]=='O'&&a[1][tempj]=='O')||(a[0][tempj]=='O'&&a[2][tempj]=='O')||(a[1][tempj]=='O'&&a[2][tempj]=='O')||(a[0][2]=='O'&&a[2][2]=='O'))
    {
        printf("asfsaf\n");
        for(i=0;i<3;i++)
        {
            if(a[i][tempj]==' ')
            {
                i=i;
                j=tempj;
                a[i][j]='X';
            }
        }
    }
    else
    {
        
        if (a[tempi][(tempj+2)%3]==' ')
        {
            j=(tempj+2)%3;
            i=tempi;
            a[i][j]='X';
        }
        else if (a[tempi][(tempj+1)%3]==' ')
        {
            i=tempi;
            j=(tempj+1)%3;
            a[i][j]='X';
        }
        else if (a[(tempi+2)%3][tempj]==' ')
        {
            i=(tempi+2)%3;
            j=tempj;
            a[i][j]='X';
            
        }
        else if (a[(tempi+1)%3][tempj]==' ')
        {
            i=(tempi+1)%3;
            j=tempj;
            a[i][j]='X';
        }
        else
        {
            i=rand()%3;
            j=rand()%3;
        abc:
            if(a[i][j]==' ')
            a[i][j]='X';
            else
            {
                i=rand()%3;
                j=rand()%3;
                goto abc;
            }
        }
        
    }
    return 0;
}



int main()
{
    srand(0);
    char q;
    int i,j,k,l,n,d,val;
    system("clear");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        a[i][j]=' ';        //Filling the blocks with a blank space.....
        
    }
    
    a[1][1]='X';
    
    printf("   0 1 2  \n");  // Indication of the columns
    printf("  _______\n");
    for(i=0;i<3;i++)
    {
        printf("%d  ",i);       // Indication of the row no.
        for(j=0;j<3;j++)
        printf("%c|",a[i][j]);
        printf("\n");
        printf("  _______\n");
    }
    printf("Press ENTER to continue.  \n");
    scanf("%c",&q);
    d=1;
    for(k=1;k<=5;k++)
    {
        printf("\nPlayer 1: \n");
        printf("Enter the row followed by column no.\n");     //Player 1's turn
        scanf("%d %d",&i,&j);
        tempi=i;
        tempj=j;
    check1:
        if (a[i][j]==' ')
        a[i][j]='X';
        else
        {
            printf("Invalid entry! Plz re-enter.\n");
            scanf("%d %d",&i,&j);
            goto check1;
        }
        system("clear");
        a[i][j]='O';
        printf("   0 1 2  \n");
        printf("  _______\n");
        
        for(i=0;i<3;i++)
        {
            printf("%d  ",i);
            for(j=0;j<3;j++)
            printf("%c|",a[i][j]);
            printf("\n");
            printf("  _______\n");
        }
        
        d++;
        
        //Computer's turn
        
        val=0;
        val=win();
        if(val!=1)      //If value one is returned the computer has a winning move
        	block();
        
        //Printing
        system("clear");
        printf("   0 1 2  \n");
        printf("  _______\n");
        for(i=0;i<3;i++)
        {
            printf("%d  ",i);
            for(j=0;j<3;j++)
            printf("%c|",a[i][j]);
            printf("\n");
            printf("  _______\n");
        }
        d++;
        
        
        if((a[0][1]=='X'&&a[0][2]=='X'&&a[0][0]=='X')||(a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X')||(a[2][0]=='X'&&a[2][2]=='X'&&a[2][1]=='X')||(a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')||(a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')||(a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')||(a[1][1]=='X'&&a[2][2]=='X'&&a[0][0]=='X')||(a[2][0]=='X'&&a[1][1]=='X'&&a[0][2]=='X'))
        {
            printf("Computer wins\n");     //Breaking condition if Computer wins
            break;
        }
        
        if(d==9)
        {
            printf("The game is a tie\n");       //If the game is a tie (Max 9 moves altogether)
            break;
        }
        
    }
    return 0;
}