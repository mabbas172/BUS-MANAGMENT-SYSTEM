#include<iostream>
using namespace std;

int choice; // globally declear
class Bus
{
	public:
		int bus_id;
		string name;
		string route;
		string status;
		Bus *next;
		
		Bus(int b,string n, string r, string s)
		{
		bus_id=b;
		name=n;
		route=r;
		status=	s;
		next=NULL;
		}
};

class Bus_Managment
{
	private:
		Bus *head;
		Bus *tail;
		public:
			
		int bus_id;
		string name;
		string route;
		string status;
		
		Bus_Managment()
		{
			head=tail=NULL;
		}
		void insert_front()
		{
			cout<<"Enter Bus id : ";
			cin>>bus_id;
			cout<<"Enter bus name :";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Route name : ";
		
			getline(cin,route);
			cout<<"Enter status . (Active / Inactive) : ";
		
			getline(cin,status);
			cout<<endl;
			Bus *newBus=new Bus(bus_id,name,route,status);
			if(head==NULL)
			{
				head=tail=newBus;
				
				cout<<" \t\t\tBus added at the front Successfully.....\n";
			}
			else
			{
				newBus->next=head;
				head=newBus;
			}
		}
		
		void insert_End()
		{
			cout<<"Enter Bus id : ";
			cin>>bus_id;
			cout<<"Enter bus name :";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Route name : ";
			
			getline(cin,route);
			cout<<"Enter status . (Active / Inactive) : ";
			
			getline(cin,status);
			cout<<endl;
				Bus *newBus=new Bus(bus_id,name,route,status);
				
			if(head==NULL)
			{
				head=tail=newBus;
				cout<<" \t\t\tBus added at the End Successfully.....\n";
				return;
		    }
		    Bus *temp=head;
		   while(temp->next!=NULL)
		   {
		   	temp=temp->next;
		   }
		   temp->next=newBus;
		   tail=newBus;
		cout<<"\t\t\t\tInserted at the End successfully \n";
     }
     void insert_at_pos()
     {
     	int key;
     	cout<<"Enter bus number to insert after : ";
     	cin>>key;
     	Bus *temp=head;
     	while(temp!=NULL && temp->bus_id!=key)
     	{
     		temp=temp->next;
		 }
		 if(temp==NULL)
		 {
		 	cout<<"Not Found...!";
		 	return;
		 }
		 	cout<<"Enter Bus id : ";
			cin>>bus_id;
			cout<<"Enter bus name :";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Route name : ";
			
			getline(cin,route);
			cout<<"Enter status . (Active / Inactive) : ";
		
			getline(cin,status);
			cout<<endl;
			Bus *newBus=new Bus(bus_id,name,route,status);
			newBus->next=temp->next;
			temp->next=newBus;
			if(temp==tail)
			{
				tail=newBus;
			}
			cout<<"\t\t\tInserted successfully \n";

			
	 }
	 
	 void delete_bus()
	 {
	 	int key;
	 	Bus *prev=NULL;
	 	cout<<"Enter Bus id to remove : ";
	 	cin>>key;
	 	Bus *temp=head;
	 	while(temp!=NULL && temp->bus_id!=key)
	 	{
	 		prev=temp; // need to understand
	 		temp=temp->next;
		 }
		 if(temp==NULL)
		 {
		 	cout<<"Sorry...Not found\n";
		 	return;
		 }
		 if(temp==head)
		 {
		 	head=head->next;
		 }
		 else
		 {
		 	prev->next=temp->next;
		 }
		 if(temp==tail)
		 {
		 	tail=prev;
		 }
		 delete temp;
		 
		 cout<<"Bus deleted Successfully with id "<<key;
	 }
	 
