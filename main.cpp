#include "CoffeeShop.hpp"

int main()
{
    // CoffeeShop coffee_house("Coffee_House");
    // coffee_house.addDrink(new Drink("MacCoffee", Drink::Size::Big, 700));
    // coffee_house.showMenu();
    // // coffee_house.removeDrink("MacCoffee");
    // coffee_house.showMenu();

    // Barista Boris("Boris");
    // coffee_house.hireBarista(&Boris);
    // coffee_house.showBaristas();
    // // coffee_house.fireBarista(&Boris);
    // coffee_house.displayShopInfo();

    CoffeeShop coffix("CoffIx");
    Barista Armen("Armen");
    coffix.hireBarista(&Armen);
    Customer Zaven("Zaven", 400);
    Customer Arman("Arman", 900);
    coffix.addCustomerToQueue(&Zaven);
    coffix.addCustomerToQueue(&Arman);
    Order mac_small;
    Order mac_set;
    mac_small.addDrink(Drink("Mac", Drink::Size::Small, 200));
    mac_set.addDrink(Drink("Mac", Drink::Size::Small, 200));
    mac_set.addDrink(Drink("Mac", Drink::Size::Big, 400));

    Zaven.placeOrder(&mac_small);
    Arman.placeOrder(&mac_set);

    Armen.prepareOrder(&mac_small);
    Zaven.payOrder();
    coffix.serveNextCustomer();
    return 0;
}