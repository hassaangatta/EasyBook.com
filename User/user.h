#include <iostream>
#include <string.h>
#include <fstream>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include "D:\EasyBook.com\Travel\travel.h"
//#include "D:\EasyBook.com\Residence\Residence.h"
//#include "D:\EasyBook.com\Travel\Flight\Flight.h"
//#include "D:\EasyBook.com\Travel\Train\Train.h"
//#include "D:\EasyBook.com\Travel\Buses\Bus.h"
#include "Mail.h"
using namespace std;

class user {
	string FN,LN,UserName,Email,FileName;
	char pass[13];
    //Travel *trf=&f;
    //Travel *trt=&t;
    public:
    	
	    void trainBook(){
	    	Train t;
	    	string CN,cvv;
	    	int chk;
	    	t.input();
	    	t.createFileName();
	    	t.FileRead();
	    	chk = t.book();
	    	if(chk == 1){
	    		cout<<"ENTER CREDIT CARD NUMBER: ";
		    	cin>>CN;
		    	cout<<"ENTER cvv NUMBER: ";
		    	cin>>cvv;
		    	sleep(3);
		    	system("cls");
		    	cout<<"PAYMENT SUCCESSFULL...."<<endl;
		    	fstream booked;
				fstream user;
				ofstream message;
				message.open("Message.txt");
				string data;
				booked.open(t.getfilename());
				user.open(FileName,fstream::app);
				//cout<<t.getBookId();
				while(!booked.eof() && data != t.getBookId()){
						getline(booked,data);
						//cout<<endl<<data<<endl;
				}
				//cout<<endl<<data<<endl;
				user<<endl;
				user<<data<<endl;
				message<<"EASYBOOK.com"<<endl<<endl<<endl;
				for(int i=0;i<7;i++){
					getline(booked,data);
					if(i==3){
						user<<t.price<<endl;
						//message<<t.getPrice()*t.getSeat()<<endl;
	//					cout<<t.getPrice();
						
					}
					else if(i==4)
					{
						user<<t.seats<<endl;
						//message<<t.getSeat()<<endl;
					}else
					{
						user<<data<<endl;
						message<<data<<endl;
					}
					
				}
				booked.close();
				user.close();
				message<<"NUMBER OF SEATS: "<<t.seats<<endl;
				message<<"FINAL BILL PAID: "<<t.price*t.seats<<endl;
				//message<<t.getPrice()*t.getSeat();
				message.close();		
				fstream mailpick;
				string mail; 
				mailpick.open(FileName);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				ofstream receiver;
				receiver.open("Mail.txt");
				receiver<<mail;
				receiver.close();
				ofstream subject;
				subject.open("Subject.txt");
				subject<<"BOOKING CONFIRMED";
				subject.close();
				SendMail(0);
			}
		}
		void flightBook(){
			Flight f;
	    	string CN,cvv;
	    	int chk;
	    	f.input();
	    	f.createFileName();
	    	f.FileRead();
	    	chk = f.book();
	    	if(chk == 1){
	    		cout<<"ENTER CREDIT CARD NUMBER: ";
		    	cin>>CN;
		    	cout<<"ENTER cvv NUMBER: ";
		    	cin>>cvv;
		    	sleep(3);
		    	system("cls");
		    	cout<<"PAYMENT SUCCESSFULL...."<<endl;
		    	fstream booked;
				fstream user;
				ofstream message;
				message.open("Message.txt");
				string data;
				booked.open(f.getfilename());
				user.open(FileName,fstream::app);
				//cout<<t.getBookId();
				while(!booked.eof() && data != f.getBookId()){
						getline(booked,data);
						//cout<<endl<<data<<endl;
				}
				//cout<<endl<<data<<endl;
				user<<endl;
				user<<data<<endl;
				message<<"EASYBOOK.com"<<endl<<endl<<endl;
				for(int i=0;i<7;i++){
					getline(booked,data);
					if(i==3){
						user<<f.price<<endl;
						//message<<t.getPrice()*t.getSeat()<<endl;
	//					cout<<t.getPrice();
						
					}
					else if(i==4)
					{
						user<<f.seats<<endl;
						//message<<t.getSeat()<<endl;
					}else
					{
						user<<data<<endl;
						message<<data<<endl;
					}
					
				}
				booked.close();
				user.close();
				message<<"NUMBER OF SEATS: "<<f.seats<<endl;
				message<<"FINAL BILL PAID: "<<f.price*f.seats<<endl;
				//message<<t.getPrice()*t.getSeat();
				message.close();		
				fstream mailpick;
				string mail; 
				mailpick.open(FileName);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				ofstream receiver;
				receiver.open("Mail.txt");
				receiver<<mail;
				receiver.close();
				ofstream subject;
				subject.open("Subject.txt");
				subject<<"BOOKING CONFIRMED";
				subject.close();
				SendMail(0);
			}
		}
		void busBook(){
			Bus b;
	    	string CN,cvv;
	    	int chk;
	    	b.input();
	    	b.createFileName();
	    	b.FileRead();
	    	chk = b.book();
	    	if(chk == 1){
	    		cout<<"ENTER CREDIT CARD NUMBER: ";
		    	cin>>CN;
		    	cout<<"ENTER cvv NUMBER: ";
		    	cin>>cvv;
		    	sleep(3);
		    	system("cls");
		    	cout<<"PAYMENT SUCCESSFULL...."<<endl;
		    	fstream booked;
				fstream user;
				ofstream message;
				message.open("Message.txt");
				string data;
				booked.open(b.getfilename());
				user.open(FileName,fstream::app);
				//cout<<t.getBookId();
				while(!booked.eof() && data != b.getBookId()){
						getline(booked,data);
						//cout<<endl<<data<<endl;
				}
				//cout<<endl<<data<<endl;
				user<<endl;
				user<<data<<endl;
				message<<"EASYBOOK.com"<<endl<<endl<<endl;
				for(int i=0;i<7;i++){
					getline(booked,data);
					if(i==3){
						user<<b.price<<endl;
						//message<<t.getPrice()*t.getSeat()<<endl;
	//					cout<<t.getPrice();
						
					}
					else if(i==4)
					{
						user<<b.seats<<endl;
						//message<<t.getSeat()<<endl;
					}else
					{
						user<<data<<endl;
						message<<data<<endl;
					}
					
				}
				booked.close();
				user.close();
				message<<"NUMBER OF SEATS: "<<b.seats<<endl;
				message<<"FINAL BILL PAID: "<<b.price*b.seats<<endl;
				//message<<t.getPrice()*t.getSeat();
				message.close();		
				fstream mailpick;
				string mail; 
				mailpick.open(FileName);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				ofstream receiver;
				receiver.open("Mail.txt");
				receiver<<mail;
				receiver.close();
				ofstream subject;
				subject.open("Subject.txt");
				subject<<"BOOKING CONFIRMED";
				subject.close();
				SendMail(0);			
			}
		}
		void ResidenceBook(){
			Residence r;
			int chk;
			string cvv,CN;
			r.input();
			r.createFileName();
			r.FileRead();
			chk=r.book();
			if(chk == 1){
	    		cout<<"ENTER CREDIT CARD NUMBER: ";
		    	cin>>CN;
		    	cout<<"ENTER cvv NUMBER: ";
		    	cin>>cvv;
		    	sleep(3);
		    	system("cls");
		    	cout<<"PAYMENT SUCCESSFULL...."<<endl;
				fstream booked;
				fstream user;
				ofstream message;
				message.open("Message.txt");
				string data;
				booked.open(r.getfilename());
				user.open(FileName,fstream::app);
				//cout<<t.getBookId();
				while(!booked.eof() && data != r.getBookId()){
						getline(booked,data);
						//cout<<endl<<data<<endl;
				}
				//cout<<endl<<data<<endl;
				user<<endl;
				user<<data<<endl;
				message<<"EASYBOOK.com"<<endl<<endl<<endl;
				for(int i=0;i<7;i++){
					getline(booked,data);
					if(i==6){
						user<<r.price<<endl;
						//message<<t.getPrice()*t.getSeat()<<endl;
	//					cout<<t.getPrice();
						
					}
					else
					{
						user<<data<<endl;
						message<<data<<endl;
					}
					
				}
				booked.close();
				user.close();
				message<<"FINAL BILL PAID: "<<r.price<<endl;
				//message<<t.getPrice()*t.getSeat();
				message.close();		
				fstream mailpick;
				string mail; 
				mailpick.open(FileName);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				getline(mailpick,mail);
				ofstream receiver;
				receiver.open("Mail.txt");
				receiver<<mail;
				receiver.close();
				ofstream subject;
				subject.open("Subject.txt");
				subject<<"BOOKING CONFIRMED";
				subject.close();
				SendMail(0);
			}
			}
		void PreviousRecord(){
			fstream User;
			string data;
			int count;
			User.open(FileName);
			getline(User,data);
			getline(User,data);
			getline(User,data);
			cout<<data<<endl;
			getline(User,data);
			cout<<data<<endl;
			cout<<endl<<endl;
			while(!User.eof()){
				getline(User,data);
				count++;
				cout<<data<<endl;
				if(count == 7){
					count = 0;
					cout<<endl<<endl;
				}
			}
		}
		void SignUp(){
			char ch,a;
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
				UserName = "";
				cout<<"Enter User Name: ";
				getline(cin,UserName);
				FileName = "D:\\EasyBook.com\\User\\Users\\";
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
		int LogIn(){
				string FilePass;
				int choice,i;
				char a;
				while(1){
					cout<<"Enter User Name: ";
					fflush(stdin);
					getline(cin,UserName);
					ifstream User;
					FileName = "D:\\EasyBook.com\\User\\Users\\";
					FileName.append(UserName);
					FileName.append(".txt");
					User.open(FileName.c_str());
					if(User){
						User.close();
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
					    	User.open(FileName.c_str());
					    	getline(User,FilePass);
					    	//cout<<FilePass<<endl;
					    	User.close();
					    	cout<<FilePass<<endl<<pass<<endl;
							if(FilePass == pass){
								system("cls");
								break;
							}else
							{
								cout<<endl<<"Password Doesnot matched...."<<endl;
								cout<<"IF FORGOT PASSWORD ENTER 0: ";
								cin>>choice;
								if(choice == 0){
									User.open(FileName.c_str());
									ofstream Mail;
									ofstream Message;
									ofstream Subject;
									ofstream PassUR;
									ofstream GmailUR;
									Mail.open("D:\\EasyBook.com\\Mail.txt");
									getline(User,FilePass);
									//cout<<FilePass<<endl;
									getline(User,FilePass);
									//cout<<FilePass<<endl;
									getline(User,FilePass);
									//cout<<FilePass<<endl;
									getline(User,FilePass);
									//cout<<FilePass<<endl;
									Mail<<FilePass;
									Mail.close();
									User.close();
									GmailUR.open("D:\\EasyBook.com\\GmailUR.txt");
									GmailUR<<"easybook045@gmail.com";
									GmailUR.close();
									PassUR.open("D:\\EasyBook.com\\PassUR.txt");
									PassUR<<"Easybook.pk";
									PassUR.close();
									int otp;
									srand((unsigned) time(0));
									otp = 100000 + (rand()%100000);
									Message.open("D:\\EasyBook.com\\Message.txt");
									Message<<"YOUR OTP TO RESET PASSWORD"<<endl<<otp;
									Message.close();
									Subject.open("D:\\EasyBook.com\\Subject.txt");
									Subject<<"PASSWORD RESET";
									SendMail(0);
									int InOtp;
									cout<<"ENTER OTP SEND THROUGH MAIL: ";
									cin>>InOtp;
									if(InOtp == otp){
										ResetPass();
										User.close();
										return 0;
									}
										}
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
						}else
						{
							continue;
						}
					}
				}
				//User.close();
				return 1;
			}
			void ResetPass(){
				char pass[13],cpass[13];
				int i;
				system("cls");
				char a;
					cout<<"ENTER NEW PASSWORD: ";
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
					cout<<"CONFIRM PASSWORD: ";
					    for(i=0;;)//infinite loop
					    {
					        a=getch();//stores char typed in a
					        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
					            //check if a is numeric or alphabet
					        {
					            cpass[i]=a;//stores a in pass
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
					            cpass[i]='\0';//null means end of string.
					            break;//break the loop
					        }
					    }
					fstream User;
					ofstream temp;
					temp.open("temp.txt");
					User.open(FileName);
					if(pass != cpass){
						cout<<"TWO PASSWORDS DOESNOT MATCHED..."<<endl;
					}else
					{
						string line;
						temp<<pass<<endl;
						getline(User,line);
						//temp<<line<<endl;
						getline(User,line);
						temp<<line<<endl;
						getline(User,line);
						temp<<line<<endl;
						getline(User,line);
						temp<<line<<endl;
						//User.close();
						temp.close();
						User.close();
						ifstream tempo;
						ofstream per;
						tempo.open("temp.txt");
						per.open(FileName);
						while(!tempo.eof()){
							getline(tempo,line);
							per<<line<<endl;
						}
						cout<<"PASSWORD SUCCESSFULLY CHANGES...."<<endl;
					}
		}
};
