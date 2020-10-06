// Binary Heap.
// Min Heap implementation.
// To understand Heaps and other Data Structures see this video - [https://www.youtube.com/watch?v=RBSGKlAvoiM].
// This code is contributed by Shivam Malviya [https://github.com/TREXXX27] and Kushagra Kalash [https://github.com/TheSherlockHomie].

#include <iostream>
#include <vector>
#include "BHeap.h"

using namespace std;
using namespace ds;

int main()
{
    BinaryHeap<int> obj;

    while (1)
    {
        int c, ele;

        cout << "1. Insert Element" << "\n";
        cout << "2. Show top of heap" << "\n";
        cout << "3. Delete Element" << "\n";
        cout << "4. Display Heap" << "\n";
        cout << "5. Exit" << "\n";
        cout << "Enter your choice: ";

        cin >> c;

        try
        {
            switch (c)
            {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> ele;
                obj.Insert(ele);
                break;

            case 2:
                cout << "Top element is: " << obj.Poll() << "\n";
                break;

            case 3:
                cout << "Enter the element to be deleted: ";
                cin >> ele;
                obj.Delete(ele);
                obj.Display();
                break;

            case 4:
                obj.Display();
                break;

            case 5:
                exit(0);

            default:
                cout << "Enter Correct Choice... Try Again" << "\n";
            }
        }
        catch (string e)
        {
            cout << e << "\n";
        }
    }

    return 0;
}

