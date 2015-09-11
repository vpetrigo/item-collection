#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>

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
};

string get_name(istream& is) {
    char c;
    string name;

    while (isspace(c = is.get())) {

    }

    if (c == '\"') {
        while ((c = is.get()) != '\"') {
            name += c;
        }
    }

    return name;
}

istream& operator>>(istream& is, Item& i) {
    i.name = get_name(is);
    is >> i.iid >> i.value;

    return is;
}

ostream& operator<<(ostream& os, const Item& i) {
    os << i.iid << ": " << i.name << " - " << i.value << endl;

    return os;
}

int main() {
    string from, to;

    cin >> from >> to;

    ifstream ifs{from};
    ofstream ofs{to};

    istream_iterator<Item> is{ifs};
    istream_iterator<Item> eos;
    ostream_iterator<Item> io{ofs};

    vector<Item> v{is, eos};

    for (auto& i : v) {
        cout << "Item name: " << i.name << endl <<
            "Item ID: " << i.iid << endl <<
            "Item value: " << i.value << endl;
    }

    copy(v.begin(), v.end(), io);

    return 0;
}