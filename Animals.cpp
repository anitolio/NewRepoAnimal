#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;
    string type;
    double weight;
    string continent;

    virtual void Input() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter type: ";
        getline(cin, type);

        while (true) {
            cout << "Enter weight: ";
            if (cin >> weight) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cin.ignore(10000, '\n'); 

        cout << "Enter continent: ";
        getline(cin, continent);
    }

    virtual void Print() {
        cout << "Name: " << name
            << ", Type: " << type
            << ", Weight: " << weight
            << ", Continent: " << continent << endl;
    }

    virtual void Eat() {
        cout << name << " is eating." << endl;
    }

    virtual void Sound() {
        cout << name << " makes a sound." << endl;
    }

    virtual ~Animal() {}
};

class Parrot : public Animal {
public:
    void Sound() override {
        cout << name << " says: Squawk!" << endl;
    }
};

class Elephant : public Animal {
public:
    void Sound() override {
        cout << name << " trumpets!" << endl;
    }
};

class Dog : public Animal {
public:
    void Sound() override {
        cout << name << " barks!" << endl;
    }
};

class Cat : public Animal {
public:
    void Sound() override {
        cout << name << " meows!" << endl;
    }
};

int main() {
    Animal* myAnimal[4];

    myAnimal[0] = new Parrot();
    myAnimal[1] = new Elephant();
    myAnimal[2] = new Dog();
    myAnimal[3] = new Cat();

    for (int i = 0; i < 4; i++) {
        cout << "\nInput details for animal " << (i + 1) << ":\n";
        myAnimal[i]->Input();
    }

    cout << "\nDisplaying animal details and actions:\n";
    for (int i = 0; i < 4; i++) {
        myAnimal[i]->Print();
        myAnimal[i]->Eat();
        myAnimal[i]->Sound();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        cout << "Deleting animal " << (i + 1) << "...\n";
        delete myAnimal[i];
    }

    return 0;
}