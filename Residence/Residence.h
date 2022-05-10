#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
class Residence{
    protected:
        char where[15],checkINN[10],checkOUT[10];
        char noOfGuests;
        char fileName [50]="D:\\EasyBook.com\\Residence\\";
    public:
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
        }
        void input (int)
        {
            cout<<"Enter City: ";
            cin>>where;
            cout<<"Number of Guests: ";
            cin>>noOfGuests;
        }
        void creatFileName ()
        {
            strcat(fileName,where);
            strcat(fileName,".txt");
            cout<<fileName<<endl;
        }
        string getfilename()
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
            while (!myfile.eof())
            {
                string text[9];
                for (int i=0;i<8;i++)
                {
                    getline(myfile,text[i]);
                    //cout<<text[i]<<endl;
                }
                cout<<endl;
                if (text[4][0]==noOfGuests)
                {
                    for (int i=0;i<8;i++)
                    {
                        cout<<text[i]<<endl;
                    }
                    cout<<endl;
                }
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
            myfile<<""<<endl;
            myfile.close();
        }
};