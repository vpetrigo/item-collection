#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

struct Item {
    explicit Item(const string& n, int id, double v) : name{n}, iid{id}, value{v} {
        if (value < 0 || iid < 0) {
            throw logic_error{"Value and iid cannot be negative"};
        }
    }

    Item() : name{""}, iid{0}, value{0} {}

    string name;
    int iid;
    double value;

private:
    string get_name(istream& is);
};

istream& operator>>(istream& is, Item& i) {

    if (is.get() == '\"') {
        string good_name;
        while (is.get() != '\"') {

        }
        is >> i.name >> i.iid >> i.value;
    }
    return is;
}

string Item::get_name(istream& is) {
    char c;

    while ((c = is.get()) != '\"') {
        
    }

}

int main() {
    istream_iterator<Item> is{cin};
    istream_iterator<Item> eos;

    vector<Item> v{is, eos};

    for (auto& i : v) {
        cout << "Item name: " << i.name << endl <<
            "Item ID: " << i.iid << endl <<
            "Item value: " << i.value << endl;
    }

    return 0;
}