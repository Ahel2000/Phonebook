#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct person{
	char name[30];
	char email[100];
	char mobile[100];
};
void start();
void add();
void del();
void search();
void list();

int main(){
	int n;
	printf("***************WELCOME TO PHONEBOOK*****************");
	printf("\nEnter your choice:\n");
	printf("Enter 1 for adding contact.\n");
	printf("Enter 2 for deleting contact.\n");
	printf("Enter 3 for searching for a contact.\n");
	printf("Enter 4 for displaying the entire list of contacts.\n");
	printf("Enter 5 to exit.\n");
	switch(getch()){
		case '1':add();
				 break;
		case '2':del();
				 break;
		case '3':search();
				 break;
		case '4':list();
				 break;
		case '5':exit(1);
		default:printf("\nPlease enter a number between 1 and 6");
				printf("\nEnter any key.");
				getch();		 
	}
	main();
}

void add(){
	system("cls");
	FILE *f;
	struct person p;
	f=fopen("phonebook","ab+");
	printf("\nEnter your name:");
	scanf("%s",p.name);
	printf("\nEnter email id:");
	scanf("%s",p.email);
	printf("\nEnter mobile number:");
	scanf("%s",p.mobile);
	fwrite(&p,sizeof(p),1,f);
	
	fflush(stdin);
	printf("\nYour contact has beeen saved.");
	fclose(f);
	printf("\nEnter any key\n");
	getch();
	system("cls");
	main();
}

void del(){
	struct person p;
	char name[30];
	int flag=0;
	FILE *f;
	f=fopen("phonebook","rb");
	if(f==NULL){
		printf("NO CONTACT SAVED!");
	}
	else{
		printf("Enter name of the person whose contact you want to delete.");
		scanf("%s",name);
		FILE *ft;
		ft=fopen("phone","wb+");
		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1){
			if(strcmp(name,p.name)!=0){
				fwrite(&p,sizeof(p),1,ft);
			}
			if(strcmp(name,p.name)==0){
				flag=1;
			}
		}
		fclose(f);
		fclose(ft);
		if(flag!=1){
			printf("\nNo contact exists with that name.");
			remove("phone");
		}
		else{
			remove("phonebook");
			rename("phone","phonebook");
			remove("phone");
			printf("Contact successfully deleted.\n");
		}
	}
}

void search(){
	struct person p;
	FILE *f;
	f=fopen("phonebook","rb");
	if(f==NULL){
		printf("No such file exists.");
		exit(1);
	}
	char name[30];
	printf("Enter name of the person you want view.");
	scanf("%s",name);
	while(fread(&p,sizeof(p),1,f)==1){
			if(strcmp(name,p.name)==0){
				printf("\nDetailed Information:");
				printf("Name:%s\nMail:%s\nPhone:%s\n",p.name,p.email,p.mobile);
			}
			else{
				printf("Contact not found.");
			}
		}
	fclose(f);
	printf("Enter any key to continue.");
	getch();
	system("cls");
}

 
void list(){
	struct person p;
	FILE *f;
	f=fopen("phonebook","rb");
	if(f==NULL){
		printf("No such file exists.");
		exit(1);
	}
	while(fread(&p,sizeof(p),1,f)==1){
				printf("Name:%s\nMail:%s\nPhone:%s\n",p.name,p.email,p.mobile);
	}
	fclose(f);
	printf("Enter any key to continue.");
	getch();
	system("cls");
} 
 