	 void search()
	 {
	 	int key;
	 	cout<<"Enter Bus ID to search : ";
	 	cin>>key;
	 	Bus *temp=head;
	 	if(temp==NULL)
		 {
		 	cout<<"Not found Boss...\n";
		 	return;
		 }
	 	while(temp!=NULL && temp->bus_id!=key)
	 	{
	 		temp=temp->next;
		 }
		 	if(temp==NULL)
		 {
		 	cout<<"Not found Boss...\n";
		 	return;
		 }
		 
		 
		 	cout<<temp->bus_id<<" \t "<<temp->name<<" \t "<<temp->route<<" \t "<<temp->status;
		 	cout<<endl;
		 
	 	
	 }
	 void display()
	 {
	 	Bus *temp=head;
	 	if(temp==NULL)
	 	{
	 		cout<<"No Buses.......";
	 		return;
		 }
		 while(temp!=NULL)
		 {
		 	
		 		cout<<temp->bus_id<<" \t "<<temp->name<<" \t "<<temp->route<<" \t "<<temp->status<<endl;
		 		temp=temp->next;
		 		cout<<"-------------------------------------------------------------------------------------------\n";

		 }
	 }
		
};

class Passenger
{
	public:
		Passenger *next;
		string name,Booking_id,Destination;
			int ticket;
		public:
			Passenger(string n,string b,string d,int t )
			{
				name=n;
				Booking_id=b;
				Destination=d;
				ticket=t;
				next=NULL;
			}
	
};

class Passenger_module
{
	private:
		
		Passenger *front;
		Passenger *rear;
		public:
			string name,Booking_id,Destination;
			int ticket;
		Passenger_module()
		{
			front=rear=NULL;
		}
		
		void Passenger_details()
		{
			cout<<endl;
			cin.ignore();
			cout<<"Enter Passenger name : ";
			getline(cin,name);
			
			cout<<"Enter Passenger Booking Id : ";
			
			getline(cin,Booking_id);
			cout<<"Enter Passenger Destination : ";
			getline(cin,Destination);
			
			cout<<"Enter amount for ticket (Fixed RS :50):  ";
			while(true)
			{
				cin>>ticket;
				
				if(ticket>50)
				{
					cout<<"Ticket amount must be lower.\n";
				}
				if(ticket<50)
				{
					cout<<"Ticket amount must be higher.\n";
				}
				if(ticket==50)
				{
					break;
				}
			}
		
			Passenger *newPassenger = new Passenger(name,Booking_id,Destination,ticket);
		if(front==NULL)
		{
			front=rear=newPassenger;
		}
		else
		{
			rear->next=newPassenger;
			rear=newPassenger;
		}
				cout<<"\t\t\tTicket Booked.........\n";	
		}
		
	void cancel_ticket()
    {
        if(front == NULL)
        {
        	cout<<endl;
            cout<<"No Passenger Records Found...\n";
            return;
        }

        string key;

        cin.ignore();

        cout<<"Enter Booking ID to Cancel : ";
        getline(cin,key);

        Passenger *temp = front;
        Passenger *prev = NULL;

        while(temp != NULL && temp->Booking_id != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout<<"Booking ID Not Found...\n";
            return;
        }

        if(temp == front)
        {
            front = front->next;

            if(front == NULL)  // edge cases
                rear = NULL;
        }
        else
        {
            prev->next = temp->next;

            if(temp == rear)   // edge cases
                rear = prev;
        }

        delete temp; 
        	cout<<endl;
		 cout<<"\t\t\tPassenger Ticket Expired with Reference id ( "<<key<<" )";
		
		}
		
		void display_Passenger()
		{
			Passenger *temp=front;
			if(front==NULL)
			{
				cout<<"No Passengers Exist.......\n";
				return;
			}
			while(temp!=NULL)
			{
				cout<<temp->name<<" \t "<<temp->Booking_id<<" \t "<<temp->Destination<<" \t "<<temp->ticket<<endl;
				cout<<"-------------------------------------------------------\n";
				temp=temp->next;
			}
		}
};

//--------------------------------Routie Module

class Route
{
public:
    string routeName;
    Route *left;
    Route *right;

    Route(string r)
    {
        routeName = r;
        left = NULL;
        right = NULL;
    }
};

class Route_Module
{
private:
    Route *root;

    Route* insert(Route *node, string route)
    {
        if(node == NULL)
            return new Route(route);

        if(route < node->routeName)
            node->left = insert(node->left, route);
        else if(route > node->routeName)
            node->right = insert(node->right, route);

        return node;
    }

