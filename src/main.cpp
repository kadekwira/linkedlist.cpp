/*              PROGRAM ANTRIAN ATM MENGGUNAKAN LINKED LIST

                NAMA : KADEK WIRA ADHI KUSUMA PRATAMA
                NIM:210040131
                GITHUB: kadekwira

                */

#include <iostream>
#include <conio.h>

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
        cout << "Antrian Penuh !!" << endl;

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
// dequeue linked List
void dequeueLinkedList()
{
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

// clear linked List
void clearLinkedList()
{
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !" << endl;
    }
    else
    {
        cur = head;
        while (cur != NULL)
        {
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
}

// print linked list
void printLinkedList()
{
    cout << "Daftar Antrian : " << endl;
    if (isEmptyLinkedList())
    {

        cout << "Data Antrian Kosong !" << endl;
    }
    else
    {
        cout << " Jumlah Antrian : " << countLinkedList() << endl;
        cur = head;
        int no = 1;
        while (no <= maksAntrianLinkedList)
        {
            if (cur != NULL)
            {
                cout << no << " . " << cur->nama << endl;
                cur = cur->next;
            }
            else
            {
                cout << no << " . "
                     << "[kosong]" << endl;
            }
            no++;
        }
    }
    cout << endl;
}

int main()
{
    string nama;
    int pilihan;
    do
    {

        system("cls");
        cout << "======================================" << endl;
        cout << "        PROGRAM QUEUE LINKED LIST     " << endl;
        cout << "======================================" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.print" << endl;
        cout << "4.Clear" << endl;
        cout << "5.Keluar" << endl;
        cout << "================" << endl;
        cout << "pilihan menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            cout << " Masukan Nama : ";
            cin >> nama;
            enqueueLinkedList(nama);
            break;
        }
        case 2:
        {
            dequeueLinkedList();
            break;
        }
        case 3:
        {

            printLinkedList();
            break;
        }
        case 4:
        {
            clearLinkedList();
            break;
        }
        case 5:
        {
            cout << endl
                 << " Terima kasih telah menggunakan sistem ini ";
            cout << endl
                 << "Tekan Enter untuk keluar";
            break;
        }
        default:
        {
            cout << "tidak ada dalam pilihan !!" << endl;
        }
        }
        getch();
    } while (pilihan != 5);
    cin.get();
    return 0;
}
