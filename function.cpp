#include "function.h"

void getInputOfBook(char *&new_element){
    char** input = new char*[7];
    for(int i = 0; i < 7; i++){
        input[i] = new char[MAX_INFOR_LENGTH];
        
        for(int j = 0; j < MAX_INFOR_LENGTH; j++){
            input[i][j] = '\0';
        }
    }

    prompt("Ma ISBN: ",input[0]);
    prompt("Ten sach: ",input[1]);
    prompt("Ten tac gia: ",input[2]);
    prompt("Nha xuat ban: ",input[3]);
    prompt("Nam xuat ban: ",input[4]);
    prompt("The loai (horror/action/romance/comedy): ",input[5]);
    prompt("Gia: ",input[6]);
    
    writeBack(new_element,1,input,7);

    delete2Dchar(input,7);
}   

void getInputOfBorrowCard(char *&new_element){
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

void findUsingInfor(char **array, int number_of_elements, char *input, int type_of_infor,int type){
    
    for(int i = 0; i < number_of_elements; i++){
        int num = 0;
        char** infor = parseInfor(array[i],num);
        
        if(strcmp(infor[type_of_infor],input) == 0){
            if(type == 0) printInforOfOneReader(array[i]);
            else printInforOfOneBook(array[i]);
        }

        delete2Dchar(infor,num);
    }
}

char** parseInfor(char *information, int& number_of_ele){
    int num_of_elements = 0;
    int infor_length = strlen(information);

    for(int i = 0; i < infor_length; i++){
        if(information[i] == ',') num_of_elements++;
    }

    number_of_ele = num_of_elements;

    char temp[MAX_INFOR_LENGTH] = {'\0'};

    int cur_char_in_temp = 0;
    int cur_number_of_infor = 0;
    char** result = new char*[num_of_elements];
    
    for(int i = 0; i < infor_length; i++){
        if(information[i] == ','){
            int size = strlen(temp) + 1;
            result[cur_number_of_infor] = new char[size];
            strcpy(result[cur_number_of_infor], temp);

            cur_number_of_infor++;
            
            resetTemporaryInfor(temp,MAX_INFOR_LENGTH);
            cur_char_in_temp = 0;
        }
        else{
            temp[cur_char_in_temp] = information[i];
            cur_char_in_temp++;
        }
    }

    return result;
}

void resetTemporaryInfor(char arr[],int length){
    for(int i = 0; i < length; i++){
        if(arr[i] != '\0'){
            arr[i] = '\0';
        }
        else break;
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

void viewList(char **array, int number_of_elements, int type){
    for(int i = 0; i < number_of_elements; i++){
        if(type == 0){
            std::cout << "Reader ID: " << i << "\n";
            printInforOfOneReader(array[i]);
            std::cout << "\n";
        }
        else{
            std::cout << "Book ID: " << i << "\n";
            printInforOfOneBook(array[i]);
            std::cout << "\n";
        }
    }
}

void printInforOfOneBook(char* information){
    int number = 0;
    char** parsed_result = parseInfor(information,number);
    
    std::cout << "Ma ISBN: " << parsed_result[0] << "\n"
              << "Ten sach: " <<  parsed_result[1] << "\n"
              << "Ten tac gia: " <<  parsed_result[2] << "\n"
              << "Nha xuat ban: " <<  parsed_result[3] << "\n"
              << "Nam xuat ban: " <<  parsed_result[4] << "\n"
              << "The loai: " <<  parsed_result[5] << "\n"
              << "Gia: " <<  parsed_result[6] << "\n";

    delete2Dchar(parsed_result,number);
}

void addOneToArray(char **&array, int &number_of_elements, char *new_element){
    char** new_array = new char*[number_of_elements + 1];
    
    for(int i = 0; i < number_of_elements; i++){
        new_array[i] = new char[strlen(array[i]) + 1];
        strcpy(new_array[i],array[i]);
    }

    new_array[number_of_elements] = new char[strlen(new_element) + 1];
    strcpy(new_array[number_of_elements],new_element);

    
    delete2Dchar(array,number_of_elements);
    
    array = new_array;

    number_of_elements++;
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

void writeBack(char *&information, int type, char **input,int num_of_input){
    // if(information != nullptr) delete []information;
    
    int size = 0;
    for(int i = 0; i < num_of_input; i++){
        size += strlen(input[i]);
    }
    
    size = size * 2 + 1;

    information = new char[size];
    
    int position = 0;
    
    for(int i = 0; i < num_of_input; i++){
        writeOneField(information,input[i],position);
    }
    
    information[size - 1] = '\0';
}

void writeOneField(char *&information, char *infor, int &starting_pos){
    for(int i = starting_pos; i < starting_pos + strlen(infor); i++){
        information[i] = infor[i - starting_pos];
    }
    information[starting_pos + strlen(infor)] = ',';
    
    starting_pos += strlen(infor) + 1;
}

void prompt(const char line[], char *input){
    std::cout << line;
    std::cin.getline(input,MAX_INFOR_LENGTH);
}

void changeInfor(char **&readers, int ID, char *new_infor, int type_of_infor,int type){    
    int number_of_elements = 0;
    char** res = parseInfor(readers[ID],number_of_elements);

    int size = strlen(new_infor) + 1;

    delete []res[type_of_infor];

    res[type_of_infor] = new char[strlen(new_infor) + 1];
    strcpy(res[type_of_infor],new_infor);
    
    
    writeBack(readers[ID],type,res,number_of_elements);

    delete2Dchar(res,number_of_elements);
}

void deleteInfor(char **&readers, int ID, int type_of_infor,int type){
    int number_of_elements = 0;
    char** infor = parseInfor(readers[ID],number_of_elements);
        
    delete infor[type_of_infor];
    infor[type_of_infor] = new char[2];
    char input[2] = {'-','\0'};
    strcpy(infor[type_of_infor],input);

    writeBack(readers[ID],type,infor,number_of_elements);   

    delete2Dchar(infor,number_of_elements);
}

void numberOfElementByType(char **array, char **types, int number_of_ele_in_array, int number_of_types,int type_of_infor){
    int number_of_each_type[number_of_types] = {0};

    for(int i = 0; i < number_of_ele_in_array; i++){
        int number_of_elements;
        char** infor = parseInfor(array[i],number_of_elements);

        for(int j = 0; j < number_of_types; j++){
            if(strcmp(infor[type_of_infor],types[j]) == 0){
                number_of_each_type[j]++;
                break;
            }
        }
        delete2Dchar(infor,number_of_elements);
    }

    for(int i = 0; i < number_of_types; i++){
        std::cout << types[i] << ": " << number_of_each_type[i] << "\n";
    }
}

void viewTypeOfInformationOfReader(){
    std::cout << "0. Reader code" << "\n"
              << "1. Full Name" << "\n"
              << "2. Reader social ID" << "\n"
              << "3. Date of birth" << "\n"
              << "4. Gender" << "\n"
              << "5. Email" << "\n"
              << "6. Address" << "\n"
              << "7. Begin date" << "\n"
              << "8. End date" << "\n";
}

void viewTypeOfInformationOfBook(){
    std::cout << "0. ISBN" << "\n"
              << "1. Book's name" << "\n"
              << "2. Author" << "\n"
              << "3. Publisher" << "\n"
              << "4. Publish year" << "\n"
              << "5. Type" << "\n"
              << "6. Price" << "\n";
}

void viewTypeOfInformationOfCard(){
    std::cout << "0. Reader code" << "\n"
              << "1. Borrowing Date" << "\n"
              << "2. Expected return day" << "\n"
              << "3. Actual return day" << "\n"
              << "4. Borrowed books' ISBN" << "\n"
              << "5. Money" << "\n"
              << "6. Exist" << "\n";
}

void viewNumberOfElementByType(char **array, char **types, int number_of_ele_in_array, int number_of_types,int type_of_infor){
    int number_of_each_type[number_of_types] = {0};

    for(int i = 0; i < number_of_ele_in_array; i++){
        int number_of_elements;
        char** infor = parseInfor(array[i],number_of_elements);

        for(int j = 0; j < number_of_types; j++){
            if(strcmp(infor[type_of_infor],types[j]) == 0){
                number_of_each_type[j]++;
                break;
            }
        }

        delete2Dchar(infor,number_of_elements);
    }

    for(int i = 0; i < number_of_types; i++){
        std::cout << types[i] << ": " << number_of_each_type[i] << "\n";
    }
}

void viewReadersLate(char **array, int number_of_elements){
    for(int i = 0; i < number_of_elements; i++){
        int number_of_output = 0;
        char** infor = parseInfor(array[i],number_of_output);

        if(infor[3] - infor[2] > 7){
            std::cout << infor[0] << "\n";
        }

        delete2Dchar(infor,number_of_elements);
    }
}

void returnCard(char **array, int number_of_elements, char *input){
    for(int i = 0; i < number_of_elements; i++){
        int number_of_output = 0;
        char** infor = parseInfor(array[i],number_of_output);

        if(strcmp(infor[0],input) == 0){
            infor[3] = new char[strlen(infor[1]) + 1];
            strcpy(infor[3],infor[1]);
            
            writeBack(array[i],1,infor,number_of_output);
        }

        delete2Dchar(infor,number_of_output);
    }
}

int numberOfBooksInLibrary(char **array, int number_of_elements){
    int number_of_books = 0;
    
    for(int i = 0; i < number_of_elements; i++){
        int number_of_ele = 0;
        char** infor = parseInfor(array[i],number_of_ele);

        number_of_books += number_of_ele - 4;

        delete2Dchar(infor,number_of_ele);
    }

    return number_of_books;
}

void delete2Dchar(char** deleted_2d_array,int number_of_elements){
    for(int i = 0; i < number_of_elements; i++){
        delete1Dchar(deleted_2d_array[i]);
    }
    delete[]deleted_2d_array;
}

void delete1Dchar(char* deleted_1d_array){
    delete[]deleted_1d_array;
}