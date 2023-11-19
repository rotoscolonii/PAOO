#pragma once

#include <string>
using namespace std;

namespace farm{

   class InterfaceAnimal{
        public:
            virtual void Feed() = 0;
   };

   class Animal : public InterfaceAnimal{
        public:
            string name;
        protected:
            string favFood;
        public:
            virtual void Feed() = 0;
   }; 

   class Cow : public Animal{
        public:
            Cow(string name, string favFood);
            Cow(const Cow &other);
            ~Cow();
            Cow &operator=(const Cow &other);
            Cow(Cow &&other);
            void Feed() override;
   };

   class Chicken : public Animal{
        public:
            Chicken(string name, string favFood);
            Chicken(const Chicken &other);
            ~Chicken();
            Chicken &operator=(const Chicken &other);
            Chicken(Chicken &&other);
            void Feed() override;
   };

   class Farm{
    public:
        Farm(string location);
        Farm(const Farm &other);
        ~Farm();
        Farm &operator=(const Farm &other);
        string location;
        void WakeUp();
        void Feed(Cow* cow);
        void Feed(Chicken* chicken);
        void GetEggs(Chicken* chicken);
        void MilkCow(Cow* cow);
        void Sleep();
    };
}