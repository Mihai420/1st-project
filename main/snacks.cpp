#include "Snacks.h"
#include <iostream>
#include <fstream>
 
void Snack::alegeSnack(const string& client) {
    ofstream fout("snacks.txt", ios::app);
    if (!fout) {
        cout << "Eroare la deschiderea fisierului snacks.txt\n";
        return;
    }

    int tipSnack;
    cout << "\nAlege tipul de snack:\n";
    cout << "1. Popcorn\n";
    cout << "2. Nachos\n";
    cout << "0. Anuleaza\nOptiune: ";
    cin >> tipSnack;
    if (tipSnack == 0) return;

    int dimensiune;
    cout << "\nAlege dimensiunea:\n";
    if (tipSnack == 1) {
        cout << "1. Mic (100g - 20 lei)\n";
        cout << "2. Mediu (150g - 25 lei)\n";
        cout << "3. Mare (200g - 30 lei)\n";
    }
    else {
        cout << "1. Mic (80g - 25 lei)\n";
        cout << "2. Mediu (150g - 30 lei)\n";
        cout << "3. Mare (250g - 35 lei)\n";
    }
    cout << "Optiune: ";
    cin >> dimensiune;

    string numeDim;
    int gramaj = 0;
    double volum = 0.0;
    double pret = 0.0;

    if (dimensiune == 1) { numeDim = "Mic"; volum = 0.3; }
    else if (dimensiune == 2) { numeDim = "Mediu"; volum = 0.5; }
    else if (dimensiune == 3) { numeDim = "Mare"; volum = 0.75; }
    else {
        cout << "Dimensiune invalida.\n";
        return;
    }

    if (tipSnack == 1) {
        if (dimensiune == 1) { gramaj = 100; pret = 20.0; }
        else if (dimensiune == 2) { gramaj = 150; pret = 25.0; }
        else if (dimensiune == 3) { gramaj = 200; pret = 30.0; }
    }
    else {
        if (dimensiune == 1) { gramaj = 80; pret = 25.0; }
        else if (dimensiune == 2) { gramaj = 150; pret = 30.0; }
        else if (dimensiune == 3) { gramaj = 250; pret = 35.0; }
    }

    cout << "\nAi ales:\n";
    cout << "Snack: " << numeDim << " - " << gramaj << "g\n";
    cout << "Bautura: " << volum << "L\n";

    int b;
    string bautura;
    cout << "\nAlege bautura:\n";
    cout << "1. Pepsi (" << volum << "L)\n";
    cout << "2. Fanta (" << volum << "L)\n";
    cout << "3. Sprite (" << volum << "L)\n";
    cout << "4. Lipton (" << volum << "L)\n";
    cout << "Optiune: ";
    cin >> b;
    switch (b) {
    case 1: bautura = "Pepsi"; break;
    case 2: bautura = "Fanta"; break;
    case 3: bautura = "Sprite"; break;
    case 4: bautura = "Lipton"; break;
    default:
        cout << "Bautura invalida.\n";
        return;
    }

    cout << "Ai ales bautura: " << bautura << " (" << volum << "L)\n";

    if (tipSnack == 1) {
        string aroma;
        int a, costAroma = 0;
        cout << "\nAlege aroma:\n";
        cout << "1. Sare (0 lei)\n";
        cout << "2. Caramel (+3 lei)\n";
        cout << "3. Ciocolata (+5 lei)\nOptiune: ";
        cin >> a;
        switch (a) {
        case 1: aroma = "Sare"; costAroma = 0; break;
        case 2: aroma = "Caramel"; costAroma = 3; break;
        case 3: aroma = "Ciocolata"; costAroma = 5; break;
        default:
            cout << "Aroma invalida.\n";
            return;
        }
        pret += costAroma;
        fout << client << " a ales:\n";
        fout << "Popcorn " << numeDim << " (" << aroma << "), " << gramaj << "g, "
            << bautura << " " << volum << "L\n";
        fout << "Pret total: " << pret << " lei\n";

        // Afiseaza comanda finala
        cout << "\nComanda ta finala:\n";
        cout << "-----------------------------------\n";
        cout << "Client: " << client << endl;
        cout << "Snack: Popcorn " << numeDim << " (" << aroma << ")\n";
        cout << "Gramaj: " << gramaj << "g\n";
        cout << "Bautura: " << bautura << " (" << volum << "L)\n";
        cout << "Pret total: " << pret << " lei\n";
        cout << "-----------------------------------\n";
    }
    else {
        string sos;
        int s;
        cout << "\nAlege sos:\n";
        cout << "1. Branza\n2. Salsa\n3. Ambele (doar pentru Mare)\nOptiune: ";
        cin >> s;
        if (s == 3 && dimensiune != 3) {
            cout << "Optiunea 'Ambele sosuri' este disponibila doar pentru dimensiunea Mare.\n";
            return;
        }
        switch (s) {
        case 1: sos = "Branza"; break;
        case 2: sos = "Salsa"; break;
        case 3: sos = "Branza si Salsa"; break;
        default:
            cout << "Sos invalid.\n";
            return;
        }
        fout << client << " a ales:\n";
        fout << "Nachos " << numeDim << " cu sos " << sos << ", " << gramaj << "g, "
            << bautura << " " << volum << "L\n";
        fout << "Pret total: " << pret << " lei\n";

        // Afiseaza comanda finala
        cout << "\nComanda ta finala:\n";
        cout << "-----------------------------------\n";
        cout << "Client: " << client << endl;
        cout << "Snack: Nachos " << numeDim << " cu sos " << sos << "\n";
        cout << "Gramaj: " << gramaj << "g\n";
        cout << "Bautura: " << bautura << " (" << volum << "L)\n";
        cout << "Pret total: " << pret << " lei\n";
        cout << "-----------------------------------\n";
    }

    fout.close();
}
