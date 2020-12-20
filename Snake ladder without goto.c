#include<stdio.h>
#include<stdlib.h>
int rd()
{
	int rem;
	rem=rand()%7;
	while(!rem)
        rem=rand()%7;
    return rem;
}
void displaychart(int curp,char player[4])
{	int i,j,t,c,row=0,display,pos1,pos2;
		if(curp==100)
		{
			printf("*****Congratulations*****\n\n\nPlayer %s wins\n",player);
			exit(0);
		}

	for(i=10;i>=1;i--)
	{
		t=i-1;
		if((row%2)==0)
		{
			c=0;
			for(j=10;j>=1;j--)
			{
				display=(i*j)+(t*c++);
				if(curp==display)
					printf("%s\t",player);
				else
				printf("%d\t",display);

			}
			row++;
		}
		else
		{
			c=9;
			for(j=1;j<=10;j++)
			{
				display=(i*j)+(t*c--);

				if(curp==display)
					printf("%s\t",player);
				else
					printf("%d\t",display);
			}


			row++;
		}
		printf("\n\n");
	}



	printf("--------------------------------------------------------------------------\n");
}
void main()
{
	int i,dice,cur_pos1=0,cur_pos2=0,p;
	while(1)
	{	printf("\n		** SNAKE AND LADDER GAME** \n");
		printf("Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n");
		printf("Choose your option\n");
		printf("1. Player 1 plays\n");
		printf("2. Player 2 plays\n");
		printf("3. Exit\n");
		scanf("%d",&p);

		switch(p)
		{

			case 1:dice=rd();
			system("cls");
					printf("\t\t\t\tDice = %d\n\n",dice);
					cur_pos1=dice+cur_pos1;
					if(cur_pos1<101){
						if(cur_pos1==99)
						{
						displaychart(1,"$P1$");//snake
						printf("\nOops!You reached a snake\n");
						cur_pos1=1;
						}
						else if(cur_pos1==65)
						{
						displaychart(40,"$P1$");//snake
						printf("\nOops!You reached a snake\n");
						cur_pos1=40;
						}
						else if(cur_pos1==25)
						{
						displaychart(9,"$P1$");//snake
						printf("\nOops!You reached a snake\n");
						cur_pos1=9;
						}
						else if(cur_pos1==70)
						{
						displaychart(93,"$P1$");//ladder
						printf("\nHurray!You reached a ladder\n");
						cur_pos1=93;
						}
						else if(cur_pos1==60)
						{
						displaychart(83,"$P1$");//ladder
						printf("\nHurray!You reached a ladder\n");
						cur_pos1=83;
						}
						else if(cur_pos1==13)
						{
						displaychart(42,"$P1$");//ladder
						printf("\nHurray!You reached a ladder\n");
						cur_pos1=42;
						}
						else{
							displaychart(cur_pos1,"$P1$");
						}

					}
					else{
						cur_pos1=cur_pos1-dice;
						printf("Range exceeded of Player 1.\n");
						displaychart(cur_pos1,"$P1$");
					}
					printf("Player 2 position is %d\n",cur_pos2);
                    break;
			case 2:dice=rd();
			system("cls");
					printf("\t\t\t\tDice = %d\n\n",dice);
					cur_pos2=dice+cur_pos2;
					if(cur_pos2<101){
						if(cur_pos2==99)	//snake
						{
						displaychart(1,"$P2$");
						printf("\nOops!You reached a snake\n");
						cur_pos2=1;
						}
						else if(cur_pos2==65)	//snake
						{
						displaychart(40,"$P2$");
						printf("\nOops!You reached a snake\n");
						cur_pos2=40;
						}
						else if(cur_pos2==25)	//snake
						{
						displaychart(9,"$P2$");
						printf("\nOops!You reached a snake\n");
						cur_pos2=9;
						}
						else if(cur_pos2==70)	//ladder
						{
						displaychart(93,"$P2$");
						printf("\nHurray!You reached a ladder\n");
						cur_pos2=93;
						}
						else if(cur_pos2==60)	//ladder
						{
						displaychart(83,"$P2$");
						printf("\nHurray!You reached a ladder\n");
						cur_pos2=83;
						}
						else if(cur_pos2==13) 	//ladder
						{
						displaychart(42,"$P2$");
						printf("\nHurray!You reached a ladder\n");
						cur_pos2=42;
						}
						else{
							displaychart(cur_pos2,"$P2$");
						}
					}

					else{
						cur_pos2=cur_pos2-dice;
						printf("Range exceeded of Player 2.\n");
						displaychart(cur_pos2,"$P2$");
					}
					printf("Player 1 position is %d\n",cur_pos1);
                    break;
			case 3:exit(0);
                     break;

			default:printf("Incorrect choice.Try Again\n");

		}
		if(dice==6)
        {
            if(p==1)
                printf("\nPlayer 1 can play again");
            else
                printf("\nPlayer 2 can play again");
        }
        else
        {
            if(p==1)
                printf("\nPlayer 2 can play");
            else
                printf("\nPlayer 1 can play");
        }

	}

}
