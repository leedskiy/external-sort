#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

void Create(string name);
void Sort(fstream& ff, size_t sizet, fstream& f, fstream& f1, fstream& f2);

int main() {
    fstream f("res.txt", ios::out);
    fstream f1("f1.txt", ios::out);
    fstream f2("f2.txt", ios::out);
    size_t sizet = 0;

    string name = "array.txt";

    Create(name);
    fstream ff(name);
    Sort(ff, sizet, f, f1, f2);

    return 0;
}

void Create(string name) {
    ofstream fout;
    fout.open(name);

    if (!fout.is_open()) {
        cout << "Can't create." << endl;
    }

    else {
        fout << "77 2 35 96 1 9 7";
    }
    fout.close();
}

void Sort(fstream& ff, size_t sizet, fstream& f, fstream& f1, fstream& f2) {

    int x1, x2, x3, temp;

    while (!ff.eof()) {
        ff >> temp;
        f << temp << " ";
        sizet++;
    }

    int pos;
    size_t ffsize;
    size_t n = 0;
    ffsize = pow(2, n);

    while (ffsize < sizet) {
        pos = 0;
        f.close();
        f.open("res.txt", ios::in);

        while (pos < sizet) {
            f >> x3;
            if ((pos / ffsize) % 2 == 0) {
                f1 << x3 << " ";
            }
            else {
                f2 << x3 << " ";
            }
            pos++;
        }

        f1.close();
        f2.close();
        f.close();
        f1.open("f1.txt", ios::in);
        f2.open("f2.txt", ios::in);
        f.open("res.txt", ios::out);

        size_t ixf1 = 0;
        size_t ixf2 = 0;

        while (!f1.eof() and !f2.eof()) {

            f1 >> x1;
            f2 >> x2;

            while (ixf1 < ffsize && ixf2 < ffsize && !f1.eof() && !f2.eof()) {

                if (x1 < x2) {
                    f << x1 << " ";
                    if (ixf1 != ffsize - 1)
                        f1 >> x1;
                    ixf1++;
                }

                else {
                    f << x2 << " ";
                    if (ixf2 != ffsize - 1)
                        f2 >> x2;
                    ixf2++;
                }
            }

            while (ixf1 < ffsize) {
                if (f1.eof()) break;
                f << x1 << " ";
                if (ixf1 != ffsize - 1)
                    f1 >> x1;
                ixf1++;
            }

            while (ixf2 < ffsize) {
                if (f2.eof()) break;
                f << x2 << " ";
                if (ixf2 != ffsize - 1)
                    f2 >> x2;
                ixf2++;

            }

            ixf1 = 0;
            ixf2 = 0;
        }

        while (!f1.eof()) {
            f1 >> x1;
            if (f1.eof()) break;
            f << x1;
        }

        while (!f2.eof()) {
            f2 >> x2;
            if (f2.eof()) break;
            f << x2;
        }

        n++;
        ffsize = pow(2, n);

        f1.close();
        f1.open("f1.txt", ios::out);
        f2.close();
        f2.open("f2.txt", ios::out);
    }

}
