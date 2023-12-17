#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <memory>
#include "Farm.hpp"


using namespace std;
using namespace farm;


void thread_chicken(std::weak_ptr<Chicken> c) {
    while(1) {
        auto temp = c.lock();
        if(c.expired())
            break;
        temp->Eat();
        sleep(2);
    }
}
void thread_cow(std::weak_ptr<Cow> c) {
    while(1) {
        auto temp = c.lock();
        if(c.expired())
            break;
        temp->Eat();
        sleep(3);
    }
}
void thread_worker(std::weak_ptr<Worker> w) {
    while(1) {
        auto temp = w.lock();
        if(w.expired())
            break;
        temp->produceFood();
        sleep(5);
    }
}


int main(){
    int nChicken = rand() % 10;
    int nCows = rand() % 10;
    int nWorkers = rand() % 3;

    vector<shared_ptr<Chicken>> chicken;
    vector<shared_ptr<Cow>> cow;
    vector<shared_ptr<Worker>> worker;

    // create life
    for(int i=0; i<nChicken; i++) {
        shared_ptr<Chicken> c(new Chicken());
        chicken.push_back(c);
    }

    for(int i=0; i<nCows; i++) {
        shared_ptr<Cow> c(new Cow());
        cow.push_back(c);
    }

    for(int i=0; i<nWorkers; i++) {
        shared_ptr<Worker> w(new Worker());
        worker.push_back(w);
    }


    // create threads
    vector<thread> threads;

    for(auto& i : chicken) {
        weak_ptr<Chicken> c (i);
        threads.push_back(std::thread(thread_chicken, c));
    }

    for(auto& i : cow) {
        weak_ptr<Cow> c(i);
        threads.push_back(std::thread(thread_cow, c));
    }

    for(auto& i : worker) {
        weak_ptr<Worker> w(i);
        threads.push_back(std::thread(thread_worker, w));
    }

    // sell & buy new animals / let go & hire new worker
    int n = rand() % nChicken;
    shared_ptr<Chicken> chick (new Chicken());
    chicken[n].reset();
    chicken[n] = chick;

    n = rand() % nCows;
    shared_ptr<Cow> co (new Cow());
    cow[n].reset();
    cow[n] = co;

    n = rand() % nWorkers;
    shared_ptr<Worker> worky (new Worker());
    worker[n].reset();
    worker[n] = worky;


    // wait for threads to finish
    for (auto& i : threads) {
        i.join();
    }

    // clean up corpses
    for(auto& i : chicken) {
        weak_ptr<Chicken> c (i);
        if(c.expired())
            cout << "Chicken was replaced" << endl;
        else
            i->~Chicken();
    }

    for(auto& i : cow) {
        weak_ptr<Cow> c (i);
        if(c.expired())
            cout << "Cow was replaced" << endl;
        else
            i->~Cow();
    }

    for(auto& i : worker) {
        weak_ptr<Worker> c (i);
        if(c.expired())
            cout << "Worker was replaced" << endl;
        else
            i->~Worker();
    }

    return 0;
}