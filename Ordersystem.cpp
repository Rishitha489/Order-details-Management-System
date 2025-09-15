#include <iostream>
#include <string>
using namespace std;

class OrderDetails {
private:
	long int orderid;
	string ordername;
	double price;
	int qty;

public:
	// Constructor
	OrderDetails() {
		orderid = 0;
		ordername = "";
		price = 0.0;
		qty = 0;
	}

	OrderDetails(long int id, string name, double p, int q) {
		orderid = id;
		ordername = name;
		price = p;
		qty = q;
	}

	// Getters
	string getOrderName() {
		return ordername;
	}
	double getPrice() {
		return price;
	}
	int getQty() {
		return qty;
	}

	// Setters
	void setOrderName(string name) {
		ordername = name;
	}
	void setPrice(double p) {
		price = p;
	}
	void setQty(int q) {
		qty = q;
	}

	long int getOrderId() {
		return orderid;
	}

	// Function to display order details
	void display() {
		cout << "\nOrder ID: " << orderid;
		cout << "\nOrder Name: " << ordername;
		cout << "\nPrice: " << price;
		cout << "\nQuantity: " << qty << "\n";
	}

	// Search function (checks orderid)
	bool search(long int id) {
		if (orderid == id) {
			display();
			return true;
		}
		return false;
	}

	// Update price of order
	bool updatePrice(long int id, double newPrice) {
		if (orderid == id) {
			price = newPrice;
			cout << "Price updated successfully!\n";
			return true;
		}
		return false;
	}
};

int main() {
	const int SIZE = 5;
	OrderDetails orders[SIZE];

	int choice, qty;
	string name;
	double price;
	long int id;

	int count = 0; // number of orders stored

	do {
		cout << "\n===== ORDER MANAGEMENT SYSTEM =====";
		cout << "\n1. Add Order";
		cout << "\n2. Search Order";
		cout << "\n3. Update Order Price";
		cout << "\n4. Display All Orders";
		cout << "\n5. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			if (count < SIZE) {
				cout << "Enter Order ID: ";
				cin >> id;
				cout << "Enter Order Name: ";
				cin >> name;
				cout << "Enter Price: ";
				cin >> price;
				cout << "Enter Quantity: ";
				cin >> qty;

				orders[count] = OrderDetails(id, name, price, qty);
				count++;
				cout << "Order added successfully!\n";
			} else {
				cout << "Order list is full!\n";
			}
			break;

		case 2:
			cout << "Enter Order ID to search: ";
			cin >> id;
			{
				bool found = false;
				for (int i = 0; i < count; i++) {
					if (orders[i].search(id)) {
						found = true;
						break;
					}
				}
				if (!found) cout << "Order not found!\n";
			}
			break;

		case 3:
			cout << "Enter Order ID to update price: ";
			cin >> id;
			cout << "Enter new price: ";
			cin >> price;
			{
				bool updated = false;
				for (int i = 0; i < count; i++) {
					if (orders[i].updatePrice(id, price)) {
						updated = true;
						break;
					}
				}
				if (!updated) cout << "Order not found!\n";
			}
			break;

		case 4:
			if (count == 0) {
				cout << "No orders available!\n";
			} else {
				for (int i = 0; i < count; i++) {
					orders[i].display();
				}
			}
			break;

		case 5:
			cout << "Exiting... Thank you!\n";
			break;

		default:
			cout << "Invalid choice! Try again.\n";
		}

	} while (choice != 5);

	return 0;
}
