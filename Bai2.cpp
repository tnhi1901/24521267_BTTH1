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
// Toán tử nhập (>>): Cho phép nhập phân số từ bàn phím
    istream& operator>>(istream& is, PhanSo &ps) {
    cout<<"Nhap tu so: "<<endl;
    is>>ps.ts;
    do {
        cout<<"Nhap mau so khac 0: "<<endl;
        is>>ps.ms;
    } while(ps.ms==0);
    ChuanHoaPS(ps);
    return is;
    }
// Toán tử xuất (<<): In phân số ra màn hình
    ostream& operator<<(ostream& os, PhanSo ps) {
    PhanSo pstam = ps;
    if(ps.ts==0) cout<<"0";
    else if (pstam.ms == 1) os << pstam.ts;
    else os << pstam.ts << "/" << pstam.ms;
    return os;
}
// Toán tử so sánh ">" giữa hai phân số
    bool operator>(PhanSo ps1, PhanSo ps2) {
    return double(ps1.ts)/ps1.ms>double(ps2.ts)/ps2.ms;
}

    bool operator<(PhanSo ps1, PhanSo ps2) {
    return double(ps1.ts)/ps1.ms<double(ps2.ts)/ps2.ms;
}

    bool operator==(PhanSo ps1, PhanSo ps2) {
    return double(ps1.ts)/ps1.ms==double(ps2.ts)/ps2.ms;
}
// Hàm tìm phân số lớn nhất trong hai phân số
    PhanSo TimMax(PhanSo ps1, PhanSo ps2) {
    PhanSo psmax;
    if(ps1>ps2) psmax=ps1;
    else if(ps1<ps2) psmax=ps2;
    else {
     cout<<"Hai phan so bang nhau = ";
     psmax=ps1;
    }
    return psmax;
}

int main() {
  PhanSo ps1,ps2;
  cout<<"Nhap phan so thu nhat: "<<endl;
  cin>>ps1;
  cout<<"Nhap phan so thu hai: "<<endl;
  cin>>ps2;
  cout<<"Max("<<ps1<<","<<ps2<<") la phan so: "<<TimMax(ps1, ps2)<<endl;
  return 0;
}
