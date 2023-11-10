#include<iostream>
using namespace std;
#define size 10

template <class T>
void getdata(T a[size],int n)
{
 cout<<"Enter the Integer Element of the array:"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
}

template < class T >
void Display(T a[size],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<a[i]<<" ";
 }
}

template < class T>
void selection_sort(T a[size],int n)
{
 int i,j,min;
    T temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    Display(a,n);
}
int main()
{
 int n,op;
 int A[size];
 float B[size];
 do
 {
	
 cout<<"\n* * * * * SELECTION SORT SYSTEM * * * * *";
 cout<<"\n--------------------MENU-----------------------";
 cout<<"\n1. Get data (Interger)";
 cout<<"\n2. Get data (FLoat)";
 cout<<"\n3. Display data (Interger)";
 cout<<"\n4. Display data(FLoat)";
 cout<<"\n5. Selection sort(Integer)";
 cout<<"\n6. Selection sort(FLoat)";
 cout<<"\n7. Exit";
 cout<<"\n\nEnter your choice : ";
 cin>>op;
	
 switch(op)
 {
  case 1:
   cout<<"Enter the Integer number of elements :";
          cin>>n;
          getdata(A,n);
          break;
          
      case 2:
       cout<<"Enter the Float number of elements :";
       cin>>n;
       getdata(B,n);
       break;
       
      case 3:
       cout<<"The Array of Integer Number:";
       Display(A,n);
       break;
       
      case 4:
       cout<<"The Array of Floating Number :";
       Display(B,n);
       break;
       
      case 5:
       cout<<"After sorting the Integer Array:";
       selection_sort(A,n);
       break;
        
        case 6:
         cout<<"After Sorting the Floating Array";
         selection_sort(B,n);
         break;
         
        case 7:
         cout<<"Thank you";
         break;
         
        default:
         cout<<"Enter the valid choice from 1 to 7..";
         break;
         
 }
}while(op!=7);
}                              
