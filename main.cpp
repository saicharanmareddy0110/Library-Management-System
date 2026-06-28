#include <iostream>
#include <vector>
#include <string>

using namespace std;

//=========================
// Book Class
//=========================

class Book
{
public:
    int id;
    string title;
    string author;
    string publisher;
    int year;
    bool available;

    Book()
    {
        id = 0;
        year = 0;
        available = true;
    }

    void input()
    {
        cout << "\nEnter Book ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title : ";
        getline(cin, title);

        cout << "Enter Author : ";
        getline(cin, author);

        cout << "Enter Publisher : ";
        getline(cin, publisher);

        cout << "Enter Year : ";
        cin >> year;

        available = true;
    }

    void display() const
    {
        cout << "\n--------------------------------";
        cout << "\nBook ID      : " << id;
        cout << "\nTitle        : " << title;
        cout << "\nAuthor       : " << author;
        cout << "\nPublisher    : " << publisher;
        cout << "\nYear         : " << year;
        cout << "\nStatus       : ";

        if (available)
            cout << "Available";
        else
            cout << "Issued";

        cout << "\n--------------------------------\n";
    }
};

//=========================
// Member Class
//=========================

class Member
{
public:
    int id;
    string name;
    string phone;
    string email;

    void input()
    {
        cout << "\nEnter Member ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name : ";
        getline(cin, name);

        cout << "Enter Phone : ";
        getline(cin, phone);

        cout << "Enter Email : ";
        getline(cin, email);
    }

    void display() const
    {
        cout << "\n--------------------------------";
        cout << "\nMember ID : " << id;
        cout << "\nName      : " << name;
        cout << "\nPhone     : " << phone;
        cout << "\nEmail     : " << email;
        cout << "\n--------------------------------\n";
    }
};

//=========================
// Borrow Record
//=========================

class BorrowRecord
{
public:
    int bookID;
    int memberID;
    string issueDate;
    string returnDate;
    bool returned;

    BorrowRecord()
    {
        returned = false;
    }

    void display() const
    {
        cout << "\n--------------------------------";
        cout << "\nBook ID      : " << bookID;
        cout << "\nMember ID    : " << memberID;
        cout << "\nIssue Date   : " << issueDate;

        if (returned)
            cout << "\nReturn Date  : " << returnDate;
        else
            cout << "\nReturn Date  : Not Returned";

        cout << "\nStatus       : ";

        if (returned)
            cout << "Returned";
        else
            cout << "Issued";

        cout << "\n--------------------------------\n";
    }
};

//=========================
// Global Vectors
//=========================

vector<Book> books;
vector<Member> members;
vector<BorrowRecord> records;

//=========================
// Helper Functions
//=========================

int findBook(int id)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
            return i;
    }

    return -1;
}

int findMember(int id)
{
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].id == id)
            return i;
    }

    return -1;
}

int findBorrowRecord(int bookID)
{
    for (int i = 0; i < records.size(); i++)
    {
        if (records[i].bookID == bookID && !records[i].returned)
            return i;
    }

    return -1;
}
//=========================
// Book Management Functions
//=========================

void addBook()
{
    Book b;
    b.input();

    if (findBook(b.id) != -1)
    {
        cout << "\nBook ID already exists!\n";
        return;
    }

    books.push_back(b);

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n";

    for (const Book &b : books)
    {
        b.display();
    }
}

void searchBook()
{
    if (books.empty())
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    int choice;

    cout << "\nSearch Book By";
    cout << "\n1. Book ID";
    cout << "\n2. Title";
    cout << "\n3. Author";
    cout << "\nEnter Choice : ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        int id;
        cout << "Enter Book ID : ";
        cin >> id;

        int index = findBook(id);

        if (index == -1)
            cout << "\nBook Not Found.\n";
        else
            books[index].display();

        break;
    }

    case 2:
    {
        string title;
        bool found = false;

        cout << "Enter Title : ";
        getline(cin, title);

        for (const Book &b : books)
        {
            if (b.title == title)
            {
                b.display();
                found = true;
            }
        }

        if (!found)
            cout << "\nBook Not Found.\n";

        break;
    }

    case 3:
    {
        string author;
        bool found = false;

        cout << "Enter Author : ";
        getline(cin, author);

        for (const Book &b : books)
        {
            if (b.author == author)
            {
                b.display();
                found = true;
            }
        }

        if (!found)
            cout << "\nBook Not Found.\n";

        break;
    }

    default:
        cout << "\nInvalid Choice.\n";
    }
}

void updateBook()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    int index = findBook(id);

    if (index == -1)
    {
        cout << "\nBook Not Found.\n";
        return;
    }

    cin.ignore();

    cout << "Enter New Title : ";
    getline(cin, books[index].title);

    cout << "Enter New Author : ";
    getline(cin, books[index].author);

    cout << "Enter New Publisher : ";
    getline(cin, books[index].publisher);

    cout << "Enter New Year : ";
    cin >> books[index].year;

    cout << "\nBook Updated Successfully!\n";
}

void deleteBook()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    int index = findBook(id);

    if (index == -1)
    {
        cout << "\nBook Not Found.\n";
        return;
    }

    if (!books[index].available)
    {
        cout << "\nBook is currently issued and cannot be deleted.\n";
        return;
    }

    books.erase(books.begin() + index);

    cout << "\nBook Deleted Successfully!\n";
}
//=========================
// Member Management Functions
//=========================

void addMember()
{
    Member m;
    m.input();

    if (findMember(m.id) != -1)
    {
        cout << "\nMember ID already exists!\n";
        return;
    }

    members.push_back(m);

    cout << "\nMember Added Successfully!\n";
}

