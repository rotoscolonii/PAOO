#include <iostream>
#include "farm.hpp"

using namespace std;

namespace farm{

    Cow::Cow(string name, string favFood){
        this->name = name;
        this->favFood = favFood;
        cout << "Cow constructor\n";
    }

    Cow::Cow(const Cow& other){
        this->name = other.name;
        this->favFood = other.favFood;
        cout << "Cow copy constructor\n";
    }

    Cow::~Cow(){
        cout << "Cow destructor\n";
    }

    Cow &Cow::operator=(const Cow &other){
        if (this != &other){
            this->name = other.name;
            this->favFood = other.favFood; 
        }
        cout << "Cow assignment operator\n";
        return *this;
    }

    Cow::Cow(Cow &&other){
        swap(this->name, other.name);
        swap(this->favFood, other.favFood);
        cout << "Cow move constructor\n";
    }

    Chicken::Chicken(string name, string favFood){
        this->name = name;
        this->favFood = favFood;
        cout << "Chicken constructor\n";
    }

    Chicken::Chicken(const Chicken& other){
        this->name = other.name;
        this->favFood = other.favFood;
        cout << "Chicken copy constructor\n";
    }

    Chicken::~Chicken(){
        cout << "Chicken destructor\n";
    }

    Chicken &Chicken::operator=(const Chicken &other){
        if (this != &other){
            this->name = other.name;
            this->favFood = other.favFood; 
        }
        cout << "Chicken assignment operator\n";
        return *this;
    }

    Chicken::Chicken(Chicken &&other){
        swap(this->name, other.name);
        swap(this->favFood, other.favFood);
        cout << "Chicken move constructor\n";
    }

    void Animal::Feed(){
        cout << "Animal is abstract, can not be instatiated.\n";
    }

    void Cow::Feed(){
        cout << "The cow - "+name+" - eats "+favFood+".\n";
    }

    void Chicken::Feed(){
        cout << "The chicken - "+name+" - eats "+favFood+".\n";
    }

    Farm::Farm(string location){
        this->location = location;
        cout << "Farm created.\n";
    }

    Farm::~Farm(){
        cout << "Farm destructor\n";
    }

    Farm::Farm(const Farm &other){
        this->location = other.location;
        cout << "Farm copy constructor\n";
    }

    Farm &Farm::operator=(const Farm &other){
        if (this != &other){
            this->location = other.location;
        }
        
        cout << "Farm assignment operator\n";
        return *this;
    }

    void Farm::WakeUp(){
        cout << "Guten Morgen in " + location + "!\n";
    }

    void Farm::GetEggs(Chicken* chicken){
        cout << chicken->name +" is productive.\n";
    }

    void Farm::MilkCow(Cow* cow){
        cout << cow->name +" is productive.\n";
    }
    
    void Farm::Feed(Cow* cow){
        Cow* copy = new Cow(*cow);
        cout << cow->name+" is happy.\n";
        copy->Feed();
        delete copy;
    }  

    void Farm::Feed(Chicken* chicken){
        Chicken* copy = new Chicken(*chicken);
        cout << chicken->name+" is happy.\n";
        copy->Feed();
        delete copy;
    }

    void Farm::Sleep(){
        cout << "GN\n";
    }
}