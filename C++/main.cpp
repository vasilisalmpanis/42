#include <iostream>

class Employee {
public:
    std::string Name;
    std::string Company;
    int Age;

    void introduceyourself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
};

int main(void)
{
    Employee employee1;
    employee1.Name = "vasilis";
    employee1.Company = "google";
    employee1.Age = 21;
    employee1.introduceyourself();
}