void displayMembers()
{
    if (members.empty())
    {
        cout << "\nNo Members Available.\n";
        return;
    }

    cout << "\n========== MEMBER LIST ==========\n";

    for (const Member &m : members)
    {
        m.display();
    }
}

void searchMember()
{
    if (members.empty())
    {
        cout << "\nNo Members Available.\n";
        return;
    }

    int choice;

    cout << "\nSearch Member By";
    cout << "\n1. Member ID";
    cout << "\n2. Member Name";
    cout << "\nEnter Choice : ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        int id;

        cout << "Enter Member ID : ";
        cin >> id;

        int index = findMember(id);

        if (index == -1)
            cout << "\nMember Not Found.\n";
        else
            members[index].display();

        break;
    }

    case 2:
    {
        string name;
        bool found = false;

        cout << "Enter Member Name : ";
        getline(cin, name);

        for (const Member &m : members)
        {
            if (m.name == name)
            {
                m.display();
                found = true;
            }
        }

        if (!found)
            cout << "\nMember Not Found.\n";

        break;
    }

    default:
        cout << "\nInvalid Choice.\n";
    }
}

void updateMember()
{
    int id;

    cout << "\nEnter Member ID : ";
    cin >> id;

    int index = findMember(id);

    if (index == -1)
    {
        cout << "\nMember Not Found.\n";
        return;
    }

    cin.ignore();

    cout << "Enter New Name : ";
    getline(cin, members[index].name);

    cout << "Enter New Phone : ";
    getline(cin, members[index].phone);

    cout << "Enter New Email : ";
    getline(cin, members[index].email);

    cout << "\nMember Updated Successfully!\n";
}

void deleteMember()
{
    int id;

    cout << "\nEnter Member ID : ";
    cin >> id;

    int index = findMember(id);

    if (index == -1)
    {
        cout << "\nMember Not Found.\n";
        return;
    }

    // Check if the member has any book currently issued
    for (const BorrowRecord &record : records)
    {
        if (record.memberID == id && !record.returned)
        {
            cout << "\nMember has an issued book.";
            cout << "\nReturn the book before deleting the member.\n";
            return;
        }
    }

    members.erase(members.begin() + index);

    cout << "\nMember Deleted Successfully!\n";
}
//=========================
// Borrow Record Functions
//=========================

void issueBook()
{
    int memberID, bookID;
    BorrowRecord record;

    cout << "\nEnter Member ID : ";
    cin >> memberID;

    int memberIndex = findMember(memberID);

    if (memberIndex == -1)
    {
        cout << "\nMember Not Found!\n";
        return;
    }

    cout << "Enter Book ID : ";
    cin >> bookID;

    int bookIndex = findBook(bookID);

    if (bookIndex == -1)
    {
        cout << "\nBook Not Found!\n";
        return;
    }

    if (!books[bookIndex].available)
    {
        cout << "\nBook is already issued!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Issue Date (DD/MM/YYYY) : ";
    getline(cin, record.issueDate);

    record.bookID = bookID;
    record.memberID = memberID;
    record.returned = false;
    record.returnDate = "";

    books[bookIndex].available = false;

    records.push_back(record);

    cout << "\nBook Issued Successfully!\n";
}

//=========================

void returnBook()
{
    int bookID;

    cout << "\nEnter Book ID : ";
    cin >> bookID;

    int recordIndex = findBorrowRecord(bookID);

    if (recordIndex == -1)
    {
        cout << "\nNo Active Borrow Record Found!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Return Date (DD/MM/YYYY) : ";
    getline(cin, records[recordIndex].returnDate);

    records[recordIndex].returned = true;

    int bookIndex = findBook(bookID);

    if (bookIndex != -1)
        books[bookIndex].available = true;

    cout << "\nBook Returned Successfully!\n";
}

//=========================

void displayBorrowRecords()
{
    if (records.empty())
    {
        cout << "\nNo Borrow Records Found!\n";
        return;
    }

    cout << "\n========== BORROW RECORDS ==========\n";

    for (const BorrowRecord &record : records)
    {
        record.display();
    }
}

//=========================

void displayAvailableBooks()
{
    bool found = false;

    cout << "\n========== AVAILABLE BOOKS ==========\n";

    for (const Book &book : books)
    {
        if (book.available)
        {
            book.display();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Available Books.\n";
}

//=========================

void displayIssuedBooks()
{
    bool found = false;

    cout << "\n========== ISSUED BOOKS ==========\n";

    for (const Book &book : books)
    {
        if (!book.available)
        {
            book.display();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Issued Books.\n";
}
//=========================
// Main Function
//=========================

int main()
{
    int choice;

    do
    {
        cout << "\n==========================================";
        cout << "\n      LIBRARY MANAGEMENT SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Update Book";
        cout << "\n5. Delete Book";

        cout << "\n\n6. Add Member";
        cout << "\n7. Display Members";
        cout << "\n8. Search Member";
        cout << "\n9. Update Member";
        cout << "\n10. Delete Member";

        cout << "\n\n11. Issue Book";
        cout << "\n12. Return Book";

        cout << "\n13. Display Borrow Records";
        cout << "\n14. Display Available Books";
        cout << "\n15. Display Issued Books";

        cout << "\n\n0. Exit";

        cout << "\n==========================================";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            updateBook();
            break;

        case 5:
            deleteBook();
            break;

        case 6:
            addMember();
            break;

        case 7:
            displayMembers();
            break;

        case 8:
            searchMember();
            break;

        case 9:
            updateMember();
            break;

        case 10:
            deleteMember();
            break;

        case 11:
            issueBook();
            break;

        case 12:
            returnBook();
            break;

        case 13:
            displayBorrowRecords();
            break;

        case 14:
            displayAvailableBooks();
            break;

        case 15:
            displayIssuedBooks();
            break;

        case 0:
            cout << "\nThank You for Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}