#pragma once
#include<iostream>
#include<cstring>

#define MAX_INFOR_LENGTH 1000

//ok

//chức năng: chia một chuỗi char dài thành mảng 2 chiều gồm nhiều chuỗi char nhỏ, mỗi phần tử cách nhau dấu phẩy
//input example: Vu Van Vu,23CLC3,1/1/2005,
//output example: {{V','u',' ','V','a','n',' ','V','u'},{'2','3','C','L','C','3'},{'1','/','1','/','2','0','0','5'}}

char** parseInfor(char *information, int& number_of_ele);

//chức năng: reset các kí tự trong chuỗi arr[] thành '\0'
void resetTemporaryInfor(char arr[],int length);

//chức năng: in ra các thông tin cơ bản của 1 đọc giả.
void printInforOfOneReader(char* information);

//chức năng: in ra thông tin của các đọc giả, hoặc các quyển sách trong thư viện
//type = 0 -> đọc giả
//type = 1 -> thư viện
void viewList(char **array, int number_of_elements, int type);

//chức năng: in ra các thông tin cơ bản của 1 cuốn sách.
void printInforOfOneBook(char* information);

//chức năng: viết lại các thông tin trong mảng 2 chiều input vào information.
//input: + input: {{V','u',' ','V','a','n',' ','V','u'},{'2','3','C','L','C','3'},{'1','/','1','/','2','0','0','5'}}
        //+ information: phần tử cần được viết
        //+type: 0 -> đọc giả, 1 -> sách
        //+ num_of_input: 3
//output: Vu Van Vu,23CLC3,1/1/2005,
void writeBack(char *&information, int type, char **input,int num_of_input);


//chức năng: hỗ trợ writeBack, viết 1 vùng của information
void writeOneField(char *&information, char *infor, int &starting_pos);

//chức năng: lấy dữ liệu nhập vào.
void prompt(const char line[], char *input);

//chức năng: tìm kiếm dùng thông tin gì đó.
int findUsingInfor(char** array,int number_of_elements,char* input,int type_of_infor);

//chức năng: lấy dữ liệu nhập vào cho 1 đọc giả
void getInputOfReader(char *&new_element);

//chức năng: lấy dữ liệu nhập vào cho 1 cuốn sách
void getInputOfBook(char* &new_element);

//chức năng: lấy dữ liệu nhập vào cho 1 thẻ mượn
void getInputOfBorrowCard(char* &new_element,bool stateOfBooks[],char** books_in_lib,int number_of_books_in_lib);

//chức năng: lấy dữ liệu nhập vào cho 1 thẻ trả
void getInputOfReturnCard(char* &new_element);


//chức năng: thêm 1 phần tử vào mảng
void addOneToArray(char **&array, int &number_of_elements, char *new_element);

//chức năng: thay đổi 1 thông tin của 1 phần tử trong mảng 2 chiều
void changeInfor(char** &readers,int ID, char* new_infor,int type_of_infor,int type);

//chức năng: xóa 1 thông tin của 1 phần tử trong mảng 2 chiều
void deleteInfor(char** &readers,int ID,int type_of_infor,int type);
//chức năng: các thông tin cơ bản của 1 đọc giả
void viewTypeOfInformationOfReader();

//chức năng: các thông tin cơ bản của 1 cuốn sách
void viewTypeOfInformationOfBook();

//chức năng: các thông tin cơ bản của 1 thẻ mượn / trả
void viewTypeOfInformationOfCard();

//chức năng: xem số lượng 1 phần tử của một mảng
void viewNumberOfElementByType(char** array, char** types,int number_of_ele_in_array,int number_of_types,int type_of_infor);

//chức năng: xem mã số các đọc giả trả sách trễ hạn
void viewReadersLate(char **array,int number_of_elements,char* today);

//chức năng: trả lại thẻ
void returnCard(char** array,int number_of_elements,char* input,char** booksInLib,bool isBookInLib[],int number_of_books_in_lib);

//chức năng: trả về số lượng sách trong thư viện.
int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books);

//chức năng: giải phóng vùng nhớ cho mảng 2 chiều chuỗi kí tự 
void delete2Dchar(char** deleted_2d_array,int number_of_elements);

//chức năng: giải phóng vùng nhớ cho mảng 1 chiều chuỗi kí tự
void delete1Dchar(char* deleted_1d_array);

//chức năng: tìm khoảng cách giữa 2 ngày
bool isDay1LargerThanDay2(char* day1,char* day2);

//phân chuỗi kí tự date thành ngày tháng năm
//input: date = {'1','/','1','/','2','0','0','0','\0'}, day,month,year
//output: day = 1, month = 1, year = 2000
void parseDateCharIntoDayMonthYear(char* date,int&day,int&month,int&year);

//chuyển 1 chuỗi kí tự gồm các kí tự số thành một số nguyên
//input: input = {'1','2','3','\0'}
//output: 123
int convertCharToNum(char *input);

//lấy chuỗi kí tự từ start tới end - 1 trong input
//input: date = {'1','/','1','/','2','0','0','0','\0'}, start = 0,end = 5
//output:  date = {'1','/','1','/','2','\0'}
char* subChar(char* input,int start,int end);

//tìm vị trí xuất hiện lần thứ X của kí tự specific_char trong chuỗi kí tự input
int findXpositionOfSpecificCharInCharArray(char* input,char specific_char,int X);


