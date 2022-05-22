//#include "D:\EasyBook.com\Travel\travel.h"
#include <string>
#include <fstream>
#include <iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;
class Train: public Travel
{
    protected:
        //string type;
        char fileName [50]="D:\\EasyBook.com\\Travel\\Train\\";
        //int seats;
    public:
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
            FileRead();
        }
        void FileRead ()
        {
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
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl<<endl<<endl<<endl;
                }
            }
            book();
        }
        void book(){
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
					cout<<"FINAL BILL = "<<price*seats;	
				}		
			}
		}
		void input ()
        {
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
            cout<<"NUMBER OF SEATS: ";
            cin>>seats;
            cout<<"When? (Date format mm/dd/yyyy):";
            cin>>when;
            cout<<"Select Class(Economy/Buisness/First):";
            fflush(stdin);
            getline(cin,type);
//            cout<<from<<endl<<whereTo;
            createFileName();
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
};
