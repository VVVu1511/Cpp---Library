#include "card.h"

void returnCard(char** array,int number_of_elements,char* input,char** booksInLib,bool isBookInLib[],int number_of_books_in_lib){
    for(int i = 0; i < number_of_elements; i++){
        int number_of_output = 0;
        char** infor = parseInfor(array[i],number_of_output);
        char temp[2] = {'-','\0'};

        if(strcmp(infor[0],input) == 0 && strcmp(infor[3],temp) == 0){
            infor[3] = new char[strlen(infor[1]) + 1];
            strcpy(infor[3],infor[1]);
            
            writeBack(array[i],1,infor,number_of_output);

            for(int i = 4; i < number_of_output - 4; i++){
                int book_ID = findUsingInfor(booksInLib,number_of_books_in_lib,infor[i],0);
                isBookInLib[book_ID] = true;
            }
        }

        delete2Dchar(infor,number_of_output);
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

void getInputOfBorrowCard(char* &new_element,bool stateOfBooks[],char** books_in_lib,int number_of_books_in_lib){
    int number_of_books;
    std::cout << "Enter number of books you want to borrow: ";
    std::cin >> number_of_books;
    std::cin.ignore();
    
    char** input = new char*[4 + number_of_books];
    for(int i = 0; i < 4 + number_of_books; i++){
        input[i] = new char[MAX_INFOR_LENGTH];
        
        for(int j = 0; j < MAX_INFOR_LENGTH; j++){
            input[i][j] = '\0';
        }
    }

    char real_return_day[2] = {'-','\0'};

    prompt("Ma doc gia: ",input[0]);
    prompt("Ngay muon: ",input[1]);
    prompt("Ngay tra du kien: ",input[2]);
    strcpy(input[3],real_return_day);


    for(int i = 0; i < number_of_books; i++){
        prompt("ISBN of book: ",input[i + 4]);
        
        int book_ID = findUsingInfor(books_in_lib,number_of_books_in_lib,input[i + 4],0);
        stateOfBooks[book_ID] = false;
    }
    
    writeBack(new_element,1,input,4 + number_of_books);

    delete2Dchar(input,4 + number_of_books);
}

void getInputOfReturnCard(char *&new_element){
    char **input = new char*[2];

    for(int i = 0; i < 2; i++){
        input[i] = new char[MAX_INFOR_LENGTH];
        for(int j = 0; j < MAX_INFOR_LENGTH; j++) input[i][j] = '\0';
    }
    prompt("Enter reader code: ",input[0]);
    prompt("Enter return date: ",input[1]);

    writeBack(new_element,1,input,2);

    delete2Dchar(input,2);
}
