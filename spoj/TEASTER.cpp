#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct Date {
	int d, m, y;
};

const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };

int countLeapYears(Date d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

int getDifference(Date dt1, Date dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;

	for (int i = 0; i < dt1.m - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	return (n2 - n1);
}

int main() {
    int firstDig, remain19, temp;
    int ta, tb, tc, td, te;

    int y, d, m;
    bool status = true;

    int date, nmonth, year, testcase;
    char month[10];

    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &date);
        scanf("%s", month);
        scanf("%d", &year);
        // scanf("%d %s %d", &date, month, &year);

        if(strcmp(month, "January") == 0) nmonth=1;
        else if(strcmp(month, "February") == 0) nmonth=2;
        else if(strcmp(month, "March") == 0) nmonth=3;
        else if(strcmp(month, "April") == 0) nmonth=4;
        else if(strcmp(month, "May") == 0) nmonth=5;
        else if(strcmp(month, "June") == 0) nmonth=6;
        else if(strcmp(month, "July") == 0) nmonth=7;
        else if(strcmp(month, "August") == 0) nmonth=8;
        else if(strcmp(month, "September") == 0) nmonth=9;
        else if(strcmp(month, "October") == 0) nmonth=10;
        else if(strcmp(month, "November") == 0) nmonth=11;
        else if(strcmp(month, "December") == 0) nmonth=12;

        y = year;
        firstDig = y/100;
        remain19 = y%19;

        /*Calculate PFM Date */
        temp = (firstDig - 15) / 2 + 202 - 11 * remain19;

        if (firstDig == 21 || firstDig == 24 || firstDig == 25 || firstDig == 34 || firstDig == 35 || firstDig == 38) {
            temp = temp - 1;
        } else if (firstDig >= 27 && firstDig <= 32){
            temp= temp -1;
        } else if (firstDig == 33 || firstDig == 36 || firstDig == 37 || firstDig == 39 || firstDig == 40){
            temp = temp-2;
        }
        temp = temp % 30;

        ta = temp + 21;
        if (temp == 29) {
            ta = ta -1;
        }
        if (temp == 28 && remain19 > 10) {
            ta = ta -1;
        }

        /* find the next sunday */
        tb = (ta - 19) % 7;
        tc = (40 - firstDig) % 4;
        if (tc == 3) {
            tc = tc + 1;
        }
        if (tc > 1) {
            tc = tc + 1;
        }
        temp = y % 100;
        td = (temp + temp /4) % 7;
        te = ((20 - tb - tc - td) % 7) + 1;
        d = ta + te;

        if (d > 31) {
            d = d - 31;
            m = 4;
        } else {
            m = 3;
        }

        Date dt1 = {date, nmonth, year};
        Date dt2 = {d, m, y};
        int hasil = getDifference(dt1, dt2);
        if (hasil >= 0) {
            cout << getDifference(dt1, dt2) << endl;
        } else {
            y = y+1;
            firstDig = y/100;
            remain19 = y%19;

            /*Calculate PFM Date */
            temp = (firstDig - 15) / 2 + 202 - 11 * remain19;

            if (firstDig == 21 || firstDig == 24 || firstDig == 25 || firstDig == 34 || firstDig == 35 || firstDig == 38) {
                temp = temp - 1;
            } else if (firstDig >= 27 && firstDig <= 32){
                temp= temp -1;
            } else if (firstDig == 33 || firstDig == 36 || firstDig == 37 || firstDig == 39 || firstDig == 40){
                temp = temp-2;
            }
            temp = temp % 30;

            ta = temp + 21;
            if (temp == 29) {
                ta = ta -1;
            }
            if (temp == 28 && remain19 > 10) {
                ta = ta -1;
            }

            /* find the next sunday */
            tb = (ta - 19) % 7;
            tc = (40 - firstDig) % 4;
            if (tc == 3) {
                tc = tc + 1;
            }
            if (tc > 1) {
                tc = tc + 1;
            }
            temp = y % 100;
            td = (temp + temp /4) % 7;
            te = ((20 - tb - tc - td) % 7) + 1;
            d = ta + te;

            if (d > 31) {
                d = d - 31;
                m = 4;
            } else {
                m = 3;
            }

            Date dt1 = {date, nmonth, year};
            Date dt2 = {d, m, y};
            cout << getDifference(dt1, dt2) << endl;
        }
    }
        
}