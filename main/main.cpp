#include <iostream>
#include "Cinema.h"
#include "Snacks.h"

using namespace std;

int main() {
    Cinema cinema;
    string client;

    cout << "Introdu numele tau: ";
    cin >> client;

    int opt;
    do {
        cout << "\n1. Afiseaza filme\n2. Afiseaza locuri\n3. Cumpara bilet\n4. Schimba loc\n5. Anuleaza loc\n6. Snacks\n0. Iesire\nOptiune: ";
        cin >> opt;

        if (opt == 1) {
            cinema.afiseazaFilme();
        }
        else if (opt == 2) {
            cinema.afiseazaFilme();
            int i;
            cout << "Alege film (1-" << cinema.getNrFilme() << "): ";
            cin >> i;
            if (i > 0 && i <= cinema.getNrFilme()) {
                cinema.getFilm(i - 1).afiseazaLocuri();
            }
            else {
                cout << "Film invalid.\n";
            }
        }
        else if (opt == 3) { // Cumpara bilet
            cinema.afiseazaFilme();
            int i, r, l;
            cout << "Alege film (1-" << cinema.getNrFilme() << "): ";
            cin >> i;
            if (i <= 0 || i > cinema.getNrFilme()) {
                cout << "Film invalid!\n";
                continue;
            }
            cinema.getFilm(i - 1).afiseazaLocuri();
            cout << "Rand: "; cin >> r;
            cout << "Loc: "; cin >> l;
            if (r < 1 || r > RANDURI || l < 1 || l > LOCURI) {
                cout << "Rand sau loc invalid.\n";
                continue;
            }
            cinema.cumparaBilet(i - 1, r - 1, l - 1, client);
        }
        else if (opt == 4) { // Schimba loc
            cinema.afiseazaFilme();
            int i, r1, l1, r2, l2;
            cout << "Alege film (1-" << cinema.getNrFilme() << "): ";
            cin >> i;
            if (i <= 0 || i > cinema.getNrFilme()) {
                cout << "Film invalid!\n";
                continue;
            }
            cinema.getFilm(i - 1).afiseazaLocuri();
            cout << "Loc initial - Rand: "; cin >> r1;
            cout << "Loc initial - Loc: "; cin >> l1;
            cout << "Loc nou - Rand: "; cin >> r2;
            cout << "Loc nou - Loc: "; cin >> l2;
            if (r1 < 1 || r1 > RANDURI || l1 < 1 || l1 > LOCURI ||
                r2 < 1 || r2 > RANDURI || l2 < 1 || l2 > LOCURI) {
                cout << "Rand sau loc invalid.\n";
                continue;
            }
            cinema.getFilm(i - 1).schimbaLoc(r1 - 1, l1 - 1, r2 - 1, l2 - 1, client);
        }
        else if (opt == 5) { // Anuleaza loc
            cinema.afiseazaFilme();
            int i, r, l;
            cout << "Alege film (1-" << cinema.getNrFilme() << "): ";
            cin >> i;
            if (i <= 0 || i > cinema.getNrFilme()) {
                cout << "Film invalid!\n";
                continue;
            }
            cinema.getFilm(i - 1).afiseazaLocuri();
            cout << "Rand: "; cin >> r;
            cout << "Loc: "; cin >> l;
            if (r < 1 || r > RANDURI || l < 1 || l > LOCURI) {
                cout << "Rand sau loc invalid.\n";
                continue;
            }
            cinema.getFilm(i - 1).anuleazaLoc(r - 1, l - 1, client);
        }
        else if (opt == 6) {
            Snack::alegeSnack(client);
        }
        else if (opt == 0) {
            cout << "Iesire din program. Salvam datele...\n";
        }
        else {
            cout << "Optiune invalida!\n";
        }

    } while (opt != 0);

    cinema.salveazaDate();

    return 0;
}
