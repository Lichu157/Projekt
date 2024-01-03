#include <iostream>
#include <fstream>

using namespace std;

void dodajElement(int*& tablica, int& rozmiar, int element) {
    int* nowaTablica = new int[rozmiar + 1];
    for (int i = 0; i < rozmiar; ++i) {
        nowaTablica[i] = tablica[i];
    }
    nowaTablica[rozmiar] = element;
    delete[] tablica;
    tablica = nowaTablica;
    ++rozmiar;
}

void usunPoIndeksie(int*& tablica, int& rozmiar, int indeks) {
    if (indeks >= 0 && indeks < rozmiar) {
        int* nowaTablica = new int[rozmiar - 1];
        for (int i = 0, j = 0; i < rozmiar; ++i) {
            if (i != indeks) {
                nowaTablica[j++] = tablica[i];
            }
        }
        delete[] tablica;
        tablica = nowaTablica;
        --rozmiar;
    }
}

void wstawNaIndeks(int*& tablica, int& rozmiar, int indeks, int element) {
    if (indeks >= 0 && indeks <= rozmiar) {
        int* nowaTablica = new int[rozmiar + 1];
        for (int i = 0, j = 0; i <= rozmiar; ++i) {
            if (i == indeks) {
                nowaTablica[i] = element;
            } else {
                nowaTablica[i] = tablica[j++];
            }
        }
        delete[] tablica;
        tablica = nowaTablica;
        ++rozmiar;
    }
}

void wyswietlTablice(const int* tablica, int rozmiar) {
    cout << "Tablica: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void zapiszDoPliku(const int* tablica, int rozmiar, const string& nazwaPliku) {
    ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        for (int i = 0; i < rozmiar; ++i) {
            plik << tablica[i] << " ";
        }
        plik.close();
        cout << "Tablica zapisana do pliku." << endl;
    } else {
        cout << "Błąd podczas otwierania pliku do zapisu." << endl;
    }
}

void odczytajZPliku(int*& tablica, int& rozmiar, const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        int liczba;
        while (plik >> liczba) {
            dodajElement(tablica, rozmiar, liczba);
        }
        plik.close();
        cout << "Tablica wczytana z pliku." << endl;
    } else {
        cout << "Błąd podczas otwierania pliku do odczytu." << endl;
    }
}

int main() {
    int* tablica = NULL;
    int rozmiar = 0;
    int wybor;

    do {
        cout << "\nMenu:\n";
        cout << "1. Dodaj element\n";
        cout << "2. Usun po indeksie\n";
        cout << "3. Wstaw na indeks\n";
        cout << "4. Wyswietl tablice\n";
        cout << "5. Odczytaj z pliku\n";
        cout << "6. Zapisz do pliku\n";
        cout << "7. Wyjdz\n";
        cout << "Wybierz numer: ";
        cin >> wybor;

        switch (wybor) {
            case 1: {
                int element;
                cout << "Podaj element do dodania: ";
                cin >> element;
                dodajElement(tablica, rozmiar, element);
                break;
            }
            case 2: {
                int indeks;
                cout << "Podaj indeks do usuniecia: ";
                cin >> indeks;
                usunPoIndeksie(tablica, rozmiar, indeks);
                break;
            }
            case 3: {
                int indeks, element;
                cout << "Podaj indeks: ";
                cin >> indeks;
                cout << "Podaj element do wstawienia: ";
                cin >> element;
                wstawNaIndeks(tablica, rozmiar, indeks, element);
                break;
            }
            case 4:
                wyswietlTablice(tablica, rozmiar);
                break;
            case 5: {
                string nazwaPliku;
                cout << "Podaj nazwe pliku do odczytu: ";
                cin >> nazwaPliku;
                odczytajZPliku(tablica, rozmiar, nazwaPliku);
                break;
            }
            case 6: {
                string nazwaPliku;
                cout << "Podaj nazwe pliku do zapisu: ";
                cin >> nazwaPliku;
                zapiszDoPliku(tablica, rozmiar, nazwaPliku);
                break;
            }
            case 7:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie.\n";
        }

    } while (wybor != 7);

    delete[] tablica;

    return 0;
}
