#include <bits/stdc++.h>
using namespace std;

class hashing
{
public:
    int size;
    int flag = 1;
    // int *HashTable = new int[size];
    vector<int> HashTable;
    hashing() // Default constructor
    {
        cout << "\nEnter size of hash table: ";
        cin >> size;
        HashTable.resize(size, -1);
    }
    
    void insertElementLinearProbing(long long int value) // function for linear probing
    {
        if (flag == 0)
        {
            cout << "Table full cannot add more!\n";
            return;
        }
        int hash_val = value % size; // hash value or key
        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] == value)
            {
                cout << "Element already exists!";
                return;
            }
        }
        if (HashTable[hash_val] == -1)
        {
            HashTable[hash_val] = value;
        }
        else
        {
            if (hash_val == size) // jumping from last element to first element
            {
                hash_val = 0;
            }

            while (HashTable[hash_val] != -1)
            {
                hash_val += 1;
                if (hash_val == size) // jumping from last element to first element
                {
                    hash_val = 0;
                }
            }
            HashTable[hash_val] = value;
        }
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] != -1)
                count += 1;
        }
        if (count == size)
        {
            cout << "\nTable full!";
            flag = 0;
        }
    }
    void insertElementLQuadraticProbing(long long int value) // function for quadratic probing
    {
        int hash_val = value % size;
        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] == value)
            {
                cout << "Element already exists!";
                return;
            }
        }
        if (HashTable[hash_val] == -1)
        {
            HashTable[hash_val] = value;
        }
        else
        {
            for (int j = 1; j < size; j++)
            {
                int hash_new = (hash_val + (j * j)) % size; // new key
                if (HashTable[hash_new] == -1)
                {
                    HashTable[hash_new] = value;
                    break;
                }
                else
                {
                    cout << "\nBlock not empty";
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\na[" << i << "] :" << HashTable[i];
        }
    }
    void SearchNumber(long long int temp)
    {
        int fnd = 0;
        for (int i = 0; i < size; i++)
        {
            if (HashTable[i] == temp)
            {
                cout << "\nNumber found!";
                fnd = 1;
                break;
            }
        }
        if (fnd == 0)
        {
            cout << "Number not found!";
        }
    }
};
int main()
{
    hashing h;
    long long int num, temp;
    int ch, ret;
    cout << "Telephone Directory";
    cout << "\n1) Insert using linear probing\n2) Insert using quadratic probing\n3) Display\n4) Search a number\n5) Exit ";
    do
    {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> num;
            h.insertElementLinearProbing(num);
            break;
        case 2:
            cout << "\nEnter phone no. to be inserted : ";
            cin >> num;
            h.insertElementLQuadraticProbing(num);
            break;
        case 3:
            cout << "Telephone Directory";
            h.display();
            break;
        case 4:
            cout << "\nEnter number to be searched: ";
            cin >> temp;
            h.SearchNumber(temp);
            break;
        case 5:
            cout << "\nExit!";
        default:
            break;
        }
    } while (ch != 5);
}
