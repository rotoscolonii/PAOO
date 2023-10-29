#include <iostream>

using namespace std;

class Student {
private:
    int nrNote;
    int* note;
    

public:
    // Constructor care inițializează membrii clasei
    Student(int no){
        nrNote = no;
        note = new int[nrNote];
        for (int i = 0; i < nrNote; i++) {
            note[i] = 0;
        }
    }
    
    // Constructor cu parametrii 
    Student(int no, int* n){
        nrNote = no;
        note = new int[nrNote];
        for (int i = 0; i < nrNote; i++) {
            note[i] = n[i];
        }
    }

    // Destructor care eliberează memoria heap
    ~Student() {
        cout <<"A fost apelat destructorul" << endl;
        delete note;
    }

    // Copy constructor pentru a gestiona corect copierea
    Student(const Student& other){
        nrNote = other.nrNote;
        note = new int[nrNote];
        for (int i = 0; i < nrNote; ++i) {
            note[i] = other.note[i];
        }
    }

    // Move constructor pentru a eficientiza transferul resurselor
    Student(Student&& other){
        note = other.note;
        nrNote = other.nrNote;
        other.note = nullptr;
        other.nrNote = 0;
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

    //init
    Student st_general(5); // constructor pentru initializare
    cout << "student general cu 5 note de 0: ";
    st_general.afisare();

    //constructor cu parametrii
    Student st1(5, note1); 
    //deep copy
    Student st2(st1); // Utilizare copy constructor = creeaza alt student cu 5 note

    cout << "student1 cu notele note1: ";
    st1.afisare();
    cout << "student2 cu notele lui st1: ";
    st2.afisare();

    st1.setNote(note2);
    cout << "student1 cu notele note1 modificat: ";
    st1.afisare();
    cout << "student2 cu notele sale: ";  //notele nu s-au modificat pentru ca s-a folosit deep copy
    st2.afisare();

    Student st3 = std::move(st1); // Utilizare move constructor 
    cout << "student3 cu notele lui st1: ";
    st3.afisare();
    cout << "student1 = nullptr: ";
    st1.afisare();

    //destructor
    




    return 0;
}