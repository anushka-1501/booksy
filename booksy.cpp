#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

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
        cout << "Hello! Enter details in the following manner. Caution- Do not add spaces in between words of books or authors. Example- Harry Potter will be written s HarryPotter or harrypotter" << endl;
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
            cout << "Deleted!" << endl;
            fin.close();
            fout.close();
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
                cout << "\n" << bname << " \t\t" << aname << "\t\t" << price << "\t\t" << copies;

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
    /*void update(char* t){
        fstream file;

        // Open the file
        file.open("books.txt",
            ios::in | ios::out | ios::ate);
        file.seekg(0);
        file.read((char*)this, sizeof(*this));

        // Read the file
        while (!file.eof()) {
            if (!strcmp(t, bname)) {
                cout << "Enter book name, author name, price and number of copies:  ";
                cin >> bname;
                cin >> aname;
                cin >> price;
                cin >> copies;

                file.seekp(file.tellp() - sizeof(*this));
                file.write((char*)this, sizeof(*this));
            }
            file.read((char*)this, sizeof(*this));
        }

        // Close the file
        file.close();
    }*/
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
        cout << "Enter your name: ";
        cin >> cname;
        cout << "Enter MRP as price please." << endl;
        n.addbooks();
        cout << "Thank you for donating " << cname << ". You are taking a very good step." << endl;
    }
    void buybook() {
        Manage n;
        char title[1000];
        cout << "\nEnter title of "
            << "book you want to buy : ";
        cin.ignore();
        cin.getline(title, 19);
        //n.update(title);
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
    int n, x = 0;
    char title[1000];
    Manage m;
    Customer c;
    do {
        cout << "\nAre you a customer or the management. Press 1 for customer and 2 for management. Press 3 to exit" << endl;
        cin >> n;
        switch (n) {
        case 1: cout << "Enter number according to choice!" << endl;
            cout << "1)Buy a book\n2)Donate a book\n3)Search a book by name\n4)Search a book by author name\n5)Exit\n";
            cin >> x;
            switch (x) {
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
        case 2: cout << "Enter number according to choice\n1)Add new books\n2)Update book details\n3)Delete a book\n4)Display details of a book\n5)Display all books\n6)Exit" << endl;
            cin >> x;
            switch (x) {
            case 1:m.addbooks();
                break;
            case 2:cout << "\nEnter book title "
                << "to update record : ";
                cin.ignore();
                cin.getline(title, 19);
                //m.update(title);
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
            case 6:exit(0);
                break;
            }
            break;
        case 3:exit(0);
            break;
        }
    } while (n != 3);
}
