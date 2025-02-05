#pragma once
#include<iostream>
#include<cstring>

#define MAX_INFOR_LENGTH 1000


// Chức năng: Phân tách thông tin từ một chuỗi thông qua dấu phân cách (,) và lưu các phần tử vào mảng con.
// Input:
// information: chuỗi thông tin cần phân tách.
// number_of_ele: biến để lưu số lượng phần tử được phân tách.
// Output:
// Trả về mảng con chứa các thông tin đã phân tách
char** parseInfor(char *information, int& number_of_ele);



// Chức năng: Xóa sạch thông tin tạm thời trong một mảng.
// Input:
// arr: mảng chứa thông tin cần xóa.
// length: độ dài của mảng.
// Output: Không có giá trị trả về (chỉ thay đổi mảng).
void resetTemporaryInfor(char arr[],int length);



// Chức năng: In thông tin chi tiết của một độc giả, bao gồm mã độc giả, họ tên, chứng minh nhân dân, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn.
// Input:
// information: chuỗi thông tin của một độc giả.
// Output:
// In ra console các thông tin chi tiết của độc giả.
void printInforOfOneReader(char* information);



// Chức năng: Hiển thị danh sách độc giả hoặc sách.
// Input:
// array: mảng chứa thông tin độc giả hoặc sách.
// number_of_elements: số lượng phần tử trong mảng.
// type: loại thông tin cần hiển thị (0 cho độc giả, 1 cho sách).
// Output:
// In ra danh sách thông tin của độc giả hoặc sách.
void viewList(char **array, int number_of_elements, int type);




// Chức năng: In thông tin chi tiết của một cuốn sách, bao gồm mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại và giá.
// Input:
// information: chuỗi thông tin của cuốn sách.
// Output:
// In ra console các thông tin chi tiết của sách.
void printInforOfOneBook(char* information);

// Chức năng: Ghi lại thông tin vào một chuỗi.
// Input:
// information: chuỗi thông tin cần ghi lại.
// type: loại thông tin.
// input: mảng 2D chứa các thông tin.
// num_of_input: số lượng phần tử trong mảng.
// Output:
// Cập nhật lại chuỗi information.
void writeBack(char *&information, int type, char **input,int num_of_input);




// Chức năng: Ghi một trường thông tin vào chuỗi information.
// Input:
// information: chuỗi thông tin.
// infor: trường thông tin cần ghi.
// starting_pos: vị trí bắt đầu để ghi thông tin.
// Output:
// Cập nhật chuỗi information với trường thông tin mới.
void writeOneField(char *&information, char *infor, int &starting_pos);

// Chức năng: Hiển thị thông báo và nhận đầu vào từ người dùng.
// Input:
// line: thông báo yêu cầu người dùng nhập thông tin.
// input: mảng chứa chuỗi kết quả đầu vào.
// Output:
// Lưu đầu vào người dùng vào input.
void prompt(const char line[], char *input);

// Chức năng: Tìm kiếm thông tin trong mảng 2D dựa trên giá trị đầu vào và chỉ mục thông tin.
// Input:
// array: mảng 2D chứa các thông tin.
// number_of_elements: số lượng phần tử trong mảng.
// input: giá trị cần tìm.
// type_of_infor: chỉ mục của thông tin cần tìm.
// Output:
// Trả về chỉ số của phần tử có thông tin phù hợp, nếu không trả về -1.
int findUsingInfor(char** array,int number_of_elements,char* input,int type_of_infor);

// Chức năng: Lấy thông tin của độc giả, bao gồm mã độc giả, họ tên, chứng minh nhân dân, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn.
// Input:
// Người dùng nhập các thông tin độc giả qua console.
// Output:
// Lưu lại thông tin vào new_element.
void getInputOfReader(char *&new_element);

// Chức năng: Lấy thông tin sách từ người dùng, bao gồm Ma ISBN, tên sách, tên tác giả, nhà xuất bản, năm xuất bản, thể loại và giá tiền.
// Input:
// Người dùng nhập các thông tin sách qua console.
// Output:
// Lưu lại các thông tin sách vào new_element theo định dạng chuỗi.
void getInputOfBook(char* &new_element);

// Chức năng: Lấy thông tin mượn sách của người đọc, bao gồm mã độc giả, ngày mượn, ngày trả dự kiến và danh sách các sách được mượn.
// Input:
// Mã độc giả, ngày mượn, ngày trả dự kiến và mã ISBN của sách.
// Output:
// Cập nhật lại new_element chứa thông tin thẻ mượn sách. Thay đổi trạng thái sách trong thư viện.
void getInputOfBorrowCard(char* &new_element,bool stateOfBooks[],char** books_in_lib,int number_of_books_in_lib);

// Chức năng: Lấy thông tin trả sách từ người đọc, bao gồm mã độc giả và ngày trả sách.
// Input:
// Mã độc giả và ngày trả sách.
// Output:
// Lưu thông tin vào new_element.
void getInputOfReturnCard(char* &new_element);


// Chức năng: Thêm một phần tử mới vào mảng.
// Input:
// array: mảng cần thêm phần tử.
// number_of_elements: số lượng phần tử trong mảng.
// new_element: phần tử cần thêm vào mảng.
// Output:
// Mảng array được cập nhật với phần tử mới.
void addOneToArray(char **&array, int &number_of_elements, char *new_element);

// Chức năng: Thay đổi thông tin của độc giả tại một chỉ số nhất định.
// Input:
// readers: mảng chứa thông tin các độc giả.
// ID: chỉ số của độc giả cần thay đổi.
// new_infor: thông tin mới cần thay đổi.
// type_of_infor: loại thông tin cần thay đổi.
// type: loại thông tin.
// Output:
// Cập nhật thông tin của độc giả trong mảng.
void changeInfor(char** &readers,int ID, char* new_infor,int type_of_infor,int type);

