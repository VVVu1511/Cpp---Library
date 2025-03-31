#include "book.h"

void getInputOfBook(char new_element[]){
    char input[7][1000];

    prompt("Ma ISBN: ",input[0]);
    prompt("Ten sach: ",input[1]);
    prompt("Ten tac gia: ",input[2]);
    prompt("Nha xuat ban: ",input[3]);
    prompt("Nam xuat ban: ",input[4]);
    prompt("The loai (horror/action/romance/comedy): ",input[5]);
    prompt("Gia: ",input[6]);
    
    writeBack(new_element,1,input,7);
}  

void printInforOfOneBook(char information[]){
    int number = 0;
    char parsed_result[100][1000];
    parseInfor(parsed_result,information,number);
    
    std::cout << "Ma ISBN: " << parsed_result[0] << "\n"
            << "Ten sach: " <<  parsed_result[1] << "\n"
            << "Ten tac gia: " <<  parsed_result[2] << "\n"
            << "Nha xuat ban: " <<  parsed_result[3] << "\n"
            << "Nam xuat ban: " <<  parsed_result[4] << "\n"
            << "The loai: " <<  parsed_result[5] << "\n"
            << "Gia: " <<  parsed_result[6] << "\n";
}

void viewTypeOfInformationOfBook(){
    std::cout << "0. ISBN" << "\n"
            << "1. Ten sach" << "\n"
            << "2. Ten tac gia" << "\n"
            << "3. Nha xuat ban" << "\n"
            << "4. Nam xuat ban" << "\n"
            << "5. The loai" << "\n"
            << "6. Gia" << "\n";
}

int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books){
    int result = 0;

    for(int i = 0; i < number_of_books; i++){
        if(stateOfBooks[i] == false) result++;
    }

    return result;
}