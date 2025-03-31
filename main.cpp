#include<iostream>
#include "General/general.h"
#include "Reader/reader.h"
#include "Book/book.h"
#include "Card/card.h"

//g++ -I. -IBook -ICard -IGeneral -IHelper -IReader -o main main.cpp Book/book.cpp Card/card.cpp General/general.cpp Helper/helper.cpp Reader/reader.cpp

int main(){
    char readers[2][1000] = {
        "23127543,Vu Van Vu,1100 1001 0110,15/11/2005,male,vvv@gmail.com,222 God Street,12/9/2023,12/9/2027",
        "23127544,Nguyen Van A,8712 5634 2001,1/1/2005,female,nva@gmail.com,333 God Street,12/10/2023,12/10/2027"
    };
    
    char types[4][1000] = {
        "horror",
        "comedy",
        "action",
        "romance"
    };

    char genders[2][1000] = {
        "male",
        "female"
    };

    char books_information[7][1000] = {
        "HBO112,Adventure,Vu Van Vu,Unique publisher,2001,action,50000",
        "HCMUS113,Journey at HCMUS,Vu Van Vu,Limited publisher,2027,romance,100000",
        "HCMUS119,Cinema,Nguyen Van A,Good publisher,1999,horror,200000",
        "HCMUS139,Tran Thi G,Pham Thi B,Past,2000,romance,150000",
        "HCMUS125,What is cinema,Nguyen Van C,Cinematic,1970,action,300000",
        "HCMUS127,The future,Ta Thi D,Future,1977,comedy,180000",
        "HCMUS130,The past,Nguyen Thi E,Past,1977,action,380000"
    };

    char cards[100][1000];
    
    int number_of_books = 7;
    int number_of_readers = 2;
    int number_of_cards = 0;

    char studentLosingBook[number_of_books][1000];

    for(int i = 0; i < number_of_books; i++){
        strcpy(studentLosingBook[i],"-");
    }

    int number_of_types = 4;
    int number_of_genders = 2;

    bool isBookInLib[number_of_books];
    for(int i = 0; i < number_of_books; i++) isBookInLib[i] = true;

    bool execute = true;
    
    while(execute != false){
        std::cout << "LIBRARY MANAGEMENT SYSTEM" << "\n"
                << "0. Thoat" << "\n"
                << "1. Danh sach doc gia" << "\n"
                << "2. Them doc gia" << "\n"
                << "3. Chinh sua thong tin 1 doc gia" << "\n"
                << "4. Xoa thong tin 1 doc gia" << "\n"
                << "5. Tim kiem doc gia theo CMND/CCCD" << "\n"
                << "6. Tim kiem doc gia theo ho ten" << "\n"

                << "7. Danh sach sach trong thu vien" << "\n"
                << "8. Them sach" << "\n"
                << "9. Chinh sua thong tin 1 quyen sach" << "\n"
                << "10. Xoa thong tin sach" << "\n"
                << "11. Tim sach theo ISBN" << "\n"
                << "12. Tim sach theo ten sach" << "\n"
                << "13. Lap phieu muon sach" << "\n"
                << "14. Lap phieu tra sach" << "\n"
                << "15. So luong sach trong thu vien" << "\n" 
                << "16. So luong sach theo the loai" << "\n"
                << "17. So luong doc gia" << "\n" 
                << "18. So luong doc gia theo gioi tinh" << "\n"
                << "19. So sach dang duoc muon" << "\n"
                << "20. Danh sach doc gia bi tre han" << "\n"
                << "21. Xem tien phat cua 1 hoc sinh" << "\n"
                << "22. Hoc sinh lam mat sach" << "\n\n"
                << "Enter your choice: ";
        int choice;
        int reader_ID;
        int type_to_be_deleted;
        int type_to_be_changed;
        int book_ID;
        std::cin >> choice;
        std::cin.ignore();
        char input[1000];

        switch(choice){
            case 0:
                execute = false;
                break;
            case 1:
                viewList(readers,number_of_readers,0);
                break;
            case 2:
                std::cout << "Fill in information for new reader" << "\n";
                getInputOfReader(input);
                addOneToArray(readers,number_of_readers,input);
                std::cout << "Add reader successfully!" << "\n";
                break;
            case 3:
                viewList(readers,number_of_readers,0);
                std::cout << "Enter Reader ID(0 - " << number_of_readers - 1 << "): ";
                std::cin >> reader_ID;

                viewTypeOfInformationOfReader();
                std::cout << "Enter type to be changed: " ;
                std::cin >> type_to_be_changed;
                std::cin.ignore();

                std::cout << "Enter new data for that field: ";
                std::cin.getline(input,1000);

                changeInfor(readers,reader_ID,input,type_to_be_changed,0);
                std::cout << "Change information successfully!" << "\n";
                break;
            case 4:
                viewList(readers,number_of_readers,0);
                std::cout << "Enter Reader ID(0 -" << number_of_readers - 1 << "): ";
                std::cin >> reader_ID;

                viewTypeOfInformationOfReader();
                std::cout << "Enter type to be deleted: " ;
                std::cin >> type_to_be_deleted;
                deleteInfor(readers,reader_ID,type_to_be_deleted,0);
                break;
            case 5:
                std::cout << "Enter social ID: ";
                std::cin.getline(input,1000);
                
                reader_ID = findUsingInfor(readers,number_of_readers,input,2);
                
                if(reader_ID != -1){
                    printInforOfOneReader(readers[reader_ID]);
                }

                else{
                    std::cout << "There is no reader with entered social ID\n";
                }

                break;
            case 6:
                std::cout << "Enter full name: ";
                std::cin.getline(input,1000);
                reader_ID = findUsingInfor(readers,number_of_readers,input,1);
                
                if(reader_ID != -1){
                    printInforOfOneReader(readers[reader_ID]);
                }

                else{
                    std::cout << "There is no reader with entered name\n";
                }

                break;
            case 7:
                viewList(books_information,number_of_books,1);
                break;
            case 8:
                std::cout << "Fill in information for new book" << "\n";
                getInputOfBook(input);
                addOneToArray(books_information,number_of_books,input);
                std::cout << "Add book successfully!" << "\n";
                break;
            case 9:
                viewList(books_information,number_of_books,1);
                std::cout << "Enter Book ID(0 - " << number_of_books - 1 << "): ";
                std::cin >> book_ID;

                viewTypeOfInformationOfBook();
                std::cout << "Enter type to be changed: " ;
                std::cin >> type_to_be_changed;
                std::cin.ignore();

                std::cout << "Enter new data for that field: ";
                std::cin.getline(input,1000);

                changeInfor(books_information,book_ID,input,type_to_be_changed,1);
                std::cout << "Change infor of book successfully!" << "\n";
                break;
            case 10:
                viewList(books_information,number_of_books,1);
                std::cout << "Enter Book ID(0 -" << number_of_books - 1 << "): ";
                std::cin >> book_ID;

                viewTypeOfInformationOfBook();
                std::cout << "Enter type to be deleted: " ;
                std::cin >> type_to_be_deleted;

                deleteInfor(books_information,book_ID,type_to_be_changed,1);
                std::cout << "Deleted successfully!";
                break;
            case 11:
                std::cout << "Enter ISBN: ";
                std::cin.getline(input,1000);
                book_ID = findUsingInfor(books_information,number_of_books,input,0);
                
                if(book_ID != -1){
                    printInforOfOneBook(books_information[book_ID]);
                }

                else{
                    std::cout << "There is no book with entered ISBN\n";
                }

                break;
            case 12:
                std::cout << "Enter book's name: ";
                std::cin.getline(input,1000);
                book_ID = findUsingInfor(books_information,number_of_books,input,1);

                if(book_ID != -1){
                    printInforOfOneBook(books_information[book_ID]);
                }

                else{
                    std::cout << "There is no book with entered name\n";
                }

                break;
            case 13:
                std::cout << "Enter information for new card: " << "\n";
                getInputOfBorrowCard(input,isBookInLib,books_information,number_of_books);
                addOneToArray(cards,number_of_cards,input);

                std::cout << "Successfully add card" << "\n";
                break;
            case 14:
                std::cout << "Enter information: " << "\n";
                getInputOfReturnCard(input);
                returnCard(cards,number_of_cards,input,books_information,isBookInLib,number_of_books);
                std::cout << "Successfully add return card!" << "\n";
                break;
            case 15:
                std::cout << "Number of books in library: " << number_of_books << "\n";
                break;
            case 16:
                viewNumberOfElementByType(books_information,types,number_of_books,number_of_types,5);
                break;
            case 17:
                std::cout << "Number of readers: " << number_of_readers << "\n";
                break;
            case 18:
                viewNumberOfElementByType(readers,genders,number_of_readers,number_of_genders,4);
                break;
            case 19:
                std::cout << "Number of books being borrowed: " << numberOfBooksBeingBorrowed(isBookInLib,number_of_books,studentLosingBook) << "\n";
                break;
            case 20:
                prompt("Enter today's date: ",input);
                viewReadersLate(cards,number_of_cards,input);
                break;
            case 21:
                char current_date[1000];
                prompt("Enter ID: ", input);
                prompt("Enter current day: ", current_date);
                viewFine(input, cards,number_of_cards, current_date, studentLosingBook,number_of_books,books_information);
                break;
            case 22:
                char book_ISBN[1000];
                prompt("Enter ID: ", input);
                prompt("Enter ISBN: ", book_ISBN);
                notifyLosingBook(book_ISBN, input,studentLosingBook,number_of_books,books_information,isBookInLib);
                std::cout << "Succesfully notify losing book!\n";
                break;
            default:
                break;
        }

        system("pause");
        system("cls");
        
    }
    
    return 0;
}