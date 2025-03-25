#include<iostream>
using namespace std;
struct PhanSo {
    int ts,ms;
};
// Định dạng phân số cho đúng: nếu mẫu số âm, chuyển dấu trừ lên tử số
    void ChuanHoaPS(PhanSo &ps) {
        if(ps.ms<0) {
            ps.ts=-ps.ts;
            ps.ms=-ps.ms;
        }
    }
// Hàm nhập phân số từ bàn phím
    void nhap(PhanSo &ps) {
        cout<<"Nhap tu so: ";
        cin>>ps.ts;
// Kiểm tra nhập mẫu số, không cho phép nhập 0
        do {
            cout<<"Nhap mau so: ";
            cin>>ps.ms;
            if(ps.ms==0)
            cout<<"Nhap lai mau so khac 0:\n";
    } while(ps.ms==0);
    ChuanHoaPS(ps);
    }
    void in(PhanSo ps) {
        cout<<"Phan so da rut gon: "<<endl;
// Kiểm tra các trường hợp đặc biệt khi in phân số
        if(ps.ts==0) cout<<"0"<<endl;
        else if (ps.ms==1) cout<<ps.ts<<endl;
        else cout<<ps.ts<<"/"<<ps.ms<<endl;
    }
// Hàm tìm ước chung lớn nhất (UCLN) của hai số nguyên
int UCLN(int a, int b) {
    int ucln;
    a=a<0 ? -a:a;    // Chuyển số âm thành số dương
    b=b<0 ? -b:b;
    if(a==0 || b==0) {
        ucln=a+b;   // Nếu một trong hai số bằng 0, UCLN là số còn lại
    }
    // Thuật toán trừ liên tiếp để tìm UCLN
    else {
        while(a!=b) {
            if(a>b) a-=b;
            else b-=a;
        }
        if(a==b) ucln=a;  // Khi a == b, đó chính là UCLN
    }
    return ucln;
}
// Hàm rút gọn phân số bằng cách chia tử số và mẫu số cho UCLN của chúng
void RutGon(PhanSo &ps) {
    int ucln=UCLN(ps.ts, ps.ms);
    if(ucln>0) {
    ps.ts/=ucln;
    ps.ms/=ucln;
   }
   ChuanHoaPS(ps);
}
int main() {
    PhanSo ps;
    nhap(ps);
    RutGon(ps);
    in(ps);
    return 0;
}
