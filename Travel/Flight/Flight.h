#include "D:\EasyBook.com\EasyBook.com\Travel\travel.h"
#include <string.h>
class Flight: public Travel
{
    protected:
        string type;
        char fileName [30];
    public:
        void creatFileName ()
        {
            strcpy(fileName,from);
            strcat(fileName,"-");
            strcat(fileName,whereTo);
            strcat(fileName,".txt");
        }
};