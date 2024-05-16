#include<stdio.h>
#include <Windows.h>
#define CYCLE 5


int main(){
	int hour,minute,second;
	
	printf("Enter Hour Minute Second:");
	scanf("%d%d%d",&hour,&minute,&second);

	
	int h=0,m=0,s=0;
	while(1){
		system("cls");
		printf("%.2d:%.2d:%.2d\n",h,m,s);
		if(h==hour&&m==minute&&s==second){
			break;
		}
		
		s++;
		sleep(1);
		if(s==CYCLE){
			m++;
			s=0;
		}
		if(m==CYCLE){
			h++;
			m=0;
		}
	}
	
	
	return 0;
}
