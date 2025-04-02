#pragma once
#include<cstring>
#include<iostream>
#include <ctime>
#include <cstdlib>

// Chức năng:
// Chuyển một chuỗi chứa nhiều thông tin được phân tách bằng dấu , thành một mảng các chuỗi riêng biệt.

// Input:
// information[]: Chuỗi chứa thông tin (các phần cách nhau bởi ,).

// res[][1000]: Mảng chứa các phần tử đã tách ra.

// number_of_ele: Biến tham chiếu để lưu số lượng phần tử sau khi tách.

// Output:
// res sẽ chứa các phần tử đã tách từ information.

// number_of_ele lưu số lượng phần tử tách được.
void parseInfor(char res[][1000], char information[], int& number_of_ele);


// Chức năng:
// Ghi dữ liệu từ một mảng chuỗi (input) vào một chuỗi duy nhất (information), mỗi phần tử cách nhau bằng dấu ,.

// Input:
// information[]: Chuỗi đầu ra.

// type: Không sử dụng trong hàm này.

// input[][1000]: Mảng chuỗi chứa các thông tin cần ghi.

// num_of_input: Số lượng phần tử trong input.

// Output:
// information chứa dữ liệu gộp từ input, cách nhau bằng ,.
void writeBack(char information[], int type, char input[][1000],int num_of_input);


// Chức năng:
// Ghi một chuỗi (infor) vào chuỗi information tại vị trí starting_pos, sau đó thêm dấu ,.

// Input:
// information[]: Chuỗi lưu kết quả.

// infor[]: Chuỗi cần ghi vào information.

// starting_pos: Vị trí bắt đầu ghi trong information.

// Output:
// information chứa infor tại starting_pos, sau đó thêm dấu ,.

// starting_pos được cập nhật cho lần ghi tiếp theo.
void writeOneField(char information[], char infor[], int &starting_pos);


// Chức năng:
// Hiển thị dòng nhắc (line) và nhận dữ liệu nhập vào từ người dùng.

// Input:
// line[]: Chuỗi nhắc người dùng nhập dữ liệu.

// input[]: Chuỗi chứa dữ liệu nhập vào.

// Output:
// input chứa dữ liệu mà người dùng nhập vào.
void prompt(const char line[], char input[]);


// Chức năng:
// So sánh hai ngày, kiểm tra xem day1 có lớn hơn day2 không.

// Input:
// day1[]: Ngày đầu tiên.

// day2[]: Ngày thứ hai.

// Output:
// true nếu day1 lớn hơn day2, false nếu ngược lại.
bool isDay1LargerThanDay2(char day1[],char day2[]);


// Chức năng:
// Tách ngày, tháng, năm từ chuỗi date và lưu vào các biến day, month, year.

// Input:
// date[]: Chuỗi ngày dạng dd/mm/yyyy.

// day, month, year: Biến tham chiếu để lưu ngày, tháng, năm.

// Output:
// day, month, year chứa giá trị tương ứng từ date.


void parseDateCharIntoDayMonthYear(char date[],int&day,int&month,int&year);



// Chức năng:
// Chuyển một chuỗi số (input) thành số nguyên.

// Input:
// input[]: Chuỗi chứa số (ví dụ: "1234").

// Output:
// Trả về số nguyên tương ứng (1234 trong ví dụ trên).
int convertCharToNum(char input[]);


// Chức năng:
// Tính số ngày giữa hai ngày first_date và second_date.

// Input:
// first_date[]: Ngày đầu tiên (dưới dạng chuỗi dd/mm/yyyy).

// second_date[]: Ngày thứ hai (dưới dạng chuỗi dd/mm/yyyy).

// Output:
// Trả về số ngày giữa hai ngày (second_date - first_date).
int intervalsBetween2Days(char first_date[], char second_date[]);





