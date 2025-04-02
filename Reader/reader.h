
#pragma once
#include "Helper/helper.h"
#include "General/general.h"

// Chức năng:
// Nhận thông tin của một độc giả mới từ người dùng.

// Input:
// new_element[]: Chuỗi chứa thông tin độc giả mới.

// Output:
// Ghi thông tin người dùng nhập vào new_element[].
void getInputOfReader(char new_element[]);

// Chức năng:
// In thông tin chi tiết của một độc giả.

// Input:
// information[]: Chuỗi chứa thông tin của một độc giả.

// Output:
// In các thông tin của độc giả như mã độc giả, họ tên, số CMND, ngày sinh, giới tính, email, địa chỉ, ngày cấp thẻ, ngày hết hạn.
void printInforOfOneReader(char information[]);

// Chức năng:
// Hiển thị danh sách các loại thông tin có trong hồ sơ độc giả.

// Input:
// Không có.

// Output:
// In ra danh sách các trường thông tin như mã độc giả, họ tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn.
void viewTypeOfInformationOfReader();

// Chức năng:
// Liệt kê danh sách các sinh viên đang mượn sách quá hạn.

// Input:
// array[][1000]: Danh sách thẻ mượn sách.

// number_of_elements: Số lượng thẻ mượn.

// today[]: Ngày hiện tại.

// Output:
// In ra mã sinh viên của những người trả sách trễ.

// Nếu không có ai trễ hạn, in "No readers are late!".

void viewReadersLate(char array[][1000], int number_of_elements,char today[]);


// Chức năng:
// Tính tiền phạt của một sinh viên dựa trên số ngày trả sách trễ và sách bị mất.

// Input:
// MSSV[]: Mã số sinh viên cần tính tiền phạt.

// cards[][1000]: Danh sách các thẻ mượn sách (gồm thông tin về sinh viên mượn và ngày trả).

// number_of_cards: Số lượng thẻ mượn sách.

// current_date[]: Ngày hiện tại.

// studentLosingBook[][1000]: Danh sách sinh viên làm mất sách.

// num_of_books: Số lượng sách bị mất.

// books[][1000]: Danh sách thông tin về sách.

// Output:
// In ra số tiền phạt của sinh viên có mã MSSV.
void viewFine(const char MSSV[], char cards[][1000], int number_of_cards, char current_date[],char studentLosingBook[][1000], const int &num_of_books, char books[][1000]);


// Chức năng:
// Ghi nhận việc sinh viên làm mất sách và cập nhật danh sách.

// Input:
// ISBN[]: Mã ISBN của sách bị mất.

// MSSV[]: Mã số sinh viên làm mất sách.

// studentLosingBook[][1000]: Danh sách sinh viên làm mất sách.

// num_of_books: Số lượng sách bị mất (tham chiếu để cập nhật).

// books[][1000]: Danh sách thông tin sách.

// isBookInLib[]: Mảng đánh dấu sách còn trong thư viện hay không.

// Output:
// Cập nhật danh sách sinh viên làm mất sách.
void notifyLosingBook(char ISBN[],const char MSSV[], char studentLosingBook[][1000], int &num_of_books, char books[][1000], bool isBookInLib[]);