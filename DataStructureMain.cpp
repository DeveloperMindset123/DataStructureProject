#include "DataStructure.h"    //include the header file
#include <vector>
//Note: Don't traverse using the head node, always use a temp pointer for traversal, the head and tail node is used to keep track of the beginning and the end node

int main() {
    //Name: Ayan Das  Emplid: 24073854
    //Name: Richard Karikari  Emplid: 23933360

    StuList Enrollment[5]; //each index can hold up to 10 students
    StuList Waiting[5];    //each index can hold up to 5 students
    int option;
    string name;
    int id;
    int section;
    cout << "Welcome CSC 212 students. This project was done by Ayan Das and Richard Karikari.\n";
    StuNode *head;

    //Menu Implementation
    while (option != 5)
    {
        cout << "The following are the list of options you have available:\n";
        cout << "1. Enroll a Student in a section. You can required to specify the section you want to enroll in.\n";
        cout << "2. Withdraw a student from a section, requires id to be specified.\n";
        cout << "3. Print the list of enrolled students and the waiting list of the section.\n";
        cout << "4. Search for a student in a section:\n";
        cout << "5. Exit the program\n";
        cin >> option;

        //implementation based on the specifc section
        if (option== 1)
        {
            cout << "Write you name, id and section number: (use space to seperate your answers)";
            cin >> name >> id >> section;

            if (Enrollment[section].ListLength() < 10) {  //will check if the specified section's Listlength is less than 10
                if (Enrollment[section].isEmpty()) //checks if the linked list at the specified section is empty
                {
                    Enrollment[section].addToHead(name, id);
                    cout << "Student has been successfully added to enrollment.\n";
                }
                else {
                    //if the section isn't empty and the length of the list is less than 10
                    Enrollment[section].addToTail(name, id);
                    cout << "Student has been successfully added to enrollment.\n";
                }

            }
            else if (Enrollment[section].ListLength() >= 10) //if the length of the list is greater 10
            {
                if (Waiting[section].ListLength() < 5)
                {
                    if (Waiting[section].isEmpty())  //checks if the linked list at the present is empty
                    {
                        Waiting[section].addToHead(name, id);
                        cout << "Enrollment section is full, student has been placed in the waiting list.\n";
                    }
                    else {
                        Waiting[section].addToTail(name, id);
                        cout << "Enrollment section is full, student has been placed in the waiting list.\n";
                    }
                }
            }
            else //in the case that both Waiting list and Enrollment section is full
            {
                cout << "Both the Waiting and Enrollment section is full, please try again with a different section";
                break;
            }
        }

        else if (option == 2)
        {
            cout << "Specify the section:\n";
            cin >> section;
            cout << "\nSpecify the id:\n";
            cin >> id;
            if (Enrollment[section].search(id))  //checks to see if the student at the specifed section with the given id exist
            {
                Enrollment[section].deleteNode(id);
                cout << "The student has been successfully deleted.\n";
                //Note: Not sure how to access the student from the waiting list, unable to implement this single aspect
            }
        }

        else if (option == 3) {
            //Print the list of enrolled students and waiting list of the students
            //base case: check if the list is empty
            cout << "Enter a section number between 0 and 4:\n";
            cin >> section;
            if (!Enrollment[section].isEmpty()) {
                cout << "The enrollment list at the specified section is:\n";
                Enrollment[section].printList();
            }
            if (!Waiting[section].isEmpty()) {
                cout << "\nThe Waiting list at the specified section is:\n";
                Waiting[section].printList();
            }
            if (Enrollment[section].isEmpty()) {
                cout << "\nThe Enrollment list at the section specified is empty.\n";
            }
            if (Waiting[section].isEmpty())
            {
                cout << "\nThe Waiting list at the section specifed is empty.\n";
            }

        }

        else if (option == 4) //This option will ask the user to specify the section in which you want to search in
        {
            cout << "Specify a section number between 0 and 4:\n";
            cin >> section;
            cout << "Specify the id number of the student you are searching for:\n";
            cin >> id;

            if (Enrollment[section].search(id))
                cout << "Student with the specified id is in the Enrollment list.\n";
            else if (Waiting[section].search(id))
                cout << "Student with the specified id is in the Waiting list.\n";
            else
                cout << "Student with the specified id is neither in the Enrollment nor Waiting list.\n";
        }

        else if (option == 5)
            break;
        else {
            cout << "Please specify a number between 1 and 5, an out of range number/character isn't acceptable.\n";
            break;
        }
    }
    return 0;
}