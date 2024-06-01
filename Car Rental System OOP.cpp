#include<iostream>
using namespace std;
class Customer{
	public:
	string name;
	int age;
	int number;
	string address;
    void setName(string n){
		name=n;
	}
	void setAge(int a){
		age=a;
	}
	void setNumber(int num){
		number=num;
	}
	void setAddress(string add){
		address=add;
	}
	void display(){
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\nCustomer Details"<<endl;
		cout<<"Name:"<<name<<endl;
		cout<<"Age:"<<age<<endl;
		cout<<"Number:"<<number<<endl;
		cout<<"Address:"<<address<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	}
};
class Vehical{
	protected:
	string make;
	string model;
	int year;
	int perDay;
	int days;
	public:
		Vehical(string make,string model,int year,int perDay){
			this->make=make;
			this->model=model;
			this->year=year;
			this->perDay=perDay;
		}	
	void setDays(int d){
		days=d;
	}
	int getDays(){
		return days;
	}
	virtual double totalRent(int days)= 0;
    virtual void display()= 0;
};
class Driver{
	private:
	string name;
	int age;
	public:
		Driver(string name,int age){
			this->name=name;
			this->age=age;
		}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
};
class Car: public Vehical{
	private:
	int seats;
	Driver *d;
	public:
		Car(string make,string model,int year,int perDay,int seats): Vehical(make,model,year,perDay){
			this->seats=seats;
		}
	 double totalRent(int days){
        return perDay * days;
    }
    void addDriver(Driver *d){
    	this->d=d;
	}
    void display(){
       	cout<<"\nCAR DETAILS:"<<endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price per day: " << perDay << endl;
        cout << "Number of seats: " << seats<< endl;
        cout<<  "Driver Name: "<<d->getName()<<endl;
        cout<<  "Driver Age: "<<d->getAge()<<"\n"<<endl;   
    }
  
};
class Jeep: public Vehical{
	int seats;
	Driver *d;
	public:
		Jeep(string make,string model,int year,int perDay,int seats): Vehical(make,model,year,perDay){
			this->seats=seats;
		}
	double totalRent(int days){
        return perDay * days;
    }
    void addDriver(Driver *d){
    	this->d=d;
	}
    void display(){
       	cout<<"\nJEEP DETAILS:"<<endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price per day: " << perDay << endl;
        cout << "Number of seats: " << seats<< endl;
        cout<<  "Driver Name: "<<d->getName()<<endl;
        cout<<  "Driver Age: "<<d->getAge()<<"\n"<<endl; 
		   
    }
};
int main(){
	Customer k;
	string n,add;
	int num,a;
	cout<<"Enter Name:";
	cin>>n;
	k.setName(n);
	cout<<"Age:";
	cin>>a;
	k.setAge(a);
	cout<<"Number:";
	cin>>num;
	k.setNumber(num);
	cout<<"Address:";
	cin>>add;
	k.setAddress(add);
	k.display();
	cout<<"Vehical 1 "<<endl;
	Car c1("Honda","City",2017,5000,5);
	Driver *d1=new Driver("Ali",35);
	c1.addDriver(d1);
	c1.display();
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Vehical 2 "<<endl;
	Car c2("Toyota","Corolla",2013,6000,5);
	Driver *d2=new Driver("Ahmad",29);
	c2.addDriver(d2);
	c2.display();
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Vehical 3 "<<endl;
	Jeep j1("Suzuki","Jimmny",2009,10000,4);
	Driver *d3=new Driver("Saqib",40);
	j1.addDriver(d3);
	j1.display();
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Vehical 4 "<<endl;
	Jeep j2("Mistubishi","Pajero",2007,12000,4);
	Driver *d4=new Driver("Sahil",31);
	j2.addDriver(d4);
	j2.display();	
	int days,s,c=0;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	while(c!=-1){
	cout<<"Select Vehical Number:";
	cin>>s;
	cout<<"Enter number of Days:";
	cin>>days;
	if(s==1){
	c1.setDays(days);
	cout<<  "Total Rent: "<< c1.totalRent(days)<<endl;	
	cout<<"Congratulations you have Booked -> Honda City <-\n"<<endl;
	}
    if(s==2){
	c2.setDays(days);
	cout<<  "Total Rent: "<< c2.totalRent(days)<<endl;	
	cout<<"Congratulations you have Booked -> Toyota Corolla <-\n"<<endl;
	}	
	if(s==3){
	j1.setDays(days);
	cout<<  "Total Rent: "<< j1.totalRent(days)<<endl;	
	cout<<"Congratulations you have Booked -> Suzuki Jimmny <-\n"<<endl;
	}
	if(s==4){
	j2.setDays(days);
	cout<<  "Total Rent: "<< j2.totalRent(days)<<endl;
	cout<<"Congratulations you have Booked -> Mistubishi Pajero <-\n"<<endl;	
	}	
cout<<"Press -1 to Exit or 0 to select another Vehical:";
cin>>c;
cout<<"\n\n";
 }
}

