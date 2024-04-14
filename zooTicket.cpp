#include <iostream>
#include <vector>

using namespace std;

class Guest {
private:
    int age;

public:
    Guest(int _age) : age(_age) {}

    int getAge() const {
        return age;
    }
};

class Ticket {
private:
    vector<Guest> guests;
    int totalPrice;

public:
    Ticket(const vector<Guest>& _guests) : guests(_guests) {
        totalPrice = 0;
        for (const auto& guest : guests) {
            int age = guest.getAge();
            if (age <= 2)
                totalPrice += 0;
            else if (age < 18)
                totalPrice += 100;
            else if (age < 60)
                totalPrice += 500;
            else
                totalPrice += 300;
        }
    }

    void displayTicketDetails() const {
        cout << "Ticket Details:" << endl;
        for (size_t i = 0; i < guests.size(); ++i) {
            cout << "Guest " << i + 1 << " (age: " << guests[i].getAge() << ")" << endl;
        }
        cout << "Total Price: INR " << totalPrice << endl;
    }
};

int main() {
    int numGuests;
    cout << "Enter the number of guests: ";
    cin >> numGuests;

    vector<Guest> guests;
    for (int i = 0; i < numGuests; ++i) {
        int age;
        cout << "Enter age of guest " << i + 1 << ": ";
        cin >> age;
        guests.push_back(Guest(age));
    }

    Ticket ticket(guests);

    // Display ticket details
    ticket.displayTicketDetails();

    // Security personnel validation
    // Security personnel can manually verify guests based on the displayed ticket details

    return 0;
}