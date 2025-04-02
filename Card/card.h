#pragma once
#include "Helper/helper.h"
#include "General/general.h"

// Chức năng:
// Xử lý việc trả sách từ một thẻ mượn (input).

// Cập nhật lại trạng thái của sách trong thư viện (isBookInLib).

// Cập nhật ngày trả thực tế của sách trong thẻ mượn.

// Input:
// array[][1000]: Mảng chứa danh sách thẻ mượn.

// number_of_elements: Số lượng thẻ mượn.

// input[]: Dữ liệu đầu vào của thẻ mượn chứa danh sách sách trả.

// booksInLib[][1000]: Mảng chứa thông tin sách trong thư viện.

// isBookInLib[]: Mảng trạng thái của sách (true = có trong thư viện, false = đang được mượn).

// number_of_books_in_lib: Số lượng sách trong thư viện.

// Output:
// Cập nhật trạng thái isBookInLib[] để đánh dấu sách đã được trả.

// Cập nhật ngày trả thực tế (card_infor[k + 1]) cho từng sách trong thẻ mượn.
void returnCard(char array[][1000],int number_of_elements,char input[],char booksInLib[][1000],bool isBookInLib[],int &number_of_books_in_lib);


// Chức năng:
// Nhận đầu vào cho một thẻ mượn mới.

// Đánh dấu các sách đã mượn trong stateOfBooks[] (false = đã được mượn).

// Giảm số lượng sách có sẵn trong thư viện (number_of_books_in_lib).

// Input:
// new_element[]: Chuỗi chứa thông tin của thẻ mượn mới.

// stateOfBooks[]: Mảng trạng thái sách trong thư viện.

// books_in_lib[][1000]: Danh sách sách trong thư viện.

// number_of_books_in_lib: Số lượng sách trong thư viện.

// Output:
// Ghi thông tin mới vào new_element.

// Cập nhật trạng thái stateOfBooks[] và giảm số lượng sách thư viện.
void getInputOfBorrowCard(char new_element[],bool stateOfBooks[],char books_in_lib[][1000],int &number_of_books_in_lib);



// Chức năng:
// Nhận đầu vào cho một giao dịch trả sách.

// Input:
// new_element[]: Chuỗi chứa thông tin trả sách.

// Output:
// Ghi thông tin trả sách vào new_element.

void getInputOfReturnCard(char new_element[]);

// Chức năng:
// Hiển thị danh sách các trường thông tin của một thẻ mượn.

// Output:
// In ra màn hình danh sách thông tin như mã độc giả, ngày mượn, ngày trả dự kiến, ngày trả thực tế, danh sách ISBN, tiền phạt, tình trạng thẻ.
void viewTypeOfInformationOfCard();