#include "Loc.h"

Loc::Loc() : ocupat(false), nume_client("") {}

bool Loc::esteOcupat() const {
    return ocupat;
}

string Loc::getClient() const {
    return nume_client;
}

void Loc::rezerva(const string& client) {
    ocupat = true;
    nume_client = client;
}

void Loc::elibereaza() {
    ocupat = false;
    nume_client = "";
}
