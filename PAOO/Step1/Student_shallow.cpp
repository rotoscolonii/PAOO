#include <iostream>

using namespace std;

class Student {
private:
    int nrNote;
    int* note;
    

public:
    // Constructor cu parametrii 
    Student(int no, int* n){
        nrNote = no;
        note = new int[nrNote];
        for (int i = 0; i < nrNote; i++) {
            note[i] = n[i];
        }
    }

    // Metodă pentru afișarea datelor
    void afisare() {
        for (int i = 0; i < nrNote; ++i) {
            cout << note[i] << " ";
        }
        cout << endl;
    }

    void setNote(int *n){
        for (int i = 0; i < nrNote; i++) {
            note[i] = n[i];
        }
    }
};

int main() {
    //variabile utilizate
    
    int nrNote = 5;
    int* note1 = new int[nrNote];
    for (int i = 0; i < nrNote; i++) {
            note1[i] = 10-i;
        }
    int* note2 = new int[nrNote];
    for (int i = 0; i < nrNote; i++) {
            note2[i] = 10;
        }

    //constructor cu parametrii
    Student st1(5, note1); 
    //shallow  copy
    Student st2 =st1 ;

    cout << "student1 cu notele note1: ";
    st1.afisare();
    cout << "student2 cu notele lui st1: ";
    st2.afisare();

    st1.setNote(note2);
    cout << "student1 cu notele note1 modificat: ";
    st1.afisare();
    cout << "student2 cu notele lui st1 modificate: ";  //notele s-au modificat pentru ca s-a folosit shallow copy
    st2.afisare();
}