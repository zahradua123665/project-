#include <iostream>
#include <string>
using namespace std;
#include <iostream>

void clear_screen()
 {
 #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}

int main() {
    
    clear_screen();  
    
    cout << "Library Management System\n";
    cout << "1. Add Book\n";
    cout << "2. View Books\n";
    cout << "3. Exit\n";

    return 0;
}
// ANSI escape codes for colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

const int MAX_BOOKS = 100;

struct Book 

{
    int id;
    string title;
    string author;
    int year;
    bool isIssued;
};

// Function declarations
void displayMenu();
void addBook(Book books[], int &bookCount);
void viewBooks(const Book books[], int bookCount);
void updateBook(Book books[], int bookCount);
void deleteBook(Book books[], int &bookCount);
void issueBook(Book books[], int bookCount);
void returnBook(Book books[], int bookCount);
void searchBookByTitle(const Book books[], int bookCount);
void listIssuedBooks(const Book books[], int bookCount);
int findBookById(const Book books[], int bookCount, int id);
void categorizeBooks(const Book books[], int bookCount);

intmain()

 {
    Book books[MAX_BOOKS];
    int bookCount = 26;
    
     // Pre-added books
     
    books[0] = {1, "Harry potter ", "J.K. Rowling", 1925, false};
    books[1] = {2, "Then Monster at the End of This Book", "Jon Stone", 1960, false};
    books[2] = {3, "Where the Wild Things Are", "Maurice Sendak", 1963, false};
    books[3] = {4, "The Cat in the Hat", "Dr. Seuss", 1957, false};
            
    books[4]= {5, "The Tale of Peter Rabbit", "Beatrix Potter", 1902, false};
    books[5]= {6, "Diary of a Wimpy Kid", "Jeff Kinney", 2007, false};
    books[6]= {7, "The Giving Tree", "Shel Silverstein", 1964, false};

    books[7]= {8, "Harry Potter", "J.K. Rowling", 1997, false};
    books[8]= {9, "The Lightning Thief", "Rick Riordan", 2005, false};
    books[9]= {10, "Wonder", "R.J. Palacio", 2012, false};
    books[10]= {11, "The BFG", "Roald Dahl", 1982, false};
    books[11]= {12, "Island of the Blue Dolphins", "Scott O'Dell", 1960, false};

    books[12]= {13, "The Outsiders", "S.E. Hinton", 1967, false};
    books[13]= {14, "To Kill a Mockingbird", "Harper Lee", 1960, false};
    books[14]= {15, "The Fault in Our Stars", "John Green", 2012, false};
    books[15]= {16, "The Giver", "Lois Lowry", 1993, false};
    books[16]= {17, "The Diary of a Young Girl", "Anne Frank", 1947, false};

    books[17]= {18, "Alice's Adventures in Wonderland", "Lewis Carroll", 1865, false};
    books[18]= {19, "Treasure Island", "Robert Louis Stevenson", 1883, false};
    books[19]= {20, "Black Beauty", "Anna Sewell", 1877, false};
    books[20]= {21, "The Jungle Book", "Rudyard Kipling", 1894, false};
    books[21]={22, "Robin Hood", "Howard Pyle", 1883, false};

    books[22]= {22, "The Curious Incident of the Dog in the Night-Time", "Mark Haddon", 2003, false};
    books[23]= {23, "Before We Were Strangers", "Renée Carlino", 2015, false};
    books[24]= {24, "The Boy in the Striped Pajamas", "John Boyne", 2006, false};
    books[25]= {25, "The House on Mango Street", "Sandra Cisneros", 1984, false};
    books[26]= {26, "Love, Stargirl", "Jerry Spinelli", 2007, false};

    int choice;

    do {
        displayMenu();
        cout << CYAN "Enter your choice: " RESET;
        cin >> choice;

        switch (choice) 
		
		{
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                viewBooks(books, bookCount);
                break;
            case 3:
                updateBook(books, bookCount);
                break;
            case 4:
                deleteBook(books, bookCount);
                break;
            case 5:
                issueBook(books, bookCount);
                break;
            case 6:
                returnBook(books, bookCount);
                break;
            case 7:
                searchBookByTitle(books, bookCount);
                break;
            case 8:
                listIssuedBooks(books, bookCount);
                break;
            case 9:
                cout << GREEN "Exiting the program. Goodbye!\n" RESET;
                break;
            default:
                cout << RED "Invalid choice! Please try again.\n" RESET;
        }

    } while (choice != 9);

    return 0;
}

void displayMenu() 

{
    cout << YELLOW "\n===== Library Management System =====\n" RESET;
    cout << "1. Add Book\n";
    cout << "2. View All Books\n";
    cout << "3. Update Book Details\n";
    cout << "4. Delete Book\n";
    cout << "5. Issue Book\n";
    cout << "6. Return Book\n";
    cout << "7. Search Book by Title\n";
    cout << "8. List All Issued Books\n";
    cout << "9. Exit\n";
    cout << YELLOW "====================================\n" RESET;
}

void addBook(Book books[], int &bookCount) 

{
    if (bookCount >= MAX_BOOKS)
	
	 {
        cout << RED "Library is full! Cannot add more books.\n" RESET;
        return;
    }

    Book newBook;
    cout << MAGENTA "Enter Book ID: " RESET;
    cin >> newBook.id;
    cin.ignore(); 
    
    cout << YELLOW "Enter Title: " RESET;
    getline(cin, newBook.title);
    
    cout << GREEN "Enter Author: " RESET;
    getline(cin, newBook.author);
    
    cout << BLUE "Enter Year of Publication: " RESET;
    cin >> newBook.year;
    newBook.isIssued = false;

    books[bookCount++] = newBook;
    cout << GREEN "Book added successfully!\n" RESET;
}

void viewBooks(const Book books[], int bookCount)

 {
    if (bookCount == 0)
	
	 {
        cout << RED "No books available in the library.\n" RESET;
        return;
    }

    cout << BLUE "\n===== List of Books =====\n" RESET;
    for (int i = 0; i < bookCount; i++) 
	{
	
       cout << MAGENTA "ID: " << books[i].id << "\n";
        cout << YELLOW "Title: " << books[i].title << "\n";
        cout << GREEN "Author: " << books[i].author << "\n";
        cout << BLUE "Year: " << books[i].year << "\n";
        cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
        cout << "----------------------------\n";
    }

    // Call to categorize books
    categorizeBooks(books, bookCount);
}

void categorizeBooks(const Book books[], int bookCount) 
{
    // Children's Books (Ages 5-12)
    cout << BLUE "\n===== Children's Books (Ages 5-12) =====\n" RESET;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year <= 1980 && books[i].year > 1950) { // Example range for children's books
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << YELLOW "Title: " << books[i].title << "\n";
            cout << GREEN "Author: " << books[i].author << "\n";
            cout << BLUE "Year: " << books[i].year << "\n";
            cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
        }
    }

    // Middle Grade (Ages 8-14)
    cout << BLUE "\n===== Middle Grade (Ages 8-14) =====\n" RESET;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year > 1980 && books[i].year <= 2000) { // Example range for middle grade
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << YELLOW "Title: " << books[i].title << "\n";
            cout << GREEN "Author: " << books[i].author << "\n";
            cout << BLUE "Year: " << books[i].year << "\n";
            cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
        }
    }

    // Young Adult (Ages 12+)
    cout << BLUE "\n===== Young Adult (Ages 12+) =====\n" RESET;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year > 2000 && books[i].year <= 2015) { // Example range for young adult
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << YELLOW "Title: " << books[i].title << "\n";
            cout << GREEN "Author: " << books[i].author << "\n";
            cout << BLUE "Year: " << books[i].year << "\n";
            cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
        }
    }

    // Classics (Simple English)
    cout << BLUE "\n===== Classics (Simple English) =====\n" RESET;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year <= 1950) { // Example range for classics
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << YELLOW "Title: " << books[i].title << "\n";
            cout << GREEN "Author: " << books[i].author << "\n";
            cout << BLUE "Year: " << books[i].year << "\n";
            cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
        }
    }

    // Modern Fiction (Easy Reads)
    cout << BLUE "\n===== Modern Fiction (Easy Reads) =====\n" RESET;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year > 1925) { // Example range for modern fiction
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << YELLOW "Title: " << books[i].title << "\n";
            cout << GREEN "Author: " << books[i].author << "\n";
            cout << BLUE "Year: " << books[i].year << "\n";
            cout << CYAN "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
        }
    }
    
    
}

