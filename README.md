# DataStructureProject

- A project that was required to be completed for my Data Structure 212 course. The purpose of this project was to implement a scalable system for enrolling, removing and updating informations for student. Similar to the backend implementation of CUNYFirst system except at a much smaller scale with lower level of complexity, aimed toward challneging our understanding of linked list, array-based data structure as well as our knowledge and understanding of classes, functions and pointers.

- The skeleton for the linked list was provided to be the following:

<b>class StuList
  
{
  
 private:
  
 StuNode *head;
  
 StuNode *tail;
  
 public:
  
    StuList(); // constructor that makes the list empty
  
    bool isEmpty(); // checks whether the list is empty
  
    void addtoHead(string, int); // adds a student to the beginning of the list
  
    void addtoTail(string, int); // adds a student to the end of the list
  
    StuNode deleteFromHead(); // deletes a student from the beginning of the list
  
    StuNode deleteFromTail(); // deletes a student from the end of the list
  
    void deleteNode(int); // deletes a student given the id
  
    bool search(int); // searches for a student given the id
  
    void printList(); // prints all the information of students in the list
  
    int ListLength(); // returns number of students in the list
  
 }; </b>
 
 - A menu implementation feature asking the user to choose between 5 options, and upon user input is recieved, different task would execute. Such as enrolling a student from a section, withdrawing a student from a section, printing out the list of current students within a specified section, searching for a student given the unique id and exiting the program. The project was open-ended, we were free to choose the data structure implementation best suited for this prompt since it is something that could also have been implemented using a stack or a queue, we weren't limited to simply linked list. 
 
 -  The following image shows how an array of linked list works to keep track of the section and the student within that section compring of linked list of nodes.
 
 ![Array Of Linked List Visual](https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/Adjacencylist_array_of_linkedlists_undirectedgraph.svg/1280px-Adjacencylist_array_of_linkedlists_undirectedgraph.svg.png#light-mode)
 
Reference Used:
//https://www.codewhoop.com/linked-list/delete-node-from-start-and-end.html
  
  


