/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * This Project from struktur data
 * This project use struktur data queues inmplements circular array.
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data / display
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author your name (you@domain.com)
 * - Nama : Basna yanti djakiman
 * - Nim : 20240140238
 * - Kelas : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */

class Queues 
{

private:
    int FRONT; /// private variable front for indicate first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for maximum capasity of element
    int queue_array[5]; /// private variable queue

public:
/**
 * @brief Construct a new Queues object
 * set default queues null
 * with front = -1 rear = -1
 */
   Queues()
    {
        FRONT = -1;
        REAR = -1;
    }  

    /**
     * @brief method for entering data into a queues
     * 
     */
    void insert()
    {
        int num; 
        cout << "Enter a number: ";
        cin >> num;  
        cout << endl; 

     // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        //Cek apakah antrian kosong
        if (FRONT == -1)
            REAR = 0;
        else 
        {
            if (REAR == max - 1)
                REAR = 0;
            else
            REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method for removing the front element from the queues.
     * 
     * 
     */
    void remove()
{
    //Cek apakah atrian kosong
    if (FRONT == -1)
    {
        cout << "Queue underflow\n";
        return;
    }
    cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

    //Cek jika antrian hanya memiliki satu max_elemen
    if (FRONT == REAR)
    {
            FRONT = -1;
            REAR = -1;
    }
    else
    {
        //jika elemn yang dihapus di berada di posisi terakhir array, kembali ke awal array
        if (FRONT == max -1)
            FRONT = 0;
        else
            FRONT = FRONT + 1;
    }
}

/**
 * @brief Displays all elements in the queue.
 * 
 */
void display()
    {
        int FRONT_position = FRONT; /// Stores the current front index of the queue
        int REAR_position = REAR; /// Stores the current rear index of the queue

        //Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";
        
        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "    ";
                FRONT_position++;
            }
            cout << endl;
        }
        else{
            //jika FRONT_position > RERA_position, iterasi dar FRONT hingga akhir arrray
            while (FRONT_position <= max -1)
            {
                cout << queue_array[FRONT_position] << "    ";
                FRONT_position++;   
            }

            FRONT_position = 0;

            //Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] <<"    ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief Entry point of the program.
 * 
 * @return int 
 */
int main()
{
    Queues q; /// Object of class Queues to manage queue operations
    char ch; /// Variable to store the user’s menu choice

    while (true)
    {
        try 
        {
            cout << "Menu " << endl;
            cout << "1. Implement insert operation " << endl;
            cout << "2. Implement deleted operation " << endl;
            cout << "3. Display values " << endl;
            cout << "4. Exit " << endl;
            cout << " Enter your choice (1-4) : ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;   
            }
               case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << " Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << " Check forbthe values entered. " << endl;
        }
    }
}