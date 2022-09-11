#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "header.h"

node *head=NULL;
node *current = NULL;
node *prev = NULL;
u32 ListLength = 0,Size=0,ID,time,i;
u8 name[100];
u8 gender[10];
u32 pat_age,pat_id,id;
void main(void)
{
	u32 choice,input,newValue,Node_Value,position,PW;
	u8   flag=0,Exit_flag=1;
	
		printf("\t\t\t******** WELCOME TO OUR CLINIC ********\n\n");
	while(Exit_flag)
	{
	printf("Enter 1 for admin mode (or) enter 2 for user mode (or) enter 3 to exit\n");
	printf("Your choice: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		
	printf("\t\t\t******** Admin Mode ********\n\n");
	 printf("Please Enter the Password: ");
		for (i=0; i<3; i++)
		{
			
			  scanf ("%d",&PW);
					   if(PW==1234)
					   {
						   printf("\t\t\t******** Welcome ********\n\n");
						   flag = 1;
						   break;
					   }
					   
					   else if (i<2)
					   {
						   printf("Try again: ");
					   }
					   
	   }
	   if(flag==1)
	   {
		printf("if you want to add new patient record press 1\n");
		printf("if you want to edit patient record press 2\n");
		printf("if you want to reserve a slot with the doctor press 3\n");
		printf("if you want to cancel reservation press 4\n");
		printf("Your Choice: ");
		scanf("%d",&input);
		switch (input)
		{
			case 1 : printf("Please Enter the patient's name: ");
			         scanf(" %[^\n]%*c",name);
					 printf("Please Enter the patient's age: ");
			         scanf("%d",&pat_age);
					 printf("Please Enter the patient's gender (male or female): ");
			         scanf(" %[^\n]%*c",gender);
					 printf("Please Enter the patient's id: ");
			         scanf("%d",&pat_id);
					 Add_patient(name,pat_age,gender,pat_id);
					 break;
			case 2 : printf("Enter Your ID: ");
					 scanf("%d",&id);
					Edit_List(id); break;
			case 3 : Time_Reservation();
					 break;
			case 4 : printf("Enter Your ID: ");
					 scanf("%d",&id);
			         Cancel_Res(id);
					 break;
			default: printf("Invalid Choice please try again\n"); break;
		}
	   }
		else if (flag == 0)
		{
		printf("Incorrect password for 3 consecutive times\n"); Exit_flag=0;
		}
	}
	
	else if(choice==2)
	{
		printf("\t\t\t******** User Mode ********\n\n");
		printf("For Patient record press 1\n");
		printf("For today's reservation press 2\n");
		printf("Your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1 : printf("Enter Your ID: ");
					 scanf("%d",&id);
					 printf("\t\t\t********** Patient Record **********\n\n");
					 Print_List(id);
					 break;
			case 2 : printf("\t\t\t****** Today's Reservation ******\n\n ");
					Print_Res();
					break;
			default: printf("Invalid Choice please try again\n"); break;
		}
	}
	else if(choice==3)
		
		{
		Exit_flag=0; 
		printf("Good Bye");
		}
	else 
		printf("Wrong entry\n");
	}
}