#include "DataStructure.h"    //include the header file
#include <vector>
//Note: Don't traverse using the head node, always use a temp pointer for traversal, the head and tail node is used to keep track of the beginning and the end node

int main() {
    //Name: Ayan Das  Emplid: 24073854
    //Name: Richard Karikari  Emplid: 23933360

    //All the functions implemented works.

    //Introduction
    cout << "Good Morning CSC 21200 class. This project was completed by Ayan Das and Richard Karikari" << endl;

    //Testing the functions

    StuList *new_node = new StuList();   //instantiate a new list to store our values, currently the list is empty
   /* //testing the function using a normal pointer, check below for implemenation for the actual function
    new_node->addToHead("Ayan Das", 24073854);
    new_node->addToTail("Richard Karikari", 23933360);
    new_node->addToTail("Arna Das", 24073);
    new_node->addToHead("Mohhamed Charrwi", 60123);
    new_node->deleteFromTail();
    new_node->deleteNode(24073854);


    new_node->printList(); */



    //main code implementations begins here
    StuList Enrollment[5];
    StuList Waiting[5];
    //Array of pointers to info struct of size

    //intialize pointer array to NULL for both arrays
    int id;
    string name;
    int fullSectionsEnrollment[5];
    int fullSectionsWaiting[5];

    for (int i = 0; i < 5; i++)
    {
        while (Enrollment->ListLength() <= 10) {
            cout << "Enter name and id: ";
            cin >> name, id;
            cout << endl;
            if (Enrollment->isEmpty())
                Enrollment->addToHead(name, id);
            else
                Enrollment->addToTail(name, id);

        }
        fullSectionsEnrollment[i] = 10;  //to check for the number of lists filled out, once this vector is filled out, that means all the enrollment section has been filled
        cout << "Current length: " << Enrollment->ListLength() << endl;
        Enrollment->printList();
        cout << "Current length of linked List: " << Enrollment->ListLength() << endl;
        cout << endl;
        Enrollment->EmptyList();  //reset the node, essentially the constructor
    //once this loop ends, we will have filled out the enrollment section, we do the same for the waiting list
    }


    //uncomment this and comment the previous loop to test
    /*
    if (fullSectionsEnrollment.size() == 5) {
        for (int i = 0; i < 5; i++) {
            while (Waiting->ListLength() <= 5) {
                cout << "Enter name and id: ";
                cin >> name, id;
                cout << endl;

                if (Waiting->isEmpty())
                    Waiting->addToHead(name, id);
                else
                    Waiting->addToTail(name, id);
                cout << "Current Linked List size: " << Waiting->ListLength() << endl;
            }
            fullSectionsWaiting[i] = 5;  //to check for the number of lists filled out
            Waiting->printList();
            Waiting->EmptyList();  //reset the node, essentially the constructor
            cout << Waiting->isEmpty() << endl;
        }
    }
     */

    return 0;
}
