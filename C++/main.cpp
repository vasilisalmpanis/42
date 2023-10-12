#include <iostream>
#include <string> // You need to include the <string> header for string data type.

class AbstractEmployee {
    virtual void Askforpromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    std::string Name;
    std::string Company;
    int Age;
public:
    void set_name(const std::string& name) {
        Name = name;
    }
    std::string get_name() {
        return Name;
    }
    void set_company(const std::string& company) {
        Company = company;
    }
    std::string get_company() {
        return Company;
    }
    void set_age(int age) {
        if (age > 18)
            Age = age;
    }
    int get_age() const {
        return Age;
    }
    void introduceyourself()
    {
        std::cout << "Name - " << get_name() << std::endl;
        std::cout << "Company - " << get_company() << std::endl;
        std::cout << "Age - " << get_age() << std::endl;
    }

    // You should use std::string instead of just string.
    Employee(const std::string& name, const std::string& company, int age) : Age() {
        set_name(name);
        set_company(company);
        set_age(age);
    }
    void Askforpromotion() {
        if (Age > 30)
            std::cout << Name << " got promoted!." << std::endl;
        else
            std::cout << Name << " Sorry no promotion!." << std::endl;

    }
};

class Developer:public Employee {
public:
	std::string fpl;
	Developer(const std::string& name, const std::string& company, int age, const std::string& lang)
			:Employee(name, company, age)
	{
		fpl = lang;
	}
	void    fix_bug() {
		std::cout << get_name() << " fixed bug using " << fpl << std::endl;
	}
};

class Teacher: public Employee{
public:
	std::string sub;
	void preparedlesson() {
		std::cout << get_name() << " is preparin " << sub << "lesson" << std::endl;
	}
	Teacher(const std::string& name, const std::string& company, int age, const std::string& subj)
		:Employee(name, company, age)
	{
		sub = subj;
	}
};

int main()
{
    // You can create an instance of the Employee class like this.
    Employee employee1("vasilis", "google", 5);
	Developer de = Developer("Vasilis", "google", 32, "c++");
	de.fix_bug();
	de.Askforpromotion();
	Teacher hello = Teacher("vasi", "hello", 35, "history");
	hello.preparedlesson();
	hello.Askforpromotion();
}
