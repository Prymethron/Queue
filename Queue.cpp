#include <iostream>
using namespace std;
#define size 100

struct Queue
{
    int front=0, back=0, count=0;
    int queue_list[size];

    void enqueue(int x)
    {
        if(count==100)
        {
            cout<< "There's no any space to insert an element.\n";
        }
        else
        {            
            queue_list[count] = x;
            if(count==0)
            front = queue_list[count];
            back = queue_list[count];
            count++;
            cout << x << " is queued.\n";
        }
    }  

    void dequeue(){
        if(count==0)
        {
            cout<< "There's no any element to delete.\n";
        }
        else
        {
            front = queue_list[1];
            for(int i=0; i<count-1;i++){
                queue_list[i] = queue_list[i+1];
            }
            count--;
            cout<< "The queue is dequeued.\n";
            if (count==0)
            {
                back=0;
                front=0;
            }
        }
    }  

    void printQueue()
    {
        if(count==0)
        {
            cout << "The queue is empty.\n";
        }
        else
        {
            for(int i=count-1;i>=0;i--)
            {
                cout << queue_list[i] << " ";
            }
            cout << "\n";
        }
    }

    void printFront(){
        cout << front << " is the front element.\n";
    }

    void printBack(){
        cout << back << " is the back element.\n";
    }
};

void invalidInput(){
    cout<< "Invalid input.\n";
    cin.clear();
    cin.ignore(10000,'\n');
}

int main()
{
    Queue queue;
    int selection=0, x;
    while(-1)
    {
        cout<< "Select a function to do.\n1-Enqueue\n2-Dequeue\n3-Print Queue\n4-Print Front\n5-Print Back\n6-Exit\n";
        if(!(cin >> selection))
        invalidInput();
        else
            {switch(selection){
            case 1:
            cout << "Enter a value to enqueue.\n";
            if(!(cin>>x))
            {
                invalidInput();
            }
            else
            {
                queue.enqueue(x);
            }
            break;

            case 2:
            queue.dequeue();
            break;

            case 3:
            queue.printQueue();
            break;

            case 4:
            queue.printFront();
            break;

            case 5:
            queue.printBack();
            break;

            case 6:
            exit(0);
            break;

            default:
            cout<< "Invalid input.\n";
            break;
            }}
    }
    
}