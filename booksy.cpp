#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Password {
private:
    string pw = "123456", username = "booksy_anu", cuser, cpw;
    int recovery = 2;
public:
    int login() {
        string passw, uname;
        int tries = 0, x;
        do {
            cout << "Enter username: ";
            cin >> uname;
            cout << "\nEnter password: ";
            cin >> passw;
            if (passw == pw && uname == username) {
                x = 1;
                break;
            }
            else if (passw != pw || uname != username) {
                cout << "password or username wrong" << endl;
                tries++;
                x = 0;
            }
        } while (tries != 3);
        if (x == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void recover() {
        int year = 0, x = 0;
        cout << "You only get one chance. 1+1 is?" << endl;
        cin >> year;
        if (year == recovery) {
            cout << "Your username is " << username << " and your password is " << pw << endl;
        }
        else {
            cout << "1+1 is 2 you idiot!" << endl;
        }
    }
};

class Manage {
private:
    string pw = "123456";
    int recoverynumber = 2;
    char bname[1000], aname[1000];
    int price, copies;
public:
    Manage() {
        price = 0;
        strcpy_s(bname, "no title");
        strcpy_s(aname, "no title");
        copies = 0;
    }
    void printdata() {
        cout << "Hello! Details are-" << endl;
        cout << "BOOKNAME: " << bname << endl;
        cout << "AUTHORNAME: " << aname << endl;
        cout << "PRICE: " << price << endl;
        cout << "NUMBER OF COPIES: " << copies << endl;
    }
    void addbooks() {
        cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
        cout << "BOOKNAME: ";
        cin >> bname;
        cout << "AUTHORNAME: ";
        cin >> aname;
        cout << "PRICE: ";
        cin >> price;
        cout << "NUMBER OF COPIES: ";
        cin >> copies;
        ofstream fout;
        fout.open("books.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "Books added!" << endl;
    }
    void deletebname(char* t) {
        ifstream fin;
        ofstream fout;
        fin.open("books.txt",
            ios::app);
        if (!fin)
            cout << "\n File not found";
        else {
            fout.open("tempfile.txt",
                ios::app);
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (strcmp(bname, t))
                    fout.write((char*)this, sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            cout << "deleted\n";
            remove("books.txt");
            rename("tempfile.txt", "books.txt");
        }
    }
    void inventory() {
        ifstream fin;

        // Open function open file named
        fin.open("books.txt", ios::in);
        if (!fin)
        {
            cout << "File not found";
        }
        else {
            cout << "BOOKNAME\t\tAUTHORNAME\t\tPRICE\t\tCOPIES" << endl;
            fin.read((char*)this, sizeof(*this));

            // Until end of file is
            // not reached
            while (!fin.eof()) {
                cout << "\n" << bname << "\t\t" << aname << "\t\t" << price << "\t\t" << copies << endl;

                // read is object of ifstream
                // class which is used for
                // read data of file
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
    void search(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\t" << price << "\t" << copies;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "No record found";
            fin.close();
        }
    }
    void update(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\t" << price << "\t" << copies;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "No record found";
            fin.close();
        }
        cout << "\n";
        ofstream fout;
        fin.open("books.txt",
            ios::app);
        if (!fin)
            cout << "\n File not found";
        else {
            fout.open("tempfile.txt",
                ios::app);
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (strcmp(bname, t))
                    fout.write((char*)this, sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("books.txt");
            rename("tempfile.txt", "books.txt");
        }
        cout << "\n";
        cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
        cout << "BOOKNAME: ";
        cin >> bname;
        cout << "AUTHORNAME: ";
        cin >> aname;
        cout << "PRICE: ";
        cin >> price;
        cout << "NUMBER OF COPIES: ";
        cin >> copies;
        fout.open("books.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
        cout << "\nRecord updated!\n";
    }
    void searcha(char* t) {
        int counter = 0;
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "File not found";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, aname)) {
                    cout << "\n"
                        << bname
                        << "\t" << aname << "\t" << price << "\t" << copies;
                    counter++;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0)
                cout << "No record found";
            fin.close();
        }
    }
   void donation() {
        char t[1000];
        cout << "\nEnter book title:\n";
        cin >> t;
        int counter = 0,c,pr;
        char b[1000], a[1000];
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "\nThere is some issue with the program. Get help from the Manager please!\n";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    c = copies + 1;
                    pr = price;
                    strcpy_s(b, bname);
                    strcpy_s(a, aname);
                    counter++;
                    deletebname(t);
                    ofstream fout;
                    fout.open("books.txt", ios::app | ios::binary);
                    fout << b << setw(30) << a << setw(30) << pr << setw(30) << c;
                    fout.close();
                    cout << "\nThank you for donating!\n";

                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0) {
                cout << "Hello! Enter details in the following manner.\nExample- Harry Potter will be written as harrypotter." << endl;
                cout << "BOOKNAME: ";
                cin >> bname;
                cout << "AUTHORNAME: ";
                cin >> aname;
                cout << "PRICE: ";
                cin >> price;
                cout << "NUMBER OF COPIES: ";
                cin >> copies;
                ofstream fout;
                fout.open("books.txt", ios::app | ios::binary);
                fout.write((char*)this, sizeof(*this));
                fout.close();
                cout << "\nThank you for donating!\n";
            }
                
            fin.close();
        }        

    }
    void buy() {
        char t[1000];
        cout << "\nEnter book title:\n";
        cin >> t;
        int counter = 0, c, pr,flag;
        char b[1000], a[1000];
        ifstream fin;
        fin.open("books.txt", ios::in);

        // If file is not found
        if (!fin)
            cout << "\nThere is some issue with the program. Get help from the Manager please!\n";
        else {
            fin.read((char*)this, sizeof(*this));

            // Until end of file is not reached
            while (!fin.eof()) {
                if (!strcmp(t, bname)) {
                    if (copies>1) {
                        c = copies - 1;
                        pr = price;
                        strcpy_s(b, bname);
                        strcpy_s(a,aname);
                        counter++;
                        deletebname(t);
                        ofstream fout;
                        fout.open("books.txt", ios::app | ios::binary);
                        fout << b << setw(30) << a << setw(30) << pr << setw(30) << c;
                        fout.close();
                    }
                    else if (copies == 1) {
                        deletebname(t);
                    }
                    else {
                        cout << "\nSOLD OUT\n";
                    }

                }
                fin.read((char*)this, sizeof(*this));
            }
            if (counter == 0) {
                cout << "\nNot Available\n";
            }

            fin.close();
        }
    }
};
class Customer : public Manage {
private:
    char cname[100];
public:
    Customer() {
        strcpy_s(cname, "no title");
    }
    void donatebook() {
        Manage n;
        char title[1000];
        cout << "Enter your name: ";
        cin >> cname;
        cout << "Enter price as MRP" << endl;
        n.donation();
        cout << "Thank you for donating " << cname << ". You are taking a very good step." << endl;
    }
    void buybook() {
        Manage n;
        char title[1000];
        cout << "\nEnter title of "
            << "book you want to buy : ";
        cin.ignore();
        cin.getline(title, 19);
        n.buy();
    }
    void searchbyname() {
        Manage n;
        char title[1000];
        cout << "\nEnter title of "
            << "book to search : ";
        cin.ignore();
        cin.getline(title, 19);
        n.search(title);
    }
    void searchbyauthor() {
        Manage n;
        char title[1000];
        cout << "\nEnter name of "
            << "author to search : ";
        cin.ignore();
        cin.getline(title, 19);
        n.searcha(title);
    }
};


void welcome() {
    cout << "WELCOME TO BOOKSY!" << endl;
}
int main()
{
    welcome();
    int n, y = 0;
    Password p;
    int flag = 0;
    char title[1000];
    Manage m;
    Customer c;
    do {
        cout << "\nAre you a customer or the management. Press 1 for customer and 2 for management. Press 3 to exit" << endl;
        cin >> n;
        switch (n) {
        case 1: cout << "Enter number according to choice!" << endl;
            cout << "1)Buy a book\n2)Donate a book\n3)Search a book by name\n4)Search a book by author name\n5)Exit\n";
            cin >> y;
            switch (y) {
            case 1:c.buybook();
                break;
            case 2:c.donatebook();
                break;
            case 3:c.searchbyname();
                break;
            case 4:c.searchbyauthor();
                break;
            case 5:exit(0);
                break;
            }

            break;
        case 2: flag = p.login();
            do {
                if (flag == 1) {
                    cout << "\nEnter number according to choice\n1)Add new books\n2)Update book details\n3)Delete a book\n4)Display details of a book\n5)Display all books\n6)Exit" << endl;
                    cin >> y;
                    switch (y) {
                    case 1:m.addbooks();
                        break;
                    case 2:cout << "\nEnter book title "
                        << "to update record : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.update(title);
                        break;
                    case 3:cout << "\nEnter book title "
                        << "to delete record : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.deletebname(title);
                        break;
                    case 4:cout << "\nEnter title of "
                        << "book to search : ";
                        cin.ignore();
                        cin.getline(title, 19);
                        m.search(title);
                        break;
                    case 5:m.inventory();
                        break;
                    }
                }
                else {
                    cout << "wrong!!!! try again" << endl;
                    p.recover();
                }
            } while (y != 6);
            break;
        case 3:exit(0);
            break;
        }
    } while (n != 3);
}
