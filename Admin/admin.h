#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "D:\EasyBook.com\Travel\travel.h"
#include "D:\EasyBook.com\Residence\Residence.h"
#include "D:\EasyBook.com\Travel\Flight\Flight.h"
#include "D:\EasyBook.com\Travel\Train\Train.h"
#include "D:\EasyBook.com\Travel\Buses\Bus.h"
using namespace std;

class admin {
    Residence r;
    Flight f;
    Train t;
    Travel *trf=&f;
    Travel *trt=&t;
    Bus b;
    public:
        void flightadd ()
        {
            trf->input();
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
            f.creatFileName();
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
            trt->input();
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
            t.creatFileName();
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
            b.input();
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
            b.creatFileName();
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
};