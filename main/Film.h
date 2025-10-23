#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "Loc.h"
using namespace std;

#define RANDURI 7
#define LOCURI 12

class Film {
private:
    string titlu;
    string tip;
    double pret;
    string ora_inceput;
    int durata;
    Loc sala[RANDURI][LOCURI];

public:
    Film(string t = "", string tp = "2D", double p = 0.0, string ora = "00:00", int d = 120);
    string getTitlu() const;
    string getTip() const;
    double getPret() const;
    string getOraInceput() const;
    int getDurata() const;
    Loc& getLoc(int rand, int loc);
    void afiseazaLocuri() const;
    void schimbaLoc(int randInitial, int locInitial, int randNou, int locNou, const string& client);
    void anuleazaLoc(int rand, int loc, const string& client);
    void salveazaLocuri(ofstream& f) const;
    void incarcaLocuri(ifstream& f);
};
