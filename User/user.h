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
#include "D:\EasyBook.com\Travel\travel.h"
#include "D:\EasyBook.com\Residence\Residence.h"
#include "D:\EasyBook.com\Travel\Flight\Flight.h"
#include "D:\EasyBook.com\Travel\Train\Train.h"
#include "D:\EasyBook.com\Travel\Buses\Bus.h"
#include "Mail.h"
using namespace std;

class user {
	string FN,LN,UserName,Email,FileName;
	char pass[13];
    Residence r;
    Flight f;
    Train t;
    Travel *trf=&f;
    Travel *trt=&t;
    Bus b;
    public:
    	
	    void trainBook(){
	    	t.input();
	    	fstream booked;
			fstream user;
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
			for(int i=0;i<7;i++){
				getline(booked,data);
				if(i==3){
					user<<t.getPrice()<<endl;
					
				}
				else if(i==4)
				{
					user<<t.getSeat()<<endl;
				}else
				{
					user<<data<<endl;
				}
				
			}
			booked.close();
			user.close();		
		}
		void flightBook(){
	    	f.input();
	    	fstream booked;
			fstream user;
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
			for(int i=0;i<7;i++){
				getline(booked,data);
				if(i==3){
					user<<f.getPrice()<<endl;
					
				}
				else if(i==4)
				{
					user<<f.getSeat()<<endl;
				}else
				{
					user<<data<<endl;
				}
				
			}
			booked.close();
			user.close();		
		}
		void busBook(){
	    	b.input();
	    	fstream booked;
			fstream user;
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
			for(int i=0;i<7;i++){
				getline(booked,data);
				if(i==3){
					user<<b.getPrice()<<endl;
					
				}
				else if(i==4)
				{
					user<<b.getSeat()<<endl;
				}else
				{
					user<<data<<endl;
				}
				
			}
			booked.close();
			user.close();		
		}
		void ResidenceBook(){
			r.input();
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
		void LogIn(){
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
					    	User.open(FileName.c_str());
					    	getline(User,FilePass);
					    	User.close();
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
								break;
							}else
							{
								cout<<"Password Doesnot matched...."<<endl;
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
									cout<<FilePass<<endl;
									getline(User,FilePass);
									cout<<FilePass<<endl;
									getline(User,FilePass);
									cout<<FilePass<<endl;
									getline(User,FilePass);
									cout<<FilePass<<endl;
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
										User.close();
										ResetPass();
										//return 0;
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
			}
			void ResetPass(){
				string Pass,CPass;
				system("cls");
					cout<<"ENTER NEW PASSWORD: ";
					cin>>Pass;
					cout<<"CONFIRM PASSWORD: ";
					cin>>CPass;
					fstream User;
					User.open(FileName);
					if(User.fail()){
						cout<<"Error"<<endl;
					}else
					{
						User.seekg(0);
						User<<Pass;
						cout<<"PASSWORD SUCCESSFULLY CHANGED..."<<endl;			
					}
		}
											
};