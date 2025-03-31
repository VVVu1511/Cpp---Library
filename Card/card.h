#pragma once
#include "Helper/helper.h"
#include "General/general.h"


// Chức năng:
// Trả sách của độc giả và cập nhật lại trạng thái sách trong thư viện.

// Input:
// char** array: Mảng chứa thông tin của các độc giả.
// int number_of_elements: Số lượng độc giả.
// char* input: Mã độc giả cần trả sách.
// char** booksInLib: Mảng chứa thông tin của các sách trong thư viện.
// bool* isBookInLib: Mảng trạng thái của sách trong thư viện (true nếu có, false nếu không có).
// int number_of_books_in_lib: Số lượng sách trong thư viện.
// Output:
// Cập nhật thông tin độc giả và trạng thái sách sau khi trả.
void returnCard(char array[][1000],int number_of_elements,char input[],char booksInLib[][1000],bool isBookInLib[],int number_of_books_in_lib);



// Chức năng: Lấy thông tin mượn sách của người đọc, bao gồm mã độc giả, ngày mượn, ngày trả dự kiến và danh sách các sách được mượn.
// Input:
// Mã độc giả, ngày mượn, ngày trả dự kiến và mã ISBN của sách.
// Output:
// Cập nhật lại new_element chứa thông tin thẻ mượn sách. Thay đổi trạng thái sách trong thư viện.
void getInputOfBorrowCard(char new_element[],bool stateOfBooks[],char books_in_lib[][1000],int number_of_books_in_lib);

// Chức năng: Lấy thông tin trả sách từ người đọc, bao gồm mã độc giả và ngày trả sách.
// Input:
// Mã độc giả và ngày trả sách.
// Output:
// Lưu thông tin vào new_element.
void getInputOfReturnCard(char new_element[]);


// Chức năng: Hiển thị các loại thông tin có thể có của thẻ mượn sách.
// Input: Không có.
// Output: In ra các loại thông tin của thẻ mượn sách.
void viewTypeOfInformationOfCard();