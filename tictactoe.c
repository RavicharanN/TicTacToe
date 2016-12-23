#include<stdio.h>
int main()
{
    char a[3][3],q;
    int i,j,k,l,n,d;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        	a[i][j]=' ';        //Filling the blocks with a blank space.....
        
    }
    system("clear");
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
    d=0;
    for(k=1;k<=5;k++)
    {
        printf("\nPlayer 1: \n");
        printf("Enter the row followed by column no.\n");     //Player 1's turn
    	scanf("%d %d",&i,&j);
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
        if((a[0][1]=='O'&&a[0][2]=='O'&&a[0][0]=='O')||(a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')||(a[2][0]=='O'&&a[2][2]=='O'&&a[2][1]=='O')||(a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O')||(a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')||(a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')||(a[1][1]=='O'&&a[2][2]=='O'&&a[0][0]=='O')||(a[2][0]=='O'&&a[1][1]=='O'&&a[0][2]=='O'))
        {
            printf("Player 1 wins\n");
            break;                          //Breaking condition
        }
        d++;
        if(d==9)
        {
            printf("The game is a tie\n");       //If the game is a tie (Max 9 moves altogether)
            break;
        }

    //Player 2

        printf("\nPlayer 2: \n");
        printf("Enter the row followed by column no.\n");    //Player 2's turn
        scanf("%d %d",&i,&j);
        
    check2:
        if (a[i][j]==' ')
        	a[i][j]='X';
        else
        {
            printf("Invalid entry! Plz re-enter.\n");
            scanf("%d %d",&i,&j);
            goto check2;
        }
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
            printf("Player 2 wins\n");     //Breaking condition if Player 2 wins
            break;
        }
    }
    return 0;
}