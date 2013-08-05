#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
	private:
		string name;
		int age;
		string nlNumber;
	public:
		Person(string nm, int ag,string nlnum)
		{
			name =nm;
			age =ag;
			nlNumber =nlnum;
		}
		string & getName(void)
		{
			return name;
		}
		int & getAge(void)
		{
			return age;
		}
		string & getNlNumber(void)
		{
			return nlNumber;
		}
		bool operator==(const Person &p)
		{
			return(name== p.name);
		}
		bool operator<(const Person &p)
		{
			return(age< p.age);
		}
};

void populate(list <Person> & personList)
{
	char flag ='y';
	string name;
	int age;
	string nlNumber;
	while(flag == 'y')
	{
		cout << "\nEnter Name ";
		cin >> name;
		cout << "\nEnter age";
		cin >> age;
		cout << "Enter National Ins no.";
		cin >> nlNumber;
		Person p(name,age,nlNumber);
		personList.push_back(p);
		cout << "\nEnter y to continue";
		cin.get();
		flag=cin.get();
		cin.get();
	}	
}

void print_delete(list <Person> & peopleList)
{
	while(peopleList.size() > 0)
	{
		Person p=peopleList.front();
		peopleList.pop_front();
		cout << p.getName() << "  "  << p.getAge() << "  " << p.getNlNumber() << endl;
	}
}


int main()
{
	list <Person> peopleList;
	populate(peopleList);
	peopleList.sort();
	print_delete(peopleList);
	return 0;
}
