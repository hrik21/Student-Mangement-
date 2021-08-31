#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Address{
	int house,street,pin;
	char city[20],state[20];
};
struct Student{
	int age,roll,p,c,m,h,e,total;
	float avg;
	char name[20],grade[5];
	struct Address add;
}s;
void get_details();
void display();
void display_marksheet();
void search_name();
void search_city();
void search_state();
void search_grade();
void search();
void edit();
void edit_name();
void edit_age();
void edit_address();
void delete();
void main()
{
	int ch;
	while(1)
	{
		system("pause");
		system("cls");
		printf("     Student Portal Menu");
		printf("\n--------------------------");
		printf("\n1. Add Student Details");
		printf("\n2. Display all Students Details");
		printf("\n3. Display Marksheet");
		printf("\n4. Search Record");
		printf("\n5. Edit Record");
		printf("\n6. Delete Record");
		printf("\n7. Exit");
		printf("\n--------------------------");
		printf("\nEnter Choice :  ");
		scanf("%d",&ch);
		system("cls");
		switch(ch)
		{
			case 1:
				get_details();
				break;
			case 2:
				display();
				break;
			case 3:
				display_marksheet();
				break;
			case 4:
				search();
				break;
			case 5:	
				edit();
				break;
			case 6:
				delete();
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid Choice\n");
		}
	}
}
void search()
{
	int ch;
	while(1)
	{
		system("pause");
		system("cls");
		printf("   Student Search Menu");
		printf("\n---------------------");
		printf("\n1. Search by Name");
		printf("\n2. Exit");
		printf("\n---------------------");
		printf("\nEnter Choice :  ");
		scanf("%d",&ch);
		system("cls");
		switch(ch)
		{
			case 1:
				search_name();
				break;
			case 2:
				break;
			default:
				printf("Invalid Choice\n");
		}
		if(ch==2)
		break;
	}
}
void edit()
{
	int ch;
	while(1)
	{
		system("pause");
		system("cls");
		printf("   Student Edit Menu");
		printf("\n---------------------");
		printf("\n1. Edit Name");
		printf("\n2. Exit");
		printf("\n---------------------");
		printf("\nEnter Choice :  ");
		scanf("%d",&ch);
		system("cls");
		switch(ch)
		{
			case 1:
				edit_name();
				break;
			case 2:
				break;
			default:
				printf("Invalid Choice\n");
		}
		if(ch==2)
		break;
	}
}
void get_details()
{
	struct Student temp;
	int f=0;
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	p=fopen("Student.txt","wb+");
	printf("Enter the Name of the student : ");
	fflush(stdin);
	gets(s.name);
	while(1)
	{
		f=0;
		rewind(p);
		printf("Enter the Roll Number :  ");
		scanf("%d",&s.roll);
		while(fread(&temp,sizeof(temp),1,p)==1)
		{
			if(temp.roll==s.roll)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		break;
		else
		printf("Student Roll Number already exist\n");
	}
	printf("Enter the House Number, Street Number and Pin Number :  ");
	scanf("%d%d%d",&s.add.house,&s.add.street,&s.add.pin);
	printf("Enter the City name and State Name : ");
	fflush(stdin);
	gets(s.add.city);
	gets(s.add.state);
	printf("Enter the Age of Student :  ");
	scanf("%d",&s.age);
	printf("Enter the Marks in Phy,Che,Math,Hin,Eng\n");
	scanf("%d%d%d%d%d",&s.p,&s.c,&s.m,&s.h,&s.e);
	s.total=s.p+s.c+s.m+s.h+s.e;
	s.avg=(float)s.total/5;
	if(s.avg>90)
	strcpy(s.grade,"A+");
	else if(s.avg>80)
	strcpy(s.grade,"A");
	else if(s.avg>70)
	strcpy(s.grade,"A-");
	else if(s.avg>60)
	strcpy(s.grade,"B+");
	else if(s.avg>50)
	strcpy(s.grade,"B");
	else if(s.avg>40)
	strcpy(s.grade,"B-");
	else
	strcpy(s.grade,"FAIL");
	fseek(p,0,SEEK_END);
	fwrite(&s,sizeof(s),1,p);
	fclose(p);
}
void display()
{
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	{
		printf("No Record Available\n");
		return;
	}
	printf("Name           Roll No.\t      Total\ts.avg\tGrade");
	while(fread(&s,sizeof(s),1,p)==1)
	{
		printf("\n%-15s%d\t%d\t%.2f\t%s",s.name,s.roll,s.total,s.avg,s.grade);
	}
	printf("\n");
	fclose(p);
}
void display_marksheet()
{
	int num,f=0;
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	{
		printf("No Record Available\n");
		return;
	}
	printf("Enter the Roll Number to Print Marksheet :  ");
	scanf("%d",&num);
	while(fread(&s,sizeof(s),1,p)==1)
	{
		if(num==s.roll)
		{
			f=1;
			printf("\n\tMarksheet");
		    printf("\n------------------------------");
		    printf("\nName                  %s",s.name);
    		printf("\nRoll Number         %d",s.roll);
   			printf("\nAge                 %d",s.age);
    		printf("\n-----------------------------");
    		printf("\nHouse Number        %d",s.add.house);
    		printf("\nStreet Number       %d",s.add.street);
    		printf("\nPIN Number          %d",s.add.pin);
    		printf("\nCity Name           %s",s.add.city);
    		printf("\nState Name          %s",s.add.state);
    		printf("\n-----------------------------");
    		printf("\nPhysics             %d",s.p);
    		printf("\nChemistry           %d",s.c);
    		printf("\nMath                %d",s.m);
    		printf("\nHindi               %d",s.h);
    		printf("\nEnglish             %d",s.e);
    		printf("\n----------------------------");
    		printf("\nTotal              %d",s.total);
			printf("\nAverage            %.2f",s.avg);
    		printf("\ngrade              %s",s.grade);
    		printf("\n---------------------------\n"); 
		}
	}
	fclose(p);
	if(f==0)
	printf("No Such Student Exist\n");
}
void search_name()
{
	int f=0;
	char ch[20];
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	{
		printf("No Record Available\n");
		return;
	}
	printf("Enter the Name to Search :  ");
	fflush(stdin);
	gets(ch);
	printf("Name           Roll\t      Total\ts.avg\tGrade");
	while(fread(&s,sizeof(s),1,p)==1)
	{
		if(strcmp(s.name,ch)==0)
		{
			f=1;
			printf("\n%-15s%d\t%d\t%.2f\t%s\n",s.name,s.roll,s.total,s.avg,s.grade);
		}
	}
	fclose(p);
	if(f==0)
	printf("No Such Student Exist\n");
}
void edit_name()
{
	int f=0,num,m=sizeof(s);
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	{
		printf("No Record Available\n");
		return;
	}
	printf("Enter the Roll Number to Edit :  ");
	scanf("%d",&num);
	while(fread(&s,sizeof(s),1,p)==1)
	{
		if(num==s.roll)
		{
			f=1;
			fseek(p,-m,SEEK_CUR);
			printf("Enter the Name to Update :  ");
			fflush(stdin);
			gets(s.name);
			fwrite(&s,sizeof(s),1,p);
			break;
		}
	}
	fclose(p);
	if(f==0)
	printf("No Such Student Exist\n");
}
void delete()
{
	int num;
	FILE *temp;
	FILE *p=fopen("Student.txt","rb+");
	if(p==NULL)
	{
		printf("No Record Available\n");
		return;
	}
	printf("Enter the Roll Number to delete :  ");
	scanf("%d",&num);
	temp=fopen("temp.txt","wb+");
	while(fread(&s,sizeof(s),1,p)==1)
	{
		if(num!=s.roll)
		{
			fseek(temp,0,SEEK_END);
			fwrite(&s,sizeof(s),1,temp);
		}
	}
	fclose(p);
	fclose(temp);
	remove("Student.txt");
	rename("temp.txt","Student.txt");
}
