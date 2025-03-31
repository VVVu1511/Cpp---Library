#include "card.h"

void returnCard(char array[][1000],int number_of_elements,char input[],char booksInLib[][1000],bool isBookInLib[],int &number_of_books_in_lib){    
    char input_infor[100][1000];
    int num_of_input_infor;
    parseInfor(input_infor,input,num_of_input_infor);

    number_of_books_in_lib += (num_of_input_infor - 2);

    for (int i = 0; i < number_of_elements; i++) {
        char card_infor[100][1000];
        int num_of_infor;
        parseInfor(card_infor,array[i],num_of_infor);

        if(strcmp(card_infor[0],input_infor[0]) != 0) continue;

        for(int j = 2; j < num_of_input_infor; j++){
            
            int bookID = findUsingInfor(booksInLib, number_of_books_in_lib, input_infor[j] , 0);
            isBookInLib[bookID] = true;

            for(int k = 3; k < num_of_infor; k += 2){
                if(strcmp(card_infor[k],input_infor[j]) != 0) continue;

                strcpy(card_infor[k + 1], input_infor[1]);
                break;
            }
        }

        break;
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

void getInputOfBorrowCard(char new_element[],bool stateOfBooks[],char books_in_lib[][1000],int &number_of_books_in_lib){
    int number_of_books;
    std::cout << "Enter number of books you want to borrow: ";
    std::cin >> number_of_books;
    std::cin.ignore();
    
    char input[3 + number_of_books * 2][1000];

    prompt("Ma doc gia: ",input[0]);
    prompt("Ngay muon: ",input[1]);
    prompt("Ngay tra du kien: ",input[2]);

    for(int i = 0; i < number_of_books; i += 2){
        prompt("ISBN of book: ",input[i + 3]);
        strcpy(input[i + 4], "-");
        int book_ID = findUsingInfor(books_in_lib,number_of_books_in_lib,input[i + 3],0);
        stateOfBooks[book_ID] = false;
    }
    
    number_of_books_in_lib -= number_of_books;
    writeBack(new_element,1,input,3 + number_of_books * 2);
}

void getInputOfReturnCard(char new_element[]){
    int N;
    std::cout << "Nhap so luong sach se tra: ";
    std::cin >> N;
    std::cin.ignore();

    char input[2 + N][1000];

    prompt("Enter reader code: ",input[0]);
    prompt("Enter return date: ",input[1]);
    
    for(int i = 0; i < N; i++){
        prompt("ISBN of book: ",input[i + 2]);
    }
    
    writeBack(new_element,1,input,N + 2);
}
