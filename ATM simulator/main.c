#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() 
{
	char pinstr[5];
	int pin = atoi(pinstr);
	int balen = 0;
	int genPinEntPin;
	printf("1.Enter PIN (press 1)\n2.Generate PIN(press 2)\n3.Exit(press 3)\n");
	scanf("%d",&genPinEntPin);
	printf("\n");
			
	if(genPinEntPin == 1) 
	{
		int getpin;
		printf("Enter PIN(4 digits):\n");
		scanf("%d",&getpin);
		char fname[5];
		sprintf(fname,"%d",getpin);
		strcat(fname,".txt");
		FILE *coustBal = NULL ;
		coustBal = fopen(fname,"r+");
		printf("\n");
				
		if(coustBal != NULL)
		{
			int mainmenuInput;
			printf("1.To cheak balence enter 1\n2.To change pin enter 2\n3.To deposite enter 3\n4.To withdraw enter 4\n");
			scanf("%d",&mainmenuInput);
			printf("\n");
			
			if(mainmenuInput == 1)
			{
				printf("%s","Your balence is Rs. ");
				while(!feof(coustBal))
				{
					char ch = fgetc(coustBal);
					printf("%c",ch);
				}
				fclose(coustBal);
				printf("\n");
				printf("\n");
				main();
			}			
			else if(mainmenuInput == 2)
			{
				int newPin;
				int oldPin;
				printf("Enter old PIN(4 digits):\n");
				scanf("%d",&oldPin);
				char oldFname[5];
				sprintf(oldFname,"%d",oldPin);
				strcat(oldFname,".txt");
				printf("Enter the new PIN(4 digits):\n");
				scanf("%d",&newPin);
				char newFname[5];
				sprintf(newFname,"%d",newPin);
				strcat(newFname,".txt");
				fclose(coustBal);
				int ChPIN = rename(oldFname,newFname);
				if(ChPIN == 0)
				{
					printf("PIN is changed\n");
				}
				else
				{
					printf("There is some error(exit and try again)...\n");
				};
				printf("\n");
				main();
			}				
			else if(mainmenuInput == 3)
			{
			
				int deposite;
				printf("Enter the ammount you want to deposite:\n");
			 	scanf("%d",&deposite);
			 	char balstr[10];
			 	int i = 0;
			 	while(!feof(coustBal))
		 		{
			 		balstr[i]=fgetc(coustBal);
			 		i++;
				};
				int bal = atoi(balstr);
				int netBal = bal + deposite;
				char newBal[10];
				sprintf(newBal,"%d",netBal);
				coustBal = fopen(fname,"w");
				fputs(newBal,coustBal);
				printf("\nDeposite successfull ...\n");
				fclose(coustBal);
				printf("\n");
				main();
			}			
			else if(mainmenuInput == 4)
			{
				int withdraw;
				printf("Enter the ammount you want to withdraw:\n");
			 	scanf("%d",&withdraw);
			 	char balstr2[10];
			 	int j = 0;
		 		while(!feof(coustBal))
			 	{
					balstr2[j]=fgetc(coustBal);
					j++;
				};
				int bal2 = atoi(balstr2);
				int netBal2 = bal2 - withdraw;
				if(netBal2 >= 0)
				{
					char newBal2[10];
					sprintf(newBal2,"%d",netBal2);
					coustBal = fopen(fname,"w");
					fputs(newBal2,coustBal);
					printf("\nWithdraw successfull ...\n");
				}
				else
				{
					printf("\nInsufficient of money ...\n");
				};
				fclose(coustBal);
				printf("\n");
				main();
			}			
			else
			{
				printf("You should enter from given option ...\n");
				printf("\n");
				main();
			};
		}
		else
		{
			printf("Your PIN is invalid...\n");
			printf("\n");
			main();
		};		
	}
	else if(genPinEntPin == 2)
	{
		printf("Enter new PIN(4 digits):\n");
		scanf("%s",&pinstr);
		char fname[5];
		strcpy(fname,pinstr);
		strcat(fname,".txt");
		char balenstr[15];
		sprintf(balenstr,"%d",balen);
		FILE *coustBal;
		coustBal = fopen(fname,"w");
		fputs(balenstr,coustBal);
		fclose(coustBal);
		printf("\n");
		main();
	}
	else if(genPinEntPin == 3)
	{
		exit(1);
	}
	else
	{
		printf("Please enter 1 or 2 or 3 ...\n\n");
		main();
	};
	
	getch();	 
	return 0;
}
