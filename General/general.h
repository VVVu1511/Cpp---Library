#pragma once
#include "Book/book.h"
#include "Reader/reader.h"
#include "Helper/helper.h"


// Chức năng:
// Hiển thị danh sách array, phân biệt giữa reader và book.

// Input:
// array[][1000]: Mảng chứa thông tin.

// number_of_elements: Số phần tử trong array.

// type: Xác định loại danh sách:

// 0: Hiển thị danh sách độc giả (Reader).

// 1: Hiển thị danh sách sách (Book).

// Output:
// In ra danh sách độc giả hoặc sách.
void viewList(char array[][1000], int number_of_elements, int type);

// Chức năng:
// Tìm kiếm phần tử trong mảng infor dựa trên type_of_infor và giá trị input.

// Input:
// infor[][1000]: Mảng chứa thông tin.

// number_of_elements: Số lượng phần tử trong infor.

// input[]: Giá trị cần tìm.

// type_of_infor: Chỉ mục của thông tin cần so sánh.

// Output:
// Trả về chỉ số (index) của phần tử có giá trị input trong infor.

// Trả về -1 nếu không tìm thấy
int findUsingInfor(char infor[][1000], int number_of_elements, char input[], int type_of_infor);


// Chức năng:
// Thêm một phần tử mới vào mảng array.

// Input:
// array[][1000]: Mảng chứa dữ liệu.

// number_of_elements: Số lượng phần tử hiện tại.

// new_element[]: Chuỗi chứa thông tin phần tử mới.

// Output:
// Thêm new_element vào array.

// Cập nhật number_of_elements.
void addOneToArray(char array[][1000], int &number_of_elements, char new_element[]);


// Chức năng:
// Thay đổi thông tin của một phần tử trong readers tại vị trí ID.

// Input:
// readers[][1000]: Mảng chứa thông tin.

// ID: Chỉ mục của phần tử cần thay đổi.

// new_infor[]: Giá trị mới.

// type_of_infor: Vị trí của thông tin cần thay đổi.

// type: Không sử dụng trong hàm này.

// Output:
// Cập nhật thông tin mới vào readers[ID].
void changeInfor(char readers[][1000], int ID, char new_infor[], int type_of_infor,int type);


// Chức năng:
// Xóa một thông tin cụ thể trong infor tại vị trí ID.

// Input:
// infor[][1000]: Mảng chứa dữ liệu.

// ID: Chỉ mục của phần tử cần chỉnh sửa.

// type_of_infor: Vị trí thông tin cần xóa.

// type: Không sử dụng trong hàm này.

// Output:
// Ghi đè thông tin cần xóa bằng dấu "-".
void deleteInfor(char infor[][1000], int ID, int type_of_infor,int type);



// Chức năng:
// Đếm và hiển thị số lượng phần tử trong array theo từng loại trong types.

// Input:
// array[][1000]: Mảng chứa dữ liệu.

// types[][1000]: Danh sách các loại cần thống kê.

// number_of_ele_in_array: Số lượng phần tử trong array.

// number_of_types: Số lượng loại trong types.

// type_of_infor: Vị trí thông tin cần so sánh.

// Output:
// In ra số lượng phần tử của từng loại.
void viewNumberOfElementByType(char array[][1000], char types[][1000], int number_of_ele_in_array, int number_of_types,int type_of_infor);

