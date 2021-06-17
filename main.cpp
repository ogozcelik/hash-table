#include <fstream>
#include "hash.h"

int main()
{
  int operation; //operation number
  int sizeHash;  //hash table size
  string funcHash; //function name

  cout<< "*****MENU*****"<<endl;
  cout<< "1. Initialize Hash Table"<<endl;
  cout<< "2. Load T.C. ID Numbers from file"<<endl;
  cout<< "3. Add new T.C. ID Number"<<endl;
  cout<< "4. Delete a T.C. ID Number"<<endl;
  cout<< "5. Search for a T.C. ID Number"<<endl;
  cout<< "6. Print out Hash Table"<<endl;
  cout<< "Please choose the first operation: ";
  cin>> operation;

  if (operation == 1) {
    cout<<endl;
    cout<<"Enter the size of Hash table: ";
    cin>>sizeHash;
    cout<<endl;
    cout<<"Enter the hash function name 'Folding', 'MiddleSquaring' or 'Truncation': ";
    cin>>funcHash;
    Hash h(sizeHash);

    while(1){
    cout<<endl;
    cout<< "Please choose an operation: ";
    cin>>operation;

    if (funcHash == "Folding") {

        if (operation == 2){
            long long int a[200];
            ifstream file("hash_table_init.txt");
            int number = 0;
            long long int x;

            while (number < 200 && file >> x)
                a[number++] = x;

            for (int i = 0; i < 200; i++){
                h.insertKey(a[i], "Folding");}
        }

        else if (operation == 3){
            long long int value;
            cout<<endl;
            cout<< "Please enter new value to add: ";
            cin>> value;

            if(!h.searchKey(value, "Folding")){
                h.insertKey(value, "Folding");
                cout<< "T.C. ID : "<<value<<" is added!" <<endl;
            }
            else {
                cout<<"The T.C. ID is already in the table!"<<endl;
            }
        }

        else if (operation == 4){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to delete: ";
            cin>> value;
            h.deleteKey(value, "Folding");
        }

        else if (operation == 5){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to search: ";
            cin>> value;
            if(h.searchKey(value, "Folding")){
                cout<< "T.C. ID : "<<value<<" is found!" <<endl;
            }
            else{
                cout<<"T.C. ID : "<<value<<" is not found!" <<endl;
            }
        }

        else if (operation == 6){
            h.displayHash();
        }

    }

    else if (funcHash == "MiddleSquaring"){

        if (operation == 2){
            long long int a[200];
            ifstream file("hash_table_init.txt");
            int number = 0;
            long long int x;

            while (number < 200 && file >> x)
                a[number++] = x;

            for (int i = 0; i < 200; i++)
                h.insertKey(a[i], "MiddleSquaring");
        }

        else if (operation == 3){
            long long int value;
            cout<<endl;
            cout<< "Please enter new value: ";
            cin>> value;

            if(!h.searchKey(value, "MiddleSquaring")){
                h.insertKey(value, "MiddleSquaring");
                cout<< "T.C. ID : "<<value<<" is added!" <<endl;
            }
            else {
                cout<<"The T.C. ID is already in the table!"<<endl;
            }
        }

        else if (operation == 4){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to delete: ";
            cin>> value;
            h.deleteKey(value, "MiddleSquaring");
        }

        else if (operation == 5){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to search: ";
            cin>> value;
            if(h.searchKey(value, "MiddleSquaring")){
                cout<< "T.C. ID : "<<value<<" is found!" <<endl;
            }
            else{
                cout<<"T.C. ID : "<<value<<" is not found!" <<endl;
            }
        }

        else if (operation == 6){
            h.displayHash();
        }
    }

    else if (funcHash == "Truncation"){

        if (operation == 2){
            long long int a[200];
            ifstream file("hash_table_init.txt");
            int number = 0;
            long long int x;

            while (number < 200 && file >> x)
                a[number++] = x;

            for (int i = 0; i < 200; i++)
                h.insertKey(a[i], "Truncation");
        }

        else if (operation == 3){
            long long int value;
            cout<<endl;
            cout<< "Please enter new value: ";
            cin>> value;

            if(!h.searchKey(value, "Truncation")){
                h.insertKey(value, "Truncation");
                cout<< "T.C. ID : "<<value<<" is added!" <<endl;
            }
            else {
                cout<<"The T.C. ID is already in the table!"<<endl;
            }
        }

        else if (operation == 4){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to delete: ";
            cin>> value;
            h.deleteKey(value, "Truncation");
        }

        else if (operation == 5){
            long long int value;
            cout<<endl;
            cout<< "Please enter a value to search: ";
            cin>> value;
            if(h.searchKey(value, "Truncation")){
                cout<< "T.C. ID : "<<value<<" is found!" <<endl;
            }
            else{
                cout<<"T.C. ID : "<<value<<" is not found!" <<endl;
            }
        }

        else if (operation == 6){
            h.displayHash();
        }
    }
    }
  }

  else
    cout<<"Please enter 1!"<<endl;

  return 0;
}
