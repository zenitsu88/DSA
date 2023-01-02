#include<iostream>
#include<string.h>
using namespace std;
typedef struct student
{
int roll_num;
char name [10];
float marks;
}s;
void bubble_sort(s student[10],int n)
{
int i,j;
s temp;
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(student[j].roll_num>student[j+1].roll_num)
{
temp=student[j];
student[j]=student[j+1];
student[j+1]=temp;
}
}
}
}
int main()
{
s student[10];
int choice,n;;
do
{
cout<<"\nEnter your choice:"
"\n1. Create database"
"\n2. Display database"
"\n3. Bubble sort(according to roll number)"
"\n4. Exit "
"\n Choice:";
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"\nEnter number of records:";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\nEnter roll number:";
cin>>student[i].roll_num;
cout<<"\nEnter name:";
cin>>student[i].name;
cout<<"\nEnter marks:";
cin>>student[i].marks;
}
break;
}
case 2:
{
cout<<"\n\tRoll number\tName\tMarks";
for(int i=0;i<n;i++)
{
cout<<"\n\t"<<student[i].roll_num<<"\t"<<student[i].name<<"\t"<<student[i].marks;
}
break;
}
case 3:
{
bubble_sort(student,n);
cout<<"\n\tRoll number\tName\tMarks";


for(int i=0;i<n;i++)
{
cout<<"\n\t"<<student[i].roll_num<<"\t"<<student[i].name<<"\t"<<student[i].marks;
}
break;
}
case 4:
{
break;
}

}
}
while(choice!=4);
return 0;
}
