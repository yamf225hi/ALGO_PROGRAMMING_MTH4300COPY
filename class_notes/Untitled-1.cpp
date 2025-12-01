#include <iostream>
#include <string>

class Human
{
private:
    string name;
    int age;
    int height;
    int weight;
    bool Male;
    bool Female;

    // construcot: 

public:
    Human(string n, int a, int h, int w, bool m, bool f)
    {
        name =n;
        age = a;
        height = h;
        weight = w;
        male = m;
        female = f;

    }

    //jmethgod: 
    void prays()
    {
        std::cout << name << " is praying." << std::endl;
    }
    void eats()
    {
        std::cout << name << " is eating." << std::endl;
    }
    void sleeps()
    {
        std::cout << name << " is sleeping." << std::endl;
    }
    void talks()
    {
        std::cout << name << " is talking." << std::endl;
    }
    void walks()
    {
        std::cout << name << " is walking." << std::endl;
    }
    void runs()
    {
        std::cout << name << " is running." << std::endl;
    }


};

int main()
{
    // Create a Human object
    Human person("John", 30, 180, 75, true, false);

    // Call methods
    person.prays();
    person.eats();
    person.sleeps();
    person.talks();
    person.walks();
    person.runs();

    return 0;
}



    