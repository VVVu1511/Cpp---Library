
#include "helper.h"

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