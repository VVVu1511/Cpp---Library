#include "reader.h"

void viewFine(const char MSSV[], char cards[][1000], int number_of_cards, char current_date[],const char studentLosingBook[][1000], const int &num_of_books, char books[][1000]){
    double result = 0;

    for(int i = 0; i < number_of_cards; i++){
        char card_infor[100][1000];
        int num_of_infor;
        parseInfor(card_infor,cards[i],num_of_infor);

        if(strcmp(card_infor[0], MSSV) != 0) continue;

        for(int j = 3; j < num_of_infor; j += 2){
            int distance;
            if(strcmp(card_infor[j + 1],"-") == 0){
                distance = intervalsBetween2Days(card_infor[2], current_date);

            }
            else{
                distance = intervalsBetween2Days(card_infor[2], card_infor[j + 1]);
            }

            if(distance > 7) result += (distance - 7) * 5000;
        }
    }

    for(int i = 0; i < num_of_books; i++){
        if(strcmp(studentLosingBook[i], MSSV) == 0){
            char book_infor[100][1000];
            int num_of_infor;
            parseInfor(book_infor,books[i],num_of_infor);

            result += atof(book_infor[6]) * 2;
        }
    }

    std::cout << "Penalty for student with ID " << MSSV << " is " << result << "\n";
}

void viewReadersLate(char array[][1000], int number_of_elements,char today[]){
    bool atLeastOne = false;
    
    for(int i = 0; i < number_of_elements; i++){
        int number_of_output = 0;
        char infor[100][1000];
        parseInfor(infor,array[i],number_of_output);
        bool hasReturn = false;

        for(int i = 3; i < number_of_output; i++){
            int interval;
            if(strcmp(infor[i + 1],"-") != 0){
                interval = intervalsBetween2Days(infor[2], infor[i + 1]);
                
                
            }
            else{
                interval = intervalsBetween2Days(infor[2], today);  
            }

            if(interval > 7){
                hasReturn = true;
            }
        }
        
        if(hasReturn == true){
            std::cout << infor[0] << "\n";
            atLeastOne = true;
        }
    }

    if(atLeastOne == false){
        std::cout << "No readers are late!\n";
    }
}

void printInforOfOneReader(char information[]){
    int number;
    char parsed_result[100][1000];
    parseInfor(parsed_result,information,number);
    
    std::cout << "Ma doc gia: " << parsed_result[0] << "\n"
                << "Ho ten: " <<  parsed_result[1] << "\n"
                << "Chung minh nhan dan: " <<  parsed_result[2] << "\n"
                << "Ngay thang nam sinh: " <<  parsed_result[3] << "\n"
                << "Gioi tinh: " <<  parsed_result[4] << "\n"
                << "Email: " <<  parsed_result[5] << "\n"
                << "Dia chi: " <<  parsed_result[6] << "\n"
                << "Ngay lap the: " <<  parsed_result[7] << "\n"
                << "Ngay het han: " <<  parsed_result[8] << "\n";
}

void getInputOfReader(char new_element[]){
    char input[9][1000];
    
    prompt("Ma doc gia: ",input[0]);
    prompt("Ho ten: ",input[1]);
    prompt("Chung minh nhan dan: ",input[2]);
    prompt("Ngay thang nam sinh: ",input[3]);
    prompt("Gioi tinh (male/female): ",input[4]);
    prompt("Email: ",input[5]);
    prompt("Dia chi: ",input[6]);
    prompt("Ngay lap the: ",input[7]);
    prompt("Ngay het han: ",input[8]);

    writeBack(new_element,1,input,9);
}

void viewTypeOfInformationOfReader(){
    std::cout << "0. Ma doc gia" << "\n"
            << "1. Ho ten" << "\n"
            << "2. Chung minh nhan dan" << "\n"
            << "3. Ngay thang nam sinh" << "\n"
            << "4. Gioi tinh" << "\n"
            << "5. Email" << "\n"
            << "6. Dia Chi" << "\n"
            << "7. Ngay lap the" << "\n"
            << "8. Ngay het han" << "\n";
}

void notifyLosingBook(char ISBN[],const char MSSV[], char studentLosingBook[][1000], int &num_of_books, char books[][1000], bool isBookInLib[]){
    int bookID = findUsingInfor(books,num_of_books,ISBN, 0);    
    if(isBookInLib[bookID]){
        isBookInLib[bookID] = false;
        num_of_books--;
    }
    strcpy(studentLosingBook[bookID], MSSV);
}