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

void Customer::payOrder(){ 
    if (currentOrder) 
    {
        balance -= currentOrder->getTotalPrice();
        currentOrder->markPaid();
    }
}

//Order
void Order::calculateTotalPrice()
{
    totalPrice = 0;
    for (const auto& elem : drinks)
    {
        totalPrice += elem.getPrice();
    }
}

void Order::displayOrder() const
{
    std::cout << "ID: " << orderId << std::endl;
    std::cout << "Drinks" << std::endl;
    for (const auto& elem : drinks)
    {
        elem.display();
    }
    std::cout << "TotalPrice: " << totalPrice << std::endl;
    std::cout << "IsPrepared: " << isPrepared << std::endl;
    std::cout << "IsPaid: " << isPaid << std::endl;
}


//Size
std::ostream& operator<<(std::ostream& os, const Drink::Size& volume)
{
    switch(volume) 
    {
        case Drink::Size::Small: os << "Small";  break;
        case Drink::Size::Medium: os << "Medium";  break;
        case Drink::Size::Big: os << "Big";  break;
    }
    return os;
}
//Drink

void Drink::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Volume: " <<  volume << std::endl;
    std::cout << "Price: " << price << std::endl;
} 


