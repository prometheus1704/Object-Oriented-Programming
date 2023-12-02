#include <iostream>
using namespace std;

class Publication
{
protected:
  string title;
  float price;

public:
  virtual void get() = 0;
  virtual void display() = 0;
};

class Book : public Publication
{
public:
  int page_count;

public:
  void get() 
  {
    cout << "Enter the Publication information" << endl;
    cout << "Enter the title of the publication: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter the Price of the publication: ";
    cin >> price;
    while(price<=0)
    {
    try
	{
		if (price <= 0)
            throw(2);
	}
	catch(int x)
	{
		if(x==2)
		   cout<<"INVALID ENTRY of Price!!!"<<endl;
		   cout<<"Enter the valid Price :";
		   cin>>price;
		   cout<<"---------------------"<<endl;
	}
    }
        cout << "Enter the count of the pages: ";
        cin >> page_count;
    while(page_count<=0)
    {
    try
    { 
		if (page_count <= 0)
            throw 1;
    }
    catch (int x)
    {
        if (x == 1)
        {
            cout << "--------------------------------" << endl;
            cout << "INVALID ENTRY of Page count!!!" << endl;
            cout << "Enter a valid Page count:";
            cin>>page_count;
        }
    }
    }
    } 
    
  void display() 
  {
    cout << "The Title of the publication is: " << title << endl;
    cout << "The price of the publication is: " << price <<" Rs"<< endl;
    cout << "The page count of the publication is: " << page_count <<" pages"<< endl;
  }
};

class Cassette : public Publication
{
public:
  int length;

public:
  void get() 
  {
    cout << "Enter the Publication information" << endl;
    cout << "Enter the title of the publication: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter the Price of the publication: ";
    cin >> price;
    while(price<=0)
    {
    try
	{
		if (price <= 0)
            throw(2);
	}
	catch(int x)
	{
		if(x==2)
		   cout<<"INVALID ENTRY of Price!!!"<<endl;
		   cout<<"Enter the valid Price :";
		   cin>>price;
		   cout<<"---------------------"<<endl;
	}
    }
    cout << "Enter the length of the cassette: ";
    cin >> length;
    while(length<=0)
    {
    	try
    	{
    		if(length<=0)
    		    throw(3);
		}
		catch(int x)
		{
			if(x==3)
			{
				cout<<"INVALID ENTRY of Price!!!"<<endl;
		        cout<<"Enter the valid length :";
		        cin>>length;
		        cout<<"---------------------"<<endl;
			}
		}
	}
  }

  void display() 
  {
    cout << "The Title of the publication is: " << title << endl;
    cout << "The price of the publication is: " << price << endl;
    cout << "The length of the cassette is: " << length << " minutes" << endl;
  }
};

int main()
{
  Publication *p[10];
  Book *b;
  Cassette *c;
  int op, ch;
  int i;
  int publication_count = 0;
  do
  {
  
  cout << "-------------MENU---------------" << endl;
  cout << "1: Create publication" << endl;
  cout << "2: Display publication" << endl;
  cout << "3: Display the total Number publication"<<endl;
  cout << "4: Exit"<<endl;
  cout << "Enter your choice: ";
  cin >> op;
  

  switch (op)
  {
  		
    case 1:
    cout << "----------MENU----------" << endl;
    cout << "1: Create a publication of Book" << endl;
    cout << "2: Create a publication of Cassette" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    cout << "------------------------" <<endl;

    switch (ch)
    {
    case 1:
      b= new Book;
      b->get();
      p[publication_count]=b;
      publication_count++;
      break;
    case 2:
      c = new Cassette;
      c->get();
      p[publication_count]=c;
      publication_count++;
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
    break;
    
    case 2:
    for (i=0;i<publication_count;i++)
    {
      p[i]->display();
      cout<<"-----------------------"<<endl;
    }
    break;
    
    case 3:
    	cout<<"The Total number publication Present in the database:"<<publication_count<<endl;
    	break;
    	
    case 4:
  		break;
  default:
    cout << "Invalid choice" << endl;
    break;
  }
}while(op!=4);

  return 0;
}
