#include<stdio.h>
int fr[3],m;
void display();
void main()
{
 int i,j,page[20];
 int flag1=0,flag2=0,pf=0;
 int n, top=0;
 float pr;
 system("clear");
 printf("Enter length of the reference string: ");
 scanf("%d",&n);
 printf("Enter the reference string: ");
	for(i=0;i<n;i++)
		scanf("%d",&page[i]);
 printf("Enter no of frames: ");
 scanf("%d",&m);
	for(i=0;i<m;i++)
		fr[i]=-1;
		for(j=0;j<n;j++) {
		 flag1=0;
		 flag2=0;
			 for(i=0;i<m;i++) {
			 if(fr[i]==page[j]) {
			 flag1=1;
			 flag2=1;
			  break; } }
			 if(flag1==0) {
				 for(i=0;i<m;i++) {
				 if(fr[i]==-1)  {
				 fr[i]=page[i];
				 flag2=1;
				 break;  } } }
 if(flag2==0)  {
 fr[top]=page[j];
 top++;
 pf++;
 if(top>=m)
 top=0;  }
 display(); }
pf+=m;
printf("Number of page faults : %d\n", pf);
pr=(float)pf/n*100;
printf("Page fault rate = %f \n", pr); }
void display() {
 int i;
	for(i=0;i<m;i++)
		printf("%d\t", fr[i]);
	printf("\n"); }
 