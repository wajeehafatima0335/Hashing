#include<iostream>
using namespace std;

#define SIZE 7

class HashTable{
	int table [SIZE];
	
public:
	HashTable(){
		for(int i= 0; i< SIZE; i++)
			table[i] = -1;
		}
		//insert func
		void insert(int key){
			int hash = key % SIZE;
			int index = hash;
			int  i = 1;
			
			while(table[index] != -1 && table[index] != -2){
				index = (hash + i*i) % SIZE;
				i++;
			
			if(i >= SIZE){
				cout<<"the hash is full!"<<endl;
				return;
			}
		}
		table[index] = key;
		cout<<"inserted at index " << index <<endl;
	}
	//search func..
	void search(int key){
		int hash = key % SIZE;
			int index = hash;
			int  i = 1;
	
	
		while(table[index] != -1){
			
			if(table[index] == key) {
			cout<< " key found at index "<< index << endl; 
			return;
		}
		index = (hash + i*i) % SIZE;
		i++;
		
		if(i >= SIZE)
		break;
    	}
	cout<<"key not found\n";
    } 
    //delete func..
    void delet(int key){
    	int hash = key % SIZE;
			int index = hash;
			int  i = 1;
    	
    	while(table[index] != -1){
    		
    		if(table[index] == key){
    			table[index] = -2;    //mark as deletd
    			cout<<"key delete at index "<< index << endl;
    			return;
			}
			index = (hash + i*i) % SIZE;
			i++;
			
			if(i >= SIZE)
			break;
		}
		cout<<"key nor found\n"<<endl;
	}
	//display func..
	void display(){
		for(int i = 0; i < SIZE; i++){
			if(table[i] == -1)
			cout<< i << "-> empty\n ";
			else if(table[i] == -2)
			cout<< i << " -> deleted\n";
			else
			cout<< i << "-> "<< table[i] <<endl;
		}
	}
  
};

int main(){
	HashTable h;
	int choice, key;
	
	 while(true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter key: ";
            cin >> key;
            h.insert(key);
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;
            h.search(key);
            break;

        case 3:
            cout << "Enter key: ";
            cin >> key;
            h.delet(key);
            break;

        case 4:
            h.display();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
};
