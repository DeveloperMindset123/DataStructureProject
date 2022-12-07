#include <string>
#include <iostream>
using namespace std;
//https://www.codewhoop.com/linked-list/delete-node-from-start-and-end.html

//Time Complexity: O(n), best case: o(1) where N is the length of the linked list
//Given that the student node class consists of the following members:

class StuNode
{
public:
    string name;
    int id;
    StuNode *next;
    StuNode (string s, int d, StuNode *n = 0)
    {
        name = s;   //our StuNode constructor that will be used to define the new
        id = d;
        next = n;
    }
};

//and given that the student list consists of the following members
class StuList
{
private:
    StuNode *head;   //define our two pointers for now, later on we will have to initialize new StuNode pointers when changing things up
    StuNode *tail;
public:
    StuList() //Constructor that makes the list empty
    {
        head = NULL;   //setting head value to NULL makes the entire list empty
    }

    bool isEmpty()  //checks whether the list is empty
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

    void addToHead(string name, int id) //adds a student to the beginning of the list
    {
        StuNode *new_node = new StuNode(name, id);  //instantiate a new object pointer named new_node pointing to StuNode class

        //set their data values respectively
        new_node->name = name;
        new_node->id = id;
        new_node->next = head;  //the node's next pointer points at the current head value, prepending the node
        head = new_node;  //update head as the new_node
    }

    void addToTail(string name, int id)  //adds a student at the end of the list
    {
        //instantiate another object instance of StuNode
        StuNode *new_node = new StuNode(name, id);

        //set their data values respectively
        new_node->name = name;
        new_node->id = id;
        new_node->next = NULL;  //since we are adding after the tail, the pointer points to NULL since it's the end of the linked list

        //if list is empty
        if (head == NULL) //meaning the list is empty
        {
            head = new_node;   //set head to the new_node value
        }
        else  //otherwise, if the list isn't empty
        {
            tail = head;   //set the tail pointer to the head value, whenever we traverse a linked list, we need to start at the head node
            //traverse the existing linked list
            while (tail->next != NULL)    //meaning while we haven't reached the end of the linked list
            {
                tail = tail->next;  //traverse to the next node
            }
            tail->next = new_node; //make sure once we have reached the end of the linked list, the present tail pointer points at the new node we have created
            tail = new_node;  //update our tail   -->line of code may require to be fixed
        }
    }

    void printList()   //prints all the information of the student in the list
    {
        tail = head;
        while (tail != NULL)  //while we haven't reached the end of the linked list
        {
            cout << "Name: " << tail->name << ", id:" << tail->id << endl;
            tail = tail->next;  //traverse to the next node
        }
    }

    //code works until here, the following implemenation is still being tested
    StuNode deleteFromHead() //deletes a student from the beginning of the list
    {
        StuNode *temp = head;  //create a temp node to hold the head value
        //first, check if the list is empty
        if (head == NULL)
            cout << "Empty List\n";
        else
        {
            head = temp->next;
        }
        return *temp;
        free(temp);

    }
    void EmptyList()
    {
        head = NULL;
    }

    StuNode deleteFromTail()   //this function works!
    {
        StuNode *temp;   //define another temp pointer
        //check if the list is empty
        if (head == NULL)
        {
            cout << "Empty List\n";   //there's nothing to delete
        }

        //if the list has only one node
        if (head->next == NULL)  //since there's only one node, the next pointer points to NULL
        {
            temp = head;  //store head in the temp value, we don't ever want to get rid of head node, then we lose the complete list
            head = NULL;  //set head value to NULL, since there will be no node left, emptying the list
            return *temp;
            free(temp);
        }

            //Traverse the list if there's more than one node
        else
        {
            StuNode *temp2;  //create another pointer node
            temp = head;  //the original temp node pointer will store the head node
            while (temp->next != NULL)  //we need to traverse the linked list until the tail node has been reached, once we have reached the tail node, we remove it
            {
                temp2 = temp;  //set temp2 to the current temp value, as in, we are storing a copy of the head value in temp2
                temp = temp->next;
            }
            temp2->next = NULL;   //as since temp and temp2 both point to head, as temp traverses the node, so does temp2, therefore temp == temp2, we use temp2 to set the pointer pointing to the current tail as null and delete temp
            return *temp;
            free(temp);
        }
    }

    void deleteNode(int id1)   //delete a student given the id
    {
        StuNode *temp;
        if (head == NULL)
        {
            cout << "Empty List\n";
            return;
        }
        if (head->next == NULL && head->id == id1)
        {
            temp = head;   //use the temp pointer to store the present head value
            head = NULL;  //if there's only a single node and the id of the single node matches the id in the parameter, delete that node
            free(temp);
        }

            //otherwise, traverse the list until the node to be deleted is discovered
        else
        {
            StuNode *temp;  //create another pointer node
            while (head->id != id1)  //traverse the node until we arrive at the node
            {
                head = head->next;   //there's 2 scenarios, the node given the id doesn't exist or we have arrived at the node we wish to remove
            }
            temp = head;  //store head in the temp pointer
            head = head->next;
            free(temp);
            return;
        }
    }

    //requires additional review

    bool search(int id) //searches for a student given the id
    {
        if (head == NULL) {
            return false;   //since the list is empty
        }
        else if (head->next == NULL && head->id == id)
        {
            return true;  //in the case that there's only one node and the node matches the id
        }
        else
        {
            StuNode *temp = head;
            while (temp->next != NULL) //meaning while we haven't reached the end of the list
            {
                if (temp->id == id) //the desired node has been found, loop stops
                {
                    return true;
                }
                else
                {
                    temp = temp->next;
                }
            }
            return false;  //in the case that the end of the linked list has been found and the node given id doesn't exist
        }
    }
    int ListLength()   //returns the number of students in the list
    {
        int count = 0;
        if (head == NULL) return 0; //list is empty
        else
        {
            StuNode *temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }


};
