#include<iostream>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int sizer(int month, int year)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        return 31;
    }
    else if(month==4||month==6||month==9||month==11)
    {
        return 30;
    }
    else if(month==2)
    {
         if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int day=1,month=1,year;
    int max = 100; //set the upper bound to generate the random number
    srand(time(0));
    int k=rand()%max;
    string date,setter;
    cout<<"Enter Year :";
    cin>>year;
    string file;
    file="echo k >>"+to_string(year)+".txt";
    const char *command1=file.c_str();//converting string to const char
    system("timedatectl set-ntp 0");
    while(month<=12)
    {
        for (int i=1; i<=sizer(month,year); i++)
    {
        date=to_string(year)+"-"+to_string(month)+"-"+to_string(day);
        setter="timedatectl set-time "+date;
        const char *command=setter.c_str();
        system(command);
        system("git init");
        for(int z=0;z<=k;z++)
        {
            system(command1);
            system("git add .");
            system("git commit -m \"fillgit\"");
        }
        day++;
        system("git push");
    }
    day=1;
    month++;
    
    }
    system("timedatectl set-ntp 1");
    return 0;
}