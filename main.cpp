#include<iostream>
#include<fstream>
#include<unistd.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
#include "D:\EasyBook.com\Travel\travel.h"
#include "D:\EasyBook.com\travel\Flight\Flight.h"
#include "D:\EasyBook.com\travel\Buses\Bus.h"
#include "D:\EasyBook.com\travel\Train\Train.h"
#include "D:\EasyBook.com\Residence\Residence.h"
#include "D:\EasyBook.com\User\user.h"
#include "D:\EasyBook.com\Admin\admin.h"
//#include "D:\EasyBook.com\Travel\travel.h"
int AfterLogIn(user a){
	char ch;
	while(1){
		system("cls");
		cout<<"1) BOOK TRAIN "<<endl;
		cout<<"2) BOOK FLIGHT "<<endl;
		cout<<"3) BOOK BUS "<<endl;
		cout<<"4) BOOK RESIDENCE "<<endl;
		cout<<"5) VIEW PREVIOUS RECORDS "<<endl;
		cout<<"6) EXIT"<<endl;
		cout<<endl<<endl<<"ENTER CHOICE: ";
		cin>>ch;
		switch(ch){
			case '1':
				a.trainBook();
				break;
			case '2':
				a.flightBook();
				break;
			case '3':
				a.busBook();
				break;
				//return 0;
			case '4':
				a.ResidenceBook();
				break;
				//return 0;
			case '5':
				a.PreviousRecord();
				getch();
				break;
				//return 0;
			case '6':
				return 0;
			default:
				cout<<"INVALID CHOICE....";
				//return 0;						
		}
	}
	
}
void AdminAfterLog(admin obj){
	char ch;
	while(1){
		cout<<"1)Add"<<endl;
		cout<<"2)Delete"<<endl;
		cout<<"3)Update"<<endl;
		cout<<"4)Exit";
		cout<<endl<<endl<<"ENTER CHOICE: ";
		cin>>ch;
		if(ch == '1'){
			system("cls");
			cout<<"1)FLIGHT"<<endl;
			cout<<"2)TRAIN"<<endl;
			cout<<"3)BUS"<<endl;
			cout<<"4)RESIDENCE"<<endl;
			cout<<endl<<endl<<"ENTER CHOICE: ";
			cin>>ch;
			switch (ch){
				case '1':
					obj.flightadd();
					break;
				case '2':
					obj.trainadd();
					break;
				case '3':
					obj.busadd();
					break;
				case '4':
					obj.residenceadd();		
					break;
			}
		}else if(ch == '2'){
			system("cls");
			cout<<"1)FLIGHT"<<endl;
			cout<<"2)TRAIN"<<endl;
			cout<<"3)BUS"<<endl;
			cout<<"4)RESIDENCE"<<endl;
			cout<<endl<<endl<<"ENTER CHOICE: ";
			cin>>ch;
			switch (ch){
				case '1':
					obj.flightdelete();
					break;
				case '2':
					obj.traindelete();
					break;
				case '3':
					obj.busdelete();
					break;
				case '4':
					obj.residencedelete();		
					break;
			}
		}else if(ch == '3'){
			system("cls");
			cout<<"1)FLIGHT"<<endl;
			cout<<"2)TRAIN"<<endl;
			cout<<"3)BUS"<<endl;
			cout<<"4)RESIDENCE"<<endl;
			cout<<endl<<endl<<"ENTER CHOICE: ";
			cin>>ch;
			switch (ch){
				case '1':
					obj.flightPriceUpdate();
					break;
				case '2':
					obj.trainPriceUpdate();
					break;
				case '3':
					obj.busPriceUpdate();
					break;
				case '4':
					obj.residencePriceUpdate();		
					break;
			}
		}else if(ch == '4'){
			break;
		}
	}
}
int main ()
{
    int chk;
    char choice;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                             ";
	cout<<"WELCOME TO EASYBOOK.com"<<endl;
	cout<<"                             ";
	cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
	getch();
	system("cls");
	cout<<"1) Admin"<<endl;
	cout<<"2)User"<<endl;
	cin>>choice;
	if(choice == '1'){
		admin obj;
		chk = obj.logIn();
		//cout<<chk<<endl;
		while(1){
			if(chk == 1){
				//cout<<"con";
				system("cls");
				AdminAfterLog(obj);
				break;
			}else
			{
				obj.logIn();
			}
		}
	}else{
		user a;
		cout<<"SIGUP OR LOG IN 1 FOR SIGN UP: ";
		cin>>choice;
		if(choice == '1'){
			a.SignUp();
			system("cls");
			AfterLogIn(a);
		}else
		{
			chk = a.LogIn();
			if(chk == 1){
				AfterLogIn(a);
			}else
			{
				system("cls");
				a.LogIn();
			}
		}
	}
}

