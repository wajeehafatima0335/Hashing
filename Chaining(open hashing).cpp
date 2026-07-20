#include<iostream>
#include<stdlib.h>
using namespace std;

# define SIZE 7

struct Node{
	int data;
	Node* next;
};
Node* table[SIZE];  // hash table of pointers linked to the ll

//intializing the hash table
void initi_HashTable(){
	for(int i=0; i<SIZE; i++)
	table[i] = NULL;
}
int  hashFunction(int key){
	return key % SIZE;
}

void insert(int key){
	
	int index = hashFunction(key);     
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;
    
     // If list at index is empty, make newNode the head
    if(table[index] == NULL){
    	table[index] = newNode;
    }else{
    	Node* curr = table[index];  // otherwise, add node at the end 0f LL
    	while(curr->next != NULL){
    		curr= curr->next;
		}
		curr->next = newNode;
	}
	 cout << "Inserted " << key << " at index " << index << endl;
}
void search(int key){
	int index = hashFunction(key);     
    Node* curr = table[index];
    int pos = 1;
    
    while(curr != NULL){
    	if(curr->data == key){
    	 cout << "Key " << key << " found at index " << index 
                 << ", position in chain: " << pos << endl;
            return;
        }
        curr = curr->next;
	    pos++;
	}
	 cout << "Key " << key << " not found in hash table." << endl;	
}
void delet(int key){
	int index = hashFunction(key);
	Node* curr = table[index];
	Node* prev = NULL;        //node before curr
	 
	while(curr != NULL){
	 	if(curr->data == key){  // node to delete (founded)
	 	if(prev == NULL){
	 		table[index] = curr->next;   //deleting the head node, so curr->next = head ban jae ga
		}else{
		 	prev->next = curr->next;
		}
            free(curr);
            cout << "Key " << key << " deleted from index " << index << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Key " << key << " not found in hash table." << endl;
}
// Display the hash table
void display() {
    cout << "\nHash Table Contents:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        Node* curr = table[i];
        if (!curr) {
            cout << "NULL";
        }
        while (curr != NULL) {
            cout << curr->data;
            if (curr->next != NULL) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
}

// Main function
int main() {
    initi_HashTable();    // initialize table

    int choice, key;

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                delet(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}


    








