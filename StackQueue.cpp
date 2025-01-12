#include <iostream>
using namespace std;

class Node {
  // Write Node Description here
  // Node variables are given in Assignment 
private:
  int data;
  Node* nextNode;
  
public:
  

  Node (int n) {
    data = n;
    nextNode = NULL;
  }

  int getData() {
    return data;
  }
  
  Node* getNextNode() {
    return nextNode;
  }
  
  void setData(int d) {
    data = d;
  }

  void setNextNode(Node* n) {
    nextNode = n;
  }

};
class LLStack {
  // Stack ADT
  //  Use Appropriate Variables
  //  Write Stack methods here
  //  Stack is implemented as a linked list
  //   Stack methods are Push(), Pop(), Peek()
private:
  Node* top;
  int stackSize;
public:
  
  LLStack() {
    top = nullptr;
    stackSize = 0;
  }

  void push(int val) {
    Node* temp = new Node(val);
    temp->setNextNode(top);
    top = temp;
    stackSize++;
  }

  void pop() {
    Node* temp = top;
    top = top->getNextNode();
    stackSize--;
    free(temp);

  }

  int peek() {
    return top->getData();
    
  }

  void print(LLStack LLS) {
    LLStack tempStack;

    while (LLS.getSize() != 0) {
      tempStack.push(LLS.peek());
      cout << (tempStack.peek()) << " ";
      LLS.pop();
    }
  }

  void printRev(LLStack LLS) {
    LLStack tempStack;

    while (LLS.getSize() != 0) {
      tempStack.push(LLS.peek());
      LLS.pop();
    }

    while (tempStack.getSize() != 0) {
      int temp = tempStack.peek();
      cout << temp << " ";
      tempStack.pop();
      LLS.push(temp);
    }
  }

  int getSize() {
    return stackSize;
  }

  Node* getTop(){
    return top;
  }
};

class StackQ {
  // Queue ADT
  //  This is your queue class
  //  Implement queue methods here
  //  Queue methods are given in the Assignment
  //  Queue is implemented by manipulating two stacks.
  //  You will need references to 2 stacks here
private:
  LLStack enQStack;
  LLStack deQStack;
public:
  int size;
  StackQ() {
    enQStack = LLStack();
    deQStack = LLStack();
    size = 0;
  }

  void enQ(int n) {
    enQStack.push(n);
    size++;
  }

  int deQ() {
    while (enQStack.getSize() != 0) {
      deQStack.push(enQStack.peek());
      enQStack.pop();
    }

    int temp = deQStack.peek();
    deQStack.pop();

    return temp;  
  }


  int peek() {
    while (enQStack.getSize() != 0) {
      deQStack.push(enQStack.peek());
      enQStack.pop();
    }

    return deQStack.peek();
  }

  void printQueue() {
    if (getDeQStackSize() != 0) {
      deQStack.print(deQStack);
    }
    if (getEnQStackSize() != 0) {
      enQStack.printRev(enQStack);
    }
    cout << "\n";
    
  }

  void printQStacks() {
    cout << "\nenQStack: \n";
    if (getEnQStackSize() != 0) {
      enQStack.print(enQStack);
    }
    
    cout << "\ndeQStack: \n";
    if (getDeQStackSize() != 0) {
      deQStack.print(deQStack);
    }

    cout << "\n";
  }
  int queueSize() {

    return size;
  }

  int getDeQStackSize() {
    return deQStack.getSize();
  }
  int getEnQStackSize() {
    return enQStack.getSize();
  }
};

void printMenu() {
  cout << "\nMenu: \n";
  cout << "1 - Enqueue in the queue\n";
  cout << "2 - Dequeue from the queue\n";
  cout << "3 - Peek from the queue\n";
  cout << "4 - Display the queue\n";
  cout << "5 - Display enQStack and deQStack\n";
  cout << "6 - Display size of the queue\n";
  cout << "7 - Exit\n";
  
}
int main() {

  // Main method is written here
  // Write the options for menu
  // Implement appropriate exception Handling
  int userIn = 0;
  int userNum;
  StackQ Q;
  
  cout << "\n~    StackQ Program    ~\n";
  while (userIn != 7) {
    printMenu();
    cout << "\nPlease enter your choice: ";
    cin >> userIn;
    cout << "\n";

    if (userIn == 1) {
      cout << "Enter an integer to be queued: ";
        cin >> userNum;
        Q.enQ(userNum);
        cout << "\n";
        continue;
    }
    else if (userIn == 2) {
      if (Q.size != 0) {
        userNum = Q.peek();
        Q.deQ();
        cout << "Integer Dequeued is: " << userNum << "\n";
        continue;
      }
      cout << "Queue is empty. Please try again.\n";
      
      continue;
    }
    else if (userIn == 3) {
      if (Q.queueSize() != 0) {
        userNum = Q.peek();
        cout << "Front of Queue: " << userNum << "\n";
        continue;
      }
      cout << "Queue is empty. Please try again.\n";
    }
    else if (userIn == 4) {
      Q.printQueue();
      continue;
    }
    else if (userIn == 5) {
      Q.printQStacks();
      continue;
    }
    else if (userIn == 6) {
      cout << "The size of the queue is: " << Q.queueSize() << "\n";
      continue;
    }
    else if (userIn == 7) {
      cout << "\nExiting program...\n";
    }
    else {
      cout << "Error: Invalid input. Please try again or enter 7 to terminate program.";
    }
  }
  cout << "Done.";
}