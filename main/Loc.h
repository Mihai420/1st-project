#pragma once

#include <string>
using namespace std;

class Loc {
private:
    bool ocupat;
    string nume_client;

public:
    Loc();
    bool esteOcupat() const;
    string getClient() const;
    void rezerva(const string& client);
    void elibereaza();
};
  