void updateBook(Book books[], int bookCount)

 {
    int id;
    cout << CYAN "Enter the Book ID to update: " RESET;
    cin >> id;
    int index = findBookById(books, bookCount, id);

    if (index == -1)
	
	 {
        cout << RED "Book not found!\n" RESET;
        return;
    }

    cout << CYAN "Enter new Title (current: " RESET << books[index].title << CYAN "): " RESET;
    cin.ignore();
    getline(cin, books[index].title);
    cout << CYAN "Enter new Author (current: " RESET << books[index].author << CYAN "): " RESET;
    getline(cin, books[index].author);
    cout << CYAN "Enter new Year (current: " RESET << books[index].year << CYAN "): " RESET;
    cin >> books[index].year;

    cout << GREEN "Book details updated successfully!\n" RESET;
}

void deleteBook(Book books[], int &bookCount) 

{
    int id;
    cout << CYAN "Enter the Book ID to delete: " RESET;
    cin >> id;
    int index = findBookById(books, bookCount, id);

    if (index == -1)
	
	 {
        cout << RED "Book not found!\n" RESET;
        return;
    }

    for (int i = index; i < bookCount - 1; i++) 
	
	{
        books[i] = books[i + 1];
    }

    bookCount--;
    cout << GREEN "Book deleted successfully!\n" RESET;
}

