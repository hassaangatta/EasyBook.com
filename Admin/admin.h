#include <iostream>
#include <string.h>
#include <cstdio>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
//#include "D:\EasyBook.com\Travel\travel.h"
//#include "D:\EasyBook.com\Residence\Residence.h"
//#include "D:\EasyBook.com\Travel\Flight\Flight.h"
//#include "D:\EasyBook.com\Travel\Train\Train.h"
//#include "D:\EasyBook.com\Travel\Buses\Bus.h"
using namespace std;

class admin {
    Residence r;
    Flight f;
    Train t;
    Travel *trf=&f;
    Travel *trt=&t;
    Bus b;
    public:
    	int logIn(){
    		string UN;
    		char pass[13];
    		int i;
    		char a;
    		cout<<"ENTER USERNAME: ";
    		cin>>UN;
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
//					    cout<<UN<<endl<<pass<<endl;
						//cout<<strcmp(pass,"easybook045")<<endl;
					    if(UN == "Admin" && !strcmp(pass,"easybook045")){
					    	//cout<<"con"<<endl;
							return 1;
					    	
						}
                        cout<<endl;
				return 0;		
		}
        void flightadd ()
        {
            f.input(7);
            int ID;
            string name,time,rs,noOfSeats,features;
            cout<<"Enter Airplane name: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter time: ";
            fflush(stdin);
            getline(cin,time);
            cout<<"Enter Price: ";
            cin>>rs;
            cout<<"Enter No Of Seats: ";
            cin>>noOfSeats;
            cout<<"Enter Features with space in between them : ";
            fflush(stdin);
            getline(cin,features);
            f.createFileName();
            ifstream myfile ;
            myfile.open(f.getfilename());
            if (myfile.fail())
            {
                ofstream file;
                file.open(f.getfilename());
                file.close();
                myfile.open(f.getfilename());
            }
            string str;
            int count=0;
            while (!myfile.eof())
            {
                for (int i=0;i<8;i++)
                {
                    getline(myfile,str);
                    if (i==0)
                    {
                        if (str.empty())
                        {   
                            if (count==0)
                            ID=1000;
                            else 
                            continue;
                        }
                        else 
                        {
                            count++;
                            ID=stoi(str);
                            ID++;
                        }
                    }

                }
            }
            myfile.close();
            f.FileWrite(ID,name,time,rs,noOfSeats,features);
        }
        void trainadd ()
        {
            t.input(7);
            int ID;
            string name,time,rs,noOfSeats,features;
            cout<<"Enter Train name: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter time: ";
            fflush(stdin);
            getline(cin,time);
            cout<<"Enter Price: ";
            cin>>rs;
            cout<<"Enter No Of Seats: ";
            cin>>noOfSeats;
            cout<<"Enter Features with space in between them : ";
            fflush(stdin);
            getline(cin,features);
            t.createFileName();
            ifstream myfile ;
            myfile.open(t.getfilename());
            if (myfile.fail())
            {
                ofstream file;
                file.open(t.getfilename());
                file.close();
                myfile.open(t.getfilename());
            }
            string str;
            int count=0;
            while (!myfile.eof())
            {
                for (int i=0;i<8;i++)
                {
                    getline(myfile,str);
                    if (i==0)
                    {
                        if (str.empty())
                        {   
                            if (count==0)
                            ID=2000;
                            else 
                            continue;
                        }
                        else 
                        {
                            count++;
                            ID=stoi(str);
                            ID++;
                        }
                    }

                }
            }
            myfile.close();
            t.FileWrite(ID,name,time,rs,noOfSeats,features);
        }
        void busadd ()
        {
            b.input(7);
            int ID;
            string name,time,rs,noOfSeats,features;
            cout<<"Enter Bus name: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter time: ";
            fflush(stdin);
            getline(cin,time);
            cout<<"Enter Price: ";
            cin>>rs;
            cout<<"Enter No Of Seats: ";
            cin>>noOfSeats;
            cout<<"Enter Features with space in between them : ";
            fflush(stdin);
            getline(cin,features);
            b.createFileName();
            ifstream myfile ;
            myfile.open(b.getfilename());
            if (myfile.fail())
            {
                ofstream file;
                file.open(b.getfilename());
                file.close();
                myfile.open(b.getfilename());
            }
            string str;
            int count=0;
            while (!myfile.eof())
            {
                for (int i=0;i<7;i++)
                {
                    getline(myfile,str);
                    if (i==0)
                    {
                        if (str.empty())
                        {   
                            if (count==0)
                            ID=3000;
                            else 
                            continue;
                        }
                        else 
                        {
                            count++;
                            ID=stoi(str);
                            ID++;
                        }
                    }

                }
            }
            myfile.close();
            b.FileWrite(ID,name,time,rs,noOfSeats,features);
        }
        void residenceadd ()
        {
            r.input(2);
            int ID;
            string name,adderess,type,features,rating,price;
            cout<<"Enter Hotel/Guest House name: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter Adderess: ";
            fflush(stdin);
            getline(cin,adderess);
            cout<<"Enter Type: ";
            fflush(stdin);
            getline(cin,type);
            cout<<"Enter Features with space in between them : ";
            fflush(stdin);
            getline(cin,features);
            cout<<"Enter current rating from google: ";
            fflush(stdin);
            getline(cin,rating);
            cout<<"Enter Price per night: ";
            fflush(stdin);
            getline(cin,price);
            r.createFileName();
            ifstream myfile ;
            myfile.open(r.getfilename());
            if (myfile.fail())
            {
                ofstream file;
                file.open(r.getfilename());
                file.close();
                myfile.open(r.getfilename());
            }
            string str;
            int count=0;
            while (!myfile.eof())
            {
                for (int i=0;i<9;i++)
                {
                    getline(myfile,str);
                    if (i==0)
                    {
                        if (str.empty())
                        {   
                            if (count==0)
                            ID=5000;
                            else 
                            continue;
                        }
                        else 
                        {
                            count++;
                            ID=stoi(str);
                            ID++;
                        }
                    }

                }
            }
            myfile.close();
            r.FileWrite(ID,name,adderess,type,features,rating,price);
        }
        void residencedelete ()
        {
            r.input('c');
            string ID;
            r.createFileName();
            ifstream myfile;
            myfile.open(r.getfilename());
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (!myfile.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of hotel/guest house you want to delete: ";
            cin>>ID;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(r.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="" && text[0]!=ID)
                {
                    for (int i=0;i<9;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(r.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(r.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<9;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");
        }
        void flightdelete()
        {
            f.input('c');
            f.createFileName(); 
            string ID;
            ifstream myfile;
            myfile.open(f.getfilename());
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
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of flight you want to delete: ";
            cin>>ID;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(f.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="" && text[0]!=ID)
                {
                    for (int i=0;i<8;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(f.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(f.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
        void traindelete()
        {
            t.input('c');
            t.createFileName(); 
            string ID;
            ifstream myfile;
            myfile.open(t.getfilename());
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
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of train you want to delete: ";
            cin>>ID;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(t.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="" && text[0]!=ID)
                {
                    for (int i=0;i<8;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(t.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(t.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
        void busdelete()
        {
            b.input('c');
            b.createFileName(); 
            string ID;
            ifstream myfile;
            myfile.open(b.getfilename());
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (!myfile.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<6;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of bus you want to delete: ";
            cin>>ID;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(b.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="" && text[0]!=ID)
                {
                    for (int i=0;i<7;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(b.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(b.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
        void residencePriceUpdate()
        {
            r.input('c');
            string ID,price;
            r.createFileName();
            ifstream myfile;
            myfile.open(r.getfilename());
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (!myfile.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of hotel/guest house for which you want to update price: ";
            cin>>ID;
            cout<<"Enter New price: ";
            cin>>price;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(r.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    if (text[0]==ID)
                    {
                        text[7]=price;
                    }
                    for (int i=0;i<9;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(r.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(r.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[9];
                for (int i=0;i<9;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<9;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");
        }
        void flightPriceUpdate()
        {
            f.input('c');
            f.createFileName(); 
            string ID,price;
            ifstream myfile;
            myfile.open(f.getfilename());
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
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of flight for which you want to update price: ";
            cin>>ID;
            cout<<"Enter Updated Price: ";
            cin>>price;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(f.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    if (text[0]==ID)
                    {
                        text[4]=price;
                    }
                    for (int i=0;i<8;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(f.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(f.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
        void trainPriceUpdate()
        {
            t.input('c');
            t.createFileName(); 
            string ID,price;
            ifstream myfile;
            myfile.open(t.getfilename());
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
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of train for which you want to update price : ";
            cin>>ID;
            cout<<"Enter Updated Price: ";
            cin>>price;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(t.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    if (text[0]==ID)
                    {
                        text[4]=price;
                    }
                    for (int i=0;i<8;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(t.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(t.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[8];
                for (int i=0;i<8;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<8;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
        void busPriceUpdate()
        {
            b.input('c');
            b.createFileName(); 
            string ID,price;
            ifstream myfile;
            myfile.open(b.getfilename());
            if (myfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while (!myfile.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<6;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
            }    
            myfile.close();
            cout<<"Enter ID of bus for which you want to update price: ";
            cin>>ID;
            cout<<"Enter Updated Price: ";
            cin>>price;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream currfile;
            currfile.open(b.getfilename());
            if (currfile.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!currfile.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(currfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    if (text[0]==ID)
                    {
                        text[4]=price;
                    }
                    for (int i=0;i<7;i++)
                    {
                        tempfile<<text[i]<<endl;
                    }
                }
            }
            tempfile.close();
            currfile.close();
            fstream file;
            file.open(b.getfilename(),ios::trunc);
            file.close();
            ofstream file1;
            file1.open(b.getfilename());
            ifstream file2;
            file2.open("temp.txt");
            if (file2.fail())
            {
                cout<<"Error"<<endl;
            }
            while(!file2.eof())
            {
                string text[7];
                for (int i=0;i<7;i++)
                {
                    getline(file2,text[i]);
                    //cout<<text[i]<<endl;
                }
                if (text[0]!="")
                {
                    for (int i=0;i<7;i++)
                    {
                        file1<<text[i]<<endl;
                    }
                }
            }
            file1.close();
            file2.close();
            remove("temp.txt");  
        }
};
