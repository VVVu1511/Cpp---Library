#include "general.h"

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

