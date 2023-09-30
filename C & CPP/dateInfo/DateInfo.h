#ifndef DATEINFO_H
#define DATEINFO_H

#include <iostream>
#include <cstring>

class DateInfo{

    private:
        int Month, Day, Year;

    public:
        DateInfo(int mont, int day, int year) : Month(mont), Day(day), Year(year){
            std::cout << "Called constructor" << std::endl;
        }
        ~DateInfo(){
            std::cout << "Called destructor" << std::endl;
        }

        void GetDate(int& month, int& day, int& year){
            month = Month;
            day = Day;
            year = Year;
        }


        void GetStringDate(char* strDate){
            snprintf(strDate, 80, "%02d-%02d-%02d", Month, Day, Year%100);
        }


        void GetMonth(char* monthStr) {
            const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            strcpy(monthStr, months[Month - 1]);
        }
};

#endif