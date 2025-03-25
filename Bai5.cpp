#include<iostream>
using namespace std;
struct Date {
int day, month, year;
};

// Hàm kiểm tra năm nhuận
// Một năm là năm nhuận nếu chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100
bool NamNhuan(int year) {
return (year%400==0) || (year%4==0 && year%100!=0);
}

// Hàm trả về số ngày của một tháng trong một năm cụ thể
// Nếu là tháng 2 và năm nhuận thì trả về 29 ngày, ngược lại dùng mảng để tra cứu số ngày của tháng đó
int dayinMonth(int month, int year) {
  int D[]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(month==2 && NamNhuan(year)) return 29;
  return D[month -1];
}

// Hàm kiểm tra ngày nhập có hợp lệ hay không
// Điều kiện hợp lệ: tháng phải từ 1-12 và ngày phải nằm trong khoảng cho phép của tháng đó
bool checkDate(Date d) {
   if(d.month<1 || d.month>12) return false;
   if(d.day<1 || d.day>dayinMonth(d.month, d.year)) return false;
   return true;
}

//Hàm tính ngày kế tiếp của một ngày được nhập vào
Date nextDate(Date d) {
    d.day++;   // Tăng ngày lên 1
    if(d.day>dayinMonth(d.month,d.year)) {  // Nếu vượt quá số ngày của tháng hiện tại
        d.day=1;    //Đưa về ngày 1 của tháng kế tiếp
        d.month++;  // Tăng tháng lên 1
    if(d.month>12) {  // Nếu vượt quá tháng 12 thì chuyển sang năm mới
        d.month=1;
        d.year++;
        }
    }
    return d;
}


// Hàm tính ngày trước đó của một ngày được nhập vào
Date preDate(Date d) {
    d.day--;    // Giảm ngày xuống 1
    if(d.day==0) {    // Nếu ngày giảm xuống 0, nghĩa là phải lùi về tháng trước
        d.month--;    // Giảm tháng xuống 1
    if(d.month==0) {   // Nếu tháng giảm xuống 0 thì phải lùi về tháng 12 năm trước
        d.month=12;
        d.year--;
        }
    d.day=dayinMonth(d.month,d.year);   // Lấy ngày cuối cùng của tháng mới
}
return d;
}

//Hàm tính số thứ tự của ngày trong năm
int dayofYear(Date d) {
    int sum=0;
    for(int i=1; i<d.month; i++) {
        sum+=dayinMonth(i, d.year);   // Cộng dồn số ngày của các tháng trước đó
    }
    sum+=d.day;   // Cộng thêm số ngày của tháng hiện tại
    return sum;
}

int main() {
    Date d;
    cout<<"Nhap ngay: "<<endl;
    cin>>d.day;
    cout<<"Nhap thang: "<<endl;
    cin>>d.month;
    cout<<"Nhap nam: "<<endl;
    cin>>d.year;
    if(!checkDate(d)) {
        cout<<"Ngay khong hop le!"<<endl;
    return 1;
    }
Date next= nextDate(d);
cout<<"Ngay ke tiep: "<<next.day<<"/"<<next.month<<"/"<<next.year<<endl;

Date prev=preDate(d);
cout<<"Ngay truoc do: "<<prev.day<<"/"<<prev.month<<"/"<<prev.year<<endl;

cout<<"Ngay "<<d.day<<"/"<<d.month<<"/"<<d.year<<" la ngay thu "<<dayofYear(d)<<" trong nam"<<endl;
return 0;
}
