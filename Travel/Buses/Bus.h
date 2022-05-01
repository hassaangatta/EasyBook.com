//#include "D:\EasyBook.com\Travel\travel.h"
#include <string.h>
#include <fstream>
class Bus: public Travel
{
    protected:
        char fileName [50] = "D:\\EasyBook.com\\Travel\\Buses\\";
    public:
		string getfilename ()
        {
            return fileName;
        }
    	void creatFileName()
        {
            strcat(fileName,from);
            strcat(fileName,"-");
            strcat(fileName,whereTo);
            strcat(fileName,".txt");
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
