#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int hour,minute,second,a,error;
	
	error=a=0;
	
	while(error==0)
	{
		cout<<"Enter hour: ";
		cin>>hour;
		
		cout<<"Enter minute: ";
		cin>>minute;
		
		cout<<"Enter second: ";
		cin>>second;
		
		if(hour<24&&minute<60&&second<60){
			error++;
		}
		else{
			system("cls");
		}
		
	}
	
	while(a==0)
	{
		system("cls");
		cout<<hour<<":"<<minute<<":"<<second<<endl;
		Sleep(1000);
		second++;
		if(second>59){
			second=0;
			minute++;
		}
		
		if(minute>59){
			minute=0;
			hour++;
		}
		
		if(hour>24){
			hour=0;
		}
	}
	
	return 0;
}
