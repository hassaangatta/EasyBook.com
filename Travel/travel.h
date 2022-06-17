#include <iostream>
using namespace std;
class Travel{
        //char fileName [50]="D:\\EasyBook.com\\Travel\\Train\\";
    public:
    	char from[15],whereTo[15],when[10];
        int quant,seats,price;
        string type,bookId;
    	int getSeat(){
    		return seats;
		}
		int getPrice(){
			return price;
		}
		string getBookId(){
			return bookId;		}
        virtual void input ()=0;
};
