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

int findUsingInfor(char **array, int number_of_elements, char *input, int type_of_infor){
    
    for(int i = 0; i < number_of_elements; i++){
        int num = 0;
        char** infor = parseInfor(array[i],num);
        
        if(strcmp(infor[type_of_infor],input) == 0){
            return i;
        }

        delete2Dchar(infor,num);
    }

    return -1;
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

void viewTypeOfInformationOfBook(){
    std::cout << "0. ISBN" << "\n"
              << "1. Ten sach" << "\n"
              << "2. Ten tac gia" << "\n"
              << "3. Nha xuat ban" << "\n"
              << "4. Nam xuat ban" << "\n"
              << "5. The loai" << "\n"
              << "6. Gia" << "\n";
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

int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books){
    int result = 0;

    for(int i = 0; i < number_of_books; i++){
        if(stateOfBooks[i] == false) result++;
    }

    return result;
}

void delete2Dchar(char** deleted_2d_array,int number_of_elements){
    for(int i = 0; i < number_of_elements; i++){
        delete1Dchar(deleted_2d_array[i]);
    }
    
    if(number_of_elements > 0) delete[]deleted_2d_array;
}

void delete1Dchar(char* deleted_1d_array){
    delete[]deleted_1d_array;
}

bool isDay1LargerThanDay2(char* day1,char* day2){
    int y1;
    int m1;
    int d1;
    int y2;
    int m2;
    int d2;
    parseDateCharIntoDayMonthYear(day1,d1,m1,y1);
    parseDateCharIntoDayMonthYear(day2,d2,m2,y2);
    
    if(y1 > y2) return true;
    else if(y1 < y2) return false;

    if(m1 > m2) return true;
    else if(m1 < m2) return false;

    if(d1 > d2) return true;
    else if(d1 < d2) return false;

    return false;
}

void parseDateCharIntoDayMonthYear(char* date,int&day,int&month,int&year){
    char temp[MAX_INFOR_LENGTH];
    resetTemporaryInfor(temp,MAX_INFOR_LENGTH);

    int first_slash = findXpositionOfSpecificCharInCharArray(date,'/',1);
    int second_slash = findXpositionOfSpecificCharInCharArray(date,'/',2);;
    
    char* day_char = subChar(date,0,first_slash);
    char* month_char = subChar(date,first_slash + 1,second_slash);
    char* year_char = subChar(date,second_slash + 1,strlen(date));

    day = convertCharToNum(day_char);
    month = convertCharToNum(month_char);
    year = convertCharToNum(year_char);
    

    delete1Dchar(day_char);
    delete1Dchar(month_char);
    delete1Dchar(year_char);
}

int convertCharToNum(char *input){
    int result = 0;
    for(int i = 0; i < strlen(input); i++){
        result = result * 10 + (input[i] - '0');
    }

    return result;
}

char *subChar(char *input, int start, int end){
    char *result = new char[end - start + 1];
    
    for(int i = start; i < end; i++){
        result[i - start] = input[i];
    }

    result[end - start] = '\0';

    return result;
}

int findXpositionOfSpecificCharInCharArray(char* input,char specific_char,int X){
    int cnt = 0;

    for(int i = 0; i < strlen(input); i++){
        if(input[i] == specific_char){
            cnt++;
        }
        if(cnt == X){ return i;}
    }

    return -1;
}