void issueBook(Book books[], int bookCount) 

{
    int id;
    cout << CYAN "Enter the Book ID to issue: " RESET;
    cin >> id;
    int index = findBookById(books, bookCount, id);

    if (index == -1) 
	
	{
        cout << RED "Book not found!\n" RESET;
        return;
    }

    if (books[index].isIssued)
	
	 {
        cout << RED "Book is already issued!\n" RESET;
        return;
    }

    books[index].isIssued = true;
    cout << GREEN "Book issued successfully!\n" RESET;
}

void returnBook(Book books[], int bookCount)

 {
    int id;
    cout << CYAN "Enter the Book ID to return: " RESET;
    cin >> id;
    int index = findBookById(books, bookCount, id);

    if (index == -1) 
	
	{
        cout << RED "Book not found!\n" RESET;
        return;
    }

    if (!books[index].isIssued)
	 {
	 	
        cout << RED "Book is not issued!\n" RESET;
        return;
    }

    books[index].isIssued = false;
    cout << GREEN "Book returned successfully!\n" RESET;
}

void searchBookByTitle(const Book books[], int bookCount)

 {
    string title;
    cout << CYAN "Enter the Title to search: " RESET;
    cin.ignore();
    getline(cin, title);

    cout << BLUE "\n===== Search Results =====\n" RESET;
    bool found = false;
    for (int i = 0; i < bookCount; i++) 
	
	{
		
        if (books[i].title.find(title) != string::npos)
		
		 {
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << "Title: " << books[i].title << "\n";
            cout << "Author: " << books[i].author << "\n";
            cout << "Year: " << books[i].year << "\n";
            cout << "Status: " << (books[i].isIssued ? RED "Issued" RESET : GREEN "Available" RESET) << "\n";
            cout << "----------------------------\n";
            found = true;
        }
        
    }
    if (!found)
	
	 {
	 	
        cout << RED "No books found with the given title.\n" RESET;
        
    }
    
    
}

void listIssuedBooks(const Book books[], int bookCount) 

{
    cout << BLUE "\n===== Issued Books =====\n" RESET;
    bool found = false;
    for (int i = 0; i < bookCount; i++)
    
	 {
        if (books[i].isIssued) 
		
		{
            cout << MAGENTA "ID: " << books[i].id << "\n";
            cout << "Title: " << books[i].title << "\n";
            cout << "Author: " << books[i].author << "\n";
            cout << "Year: " << books[i].year << "\n";
            cout << "----------------------------\n";
            found = true;
        }
        
    }
    if (!found)
	
	 {
	 	
        cout << RED "No books are currently issued.\n" RESET;
        
    }
    
}

int findBookById(const Book books[], int bookCount, int id) 
{
    for (int i = 0; i < bookCount; i++)
    
	 {
        if (books[i].id == id)
        
		 {
            return i;
        }
    }
    return -1;
}