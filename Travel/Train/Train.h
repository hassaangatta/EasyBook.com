//#include "D:\EasyBook.com\Travel\travel.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
class Train: public Travel
{
    protected:
        string type;
        char fileName [50]="D:\\EasyBook.com\\Travel\\Train\\";
    public:
        string getfilename ()
        {
            return fileName;
        }
        void input ()
        {
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
            cout<<"When? (Date format mm/dd/yyyy):";
            cin>>when;
            cout<<"Select Class(Economy/Buisness/First):";
            fflush(stdin);
            getline(cin,type);
        }
        void creatFileName ()
        {
            strcat(fileName,from);
            strcat(fileName,"-");
            strcat(fileName,whereTo);
            strcat(fileName,".txt");
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
                if (text[2]==when && text[6]==type && text[5]!="0")
                {
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
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
            myfile<<type<<endl;
            myfile<<features<<endl;
            myfile.close();
        }
};
