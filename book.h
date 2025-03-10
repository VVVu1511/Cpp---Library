#pragma once
#include "helper.h"

// Chức năng: In thông tin chi tiết của một cuốn sách, bao gồm mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại và giá.
// Input:
// information: chuỗi thông tin của cuốn sách.
// Output:
// In ra console các thông tin chi tiết của sách.
void printInforOfOneBook(char* information);


// Chức năng: Lấy thông tin sách từ người dùng, bao gồm Ma ISBN, tên sách, tên tác giả, nhà xuất bản, năm xuất bản, thể loại và giá tiền.
// Input:
// Người dùng nhập các thông tin sách qua console.
// Output:
// Lưu lại các thông tin sách vào new_element theo định dạng chuỗi.
void getInputOfBook(char* &new_element);


// Chức năng: Hiển thị các loại thông tin có thể có của sách.
// Input: Không có.
// Output: In ra các loại thông tin của sách
void viewTypeOfInformationOfBook();


// Chức năng:
// Đếm số sách hiện đang được mượn trong thư viện.

// Input:
// bool* stateOfBooks: Mảng trạng thái của các sách trong thư viện (false nếu sách đang được mượn).
// int number_of_books: Tổng số sách trong thư viện.
// Output:
// Trả về số lượng sách đang được mượn
int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books);