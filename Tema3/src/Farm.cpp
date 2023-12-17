#include <iostream>
#include "Farm.hpp"
#include <stdlib.h> 
#include <mutex>

using namespace std;

namespace farm{
    // COW
    Cow::Cow(){
        cout << "Cow was born\n";
    }

    Cow::~Cow(){
        cout << "Cow died\n";
    }

    void Cow::Eat(){
        int n = rand() % 10;
        int flag = 0;
        cowMutex.lock();
        if(farm::cowFood < n)
            flag=1;
        else
            farm::cowFood -= n;
        cowMutex.unlock();

        if(flag)
            std::terminate();
        else
            cout << "Cow consumed " << n << " food" << endl;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // CHICKEN
    Chicken::Chicken(){
        cout << "Chicken was born\n";
    }

    Chicken::~Chicken(){
        cout << "Chicken died\n";
    }

    void Chicken::Eat(){
        int n = rand() % 10;
        int flag = 0;
        chickenMutex.lock();
        if(farm::chickenFood < n)
            flag=1;
        else
            farm::chickenFood -= n;
        chickenMutex.unlock();

        if(flag)
            std::terminate();
        else
            cout << "Chicken consumed " << n << " food" << endl;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // WORKER
    Worker::Worker(){
        cout << "Worker was born\n";
    }
    Worker::~Worker(){
        cout << "Worker died\n";
    }
            
    void Worker::produceFood(){
        // decidem pentru care animal
        int n = rand();
        
        if(n % 2 == 0) {
            n = rand();
            n = n % 10; // limita 10
            cowMutex.lock();
            farm::cowFood += 10;
            cowMutex.unlock();
        }
        else {
            n = rand();
            n = n % 10;
            work += n;

            chickenMutex.lock();
            farm::chickenFood += 10;
            chickenMutex.unlock();

            if(n>100)
                std::terminate();
        }
    }

}