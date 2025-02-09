/* Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
shopkeeper inputs the items and their amounts bought by the customer. */

#include <iostream>
#include <string>
using namespace std;

class Shop
{
    string items[100];
    float prices[100];
    int counter = 0;

public:
    void add()
    {
        int n;
        cout << "Enter the number of items to add: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin.ignore();
            cout << endl << "Enter item name: ";
            getline(cin, items[counter]);
            cout << "Enter the price of the item: ";
            cin >> prices[counter];
            counter++;
        }
    }

    void edit()
    {
        if (counter == 0)
        {
            cout << "The list of items has not been initialized yet." << endl;
            return;
        }

        string temp;
        cin.ignore();
        cout << "Enter the name of the item you want to edit the price for: ";
        getline(cin, temp);

        int flag = 0;
        for (int i = 0; i < counter; i++)
        {
            if (items[i] == temp)
            {
                float newPrice;
                cout << "Item found. Enter the new price of the item: ";
                cin >> newPrice;
                prices[i] = newPrice;
                flag = 1;
                cout << "Price updated successfully" << endl;
                break;
            }
        }

        if (!(flag))
        {
            cout << "Item not found!" << endl;
        }
    }

    void display()
    {
        if (counter == 0)
        {
            cout << "The list of items has not been initialized yet." << endl;
            return;
        }

        cout << endl
             << "Displaying all the items and their prices below" << endl;
        for (int i = 0; i < counter; i++)
        {
            cout << "Item " << (i + 1) << ": " << items[i] << " | " << "Price: $" << prices[i] << endl;
        }
    }
};

int main()
{
    Shop s1;
    int choice;
    cout << "----- Welcome to the Stationary Shop -----" << endl;
    cout << "Enter 1 to add items and their prices to the list." << endl;
    cout << "Enter 2 to edit the price of an item." << endl;
    cout << "Enter 3 to display all the items and their prices." << endl;
    cout << "Enter 4 to exit." << endl;
    while (1)
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s1.add();
            break;

        case 2:
            s1.edit();
            break;

        case 3:
            s1.display();
            break;

        case 4:
            cout << "Exiting the program..." << endl;
            return 0;
        }
    }
}
