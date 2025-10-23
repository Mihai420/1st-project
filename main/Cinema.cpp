#include "Cinema.h"
#include <iostream>
#include <fstream>
#include <sstream>

Cinema::Cinema() {
    filme.emplace_back("Avatar", "3D", 30.0, "14:00", 150);
    filme.emplace_back("Minecraft", "4DX", 40.0, "17:00", 160);
    filme.emplace_back("Buzz House", "2D", 25.0, "21:00", 180);  
    incarcaDate();
}

void Cinema::afiseazaFilme() const {
    cout << "\n--- Filme disponibile ---\n";
    for (int i = 0; i < filme.size(); ++i) {
        cout << i + 1 << ". " << filme[i].getTitlu() << " (" << filme[i].getTip() << ") - Ora: "
            << filme[i].getOraInceput() << " - Durata: " << filme[i].getDurata() << " minute - Pret: "
            << filme[i].getPret() << " lei\n";
    }
}

void Cinema::cumparaBilet(int indexFilm, int rand, int loc, const string& client) {
    if (!filme[indexFilm].getLoc(rand, loc).esteOcupat()) {
        filme[indexFilm].getLoc(rand, loc).rezerva(client);
        cout << "Bilet cumparat cu succes!" << endl;
        cout << "Vizionare placuta!" << endl;
    }
    else {
        cout << "Locul este deja ocupat!" << endl;
    }
}

void Cinema::salveazaDate() {
    ofstream f("rezervari.txt");
    for (const auto& film : filme) {
        film.salveazaLocuri(f);
    }
    cout << "\nDatele au fost salvate in 'rezervari.txt'.\n";
}

void Cinema::incarcaDate() {
    ifstream f("rezervari.txt");
    if (!f) {
        cout << "Fisierul 'rezervari.txt' nu a fost gasit. Se va incepe cu date noi.\n";
        return;
    }

    string line;
    int currentFilm = -1;
    while (getline(f, line)) {
        if (line.find("FILM:") == 0) {
            ++currentFilm;
            if (currentFilm >= filme.size()) break;
        }
        else if (currentFilm >= 0 && currentFilm < filme.size()) {
            stringstream ss(line);
            int i, j;
            string client;
            char sep;
            if (!(ss >> i >> sep >> j >> sep) || sep != ',' || !getline(ss, client)) {
                cout << "Eroare la citirea fisierului: " << line << "\n";
                continue;
            }
            filme[currentFilm].getLoc(i - 1, j - 1).rezerva(client);
        }
    }
}

Film& Cinema::getFilm(int i) {
    return filme[i];
}

int Cinema::getNrFilme() const {
    return filme.size();
}
