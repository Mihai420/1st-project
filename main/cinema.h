#pragma once


#include <vector>
#include "Film.h"
using namespace std;

class Cinema {
private:
    vector<Film> filme;

public:
    Cinema();
    void afiseazaFilme() const;
    void cumparaBilet(int indexFilm, int rand, int loc, const string& client);
    void salveazaDate();
    void incarcaDate();
    Film& getFilm(int i);
    int getNrFilme() const;
};
