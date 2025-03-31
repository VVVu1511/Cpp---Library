#pragma once
#include "Book/book.h"
#include "Reader/reader.h"
#include "Helper/helper.h"


// Chức năng: Hiển thị danh sách độc giả hoặc sách.
// Input:
// array: mảng chứa thông tin độc giả hoặc sách.
// number_of_elements: số lượng phần tử trong mảng.
// type: loại thông tin cần hiển thị (0 cho độc giả, 1 cho sách).
// Output:
// In ra danh sách thông tin của độc giả hoặc sách.
void viewList(char array[][1000], int number_of_elements, int type);


// Chức năng: Tìm kiếm thông tin trong mảng 2D dựa trên giá trị đầu vào và chỉ mục thông tin.
// Input:
// array: mảng 2D chứa các thông tin.
// number_of_elements: số lượng phần tử trong mảng.
// input: giá trị cần tìm.
// type_of_infor: chỉ mục của thông tin cần tìm.
// Output:
// Trả về chỉ số của phần tử có thông tin phù hợp, nếu không trả về -1.
int findUsingInfor(char infor[][1000], int number_of_elements, char input[], int type_of_infor);


// Chức năng: Thêm một phần tử mới vào mảng.
// Input:
// array: mảng cần thêm phần tử.
// number_of_elements: số lượng phần tử trong mảng.
// new_element: phần tử cần thêm vào mảng.
// Output:
// Mảng array được cập nhật với phần tử mới.
void addOneToArray(char array[][1000], int &number_of_elements, char new_element[]);

// Chức năng: Thay đổi thông tin của độc giả tại một chỉ số nhất định.
// Input:
// readers: mảng chứa thông tin các độc giả.
// ID: chỉ số của độc giả cần thay đổi.
// new_infor: thông tin mới cần thay đổi.
// type_of_infor: loại thông tin cần thay đổi.
// type: loại thông tin.
// Output:
// Cập nhật thông tin của độc giả trong mảng.
void changeInfor(char readers[][1000], int ID, char new_infor[], int type_of_infor,int type);

// Chức năng: Xóa thông tin của độc giả tại một chỉ số nhất định.
// Input:
// readers: mảng chứa thông tin các độc giả.
// ID: chỉ số của độc giả cần xóa.
// type_of_infor: loại thông tin cần xóa.
// type: loại thông tin.
// Output:
// Cập nhật lại thông tin của độc giả sau khi xóa.
void deleteInfor(char infor[][1000], int ID, int type_of_infor,int type);


// Chức năng: Đếm số lượng phần tử của từng loại trong mảng.
// Input:
// array: mảng chứa thông tin.
// types: mảng chứa các loại thông tin.
// number_of_ele_in_array: số lượng phần tử trong mảng.
// number_of_types: số lượng loại thông tin.
// type_of_infor: chỉ mục thông tin cần đếm.
// Output:
// In ra số lượng phần tử cho từng loại thông tin.
void viewNumberOfElementByType(char array[][1000], char types[][1000], int number_of_ele_in_array, int number_of_types,int type_of_infor);

