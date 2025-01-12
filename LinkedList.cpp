#include <iostream>
#include <string.h>
#include <limits>
using namespace std;

// Node Class
class Node {
public:
  Node *next;
  int StudentREDID;
  string FullStudentName;

  Node(int ID, string name) {
    StudentREDID = ID;
    FullStudentName = name;
    next = nullptr;
  }
};

// Linked List Class

class LinkedList {
private:
  // CLASS MEMBER VARIABLES
  Node *head;
  Node *tail;
  int length;

public:
  // LINKED LIST CONSTRUCTOR
  LinkedList(int ID, string name) {
    Node *newNode = new Node(ID, name);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  // Linked List Destructor
  ~LinkedList() {
    Node *temp = head;
    while (head != nullptr) {
      head = head->next;
      delete temp;
      temp = head;
      length--;
    }
  }

  // Printing all items in the LL
  void printList() {
    Node *temp = head;
    if (length == 0)
      cout << "The list is empty";
    while (temp) {
      cout << temp->StudentREDID << " " << temp->FullStudentName << endl;
      temp = temp->next;
    }
  }

  // What's the first elemnt in the list?
  void getHead() {
    if (head == nullptr) {
      cout << "Head: nullptr" << endl;

    } else {
      cout << "Head: " << head->StudentREDID << " " << head->FullStudentName
           << endl;
    }
  }

  // What's the last element in the LL?
  void getTail() {
    if (tail == nullptr) {
      cout << "Tail: nullptr" << endl;
    } else {
      cout << "Tail: " << tail->StudentREDID << " " << tail->FullStudentName
           << endl;
    }
  }

  // How Long is the List?
  int getLength() {
    return length;
  }

  // Get the elemt at a particular index
  Node *get(int index) {
    if (index < 0 || index >= length)
      return nullptr;
    Node *temp = head;
    for (int i = 0; i < index; ++i) {
      temp = temp->next;
    }
    return temp;
  }

  // set value at a particular index
  bool set(int index, int ID, string name) {
    Node *temp = get(index);
    if (temp != nullptr) {
      temp->StudentREDID = ID;
      temp->FullStudentName = name;
      return true;
    }
    return false;
  }

  // Add node to the end of the list
  void append(int ID, string name) {
    Node *newNode = new Node(ID, name);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }

  // Add a new node to the start of the list
  void prepend(int ID, string name) {
    Node *newNode = new Node(ID, name);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    length++;
  }

  // Insert element at a particulat index
  bool insert(int index, int ID, string name) {
    if (index < 0 || index > length)
      return false;
    if (index == 0) {
      prepend(ID, name);
      return true;
    }
    if (index == length) {
      append(ID, name);
      return true;
    }
    Node *newNode = new Node(ID, name);
    Node *temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
  }

  // Delete the first node in the list
  void deleteFirst() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
    length--;
  }

