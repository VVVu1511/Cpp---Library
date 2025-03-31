
#pragma once
#include "Helper/helper.h"

// Chức năng: Lấy thông tin của độc giả, bao gồm mã độc giả, họ tên, chứng minh nhân dân, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn.
// Input:
// Người dùng nhập các thông tin độc giả qua console.
// Output:
// Lưu lại thông tin vào new_element.
void getInputOfReader(char new_element[]);


// Chức năng: In thông tin chi tiết của một độc giả, bao gồm mã độc giả, họ tên, chứng minh nhân dân, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn.
// Input:
// information: chuỗi thông tin của một độc giả.
// Output:
// In ra console các thông tin chi tiết của độc giả.
void printInforOfOneReader(char information[]);

// Chức năng: Hiển thị các loại thông tin có thể có của độc giả.
// Input: Không có.
// Output: In ra các loại thông tin của độc giả.
void viewTypeOfInformationOfReader();


// Chức năng:
// Hàm viewReadersLate kiểm tra và in ra mã độc giả của những người chưa trả sách đúng hạn, hoặc thông báo nếu không có độc giả nào muộn.

// Input:
// char **array: Mảng chứa thông tin của các độc giả.
// int number_of_elements: Số lượng độc giả.
// char *today: Ngày hiện tại.
// Output:
// In ra mã độc giả của những người muộn.
// Nếu không có ai muộn, in: No readers are late!.

void viewReadersLate(char array[][1000], int number_of_elements,char today[]);

void viewFine(const char* MSSV);