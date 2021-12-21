#include <iostream>

using namespace std;

// struct Linked List
struct antrianLinkedList
{
    string nama;

    // pointer next(selanjutnya)
    antrianLinkedList *next;
};

int maksAntrianLinkedList = 5;

antrianLinkedList *head, *tail, *cur, *del, *newNode;

int countLinkedList()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int jum = 0;
        cur = head;
        while (cur != NULL)
        {
            cur = cur->next;
            jum++;
        }
        return jum;
    }
}

// is full linked list
bool isFullLinkedList()
{
    if (countLinkedList() == maksAntrianLinkedList)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isEmpty linked list
bool isEmptyLinkedList()
{
    if (countLinkedList() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// enqueue (penambahan data) Linked List
void enqueueLinkedList(string nama)
{
    if (isFullLinkedList())
        cout << "Antrian Penuh !!"<<endl;

    else
    {
        if (isEmptyLinkedList())
        {
            head = new antrianLinkedList();
            head->nama = nama;
           
            head->next = NULL;
            tail = head;
        }
        else
        {
            newNode = new antrianLinkedList();
            newNode->nama = nama;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}
//dequeue linked List
void dequeueLinkedList()
{
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !"<< endl;
    }else{
        del=head;
        head= head->next;
        del->next= NULL;
        delete del;
    }
}

//clear linked List
void clearLinkedList()
{
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !"<< endl;
    }else{
        cur=head;
        while(cur != NULL)
        {
            del=cur;
            cur=cur->next;
            del->next= NULL;
            delete del;
        }
        head=NULL;
        tail=NULL;
    }
}

// print linked list
void printLinkedList()
{
    cout << "Daftar Antrian : " << endl;
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !"<< endl;
    }
    else
    {
        cout<<" Jumlah Antrian : "<<countLinkedList()<<endl;
        cur = head;
        int no=1;
        while ( no <= maksAntrianLinkedList)
        {
            if(cur != NULL){
                cout<<no<<" . "<<cur->nama<<endl; 
                cur =cur->next;
            }
            else{
                cout<<no<<" . "<<"[kosong]"<<endl;
    
            }
            no++;
        }
    }
    cout<<endl;
}



int main()
{       antrianLinkedList;
        int pilihan;
        char ulang;

        do{
            cout<<"1. Enqueue Linked List "<<endl;
            cout<<"2.Dequeue Linked List "<<endl;
            cout<<"3.Print Linked List "<<endl;
            cout<<"4.Clear Linked List"<<endl;
        }
        


        cout<<"apakah anda inggin mengulang ? [y/t]: ";
        cin>>ulang;
        while(ulang != 't');
        cout<<"makasi"<<endl;

    cin.get();
    return 0;
}