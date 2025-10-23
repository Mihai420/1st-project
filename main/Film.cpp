#include "Film.h"
#include <iostream>

Film::Film(string t, string tp, double p, string ora, int d)
    : titlu(t), tip(tp), pret(p), ora_inceput(ora), durata(d) {
}

string Film::getTitlu() const { return titlu; }
string Film::getTip() const { return tip; }
double Film::getPret() const { return pret; }
string Film::getOraInceput() const { return ora_inceput; }
int Film::getDurata() const { return durata; }

Loc& Film::getLoc(int rand, int loc) {
    return sala[rand][loc];
}

void Film::afiseazaLocuri() const {
    cout << "\033[32m[ ]\033[0m Liber   \033[31m[X]\033[0m Ocupat\n";
    for (int i = 0; i < RANDURI; ++i) {
        cout << "Rand " << i + 1 << ": ";
        for (int j = 0; j < LOCURI; ++j) {
            if (sala[i][j].esteOcupat())
                cout << "\033[31m[X]\033[0m";
            else
                cout << "\033[32m[ ]\033[0m";
        }
        cout << endl;
    }
}

void Film::schimbaLoc(int randInitial, int locInitial, int randNou, int locNou, const string& client) {
    if (!sala[randInitial][locInitial].esteOcupat()) {
        cout << "Locul initial nu este ocupat.\n";
        return;
    }
    if (sala[randInitial][locInitial].getClient() != client) {
        cout << "Locul este deja ocupat de " << sala[randInitial][locInitial].getClient() << ".\n";
        return;
    }
    if (sala[randNou][locNou].esteOcupat()) {
        cout << "Locul nou este deja ocupat.\n";
        return;
    }
    sala[randNou][locNou].rezerva(client);
    sala[randInitial][locInitial].elibereaza();
    cout << "Locul a fost schimbat cu succes!\n";
}

void Film::anuleazaLoc(int rand, int loc, const string& client) {
    if (!sala[rand][loc].esteOcupat()) {
        cout << "Locul nu este ocupat, deci nu poate fi anulat.\n";
        return;
    }
    if (sala[rand][loc].getClient() != client) {
        cout << "Nu poti anula rezervarea altui client.\n";
        return;
    }
    sala[rand][loc].elibereaza();
    cout << "Rezervarea a fost anulata.\n";
}

void Film::salveazaLocuri(ofstream& f) const {
    f << "FILM:" << titlu << "\n";
    for (int i = 0; i < RANDURI; ++i) {
        for (int j = 0; j < LOCURI; ++j) {
            if (sala[i][j].esteOcupat()) {
                f << (i + 1) << "," << (j + 1) << "," << sala[i][j].getClient() << "\n";
            }
        }
    }
}

void Film::incarcaLocuri(ifstream& f) {
    string line;
    while (getline(f, line)) {
        if (line.find("FILM:") == 0) break;
        stringstream ss(line);
        int i, j;
        string client;
        char sep;
        if (!(ss >> i >> sep >> j >> sep) || sep != ',' || !getline(ss, client)) {
            cout << "Eroare la citire: " << line << "\n";
            continue;
        }
        sala[i - 1][j - 1].rezerva(client);
    }
}
