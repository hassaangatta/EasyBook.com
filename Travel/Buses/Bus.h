//#include "D:\EasyBook.com\Travel\travel.h"
#include <string.h>
#include <fstream>
class Bus: public Travel
{
    protected:
        char fileName [50] = "D:\\EasyBook.com\\Travel\\Buses\\";
    public:
		void input ()
        {
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
            cout<<"When? (Date format mm/dd/yyyy):";
            cin>>when;
        }
		void input (int)
        {
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
        }
		string getfilename ()
        {
            return fileName;
        }
    	void createFileName()
        {
            strcat(fileName,from);
            strcat(fileName,"-");
            strcat(fileName,whereTo);
            strcat(fileName,".txt");
            FileRead();
    	}
    	void FileRead()
    	{
    		ifstream myfile;
			myfile.open(fileName);
			if (myfile.fail());
			{
				cout << "Error" << endl;	
			} 
			while(!myfile.eof())
			{
				string text[7];
				for(int i = 0; i < 7; i++)
				{
					getline(myfile, text[i]);
				}
				if(text[2] == when && text[5] != "0")
				{
					for(int i = 0; i < 7; i++)
					{
						cout << text[i] << endl;
					}
				}
			}
			book();
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
//            cout<<from<<endl<<whereTo;
            createFileName();
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
					cout<<line<<endl;
					if(i==4){
						fileSeats = stoi(line);
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
            myfile<<features<<endl;
            myfile.close();
        }
};