// Chức năng: Xóa thông tin của độc giả tại một chỉ số nhất định.
// Input:
// readers: mảng chứa thông tin các độc giả.
// ID: chỉ số của độc giả cần xóa.
// type_of_infor: loại thông tin cần xóa.
// type: loại thông tin.
// Output:
// Cập nhật lại thông tin của độc giả sau khi xóa.
void deleteInfor(char** &readers,int ID,int type_of_infor,int type);



// Chức năng: Hiển thị các loại thông tin có thể có của độc giả.
// Input: Không có.
// Output: In ra các loại thông tin của độc giả.
void viewTypeOfInformationOfReader();

// Chức năng: Hiển thị các loại thông tin có thể có của sách.
// Input: Không có.
// Output: In ra các loại thông tin của sách
void viewTypeOfInformationOfBook();

// Chức năng: Hiển thị các loại thông tin có thể có của thẻ mượn sách.
// Input: Không có.
// Output: In ra các loại thông tin của thẻ mượn sách.
void viewTypeOfInformationOfCard();

// Chức năng: Đếm số lượng phần tử của từng loại trong mảng.
// Input:
// array: mảng chứa thông tin.
// types: mảng chứa các loại thông tin.
// number_of_ele_in_array: số lượng phần tử trong mảng.
// number_of_types: số lượng loại thông tin.
// type_of_infor: chỉ mục thông tin cần đếm.
// Output:
// In ra số lượng phần tử cho từng loại thông tin.
void viewNumberOfElementByType(char** array, char** types,int number_of_ele_in_array,int number_of_types,int type_of_infor);



// Chức năng:
// Hàm viewReadersLate kiểm tra và in ra mã độc giả của những người chưa trả sách đúng hạn, hoặc thông báo nếu không có độc giả nào muộn.

// Input:
// char **array: Mảng chứa thông tin của các độc giả.
// int number_of_elements: Số lượng độc giả.
// char *today: Ngày hiện tại.
// Output:
// In ra mã độc giả của những người muộn.
// Nếu không có ai muộn, in: No readers are late!.
void viewReadersLate(char **array,int number_of_elements,char* today);


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
void returnCard(char** array,int number_of_elements,char* input,char** booksInLib,bool isBookInLib[],int number_of_books_in_lib);


// Chức năng:
// Đếm số sách hiện đang được mượn trong thư viện.

// Input:
// bool* stateOfBooks: Mảng trạng thái của các sách trong thư viện (false nếu sách đang được mượn).
// int number_of_books: Tổng số sách trong thư viện.
// Output:
// Trả về số lượng sách đang được mượn
int numberOfBooksBeingBorrowed(bool stateOfBooks[],int number_of_books);



// Chức năng:
// Giải phóng bộ nhớ của mảng 2 chiều chứa chuỗi ký tự.

// Input:
// char** deleted_2d_array: Mảng 2 chiều chứa chuỗi ký tự cần giải phóng.
// int number_of_elements: Số lượng phần tử trong mảng 2 chiều.
// Output:
// Giải phóng bộ nhớ của mảng 2 chiều.
void delete2Dchar(char** deleted_2d_array,int number_of_elements);



// Chức năng:
// Giải phóng bộ nhớ của mảng 1 chiều chứa chuỗi ký tự.

// Input:
// char* deleted_1d_array: Mảng 1 chiều chứa chuỗi ký tự cần giải phóng.
// Output:
// Giải phóng bộ nhớ của mảng 1 chiều
void delete1Dchar(char* deleted_1d_array);



// Chức năng:
// So sánh hai ngày, trả về true nếu ngày 1 lớn hơn ngày 2.

// Input:
// char* day1: Ngày đầu tiên.
// char* day2: Ngày thứ hai.
// Output:
// Trả về true nếu ngày 1 lớn hơn ngày 2, false nếu ngược lại.
bool isDay1LargerThanDay2(char* day1,char* day2);



// Chức năng:
// Phân tách ngày, tháng, năm từ chuỗi ngày có định dạng DD/MM/YYYY.

// Input:
// char* date: Chuỗi ngày cần phân tách.
// int& day: Ngày (được gán giá trị sau khi phân tách).
// int& month: Tháng (được gán giá trị sau khi phân tách).
// int& year: Năm (được gán giá trị sau khi phân tách).
// Output:
// Gán giá trị ngày, tháng, năm sau khi phân tách từ chuỗi ngày.
void parseDateCharIntoDayMonthYear(char* date,int&day,int&month,int&year);




// Chức năng:
// Chuyển chuỗi ký tự thành số nguyên.

// Input:
// char* input: Chuỗi ký tự cần chuyển đổi thành số.
// Output:
// Trả về số nguyên tương ứng với chuỗi ký tự.
int convertCharToNum(char *input);



// Chức năng:
// Trích xuất một phần chuỗi con từ chuỗi ban đầu.

// Input:
// char* input: Chuỗi ký tự gốc.
// int start: Vị trí bắt đầu của chuỗi con.
// int end: Vị trí kết thúc của chuỗi con.
// Output:
// Trả về chuỗi con đã được trích xuất từ chuỗi ban đầu
char* subChar(char* input,int start,int end);




// Chức năng:
// Tìm vị trí của ký tự xuất hiện lần thứ X trong chuỗi.

// Input:
// char* input: Chuỗi ký tự.
// char specific_char: Ký tự cần tìm.
// int X: Lần xuất hiện thứ X của ký tự cần tìm.
// Output:
// Trả về vị trí của ký tự xuất hiện lần thứ X trong chuỗi.
int findXpositionOfSpecificCharInCharArray(char* input,char specific_char,int X);


