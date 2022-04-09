#include <iostream>
using namespace std;
class Travel{
    protected:
        char from[15],whereTo[15],when[10];
        int quant;
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
        
};