#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Customer;
class Order;
class Drink;
class Barista;


class CoffeeShop {
private:
    std::string shopName;
    std::vector<Drink*> menu;
    std::vector<Barista*> baristas; // Aggregation
    std::vector<Customer*> queue;   // Association

public:
    CoffeeShop() = default;
    CoffeeShop(const std::string& name) : shopName{name} {};


    std::string getName() const { return shopName; };
    void setName(const std::string& newName) { shopName = newName; };

    void addDrink(Drink* drink) { menu.push_back(drink); };
    void removeDrink(const std::string& drinkName);
    void showMenu() const;

    void hireBarista(Barista* barista) { baristas.push_back(barista); };
    void fireBarista(Barista* barista);
    void showBaristas() const;

    void addCustomerToQueue(Customer* customer) { queue.push_back(customer); };
    void serveNextCustomer() { if(!queue.empty()) queue.erase(queue.begin()); };
    void showQueue() const;
    void constructMenu(); // es inch piti ani?

    void displayShopInfo() const;
};

class Customer {
private:
    std::string name;
    double balance;
    Order* currentOrder; 

public:
    Customer() = default;
    Customer(const std::string& newName, double newBalance) : name{newName}, balance{newBalance}, currentOrder{nullptr} {}


    std::string getName() const { return name; };
    double getBalance() const { return balance; };
    void setBalance(double newBalance) { balance = newBalance; };

    void placeOrder(Order* order) { delete currentOrder; currentOrder = order; };
    void payOrder();
    void viewOrder() const { currentOrder->displayOrder(); };

    void display() const;
};


class Order {
private:
    int orderId;
    std::vector<Drink> drinks;
    double totalPrice;
    bool isPrepared;
    bool isPaid;

public:

    Order() : orderId{0}, totalPrice(0), isPrepared{false}, isPaid{false} {}
    Order(int id) : orderId{id}, totalPrice(0), isPrepared{false}, isPaid{false} {}

    int getOrderId() const { return orderId; }
    double getTotalPrice() const { return totalPrice; }
    bool getIsPrepared() const { return isPrepared; }
    bool getIsPaid() const { return isPaid; }


    void addDrink(const Drink& drink) { drinks.push_back(drink); }
    void removeDrink(int index) { if (index >= 0 && index < drinks.size()) drinks.erase(drinks.begin() + index); }
    void calculateTotalPrice();


    void markPrepared() { isPrepared = true; }
    void markPaid() { isPaid = true; }

    void displayOrder() const;
};


class Drink {
public:
    enum class Size { Small, Medium, Big };
    friend std::ostream& operator<<(std::ostream& os, const Size& volume);
private:
    std::string name;
    Size volume;
    double price;

public:
    // Constructors
    Drink() = default;
    Drink(const std::string& newName, Size newVolume, double newPrice) : name{newName}, volume{newVolume}, price{newPrice} {}

    // Getters
    std::string getName() const { return name; }
    Size getVolume() const { return volume; }
    double getPrice() const { return price; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setVolume(Size newVolume) { volume = newVolume; }
    void setPrice(double newPrice) { price = newPrice; }

    // Display
    void display() const;
};


class Barista {
private:
    std::string name;

public:
    // Constructors
    Barista() = default;
    Barista(const std::string& newName) : name{newName} {}

    // Getters/Setters
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    // Behavior
    void prepareOrder(Order* order) { order->markPrepared(); } // dependency
    void greetCustomer() const;
};