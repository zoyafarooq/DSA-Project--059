#include <iostream>
#include <string>
using namespace std;

class ProductNode {
public:
    int id;
    string name;
    float price;
    ProductNode* next;

    ProductNode(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
        next = NULL;
    }
};


class ProductCatalog {
private:
    ProductNode* head;

public:
    ProductCatalog() {
        head = NULL;
    }

    void addProduct(int id, string name, float price) {
        ProductNode* newNode = new ProductNode(id, name, price);
        newNode->next = head;
        head = newNode;
    }

    void showProducts() {
        if (!head) {
            cout << "No products available.\n";
            return;
        }
        cout << "\nAvailable Products:\n";
        ProductNode* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    ProductNode* findProduct(int id) {
        ProductNode* temp = head;
        while (temp) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};


class CartItem {
public:
    int id;
    string name;
    float price;
    int quantity;
    CartItem* next;

    CartItem(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        next = NULL;
    }
};


class Cart {
private:
    CartItem* head;

public:
    Cart() {
        head = NULL;
    }

    void addItem(int id, string name, float price, int quantity) {
        CartItem* newItem = new CartItem(id, name, price, quantity);
        newItem->next = head;
        head = newItem;
    }

    void displayCart() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }

        float total = 0;
        CartItem* temp = head;
        cout << "\nCart Items:\n";
        while (temp) {
            cout << "- " << temp->name << " (x" << temp->quantity << ") = $" << temp->price * temp->quantity << endl;
            total += temp->price * temp->quantity;
            temp = temp->next;
        }
        cout << "Total: $" << total << endl;
    }
};
class CustomerNode {
public:
    int id;
    CustomerNode* next;

    CustomerNode(int i) {
        id = i;
        next = NULL;
    }
};
class CustomerQueue {
private:
    CustomerNode* front;
    CustomerNode* rear;

public:
    CustomerQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int id) {
        CustomerNode* newNode = new CustomerNode(id);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int id = front->id;
        CustomerNode* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) rear = NULL;

        return id;
    }
};



int main() {
    ProductCatalog catalog;
    CustomerQueue customerQueue;

    // Add sample products
    catalog.addProduct(101, "Eggs", 3.5);
    catalog.addProduct(102, "Milk", 2.9);
    catalog.addProduct(103, "Cereal", 4.5);

    int customerId = 1;
    char moreCustomers = 'y';

    while (moreCustomers == 'y' || moreCustomers == 'Y') {
        customerQueue.enqueue(customerId++);
        int current = customerQueue.dequeue();

        cout << "\n--- Welcome Customer #" << current << " ---\n";
        Cart cart;
        int choice;

        do {
            cout << "\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\nEnter choice: ";
            cin >> choice;

            if (choice == 1) {
                catalog.showProducts();
            } else if (choice == 2) {
                int pid, qty;
                cout << "Enter Product ID: ";
                cin >> pid;
                ProductNode* p = catalog.findProduct(pid);
                if (p) {
                    cout << "Enter quantity: ";
                    cin >> qty;
                    cart.addItem(p->id, p->name, p->price, qty);
                    cout << "Added to cart.\n";
                } else {
                    cout << "Product not found.\n";
                }
            } else if (choice == 3) {
                cart.displayCart();
            } else if (choice == 4) {
                cout << "\n--- Checkout Summary ---\n";
                cart.displayCart();
            } else {
                cout << "Invalid choice!\n";
            }

        } while (choice != 4);

        cout << "\nAdd another customer? (y/n): ";
        cin >> moreCustomers;
    }

    cout << "\nThank you for shopping with us!\n";
    return 0;
}

