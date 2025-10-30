#include "CoffeeShop.hpp"


//CoffeShop
void CoffeeShop::removeDrink(const std::string& drinkName)
{
    if (!menu.size()) return;
    menu.erase(std::remove_if(menu.begin(), menu.end(), 
        [&](Drink* ptr){
            if(ptr->getName() == drinkName)
            {
                delete ptr;
                return true;
            }
            return false;
        }),
        menu.end()
    );
}

void CoffeeShop::showMenu() const
{
    if (!menu.size()) 
    {
        std::cout << "Menu is currently empty" << std::endl;
        return;
    }

    for (auto elem : menu)
    {
        std::cout << elem->getName() << "------------" << elem->getPrice() << std::endl;
    }
}


void CoffeeShop::fireBarista(Barista* barista)
{
    for (auto elem:baristas)
    {
        if (elem == barista)
        {
            delete barista;
        }
    }
}

void CoffeeShop::showBaristas() const
{
    if (!baristas.size()) 
    {
        std::cout << "we don't have baristas, sorry" << std::endl;
        return;
    }

    for (auto elem : baristas)
    {
        std::cout << elem->getName() << std::endl;
    }
}


void CoffeeShop::showQueue() const
{
    for (const auto& elem : queue)
    {
        std::cout << elem->getName() << ' ';
    }
    std::cout << std::endl;
}


void CoffeeShop::displayShopInfo() const
{
    std::cout << "ShopName: " << shopName << std::endl;
    std::cout << "Menu" << std::endl; showMenu();
    std::cout << "Baristas" << std::endl; showBaristas();
    std::cout << "Queue" << std::endl; showQueue();

}



//Customer
void Customer::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    currentOrder->displayOrder();

}