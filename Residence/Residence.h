#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <ctime>
using namespace std;
class Residence{
    protected:
        char where[15],checkINN[10],checkOUT[10];
        char noOfGuests;
        char fileName [50]="D:\\EasyBook.com\\Residence\\";
        string bookId;
        int price;
    public:
        bool comparison (string given,string checkInn ,string checkOut);
		string todaysDate();
        void input ()
        {
            cout<<"Where? :";
            cin>>where;
            cout<<"Check Inn (Date format mm/dd/yyyy):";
            cin>>checkINN;
            cout<<"Check Out (Date format mm/dd/yyyy):";
            cin>>checkOUT;
            cout<<"Number of Guests: ";
            cin>>noOfGuests;
            createFileName();
        }
        void input (int)
        {
            cout<<"Enter City: ";
            cin>>where;
            cout<<"Number of Guests: ";
            cin>>noOfGuests;
        }
<<<<<<< Updated upstream
        void createFileName ()
        {
            strcat(fileName,where);
            strcat(fileName,".txt");
            FileRead();
        }
		void creatFileName (char city[20])
=======
		void input (char)
        {
            cout<<"Enter City: ";
            cin>>where;
        }
        void creatFileName ()
>>>>>>> Stashed changes
        {
            strcat(fileName,where);
            strcat(fileName,".txt");
        }
        string getfilename()
        {
            return fileName;
        }
		char * getfilename(int)
		{
			return fileName;
		}
        void FileRead ()
        {
            ifstream myfile;
            myfile.open(fileName);
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (myfile)
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[4][0]==noOfGuests && comparison(text[8],checkINN,checkOUT)==true)
                {
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }
            book();
        }
        void book(){
        	int chk;
        	string ch,line;
        	string CIM , CID , CIY , COM , COD , COY;
        	cout<<"ENTER ID TO BOOK ELSE ENTER 0 TO EXIT: ";
        	cin>>ch;
        	if(ch != "0"){
        		fstream booking;
        	booking.open(fileName);
        	while(!booking.eof() && line != ch){
        		getline(booking,line);
			}
			bookId = line;
			system("cls");
			for(int i=0;i<6;i++){
				getline(booking,line);
				cout<<line;
				if(i==4){
					price = stoi(line);
				}
			}
			cout<<"CHECK INN DATE: "<<checkINN<<endl;
			cout<<"CHECK OUT DATE: "<<checkOUT<<endl;
			cout<<endl<<endl;
			cout<<"PRESS 1 TO CONFIRM BOOKING: ";
			cin>>chk;
			if(chk == 1){
				cout<<"FINAL BILL: "<<price;
			}
			booking.close();	
			}
		}
        void FileWrite (int ID,string name,string adderess,string type,string features,string rating ,string price )
        {
            ofstream myfile;
            myfile.open(fileName,ios_base::app);
            myfile<<ID<<endl;
            myfile<<name<<endl;
            myfile<<adderess<<endl;
            myfile<<type<<endl;
            myfile<<noOfGuests<<" Guests"<<endl;
            myfile<<features<<endl;
            myfile<<rating<<endl;
            myfile<<price<<endl;
            myfile<<todaysDate()<<endl;
            myfile.close();
        }
};
bool Residence::comparison(string given,string checkInn ,string checkOut)
{
	// string given = "03/24/2022 04/04/2022 12/13/2022 02/14/2020 02/15/2022";
	int count = 0;
	for (int i = 0; i < given.size()-1; i++)
	{
		if (given[i] == ' ')
		count++;
	}
	count++;
	string bookedDates [count];
	int start = 0;
	for (int i = 0; i < count; i++)
	{
		bookedDates[i] = given.substr(start,10);
		start += 11;
	}
	
	// string arr[2];
	
	// cout << "Enter check in date: ";
	// cin >> arr[0];
	// cout << "Enter check out date: ";
	// cin >> arr[1];
	
	string mo1, da1, ye1, mo2, da2, ye2;
	int m1, d1, y1, m2, d2, y2, month, day, year, date1, date2, date3, sizeofrdate,check=0;
	
	mo1 = checkInn.substr(0,2);
	
	stringstream month1(mo1);
	month1 >> m1;
	
	da1 = checkInn.substr(3,2);
	
	stringstream day1(da1);
	day1 >> d1;
	
	ye1 = checkInn.substr(6,4);
	
	stringstream year1(ye1);
	year1 >> y1;
	
	mo2 = checkOut.substr(0,2);
	
	stringstream month2(mo2);
	month2 >> m2;
	
	da2 = checkOut.substr(3,2);
	
	stringstream day2(da2);
	day2 >> d2;
	
	ye2 = checkOut.substr(6,4);
	
	stringstream year2(ye2);
	year2 >> y2;
	
	char D1[4], D2[4], D3[4], m[4], y[5], M[4],Y[5];
	
	itoa(m1,m,10);
	itoa(y1,y,10);
		
	itoa(m2,M,10);
	itoa(y2,Y,10);
	
	if(m1 == m2)
	{
		day = d2 - d1;
		char requireddates[day+1][11];
		sizeofrdate = day+1;
		for(int i = 0; i <= day; i++)
		{
			char temp[11] = "";
			date1 = d1 + i;
			itoa(date1,D1,10);
			if ((m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9 ) && (date1==1 || date1==2 || date1==3 || date1==4 || date1==5 || date1==6 || date1==7 || date1==8 ||date1==9 ))
			{
				strcat(temp,"0");
				strcat(temp,m);
				strcat(temp,"/");
				strcat(temp,"0");
				strcat(temp,D1);
				strcat(temp,"/");
				strcat(temp,y);
			}
			else if (m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9)
			{
				strcat(temp,"0");
				strcat(temp,m);
				strcat(temp,"/");
				strcat(temp,D1);
				strcat(temp,"/");
				strcat(temp,y);
			}
			else if (date1==1 || date1==2 || date1==3 || date1==4 || date1==5 || date1==6 || date1==7 || date1==8 ||date1==9)
			{
				strcat(temp,m);
				strcat(temp,"/");
				strcat(temp,"0");
				strcat(temp,D1);
				strcat(temp,"/");
				strcat(temp,y);
			}
			else
			{
				strcat(temp,m);
				strcat(temp,"/");
				strcat(temp,D1);
				strcat(temp,"/");
				strcat(temp,y);
			}
			strcpy(requireddates[i],temp);		
		}
		for(int i = 0; i < sizeofrdate; i++)
		{
			for(int j = 0; j < count; j++)
			{
				if(requireddates[i] == bookedDates[j])
				{
					check=1;
				}
			}
		}
	}
	else
	{
		if(m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
		{
			date1 = 31 - d1;
			int k;
			char requireddates[date1+d2+1][10];
			sizeofrdate = date1+d2+1;
			for(int i = 0; i <= date1; i++)
			{
				char temp[10] = "";
				date2 = d1 + i;
				itoa(date2,D2,10);
				if ((m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9 ) && (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9 ))
				{
					strcat(temp,"0");
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else if (m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9)	
				{
					strcat(temp,"0");
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else if (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9)
				{
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else 
				{
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				k = i;
				strcpy(requireddates[i],temp);
			}
			int j = 0;
			k++;
			for(int i = k; i < sizeofrdate; i++)
			{	
				j++;
				char temp[10] = "";
				date3 = j;
				itoa(date3,D3,10);
				if ((m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9 ) && (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9 ))
				{
					strcat(temp,"0");
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else if (m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9)
				{
					strcat(temp,"0");
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else if (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9)
				{
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else 
				{
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}		
				strcpy(requireddates[i],temp);
			}
			for(int i = 0; i < sizeofrdate; i++)
			{
				for(int j = 0; j < count; j++)
				{
					int counting = 0;
					for (int k = 0; k < 10; k++)
					{
						if(requireddates[i][k] == bookedDates[j][k])
						{
							counting++;
						}	
					}
					if (counting == 10)
					{
						check = 1;
					}
				}
			}	
		}
		else if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
		{
			date1 = 30 - d1;
			int k;
			char requireddates[date1+d2+1][10];
			sizeofrdate = date1+d2+1;
			for(int i = 0; i <= date1; i++)
			{
				char temp[10] = "";
				date2 = d1 + i;
				itoa(date2,D2,10);
				if ((m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9 ) && (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9 ))
				{
					strcat(temp,"0");
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else if (m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9)	
				{
					strcat(temp,"0");
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else if (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9)
				{
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				else 
				{
					strcat(temp,m);
					strcat(temp,"/");
					strcat(temp,D2);
					strcat(temp,"/");
					strcat(temp,y);
				}
				k = i;
				strcpy(requireddates[i],temp);
			}
			int j = 0;
			k++;
			for(int i = k; i < sizeofrdate; i++)
			{
				j++;
				char temp[10] = "";
				date3 = j;
				itoa(date3,D3,10);
				if ((m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9 ) && (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9 ))
				{
					strcat(temp,"0");
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else if (m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9)
				{
					strcat(temp,"0");
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else if (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9)
				{
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,"0");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				else 
				{
					strcat(temp,M);
					strcat(temp,"/");
					strcat(temp,D3);
					strcat(temp,"/");
					strcat(temp,Y);
				}
				strcpy(requireddates[i],temp);
			}
			for(int i = 0; i < sizeofrdate; i++)
			{
				for(int j = 0; j < count; j++)
				{
					int counting = 0;
					for (int k = 0; k < 10; k++)
					{
						if(requireddates[i][k] == bookedDates[j][k])
						{
							counting++;
						}	
					}
					if (counting == 10)
					{
						check = 1;
					}
				}
			}
		}
		else if(m1 == 2)
		{
			if(y1 % 4 == 0)
			{
				date1 = 29 - d1;
				int k;
				char requireddates[date1+d2+1][10];
				sizeofrdate = date1+d2+1;
				for(int i = 0; i <= date1; i++)
				{
					char temp[10] = "";
					date2 = d1 + i;
					itoa(date2,D2,10);
					if ((m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9 ) && (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9 ))
					{
						strcat(temp,"0");
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else if (m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9)	
					{
						strcat(temp,"0");
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else if (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9)
					{
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else 
					{
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}	
					k = i;
					strcpy(requireddates[i],temp);
				}
				int j = 0;
				k++;
				for(int i = k; i < sizeofrdate; i++)
				{
					j++;
					char temp[10] = "";
					date3 = j;
					itoa(date3,D3,10);
					if ((m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9 ) && (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9 ))
					{
						strcat(temp,"0");
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else if (m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9)
					{
						strcat(temp,"0");
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else if (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9)
					{
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else 
					{
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					strcpy(requireddates[i],temp);
				}
				for(int i = 0; i < sizeofrdate; i++)
				{
					for(int j = 0; j < count; j++)
					{
						int counting = 0;
						for (int k = 0;k < 10; k++)
						{
							if(requireddates[i][k] == bookedDates[j][k])
							{
								counting++;
							}	
						}
						if (counting == 10)
						{
							check = 1;
						}
					}
				}
			}
			else if(y1 % 4 != 0)
			{
				date1 = 28 - d1;
				int k;
				char requireddates[date1+d2+1][10];
				sizeofrdate = date1+d2+1;
				for(int i = 0; i <= date1; i++)
				{
					char temp[10] = "";
					date2 = d1 + i;
					itoa(date2,D2,10);
					if ((m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9 ) && (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9 ))
					{
						strcat(temp,"0");
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else if (m1==1 || m1==2 || m1==3 || m1==4 || m1==5 || m1==6 || m1==7 || m1==8 ||m1==9)	
					{
						strcat(temp,"0");
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else if (date2==1 || date2==2 || date2==3 || date2==4 || date2==5 || date2==6 || date2==7 || date2==8 ||date2==9)
					{
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					else 
					{
						strcat(temp,m);
						strcat(temp,"/");
						strcat(temp,D2);
						strcat(temp,"/");
						strcat(temp,y);
					}
					k = i;
					strcpy(requireddates[i],temp);
				}
				int j = 0;
				k++;
				for(int i = 0; i < sizeofrdate; i++)
				{
					j++;
					char temp[10] = "";
					date3 = j;
					itoa(date3,D3,10);
					if ((m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9 ) && (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9 ))
					{
						strcat(temp,"0");
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else if (m2==1 || m2==2 || m2==3 || m2==4 || m2==5 || m2==6 || m2==7 || m2==8 ||m2==9)
					{
						strcat(temp,"0");
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else if (date3==1 || date3==2 || date3==3 || date3==4 || date3==5 || date3==6 || date3==7 || date3==8 ||date3==9)
					{
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,"0");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					else 
					{
						strcat(temp,M);
						strcat(temp,"/");
						strcat(temp,D3);
						strcat(temp,"/");
						strcat(temp,Y);
					}
					strcpy(requireddates[i],temp);
				}
				for(int i = 0; i < sizeofrdate; i++)
				{
					for(int j = 0; j < count; j++)
					{
						int counting = 0;
						for (int k = 0;k < 10; k++)
						{
							if(requireddates[i][k] == bookedDates[j][k])
							{
								counting++;
							}	
						}
						if (counting == 10)
						{
							check = 1;
						}
					}
				}
			}
		}
	}
	if (check==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string Residence::todaysDate ()
{
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