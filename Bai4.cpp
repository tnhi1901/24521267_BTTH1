#include <iostream>
#include <cmath>
using namespace std;
int main() {
double a = 0, b, x, s=1;
unsigned long long n = 0;
 cout << "Nhap x (rad) de tinh sin(x): ";
 cin >> x;
// Kiểm tra lỗi nhập liệu
 while (cin.fail()) {
 cin.clear(); // Xóa trạng thái lỗi
 cin.ignore(1000, '\n'); // Bỏ qua dữ liệu không hợp lệ
 cout << "Loi nhap! Vui long nhap lai x (so thuc): ";
 cin >> x;
    }
 x=fmod(x,2*M_PI);
 do
 {
     b = a;
     a += pow(-1, n) * pow(x, 2*n + 1) / s;
     n++;
     s*= (2*n + 1) * (2*n);
 }
 while (abs(a - b) >= 0.00001);
 cout<<a;
 return 0;
}
