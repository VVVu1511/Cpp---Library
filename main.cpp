#include<iostream>
#include "function.h"

//mã độc giả, họ tên, CMND, ngày tháng năm sinh, giới tính, email, địa chỉ, ngày lập thẻ và 
//ngày hết hạn của thẻ

// Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự kiến, ngày trả thực tế 
// và danh sách ISBN của các sách được mượn. Mỗi sách được mượn tối đa trong 7 ngày, nếu 
// quá hạn sẽ bị phạt tiền 5.000 đồng/ngày. 
// Nếu sách bị mất thì độc giả đó sẽ bị phạt số tiền tương ứng 200% giá sách

int main(){
    char reader1[100] = {'2','3','1','2','7','5','4','3',',','V','u',' ','V','a','n',' ','V','u',',','1','1','0','0',' ','1','0','0','1',' ','0','1','1','0',',','1','5','/','1','1','/','2','0','0','5',',','m','a','l','e',',','v','v','v','@','g','m','a','i','l','.','c','o','m',',','2','2','2',' ','G','o','d',' ','S','t','r','e','e','t',',','1','2','/','9','/','2','0','2','3',',','1','2','/','9','/','2','0','2','7',',','\0'};
    char reader2[105] = {'2','3','1','2','7','5','4','3',',','N','g','u','y','e','n',' ','V','a','n',' ','A',',','8','7','1','2',' ','5','6','3','4',' ','2','0','0','1',',','1','/','1','/','2','0','0','5',',','f','e','m','a','l','e',',','n','v','a','@','g','m','a','i','l','.','c','o','m',',','3','3','3',' ','G','o','d',' ','S','t','r','e','e','t',',','1','2','/','1','0','/','2','0','2','3',',','1','2','/','1','0','/','2','0','2','7',',','\0'};
    char book1[60] = {'H','B','O','1','1','2',',','A','d','v','e','n','t','u','r','e',',','V','u',' ','V','a','n',' ','V','u',',','U','n','i','q','u','e',' ','p','u','b','l','i','s','h','e','r',',','2','0','0','1',',','a','c','t','i','o','n',',','5','0',',','\0'};
    char book2[73] = {'H','C','M','U','S','1','1','3',',','J','o','u','r','n','e','y',' ','a','t',' ','H','C','M','U','S',',','V','u',' ','V','a','n',' ','V','u',',','L','i','m','i','t','e','d',' ','p','u','b','l','i','s','h','e','r',',','2','0','2','7',',','r','o','m','a','n','c','e',',','1','0','0','0',',','\0'};
    char book3[61] = {'H','C','M','U','S','1','1','9',',','C','i','n','e','m','a',',','N','g','u','y','e','n',' ','V','a','n',' ','A',',','G','o','o','d',' ','p','u','b','l','i','s','h','e','r',',','1','9','9','9',',','h','o','r','r','o','r',',','2','0','0',',','\0'};
    char book4[53] = {'H','C','M','U','S','1','3','9',',','T','r','a','n',' ','T','h','i',' ','G',',','P','h','a','m',' ','T','h','i',' ','B',',','P','a','s','t',',','2','0','0','0',',','r','o','m','a','n','c','e',',','1','5',',','\0'};
    char book5[64] = {'H','C','M','U','S','1','2','5',',','W','h','a','t',' ','i','s',' ','c','i','n','e','m','a',',','N','g','u','y','e','n',' ','V','a','n',' ','C',',','C','i','n','e','m','a','t','i','c',',','1','9','7','0',',','a','c','t','i','o','n',',','3','0','0',',','\0'};
    char book6[53] = {'H','C','M','U','S','1','2','7',',','T','h','e',' ','f','u','t','u','r','e',',','T','a',' ','T','h','i',' ','D',',','F','u','t','u','r','e',',','1','9','7','7',',','c','o','m','e','d','y',',','1','8','0',',','\0'};
    char book7[53] = {'H','C','M','U','S','1','3','0',',','T','h','e',' ','p','a','s','t',',','N','g','u','y','e','n',' ','T','h','i',' ','E',',','P','a','s','t',',','1','9','7','7',',','a','c','t','i','o','n',',','3','8','0',',','\0'};
    
    char type1[7] = {'h','o','r','r','o','r','\0'};
    char type2[7] = {'c','o','m','e','d','y','\0'};
    char type3[7] = {'a','c','t','i','o','n','\0'};
    char type4[8] = {'r','o','m','a','n','c','e','\0'};

    char gender1[5] = {'m','a','l','e','\0'};
    char gender2[7] = {'f','e','m','a','l','e','\0'};

    char** readers_information;
    readers_information = new char*[2];
    readers_information[0] = new char[strlen(reader1) + 1];
    strcpy(readers_information[0], reader1);
    readers_information[1] = new char[strlen(reader2) + 1];
    strcpy(readers_information[1], reader2);

    char** books_information;
    books_information = new char*[7];
    books_information[0] = new char[strlen(book1) + 1];
    strcpy(books_information[0], book1);
    books_information[1] = new char[strlen(book2) + 1];
    strcpy(books_information[1], book2);
    books_information[2] = new char[strlen(book3) + 1];
    strcpy(books_information[2], book3);
    books_information[3] = new char[strlen(book4) + 1];
    strcpy(books_information[3], book4);
    books_information[4] = new char[strlen(book5) + 1];
    strcpy(books_information[4], book5);
    books_information[5] = new char[strlen(book6) + 1];
    strcpy(books_information[5], book6);
    books_information[6] = new char[strlen(book7) + 1];
    strcpy(books_information[6], book7);

    char** cards;
    
    int number_of_books = 7;
    int number_of_readers = 2;
    int number_of_cards = 0;
    
    char** book_types;
    book_types = new char*[4];
    book_types[0] = new char[strlen(type1) + 1];
    strcpy(book_types[0], type1);
    book_types[1] = new char[strlen(type2) + 1];
    strcpy(book_types[1], type2);
    book_types[2] = new char[strlen(type3) + 1];
    strcpy(book_types[2], type3);
    book_types[3] = new char[strlen(type4) + 1];
    strcpy(book_types[3], type4);
    
    char** gender_types;
    gender_types = new char*[2];
    gender_types[0] = new char[strlen(gender1) + 1];
    strcpy(gender_types[0], gender1);
    gender_types[1] = new char[strlen(gender2) + 1];
    strcpy(gender_types[1], gender2);

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
                  << "Enter your choice: " << "\n"; 
        int choice;
        int reader_ID;
        int type_to_be_deleted;
        int type_to_be_changed;
        int book_ID;
        std::cin >> choice;
        std::cin.ignore();
        char *input = new char[MAX_INFOR_LENGTH];
        for(int i = 0; i < MAX_INFOR_LENGTH; i++) input[i] = '\0';

        switch(choice){
            case 0:
                execute = false;
                break;
            case 1:
                viewList(readers_information,number_of_readers,0);
                break;
            case 2:
                std::cout << "Fill in information for new reader" << "\n";
                getInputOfReader(input);
                addOneToArray(readers_information,number_of_readers,input);
                std::cout << "Add reader successfully!" << "\n";
                break;
            case 3:
                viewList(readers_information,number_of_readers,0);
                std::cout << "Enter Reader ID(0 - " << number_of_readers - 1 << "): ";
                std::cin >> reader_ID;

                viewTypeOfInformationOfReader();
                std::cout << "Enter type to be changed: " ;
                std::cin >> type_to_be_changed;
                std::cin.ignore();

                std::cout << "Enter new data for that field: ";
                std::cin.getline(input,MAX_INFOR_LENGTH);

                changeInfor(readers_information,reader_ID,input,type_to_be_changed,0);
                std::cout << "Change information successfully!" << "\n";
                break;
            case 4:
                viewList(readers_information,number_of_readers,0);
                std::cout << "Enter Reader ID(0 -" << number_of_readers - 1 << "): ";
                std::cin >> reader_ID;

                viewTypeOfInformationOfReader();
                std::cout << "Enter type to be deleted: " ;
                std::cin >> type_to_be_deleted;
                deleteInfor(readers_information,reader_ID,type_to_be_deleted,0);
                break;
            case 5:
                std::cout << "Enter social ID: ";
                std::cin.getline(input,MAX_INFOR_LENGTH);
                reader_ID = findUsingInfor(readers_information,number_of_readers,input,2);
                
                if(reader_ID != -1){
                    printInforOfOneReader(readers_information[reader_ID]);
                }

                else{
                    std::cout << "There is no reader with entered social ID\n";
                }

                break;
            case 6:
                std::cout << "Enter full name: ";
                std::cin.getline(input,MAX_INFOR_LENGTH);
                reader_ID = findUsingInfor(readers_information,number_of_readers,input,1);
                
                if(reader_ID != -1){
                    printInforOfOneReader(readers_information[reader_ID]);
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
                std::cin.getline(input,MAX_INFOR_LENGTH);

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
                std::cin.getline(input,MAX_INFOR_LENGTH);
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
                std::cin.getline(input,MAX_INFOR_LENGTH);
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
                viewNumberOfElementByType(books_information,book_types,number_of_books,number_of_types,5);
                break;
            case 17:
                std::cout << "Number of readers: " << number_of_readers << "\n";
                break;
            case 18:
                viewNumberOfElementByType(readers_information,gender_types,number_of_readers,number_of_genders,4);
                break;
            case 19:
                std::cout << "Number of books being borrowed: " << numberOfBooksBeingBorrowed(isBookInLib,number_of_books) << "\n";
                break;
            case 20:
                prompt("Enter today's date: ",input);
                viewReadersLate(cards,number_of_cards,input);
                break;

            default:
                break;
        }

        system("pause");
        system("cls");
        delete[] input;
    }

    
    delete2Dchar(readers_information,number_of_books);
    delete2Dchar(books_information,number_of_books);
    delete2Dchar(cards,number_of_cards);
    delete2Dchar(books_information,number_of_books);
    delete2Dchar(gender_types,number_of_genders);
    return 0;
}