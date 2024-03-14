//Using parallel arrays
#include<iostream>
using namespace std;
int main() {
   int rollnum,i;
   int rollno[] = {101,102,103,104,105};
   unsigned int age[] = {17,18,17,17,18};
   double percentage[] = {66.5,86.2,72.7,84.2,92.1};
   
   cout<<"Enter roll no. of student whose data to display = ";
   cin>>rollnum;
   for(i=0;i<5;i++) {	
     if(rollno[i] == rollnum){
	   cout<<"Roll number "<< rollno[i] <<" has "<< age[i] <<" age and obtained "<< percentage[i] <<" % marks"<<endl;
     }	
   } 
   return 0;	
}
