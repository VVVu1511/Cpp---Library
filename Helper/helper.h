#pragma once
#include<cstring>
#include<iostream>



// Chức năng: Phân tách thông tin từ một chuỗi thông qua dấu phân cách (,) và lưu các phần tử vào mảng con.
// Input:
// information: chuỗi thông tin cần phân tách.
// number_of_ele: biến để lưu số lượng phần tử được phân tách.
// Output:
// Trả về mảng con chứa các thông tin đã phân tách
void parseInfor(char res[][1000], char information[], int& number_of_ele);


// Chức năng: Ghi lại thông tin vào một chuỗi.
// Input:
// information: chuỗi thông tin cần ghi lại.
// type: loại thông tin.
// input: mảng 2D chứa các thông tin.
// num_of_input: số lượng phần tử trong mảng.
// Output:
// Cập nhật lại chuỗi information.
void writeBack(char information[], int type, char input[][1000],int num_of_input);


// Chức năng: Ghi một trường thông tin vào chuỗi information.
// Input:
// information: chuỗi thông tin.
// infor: trường thông tin cần ghi.
// starting_pos: vị trí bắt đầu để ghi thông tin.
// Output:
// Cập nhật chuỗi information với trường thông tin mới.
void writeOneField(char information[], char infor[], int &starting_pos);

// Chức năng: Hiển thị thông báo và nhận đầu vào từ người dùng.
// Input:
// line: thông báo yêu cầu người dùng nhập thông tin.
// input: mảng chứa chuỗi kết quả đầu vào.
// Output:
// Lưu đầu vào người dùng vào input.
void prompt(const char line[], char input[]);


// Chức năng:
// So sánh hai ngày, trả về true nếu ngày 1 lớn hơn ngày 2.

// Input:
// char* day1: Ngày đầu tiên.
// char* day2: Ngày thứ hai.
// Output:
// Trả về true nếu ngày 1 lớn hơn ngày 2, false nếu ngược lại.
bool isDay1LargerThanDay2(char day1[],char day2[]);



// Chức năng:
// Phân tách ngày, tháng, năm từ chuỗi ngày có định dạng DD/MM/YYYY.

// Input:
// char* date: Chuỗi ngày cần phân tách.
// int& day: Ngày (được gán giá trị sau khi phân tách).
// int& month: Tháng (được gán giá trị sau khi phân tách).
// int& year: Năm (được gán giá trị sau khi phân tách).
// Output:
// Gán giá trị ngày, tháng, năm sau khi phân tách từ chuỗi ngày.
void parseDateCharIntoDayMonthYear(char date[],int&day,int&month,int&year);


// Chức năng:
// Chuyển chuỗi ký tự thành số nguyên.

// Input:
// char* input: Chuỗi ký tự cần chuyển đổi thành số.
// Output:
// Trả về số nguyên tương ứng với chuỗi ký tự.
int convertCharToNum(char input[]);



