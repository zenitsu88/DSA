#include<iostream>
#include<string.h>
using namespace std;
typedef struct student
{
int roll_num;
char name [10];
float marks;
}s;
void insertionSort(s student[10], int n)
{
int i, j;
s key;
for (i = 1; i < n; i++)
{
key= student[i];
j = i - 1;
while (j >= 0 && strcmp(student[j].name, key.name) >0)
{
student[j + 1]= student[j];
j = j - 1;
}
student[j + 1]= key;
}
}
int par(s student[10], int l,int u)
{
int i,j;
s temp, v;
v=student[l];
i=l;
j=u+1;
do
{
do
i++;
while(student[i].marks<v.marks&&i<=u);
do
j--;
while(v.marks<student[j].marks);
if(i<j)
{
temp=student[i];
student[i]=student[j];
student[j]=temp;
}
}while(i<j);
student[l]=student[j];
student[j]=v;
return(j);
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
"\n3. Insertion sort(name)"
"\n4. Exit"
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
insertionSort(student,n);
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
}while(choice!=4);
return 0;
}

