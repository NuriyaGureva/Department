// Department.cpp 

#include <iostream>
#include <string>
#include<fstream>
using namespace std;
#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//         Constructor:

	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);

		cout << " HConstructor:\t" << this << endl;
	}
	virtual~Human()
	{
		cout << " HDestructor:\t" << this << endl;

	}
	virtual std::ostream& print(std::ostream& os)const
	{
		//return os << last_name << " " << first_name << " " << age << " лет";
		os.width(10);
		os << left;
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << "лет";
		return os;
	}
};
	ostream& operator<<(ostream& os, const Human& obj)
	{
		return obj.print(os);
	}

#define EMPLOYEE_TAKE_PARAMETERS const std::string& position
#define  EMPLOYEE_GIVE_PARAMETERS position
	class Employee :public Human
	{
		std::string position;
	public:
		const std::string& get_position()const
		{
			return position;

		}
		void set_position(const std::string& position)
		{
			this->position = position;
		}
		virtual double get_salary()const = 0;

		Employee(HUMAN_TAKE_PARAMETRS, EMPLOYEE_TAKE_PARAMETERS)
			:Human(HUMAN_GIVE_PARAMETRS)
		{
			set_position(position);
			cout << "EConstructor:\t" << this << endl;
		}
		~Employee()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		std::ostream& print(std::ostream& os)const
		{
			Human::print(os) << " ";
			return os << position;

		}
	};
#define PERMANENT_EMPLOYEE_TAKE_PARAMETRS double salary
#define PERMANENT_EMPLOYEE_GIVE_PARAMETRS  salary
	class PermanentEmployee :public Employee
	{
		double salary;
	public:
		double get_salary()const
		{
			return salary;
		}
		void set_salary(double salary)
		{
			this->salary = salary;
		}

		PermanentEmployee
		(
			HUMAN_TAKE_PARAMETRS,
			EMPLOYEE_TAKE_PARAMETERS,
			PERMANENT_EMPLOYEE_TAKE_PARAMETRS
		) :Employee(HUMAN_GIVE_PARAMETRS, EMPLOYEE_GIVE_PARAMETERS)

		{
			set_salary(salary);
			cout << "PEConstructor\t" << this << endl;
		}
		~PermanentEmployee()
		{
			cout << "PEDestructor:\t" << this << endl;
		}
		std::ostream& print(std::ostream& os)const
		{
			Employee::print(os) << " ";
			return os << salary;
		}
	};
#define HOURLY_EMPLOYEE_TAKE_PARAMETERS double rate, int hours
#define HOURLY_EMPLOYEE_GIVE_PARAMETERS  rate, hours

	class HourlyEmployee :public Employee
	{
		double rate;
		int hours;
	public:
		double get_rate()const
		{
			return rate;
		}
		int get_hours()const
		{
			return hours;
		}
		double get_salary()const
		{
			return rate * hours;
		}
		void set_rate(double rate)
		{
			this->rate = rate;
		}
		void set_hours(int hours)
		{
			this->hours = hours;
		}

		HourlyEmployee(HUMAN_TAKE_PARAMETRS, EMPLOYEE_TAKE_PARAMETERS,
			HOURLY_EMPLOYEE_TAKE_PARAMETERS)
			:Employee(HUMAN_GIVE_PARAMETRS, EMPLOYEE_GIVE_PARAMETERS)
		{
			set_rate(rate);
			set_hours(hours);
			cout << "HEConstructor\t:" << this << endl;
		}
		~HourlyEmployee()
		{
			cout << "HEDestructor:\t" << this << endl;
		}
		std::ostream& print(std::ostream& os)const
		{
			Employee::print(os) << " ";
			return os << "тариф:" << rate << ", отработано:" << hours << "часов," << " итого:" << get_salary();

		}
	};


int main()
{

	setlocale(LC_ALL, "");

	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg","Ken",30,"Lawyer",2000),
		new PermanentEmployee("Diaz","Ricardo",50,"Boss",50000),
		new HourlyEmployee("Vercetty","Tomas",30,"Security",500,8)
	};
	double total_salary = 0;
	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		cout << "\n-----------------------------\n";
		//department[i]->print();
		cout << *department[i] << endl;
		total_salary += department[i]->get_salary();

	}
	cout << "\n-----------------------------\n";
	cout << "Общая зарплата всего отдела:" << total_salary << endl;
	cout << "\n-----------------------------\n";
	ofstream fout("file.txt");
	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		fout.width(25);
		fout << left;
		fout << string(typeid(*department[i]).name()) + ":" << *department[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		delete department[i];
	}
}
