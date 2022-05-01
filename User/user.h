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

class user {
    Residence r;
    Flight f;
    Train t;
    Travel *trf=&f;
    Travel *trt=&t;
    Bus b;
};