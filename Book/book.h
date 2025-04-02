#pragma once
#include "Helper/helper.h"

// Chức năng:
// Hiển thị thông tin của một cuốn sách từ chuỗi information[].

// Gọi parseInfor() để tách dữ liệu.

// In ra màn hình từng trường thông tin.

// Input:
// information[]: Chuỗi chứa thông tin sách.

// Output:
// In thông tin sách ra màn hình.

// Cải thiện:
// Kiểm tra nếu parseInfor() thất bại (trả về số lượng phần tử number = 0).

// Hiển thị thông tin theo định dạng đẹp hơn.
void printInforOfOneBook(char information[]);

// Chức năng:
// Nhận thông tin đầu vào cho một cuốn sách mới.

// Gọi hàm prompt() để nhập dữ liệu cho các trường của sách.

// Ghi dữ liệu vào new_element thông qua writeBack().

// Input:
// new_element[]: Chuỗi lưu thông tin sách.

// Output:
// new_element[] chứa thông tin sách mới.

// Cải thiện:
// Kiểm tra đầu vào (prompt()) để tránh nhập sai dữ liệu (ví dụ: năm xuất bản phải là số, giá sách không âm, v.v.).

// Thêm xác nhận sau khi nhập dữ liệu.
void getInputOfBook(char new_element[]);

// Chức năng:
// Hiển thị danh sách các loại thông tin có trong sách.

// Output:
// In danh sách loại thông tin ra màn hình.
void viewTypeOfInformationOfBook();


// Chức năng:
// Đếm số lượng sách đang được mượn, loại trừ sách bị mất.

// Input:
// stateOfBooks[]: Mảng trạng thái sách (true = có trong thư viện, false = đang được mượn).

// number_of_books: Tổng số sách trong hệ thống.

// studentLosingBook[][1000]: Mảng lưu thông tin sách bị mất.

// Output:
// Trả về số lượng sách đang mượn (không tính sách bị mất).

// Cải thiện:
// Kiểm tra stateOfBooks[i] trước khi truy cập studentLosingBook[i] để tránh lỗi truy cập mảng ngoài phạm vi.

int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books, char studentLosingBook[][1000]);