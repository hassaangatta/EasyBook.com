//#include "D:\EasyBook.com\Travel\travel.h"
#include <string>
#include <fstream>
#include <iostream>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
using namespace std;
class Train : public Travel{
	char fileName [50]="D:\\EasyBook.com\\Travel\\Train\\";
    public:
    	string type;
        int seats;
        string getfilename ()
        {
            return fileName;
        }
        void createFileName ()
        {
            strcat(fileName,from);
            strcat(fileName,"-");
            strcat(fileName,whereTo);
            strcat(fileName,".txt");
        }
        void FileRead ()
        {
			int flag=0;  
            ifstream myfile;
            myfile.open(fileName);
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (!myfile.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                //cout<<endl;
                if (text[2]==when && text[6]==type && stoi(text[5])>seats)
                {
					flag=1;
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl<<endl<<endl<<endl;
                }
            }
			if (flag==0)
			{
				cout<<"NO TRAIN AVAILABLE OF YOUR ENTERED DATA...."<<endl;
			}
        }
        int book(){
        	int count,fileSeats,confirmation;
        	string ch;
        	cout<<"ENTER ID TO BOOK OR ENTER 0 TO EXIT: ";
        	cin>>ch;
        	if(ch != "0" ){
				fstream booking;
				booking.open(fileName);
				string line;
				while(!booking.eof() && line != ch){
					//count++;
					getline(booking,line);
					//cout<<endl<<line;
				}
				bookId = line;
				//cout<<bookId<<endl;
				system("cls");
				for(int i=0;i<7;i++){
					getline(booking,line);
					//cout<<line<<endl;
					if(i==4){
						fileSeats = stoi(line);
						cout<<seats<<endl;
					}else
					{
						cout<<line<<endl;
					}
					if(i==3){
						price = stoi(line);
					}
				}
				cout<<"NUMBER OF SEATS TO BE BOOKED: "<<seats<<endl;
				booking.close();
				cout<<"CONFIRM BOOKING PRESS 1 ELSE ENTER 0: ";
				cin>>confirmation;
				if(confirmation == 1){
					fstream main;
					ofstream temp;
					main.open(fileName);
					temp.open("temp.txt");
					while(!main.eof()){
						getline(main,line);
						if(line == ch){
							temp<<line<<endl;
							for(int i=0;i<7;i++){
								getline(main,line);
								if(i==4)
								{
									temp<<fileSeats-seats<<endl;
								}else
								{
									temp<<line<<endl;
								}
								if(i==3){
									price = stoi(line);
								}
							}
						}else
						{
							temp<<line<<endl;
						}
					}
					temp.close();
					main.close();
					fstream temporary;
					fstream mainfile;
					mainfile.open(fileName);
					temporary.open("temp.txt");
					mainfile.clear();
					while(!temporary.eof()){
						getline(temporary,line);
						mainfile<<line<<endl;
					}
					main.close();
					temp.close();
					remove("temp.txt");
					cout<<endl<<endl;
					cout<<"FINAL BILL = "<<price*seats<<endl;	
				}		
			}
			return confirmation;
		}
		void input(int){
			int dateValid,mm,dd,yy;
        	string m,y,d;
			cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
			while(dateValid != 1){
            	cout<<"When? (Date format mm/dd/yyyy):";
            	cin>>when;
            	if(when > todaysDate()){
            		m = when[0];
            		m += when[1];
            		d = when[3];
            		d += when[4];
            		y = when[6];
            		y += when[7];
            		y += when[8];
            		y += when[9];
            		mm = stoi(m);
            		dd = stoi(d);
            		yy = stoi(y);
//            		cout<<mm<<endl<<dd<<endl<<yy<<endl;
//            		cout<<(mm >= 1 && mm <= 12)<<endl;
//            		cout<<(dd >= 1 && dd <= 31)<<endl;
//            		cout<<(yy >= 2022 && yy <= 2100)<<endl;
            		if((mm >= 1 && mm <= 12) && (dd >= 1 && dd <= 31) && (yy >= 2022 && yy <= 2100)){
            			dateValid = 1;
					}else
					{
						cout<<"INVALID DATE...."<<endl;
						continue;
					}
				}else if(when == todaysDate())
				{
					cout<<"SAME DAY BOOKING IS NOT POSSIBLE.."<<endl;
					continue;
				}else if(when < todaysDate()){
					cout<<"DATE ALREADYY PASSED..."<<endl;
				}
			}
            cout<<"Select Class(Economy/Buisness/First):";
            fflush(stdin);
            getline(cin,type);
		}
		void input (char)
		{
			cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
		}
		void input ()
        {
        	int dateValid,mm,dd,yy;
        	string m,y,d;
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
            cout<<"NUMBER OF SEATS: ";
            cin>>seats;
            while(dateValid != 1){
            	cout<<"When? (Date format mm/dd/yyyy):";
            	cin>>when;
            	if(when > todaysDate()){
            		m = when[0];
            		m += when[1];
            		d = when[3];
            		d += when[4];
            		y = when[6];
            		y += when[7];
            		y += when[8];
            		y += when[9];
            		mm = stoi(m);
            		dd = stoi(d);
            		yy = stoi(y);
//            		cout<<mm<<endl<<dd<<endl<<yy<<endl;
//            		cout<<(mm >= 1 && mm <= 12)<<endl;
//            		cout<<(dd >= 1 && dd <= 31)<<endl;
//            		cout<<(yy >= 2022 && yy <= 2100)<<endl;
            		if((mm >= 1 && mm <= 12) && (dd >= 1 && dd <= 31) && (yy >= 2022 && yy <= 2100)){
            			dateValid = 1;
					}else
					{
						cout<<"INVALID DATE...."<<endl;
						continue;
					}
				}else if(when == todaysDate())
				{
					cout<<"SAME DAY BOOKING IS NOT POSSIBLE.."<<endl;
					continue;
				}else if(when < todaysDate()){
					cout<<"DATE ALREADYY PASSED..."<<endl;
				}
			}
            cout<<"Select Class(Economy/Buisness/First):";
            fflush(stdin);
            getline(cin,type);
//            cout<<from<<endl<<whereTo;
            //createFileName();
        }
        void FileWrite (int ID,string name,string time,string rs,string seats,string features)
        {
            ofstream myfile;
            myfile.open(fileName,ios_base::app);
            myfile<<ID<<endl;
            myfile<<name<<endl;
            myfile<<when<<endl;
            myfile<<time<<endl;
            myfile<<rs<<endl;
            myfile<<seats<<endl;
            myfile<<type<<endl;
            myfile<<features<<endl;
            myfile.close();
        }
        string todaysDate(){
        	string date,month,year,todaysDate,mon;
			time_t curr_time;
			curr_time = time(NULL);
			string tm = ctime(&curr_time);
			month=tm.substr(4,3);
			date=tm.substr(8,2);
			year=tm.substr(20,4);
			if (month=="Jan")
			mon="01";
			else if (month=="Feb")
			mon="02";
			else if (month=="Mar")
			mon="03";
			else if (month=="Apr")
			mon="04";
			else if (month=="May")
			mon="05";
			else if (month=="Jun")
			mon="06";
			else if (month=="Jul")
			mon="07";
			else if (month=="Aug")
			mon="08";
			else if (month=="Sep")
			mon="09";
			else if (month=="Oct")
			mon="10";
			else if (month=="Nov")
			mon="11";
			else if (month=="Dec")
			mon="12";
			todaysDate=mon+"/"+date+"/"+year;
			return todaysDate;
		}
};
