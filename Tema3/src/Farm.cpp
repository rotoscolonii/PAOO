#include <iostream>
#include "Farm.hpp"
#include <stdlib.h> 
#include <thread>
#include <unistd.h>
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
        int n = rand() % 10 +1;
        int flag = 0;
        sleep(3);
        lock_guard<mutex> lck(cowMutex);
        if(farm::cowFood < n)
            flag=1;
        else
            farm::cowFood -= n;

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
        int n = rand() % 10 +1;
        int flag = 0;
        sleep(3);
        lock_guard<mutex> lck(chickenMutex);
        if(farm::chickenFood < n)
            flag=1;
        else
            farm::chickenFood -= n;

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
        sleep(5);
        if(n % 2 == 0) {
            n = rand();
            n = n % 10; // limita 10
            lock_guard<mutex> lck(cowMutex);
            farm::cowFood += 10;
        }
        else {
            n = rand();
            n = n % 10;
            work += n;
            lock_guard<mutex> lck(chickenMutex);
            farm::chickenFood += 10;
        }
        if (n > 100)
            std::terminate();
    }

}