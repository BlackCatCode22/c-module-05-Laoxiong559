#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void addNode(string data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

unordered_map<string, LinkedList> speciesMap;

void addAnimal(string species, string animalData) {
    if (speciesMap.find(species) == speciesMap.end()) {
        speciesMap[species] = LinkedList();
    }
    speciesMap[species].addNode(animalData);
}

int main() {
    addAnimal("Lion", "Simba");
    addAnimal("Lion", "Mufasa");
    addAnimal("Tiger", "Raja");
    addAnimal("Tiger", "Rani");

    for (auto& pair : speciesMap) {
        cout << "Species: " << pair.first << endl;
        pair.second.display();
        cout << endl;
    }

    return 0;
}
