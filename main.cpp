#include "CoffeeShop.hpp"

int main()
{
    CoffeeShop coffee_house("Coffee_House");
    coffee_house.addDrink(new Drink("MacCoffee", Drink::Size::Big, 700));
    coffee_house.showMenu();
    // coffee_house.removeDrink("MacCoffee");
    coffee_house.showMenu();

    Barista Boris("Boris");
    coffee_house.hireBarista(&Boris);
    coffee_house.showBaristas();
    // coffee_house.fireBarista(&Boris);
    coffee_house.displayShopInfo();
    return 0;
}