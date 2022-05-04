#include<iostream>
#include<fstream>
#include<unistd.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
void SignUp(){
	string FN,LN,UserName,Email,FileName;
	char ch,a,pass[13];
	int i,j,k,count=0;
	cout<<"Enter First Name: ";
	fflush(stdin);
	getline(cin,FN);
	cout<<"Enter Last Name: ";
	getline(cin,LN);
	while(1)
	{
		cout<<"Enter Email(only gmail allowed): ";
		getline(cin,Email);
		int pos=0;
		string chk;
		pos = Email.find("@");
		for(i=pos,j=0;i<Email.length();i++,j++)
		{
			chk.push_back(Email[i]);
		}
		if(chk == "@gmail.com"){
			break;
		}else
		{
			cout<<"ENTER VALID EMAIL....."<<endl;
		}
	}
	while(1){
		cout<<"Enter User Name: ";
		getline(cin,UserName);
		FileName = "Users/";
		FileName.append(UserName);
		FileName.append(".txt");
		ifstream Users;
		Users.open(FileName.c_str());
		if(Users)
		{
			cout<<"USER NAME ALREADY EXISTS..."<<endl;
			Users.close();
		}else
		{
			break;
		}
	}
	while(1){
		cout<<"Enter Password: ";
		for(i=0;;)//infinite loop
		    {
		        a=getch();//stores char typed in a
		        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
		            //check if a is numeric or alphabet
		        {
		            pass[i]=a;//stores a in pass
		            ++i;
		            cout<<"*";
		        }
		        if(a=='\b'&&i>=1)//if user typed backspace
		            //i should be greater than 1.
		        {
		            cout<<"\b \b";//rub the character behind the cursor.
		            --i;
		        }
		        if(a=='\r')//if enter is pressed
		        {
		            pass[i]='\0';//null means end of string.
		            break;//break the loop
		        }
		    }
		    while(pass[count] != '\0'){
		    	count++;
			}
			if(count < 8 || count > 13){
				cout<<"PLEASE ENTER PASSWORD BETWEEN 8 TO 13 CHARACTERS.."<<endl;
			}else
			{
				break;
			}
			
	}
	ofstream User;
	User.open(FileName.c_str());
	User <<pass<<endl<< UserName<<endl<<FN<<" "<<LN<<endl<<Email;
	User.close();
}
void LogIn(){
	string UserName,FileName,FilePass;
	int choice,i;
	char a,pass[13];
	while(1){
		cout<<"Enter User Name: ";
		fflush(stdin);
		getline(cin,UserName);
		ifstream User;
		FileName = "Users/";
		FileName.append(UserName);
		FileName.append(".txt");
		User.open(FileName.c_str());
		if(User){
			getline(User,FilePass);
			while(1){
				cout<<"\nEnter Password  : ";
		    for(i=0;;)//infinite loop
		    {
		        a=getch();//stores char typed in a
		        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
		            //check if a is numeric or alphabet
		        {
		            pass[i]=a;//stores a in pass
		            ++i;
		            cout<<"*";
		        }
		        if(a=='\b'&&i>=1)//if user typed backspace
		            //i should be greater than 1.
		        {
		            cout<<"\b \b";//rub the character behind the cursor.
		            --i;
		        }
		        if(a=='\r')//if enter is pressed
		        {
		            pass[i]='\0';//null means end of string.
		            break;//break the loop
		        }
		    }
				if(FilePass == pass){
					system("cls");
					cout<<"Logged in...";
					break;
				}else
				{
					cout<<"Password Doesnot matched...."<<endl;
				}
			}
			break;
		}else
		{
			cout<<"User DoesNot Exsists...."<<endl;
			cout<<"If want to sign Up enter 1: ";
			cin>>choice;
			if(choice == 1){
				SignUp();
				break;
			}else{
				continue;
			}
		}
	}
}
int main()
{
	char choice;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                             ";
	cout<<"WELCOME TO EASYBOOK.com"<<endl;
	cout<<"                             ";
	cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
	getch();
	system("cls");
	cout<<"IF NEW HERE ENTER 1 FOR SIGN UP else press any key: ";
	cin>>choice;
	if(choice == '1'){
		SignUp();
	}else
	{
		LogIn();
	}
}
