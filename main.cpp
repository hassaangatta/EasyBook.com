#include<iostream>
#include<fstream>
#include<unistd.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
// #include "D:\EasyBook.com\Travel\travel.h"
//#include "travel/Flight/Flight.h"
// #include "travel/Train/Train.h"
// #include "D:\EasyBook.com\Residence\Residence.h"
#include "D:\EasyBook.com\User\user.h"
int AfterLogIn(user a){
	char ch;
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
			return 0;
		case '4':
			a.ResidenceBook();
			break;
			return 0;
		case '5':
			a.PreviousRecord();
			break;
			return 0;
		case '6':
			return 0;
		default:
			cout<<"INVALID CHOICE....";
			return 0;						
	}
}
int main ()
{
<<<<<<< Updated upstream
    user a;
    int chk;
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
		a.SignUp();
		AfterLogIn(a);
	}else
	{
		a.LogIn();
		AfterLogIn(a);
	}
=======
    // Flight f;
    // Travel *T = &f;
    // T->input();
    // f.creatFileName();
    // f.FileRead();
    // Train t;
    // Travel *a=&t;
    // a->input();
    // t.creatFileName();
    // t.FileRead();
    // Residence r;
    // r.input();
    // r.creatFileName();
    // r.FileRead();
    admin a;
    // a.flightadd();
    // a.trainadd();
    // a.busadd();
    // a.residenceadd();
    // a.residencedelete();
    // a.residencePriceUpdate();
    // a.flightdelete();
    // a.traindelete();
    // a.busdelete();
    // a.flightPriceUpdate();
    // a.trainPriceUpdate();
    a.busPriceUpdate();
>>>>>>> Stashed changes
}
