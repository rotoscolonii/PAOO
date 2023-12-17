#pragma once

#include <string>
#include <mutex>
using namespace std;

namespace farm{

    static std::mutex cowMutex, chickenMutex;
    static int cowFood = 20, chickenFood = 20;

    class Animal{
        public:
            string name;
        protected:
            string favFood;
        public:
            virtual void Eat() = 0;
    }; 

    class Cow : public Animal{
        public:
            Cow();
            ~Cow();
            void Eat() override;
    };

    class Chicken : public Animal{
        public:
            Chicken();
            ~Chicken();
            void Eat() override;
    };

    class Worker{
        public:
            int work = 0;
            Worker();
            ~Worker();
            void produceFood();
    };
}