    bool search(Route *node, string route)
    {
        if(node == NULL)
            return false;

        if(node->routeName == route)
            return true;

        if(route < node->routeName)
            return search(node->left, route);

        return search(node->right, route);
    }

    void inorder(Route *node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        cout << node->routeName << endl;
        inorder(node->right);
    }

public:
    Route_Module()
    {
        root = NULL;
    }

    void insertRoute()
    {
        string route;

        cin.ignore();

        cout << "Enter Route Name : ";
        getline(cin, route);

        root = insert(root, route);

        cout << "Route Added Successfully...\n";
    }

    void searchRoute()
    {
        string route;

        cin.ignore();

        cout << "Enter Route Name to Search : ";
        getline(cin, route);

        if(search(root, route))
            cout << "Route Found...\n";
        else
            cout << "Route Not Found...\n";
    }

    void displayRoutes()
    {
        if(root == NULL)
        {
            cout << "No Routes Available...\n";
            return;
        }

        cout << "\n\t\t\t ALL ROUTES (SORTED) \n";

        inorder(root);

        cout << "---------------------------------\n";
    }
};

int main()
{
	
Bus_Managment b1;
Passenger_module P1;
Route_Module R1;
	cout<<"\t\t\t\t\WELCOME TO SMART BUS MANAGMENT SYSTEM"<<endl;
	do{
		cout<<endl;
		cout<<"Enter 1 for Bus Managment"<<endl;
		cout<<"Enter 2 for Passenger MODULE"<<endl;
		cout<<"Enter 3 for Route Module"<<endl;
		cout<<"Enter 4 TO EXIT THE PROGRAM"<<endl<<endl;
		cout<<"Enter Your Choice : ";
		cin>>choice;
		cout<<endl;
		if(choice==1)
		{
			do{
				cout<<endl;
			cout<<"1. Add bus at front\n";
		    cout<<"2. Add bus at End\n";
			cout<<"3. Add bus at Any Position\n";
			cout<<"4. Delete bus with ID\n";
			cout<<"5. Searching bus with ID\n";
			cout<<"6. Displaying  all buses\n";
			cout<<"7. Return to main Menu\n";
			cout<<endl;
			
	    	cout<<"Enter Your Choice : ";
	    
			cin>>choice;
			cout<<endl;
			if(choice==1)
			{
				b1.insert_front();
			}
			if(choice==2)
			{
			b1.insert_End();
			}
			if(choice==3)
			{
				b1.insert_at_pos();
			}
			if(choice==4)
			{
			    b1.delete_bus();
			}
				if(choice==5)
			{
			   b1.search();
			}
				if(choice==6)
			{
			    b1.display();
			}
			
			
		}while(choice!=7);
	
		
		}
		//------------------------------
			if(choice==2)
		{
			do
			{
				cout<<endl;
			cout<<"1. Add Passenger Details\n";
		    cout<<"2. Cancel ticket if Passenger want\n";
			cout<<"3. Displaying all the Tickets booked\n";
			cout<<"4. Return to main Menu \n";
				cout<<endl;
				cout<<"Enter Your choice: ";
			cin>>choice;
			if(choice==1)
			{
				P1.Passenger_details();
			}
			if(choice==2)
			{
				P1.cancel_ticket();
			}
			if(choice==3)
			{
				P1.display_Passenger();
			}
			
			}while(choice!=4);
			
		}
		if(choice==3)
      {
    do
    {
        cout<<endl;
        cout<<"1. Add Route\n";
        cout<<"2. Search Route\n";
        cout<<"3. Display All Routes\n";
        cout<<"4. Return to Main Menu\n";

        cout<<"Enter Your choice: ";
        cin>>choice;

        if(choice==1)
        {
            R1.insertRoute();
        }
        else if(choice==2)
        {
            R1.searchRoute();
        }
        else if(choice==3)
        {
            R1.displayRoutes();
        }

    }while(choice!=4);
}
		if(choice>4 || choice <1)
		{
			cout<<"\t\t\tInvalid choice \n"<<endl; // edge case
		}
		if(choice==4)
		{
			cout<<" \t\t\tThank You for Visitng Our site!.......\n";
			cout<<" \t\t\t        .HAVE A GOOD DAY.\n";
		}
	} 
    while(choice!=4);



}