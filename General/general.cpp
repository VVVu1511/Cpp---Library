#include "general.h"

int findUsingInfor(char infor[][1000], int number_of_elements, char input[], int type_of_infor){
    
    for(int i = 0; i < number_of_elements; i++){
        int num = 0;
        char res[100][1000];
        parseInfor(res,infor[i],num);
        
        if(strcmp(res[type_of_infor],input) == 0){
            return i;
        }
    }

    return -1;
}

void viewList(char array[][1000], int number_of_elements, int type){
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

void addOneToArray(char array[][1000], int &number_of_elements, char new_element[]){
    strcpy(array[number_of_elements], new_element);
    
    number_of_elements++;
}

void changeInfor(char readers[][1000], int ID, char new_infor[], int type_of_infor,int type){    
    int number_of_elements = 0;
    char res[100][1000];

    parseInfor(res,readers[ID],number_of_elements);

    strcpy(res[type_of_infor],new_infor);
    
    writeBack(readers[ID],type,res,number_of_elements);
}

void deleteInfor(char infor[][1000], int ID, int type_of_infor,int type){
    int number_of_elements = 0;
    char res[100][1000];
    parseInfor(res,infor[ID],number_of_elements);
        
    strcpy(res[type_of_infor],"-");

    writeBack(infor[ID],type,res,number_of_elements);   
}


void viewNumberOfElementByType(char array[][1000], char types[][1000], int number_of_ele_in_array, int number_of_types,int type_of_infor){
    int number_of_each_type[number_of_types];
    for(int i = 0; i < number_of_types; i++){
        number_of_each_type[i] = 0;
    }

    for(int i = 0; i < number_of_ele_in_array; i++){
        int number_of_elements;
        char infor[100][1000];
        parseInfor(infor,array[i],number_of_elements);

        for(int j = 0; j < number_of_types; j++){
            if(strcmp(infor[type_of_infor],types[j]) == 0){
                number_of_each_type[j]++;
                break;
            }
        }
    }

    for(int i = 0; i < number_of_types; i++){
        std::cout << types[i] << ": " << number_of_each_type[i] << "\n";
    }
}

