#include <iostream>
#include <string>
#include <list>
#include <iomanip>
/*add the header if you need*/
using namespace std;

//Abstract base class for Dessert Item hierarchy
class DessertItem
{
private:
//Name of the DessertItem object
    string name;

public:
    DessertItem(){}
    DessertItem(string name):name(name){}
//Empty virtual destructor for DessertItem class
    virtual ~DessertItem(){}
//returns Name of DessertItem
    string getName(){ return name;}
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
};

class IceCream : public DessertItem
{
 public:
    // Write about IceCream Constructor
       IceCream(string name, double cost):DessertItem(name),cost(cost){}
    /* Write about IceCream other member functions*/
	virtual string getDetails()
	{
		return "\0";
	}
	virtual double getCost()
	{
		return cost;
	}
private:
    double cost;
};

class Topping : public IceCream
{
public:
    // Write about Topping Constructor
       Topping(string iceCreamName, double iceCreamCost,
	string toppingName, double toppingCost):IceCream(toppingName+" Sundae with "
	+iceCreamName,iceCreamCost),toppingName(toppingName),toppingCost(toppingCost){}
   /* Write about Topping otjer member functions*/
	virtual string getDetails()
	{
		return "\0";
	}
	virtual double getCost()
	{
		return IceCream::getCost()+toppingCost;
	}
private:
    string toppingName;
    double toppingCost;
};

class Cookie : public DessertItem
{
public:
    // Write about Cookie Constructor
       Cookie(string name, int number, double pricePerDozen):DessertItem(name),number(number)
	,pricePerDozen(pricePerDozen){}
    /* Write about Cookie other member functions*/
	virtual string getDetails()
	{
		int stop,i;
		string item;
		item=to_string(pricePerDozen);
		for(i=0;item[i]!='\0';i++)
		{
		    //determine whether there is a zero after point ex.13.10000
		    //item must be floating point
			if(item[i]=='0')
				if(stop==0)
					stop=i;
				else{}
			else
				stop=0;
		}
		if(stop!=0)
		{
			if(item[stop-1]=='.')
				item[stop-1]='\0';
			for(i=stop;item[i]!='\0';i++)
				item[i]='\0';
		}
		return "("+to_string(number)+" dezen(s) * "+item+"/dozen)";
	}
	virtual double getCost()
	{
		return number*pricePerDozen;
	}

private:
//Number of dozens of Cookie
    int number;
    double pricePerDozen;
};

class Candy : public DessertItem
{
public:
    // Write here about Candy Constructor
       Candy(string name, double weight, double pricePerGram):DessertItem(name),
	weight(weight),pricePerGram(pricePerGram){}
    /* Write about Candy other member functions*/
	virtual string getDetails()
	{
		int stop,i;
		string gram,price;
		gram=to_string(weight);
		for(i=0;gram[i]!='\0';i++)
			if(gram[i]=='0')
				if(stop==0)
					stop=i;
				else{}
			else
				stop=0;
		if(stop!=0)
		{
			if(gram[stop-1]=='.')
				gram[stop-1]='\0';
			for(i=stop;gram[i]!='\0';i++)
				gram[i]='\0';
		}
		price=to_string(pricePerGram);
		for(i=0;price[i]!='\0';i++)
			if(price[i]=='0')
				if(stop==0)
					stop=i;
				else{}
			else
				stop=0;
		if(stop!=0)
		{
			if(price[stop-1]=='.')
				price[stop]='\0';
			for(i=stop;price[i]!='\0';i++)
				price[i]='\0';
		}
		return "("+gram+" gram(s) * "+price+"/gram)";
	}
	virtual double getCost()
	{
		return weight*pricePerGram;
	}
private:
//Weight of Candy
    double weight;
    double pricePerGram;
};



class Checkout {
public:
    friend ostream &operator<<(std::ostream &, Checkout &);
    /* Write about Checkout member functions
    1. "enterItem" function to add the element into the list
    2. "removeItem" function to remove the elemtent from the list
    3. calculate the total cost and tax in the list
    4. "numberOfItems" for number of Item in the list
    5. "clear" clear all Items from list
    */
	void enterItem(DessertItem *input)
	{
		itemList.push_back(input);
	}
	void removeItem(DessertItem *out)
	{
		itemList.remove(out);
	}
	double total()
	{
		double total=0;
		list<DessertItem*>::iterator it;
		for(it=itemList.begin();it!=itemList.end();++it)
		{
			total+=(*it)->getCost();
		}
		return total;
	}
	double tax()
	{
		return total()*0.05;
	}
	double TotalCost()
	{
		return total()+tax();
	}
	int numberOfItems()
	{
		return itemList.size();
	}
	void clear()
	{
		itemList.clear();
	}

private:
    list<DessertItem*> itemList;
};


ostream &operator<<(ostream &output, Checkout &checkout){
/*overloaded operator that output a receipt for the current list of items*/
	list<DessertItem*>::iterator it;
	output<<"Welcome to OOP's shop"<<endl;
	output<<"------------------------------------"<<endl<<endl;
	cout<<"Number of items: "<<checkout.numberOfItems()<<endl<<endl;
	for(it=checkout.itemList.begin();it!=checkout.itemList.end();++it)
	{
		cout.width(50);
		output<<left<<(*it)->getName()<<right<<setw(5)<<(int)((*it)->getCost()+0.5)<<endl;
		if((*it)->getDetails()!="\0")
		{
			output<<(*it)->getDetails()<<endl;
		}
	}
	output<<endl;
	output<<"-------------------------------------"<<endl;
	cout.width(50);
	output<<left<<"Cost"<<right<<setw(5)<<(int)(checkout.total()+0.5)<<endl;
	cout.width(50);
	output<<left<<"Tax"<<right<<setw(5)<<(int)(checkout.tax()+0.5)<<endl;
	output<<endl;
	cout.width(50);
	output<<left<<"Total cost"<<right<<setw(5)<<(int)(checkout.TotalCost()+0.5)<<endl;
	return output;

}
