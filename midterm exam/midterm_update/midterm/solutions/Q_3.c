#include <stdio.h>
int isLeap(int year);
int yearDayDiff(int year, int startMonth, int startDay, int endMonth, int endDay);
int validDate(int month, int day);
int validYearDate(int year, int month, int day);
const int leapYearDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
	int birthMonth, birthDay;
	int year, month, day;

	printf("Please input your birthday: ");
	scanf("%d/%d", &birthMonth, &birthDay);

	if(!validDate(birthMonth, birthDay)){
		printf("Wrong birthday!");
		return 0;
	}
	printf("What's today's date? ");
	scanf("%d/%d/%d", &year, &month, &day);
	if(!validYearDate(year, month, day)){
		printf("Wrong date!");
		return 0;
	}

	int dayToWait = 0;

	int isFeb29 = (birthMonth == 2 && birthDay == 29);

	if((isFeb29 && !isLeap(year)) || month > birthMonth || (month == birthMonth && day > birthDay)){
		dayToWait = yearDayDiff(year, month, day, 12, 31) + 1;
		month =	day = 1;
		year++;

		if(isFeb29){
			while(!isLeap(year)){
				dayToWait += 365;
				year ++;
			}
		}
	}

	dayToWait += yearDayDiff(year, month, day, birthMonth, birthDay);

    printf("You need to wait %d days for your birthday.\n", dayToWait);
	return 0;
}

int isLeap(int year){
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int yearDayDiff(int year, int startMonth, int startDay, int endMonth, int endDay){
	int daySum = endDay - startDay;
	if(!isLeap(year) && startMonth <= 2 && endMonth > 2) daySum--; //if not leap year and Feb
	int i;
	for(i = startMonth - 1; i < endMonth - 1; i++) daySum += leapYearDays[i];
	return daySum;
}

int validDate(int month, int day){
	if(month < 1 || month > 12) return 0;
	if(day < 1 || day > leapYearDays[month - 1]) return 0;
	return 1;
}

int validYearDate(int year, int month, int day){
	if(year < 0 || year > 10000 || (!isLeap(year) && month == 2 && day == 29)) return 0;
	return validDate(month, day);
}
