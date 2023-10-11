#include <iostream>
#include <string> // You need to include the <string> header for string data type.

class Employee {
private:
    std::string Name;
    std::string Company;
    int Age;
public:
    void set_name(std::string name) {
        Name = name;
    }
    std::string get_name() {
        return Name;
    }
    void set_company(std::string company) {
        Company = company;
    }
    std::string get_company() {
        return Company;
    }
    void set_age(int age) {
        if (age > 18)
            Age = age;
    }
    int get_age() {
        return Age;
    }
    void introduceyourself()
    {
        std::cout << "Name - " << get_name() << std::endl;
        std::cout << "Company - " << get_company() << std::endl;
        std::cout << "Age - " << get_age() << std::endl;
    }

    // You should use std::string instead of just string.
    Employee(std::string name, std::string company, int age) {
        set_name(name);
        set_company(company);
        set_age(age);
    }
};

int main(void)
{
    // You can create an instance of the Employee class like this.
    Employee employee1("vasilis", "google", 5);
    employee1.introduceyourself();
    employee1.set_age(30);
    employee1.introduceyourself();
}
