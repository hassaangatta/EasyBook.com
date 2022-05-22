#include <iostream>
using namespace std;
class Travel{
    protected:
        char from[15],whereTo[15],when[10];
        int quant,seats,price;
        string type,bookId;
        //char fileName [50]="D:\\EasyBook.com\\Travel\\Train\\";
    public:
    	int getSeat(){
    		return seats;
		}
		int getPrice(){
			return price;
		}
		string getBookId(){
			return bookId;		}
        virtual void input ()
        {
            cout<<"From? :";
            cin>>from;
            cout<<"Where? :";
            cin>>whereTo;
            cout<<"When? (Date format mm/dd/yyyy):";
            cin>>when;
        }
		  
};