  // Delete the last element of the list.
  void deleteLast() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node *pre = head;
      while (temp->next) {
        pre = temp;
        temp = temp->next;
      }
      tail = pre;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }

  // Delete a node at a particular index
  void deleteNode(int index) {
    if (index < 0 || index >= length)
      return;
    if (index == 0)
      return deleteFirst();
    if (index == length - 1)
      return deleteLast();

    Node *prev = get(index - 1);
    Node *temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;
  }
  void printMenu() {
    cout << "\nCHOOSE FROM THE FOLLOWING OPTIONS:\n";
    cout << "\n1. Make a Linked List\n";
    cout << "2. Add a Node to the Beginning\n";
    cout << "3. Add a Node to the End\n";
    cout << "4. Add a Node at Index\n";
    cout << "5. Delete Node from the Beginning\n";
    cout << "6. Delete Node from the End\n";
    cout << "7. Delete Node at Index\n";
    cout << "8. Sort by Name\n";
    cout << "9. Sort by REDID\n";
    cout << "10. Reverse LinkedList\n";
    cout << "11. Exit\n";
  }

  void sortByName() {
    if (length == 0) {
      cout << "\nList must have nodes, try again.\n";
    return;}
    Node* curr = head;
    Node* temp = NULL;
    
    while (curr != NULL) {
      temp = curr->next;
      
      while (temp != NULL) {
        if (curr->FullStudentName > temp->FullStudentName) {
          int tempID = curr->StudentREDID;
          string tempName = curr->FullStudentName;
          curr->StudentREDID = temp->StudentREDID;
          curr->FullStudentName = temp->FullStudentName;
          temp->StudentREDID = tempID;
          temp->FullStudentName = tempName;
        }
        temp = temp->next;
      }
      curr = curr->next;
    }
  }

  void sortByREDID() {
    if (length == 0) {
      cout << "\nList must have nodes, try again.\n";
      return;}
    Node* curr = head;
    Node* temp = NULL;
    while (curr != NULL) {
      temp = curr->next;
      
      while (temp != NULL) {
        if (curr->StudentREDID > temp->StudentREDID) {
          int tempID = curr->StudentREDID;
          string tempName = curr->FullStudentName;
          curr->StudentREDID = temp->StudentREDID;
          curr->FullStudentName = temp->FullStudentName;
          temp->StudentREDID = tempID;
          temp->FullStudentName = tempName;
        }
        temp = temp->next;
      }
      curr = curr->next;
    }
    
  }

  void reverseList() {
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    Node* last = tail;
    
    if (curr == NULL) {
      return;}
    if (length == 1) {
      return;
    }
    
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
};
// main function
int main() {
  int userIn = 0;
  LinkedList *ll = new LinkedList(0, "");
  cout << "LINKED LIST PROGRAM\n";

  bool listCreated = false;
  bool reversed = false;
  while (userIn != 11) {
    int inputID;
    string inputName;
    ll->printMenu();
    cout << "\nEnter Choice: ";
    cin >> userIn;
    if (cin.fail()) {
      cin.clear();
      cout<<"Not a valid input. Exiting program.\n";
      break;
    }
    if (listCreated != true & userIn != 1) {
      cout << "\nNot possible, must have a list\n";
      continue;
    }

    if (userIn == 1) {
      ll->~LinkedList();
      
      listCreated = true;
    }
    if (userIn == 2) {
      cout << "\nEnter Student ID: ";
      cin >> inputID;
      cout << "\nEnter Student Full Name: ";
      cin.ignore();
      getline(cin, inputName);
      ll->prepend(inputID, inputName);
    } 
    else if (userIn == 3) {
      cout << "\nEnter Student ID: ";
      cin >> inputID;
      cout << "\nEnter Student Full Name: ";
      cin.ignore();
      getline(cin, inputName);
      ll->append(inputID, inputName);
    } 
    else if (userIn == 4) {
      int userIdx;
      cout << "\nEnter Node Index: ";
      cin >> userIdx;
      cout << "\nEnter Student ID: ";
      cin >> inputID;
      cin.ignore();
      cout << "\nEnter Student Full Name: ";
      getline(cin, inputName);
      ll->insert(userIdx, inputID, inputName);
    } 
    else if (userIn == 5) {
      ll->deleteFirst();
    } 
    else if (userIn == 6) {
      ll->deleteLast();
    } 
    else if (userIn == 7) {
      int userIdx;
      cout << "\nEnter Node Index: ";
      cin >> userIdx;
      ll->deleteNode(userIdx);
    } 
    else if (userIn == 8) {
      ll->sortByName();
    } 
    else if (userIn == 9) {
      ll->sortByREDID();
    } 
    else if (userIn == 10) {
      if (reversed) {
        cout << "List Already Reversed, Try Again\n";
        continue;
      }
      ll->reverseList();
      reversed = true;
    }
    ll->printList();
    cout << "\n";
  }
  cout << "\nEXITING PROGRAM";
  ll->~LinkedList();
  delete ll;
}