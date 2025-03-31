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

int intervalsBetween2Days(char first_date[], char second_date[]){
    int y1, m1, d1;
    int y2, m2, d2;
    
    parseDateCharIntoDayMonthYear(first_date, d1, m1, y1);
    parseDateCharIntoDayMonthYear(second_date, d2, m2, y2);
    
    std::tm time1 = {};
    time1.tm_year = y1 - 1900; 
    time1.tm_mon  = m1 - 1;    
    time1.tm_mday = d1;

    std::tm time2 = {};
    time2.tm_year = y2 - 1900;
    time2.tm_mon  = m2 - 1;
    time2.tm_mday = d2;

    std::time_t t1 = std::mktime(&time1);
    std::time_t t2 = std::mktime(&time2);

    return (t2 - t1) / (60 * 60 * 24);
}

bool isDay1LargerThanDay2(char day1[],char day2[]){
    return intervalsBetween2Days(day2, day1) > 0;
}

void parseDateCharIntoDayMonthYear(char date[],int&day,int&month,int&year){
    sscanf(date, "%d/%d/%d", &day, &month, &year);
}

int convertCharToNum(char input[]){
    int result = 0;
    for(int i = 0; i < strlen(input); i++){
        result = result * 10 + (input[i] - '0');
    }

    return result;
}

