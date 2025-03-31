#include "helper.h"

void parseInfor(char res[][1000], char information[], int& number_of_ele){
    number_of_ele = 0; 
    char temp[1000]; 
    strcpy(temp, information);

    char* temp2 = strtok(temp, ",");
    while (temp2 != nullptr) {
        strcpy(res[number_of_ele], temp2);
        number_of_ele++; 
        temp2 = strtok(nullptr, ",");
    }
}

void writeBack(char information[], int type, char input[][1000],int num_of_input){
    int position = 0;
    
    for(int i = 0; i < num_of_input; i++){
        writeOneField(information,input[i],position);
    }
    
    information[position] = '\0';
}

void writeOneField(char information[], char infor[], int &starting_pos){
    for(int i = starting_pos; i < starting_pos + strlen(infor); i++){
        information[i] = infor[i - starting_pos];
    }
    information[starting_pos + strlen(infor)] = ',';
    
    starting_pos += strlen(infor) + 1;
}

void prompt(const char line[], char input[]){
    std::cout << line;
    std::cin.getline(input,1000);
}

bool isDay1LargerThanDay2(char day1[],char day2[]){
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

void parseDateCharIntoDayMonthYear(char date[],int&day,int&month,int&year){
    char temp[1000];
    
    char temp[50], day_char[1000], month_char[1000],year_char[1000];
    strcpy(temp, date);

    char* token = strtok(temp, "/");
    if (token) strcpy(day_char, token);

    token = strtok(nullptr, "/");
    if (token) strcpy(month_char, token);

    token = strtok(nullptr, "/");
    if (token) strcpy(year_char, token);

    day = convertCharToNum(day_char);
    month = convertCharToNum(month_char);
    year = convertCharToNum(year_char);
    
}

int convertCharToNum(char input[]){
    int result = 0;
    for(int i = 0; i < strlen(input); i++){
        result = result * 10 + (input[i] - '0');
    }

    return result;
}

