#include <iostream>

using namespace std;

class TRachunek {
private:
    string imie, nazwisko;
    int saldo;
    int debet;

public:
    friend void wyswietl(TRachunek &rachunek);

    TRachunek(string i, string n, int s, int d = 0) {
        imie = i;
        nazwisko = n;
        saldo = s;
        debet = d;
    }

    int podajStanKonta() {
        return saldo;
    }

    string podajImieNazwisko() {
        return imie + " " + nazwisko;
    }

    void wplata(int wartosc) {
        saldo += wartosc;
    }

    bool wyplata(int wartosc) {
        if (saldo - wartosc >= -debet) {
            return true;
        } else {
            return false;
        }
    }

    bool czyDebet() {
        if (saldo < 0) {
            return true;
        }
        return false;
    }

    bool wykonajPrzelew(TRachunek &rachunekk, int kwota) {
        if (wyplata(kwota)) {
            saldo -= kwota;
            rachunekk.wplata(kwota);
            return true;
        }
        return false;
    }

    double naliczodsetki(double oprocentowanie) {
        return saldo * (oprocentowanie * 0.01);

    }
};

void wyswietl(TRachunek &rachunek) {
    cout << rachunek.imie << " " << rachunek.nazwisko << " " << rachunek.saldo << endl;
}

int main() {
    TRachunek ror("Alicja", "Nowak", 0);
    ror.wplata(400);
    ror.naliczodsetki(2.3);
    TRachunek *pror;
    pror = new TRachunek("Jan", "Kowalski", 1000, 500);
    ror.wykonajPrzelew(*pror, 350);
    wyswietl(ror);
    wyswietl(*pror);
    return 0;
}
