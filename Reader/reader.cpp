#include "reader.h"


void viewReadersLate(char **array, int number_of_elements,char* today){
    bool atLeastOne = false;
    char temp[2] = {'-','\0'};

    for(int i = 0; i < number_of_elements; i++){
        int number_of_output = 0;
        char** infor = parseInfor(array[i],number_of_output);
        bool hasReturn = false;

        if(strcmp(infor[3],temp) != 0){
            if(isDay1LargerThanDay2(infor[3],infor[2]) == true){
                hasReturn = true;
            }
        }

        else{
            if(isDay1LargerThanDay2(today,infor[2]) == true){
                hasReturn = true;
            }
        }
        
        if(hasReturn == true){
            std::cout << infor[0] << "\n";
            atLeastOne = true;
        }

        delete2Dchar(infor,number_of_elements);
    }

    if(atLeastOne == false){
        std::cout << "No readers are late!\n";
    }
}

void printInforOfOneReader(char* information){
    int number;
    char** parsed_result = parseInfor(information,number);
    
    std::cout << "Ma doc gia: " << parsed_result[0] << "\n"
                << "Ho ten: " <<  parsed_result[1] << "\n"
                << "Chung minh nhan dan: " <<  parsed_result[2] << "\n"
                << "Ngay thang nam sinh: " <<  parsed_result[3] << "\n"
                << "Gioi tinh: " <<  parsed_result[4] << "\n"
                << "Email: " <<  parsed_result[5] << "\n"
                << "Dia chi: " <<  parsed_result[6] << "\n"
                << "Ngay lap the: " <<  parsed_result[7] << "\n"
                << "Ngay het han: " <<  parsed_result[8] << "\n";
    
    delete2Dchar(parsed_result,number);
}

void getInputOfReader(char *&new_element){
    char** input = new char*[9];
    for(int i = 0; i < 9; i++){
        input[i] = new char[MAX_INFOR_LENGTH];
        
        for(int j = 0; j < MAX_INFOR_LENGTH; j++){
            input[i][j] = '\0';
        }
    }

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

    delete2Dchar(input,9);
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