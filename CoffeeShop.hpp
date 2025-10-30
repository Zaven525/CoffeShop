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

    void addCustomerToQueue(Customer* customer);
    void serveNextCustomer();
    void showQueue() const;
    void constructMenu();

    void displayShopInfo() const;
};

class Customer {
private:
    std::string name;
    double balance;
    Order* currentOrder; 

public:
    Customer() = default;
    Customer(const std::string& name, double balance);


    std::string getName() const;
    double getBalance() const;
    void setBalance(double newBalance);

    void placeOrder(Order* order);
    void payOrder();
    void viewOrder() const;

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

    Order();
    Order(int id);

    int getOrderId() const;
    double getTotalPrice() const;
    bool getIsPrepared() const;
    bool getIsPaid() const;


    void addDrink(const Drink& drink);
    void removeDrink(int index);
    void calculateTotalPrice();


    void markPrepared();
    void markPaid();

    void displayOrder() const;
};


class Drink {
public:
    enum class Size { Small, Medium, Big };

private:
    std::string name;
    Size volume;
    double price;

public:
    // Constructors
    Drink() = default;
    Drink(const std::string& newName, Size newVolume, double newPrice) : name{newName}, volume{newVolume}, price{newPrice} {};

    // Getters
    std::string getName() const { return name; };
    Size getVolume() const { return volume; };
    double getPrice() const { return price; };

    // Setters
    void setName(const std::string& newName);
    void setVolume(Size newVolume);
    void setPrice(double newPrice);

    // Display
    void display() const;
};


class Barista {
private:
    std::string name;

public:
    // Constructors
    Barista() = default;
    Barista(const std::string& newName) : name{newName} {};

    // Getters/Setters
    std::string getName() const { return name; };
    void setName(const std::string& newName);

    // Behavior
    void prepareOrder(Order* order); // dependency
    void greetCustomer() const;
};