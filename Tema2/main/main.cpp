#include "farm.hpp"

using namespace farm;

int main()
{

    Farm* mainFarm = new Farm("Abu Dhabi");

    mainFarm->WakeUp();

    Cow *firstCow = new Cow("Morty", "hay");
    Chicken *firstChicken = new Chicken("Rick","corn");

    mainFarm->Feed(firstCow);
    mainFarm->Feed(firstChicken);

    Cow secondCow = move(*firstCow);
    Chicken secondChicken = move(*firstChicken);

    secondCow.name = "Gomez";
    secondChicken.name = "Rodrigo";
    mainFarm->Feed(&secondCow);
    mainFarm->MilkCow(&secondCow);
    mainFarm->Feed(&secondChicken);
    mainFarm->GetEggs(&secondChicken);

    mainFarm->Sleep();

    delete mainFarm;

    return 0;
}