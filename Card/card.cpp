#include "card.h"

void returnCard(char array[][1000],int number_of_elements,char input[],char booksInLib[][1000],bool isBookInLib[],int number_of_books_in_lib){
    for (int i = 0; i < number_of_elements; i++) {
        int number_of_output = 0;
        char infor[100][1000];
        parseInfor(infor, array[i], number_of_output);

        if (strcmp(infor[0], input) == 0 && strcmp(infor[3], "-") == 0) {
            strcpy(infor[3], infor[1]);  
            writeBack(array[i], 1, infor, number_of_output);

            for (int j = 4; j < number_of_output - 4; j++) {
                int book_ID = findUsingInfor(booksInLib, number_of_books_in_lib, infor[j], 0);
                isBookInLib[book_ID] = true;
            }
        }
    }
}

void viewTypeOfInformationOfCard(){
    std::cout << "0. Ma doc gia" << "\n"
            << "1. Ngay muon" << "\n"
            << "2. Ngay tra du kien" << "\n"
            << "3. Ngay tra thuc te" << "\n"
            << "4. Danh sach ISBN" << "\n"
            << "5. Tien phat" << "\n"
            << "6. Ton tai" << "\n";
}

void getInputOfBorrowCard(char new_element[],bool stateOfBooks[],char books_in_lib[][1000],int number_of_books_in_lib){
    int number_of_books;
    std::cout << "Enter number of books you want to borrow: ";
    std::cin >> number_of_books;
    std::cin.ignore();
    
    char input[4 + number_of_books][1000];

    prompt("Ma doc gia: ",input[0]);
    prompt("Ngay muon: ",input[1]);
    prompt("Ngay tra du kien: ",input[2]);
    strcpy(input[3],"-");

    for(int i = 0; i < number_of_books; i++){
        prompt("ISBN of book: ",input[i + 4]);
        
        int book_ID = findUsingInfor(books_in_lib,number_of_books_in_lib,input[i + 4],0);
        stateOfBooks[book_ID] = false;
    }
    
    writeBack(new_element,1,input,4 + number_of_books);
}

void getInputOfReturnCard(char new_element[]){
    char input[2][1000];

    prompt("Enter reader code: ",input[0]);
    prompt("Enter return date: ",input[1]);

    writeBack(new_element,1,input,2);
}
