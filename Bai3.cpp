#include<iostream>
using namespace std;
struct PhanSo {
    int ts,ms;
};
    void ChuanHoaPS(PhanSo &ps) {
        if(ps.ms<0) {
            ps.ts=-ps.ts;
            ps.ms=-ps.ms;
        }
    }
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

    ostream& operator<<(ostream& os, PhanSo ps) {
    PhanSo pstam = ps;
    if(ps.ts==0) cout<<"0";
    else if (pstam.ms == 1) os << pstam.ts;
    else os << pstam.ts << "/" << pstam.ms;
    return os;
}
int UCLN(int a, int b) {
    int ucln;
    a=a<0 ? -a:a;
    b=b<0 ? -b:b;
    if(a==0 || b==0) {
        ucln=a+b;
    }
    else {
        while(a!=b) {
            if(a>b) a-=b;
            else b-=a;
        }
        if(a==b) ucln=a;
    }
    return ucln;
}
void RutGon(PhanSo &ps) {
    int ucln=UCLN(ps.ts, ps.ms);
    if(ucln>0) {
    ps.ts/=ucln;
    ps.ms/=ucln;
   }
   ChuanHoaPS(ps);
}
 PhanSo operator+(PhanSo ps1, PhanSo ps2) {
 PhanSo pstong;
 pstong.ts=ps1.ts*ps2.ms+ps1.ms*ps2.ts;
 pstong.ms=ps1.ms*ps2.ms;
 RutGon(pstong);
 return pstong;
}

//hieu 2 phan so
PhanSo operator-(PhanSo ps1, PhanSo ps2) {
 PhanSo pshieu;
 pshieu.ts=ps1.ts*ps2.ms-ps1.ms*ps2.ts;
 pshieu.ms=ps1.ms*ps2.ms;
 RutGon(pshieu);
 return pshieu;
}


PhanSo operator+(PhanSo ps, int a) {
    PhanSo pstong;
    pstong.ts = ps.ts + ps.ms * a;
    pstong.ms = ps.ms;
    RutGon(pstong);
    return pstong;
}

//cong so nguyen voi phan so (hoan vi)
PhanSo operator+(int a, PhanSo ps) {
 return ps+a;
}
//tru phan so voi so nguyen
PhanSo operator-(PhanSo ps, int a) {
    PhanSo pshieu;
    pshieu.ts =ps.ts-ps.ms*a;
    pshieu.ms = ps.ms;
    RutGon(pshieu);
    return pshieu;
}

//tru so nguyen voi phan so (hoan vi)
PhanSo operator-(int a, PhanSo ps) {
    PhanSo pshieu;
    pshieu.ts = a * ps.ms - ps.ts;
    pshieu.ms = ps.ms;
    RutGon(pshieu);
    return pshieu;
}
//ham nhan phan so
PhanSo operator*(PhanSo ps1, PhanSo ps2) {
 PhanSo pstich;
 pstich.ts=ps1.ts*ps2.ts;
 pstich.ms=ps1.ms*ps2.ms;
 RutGon(pstich);
 return pstich;
}
//ham chia phan so
PhanSo operator/(PhanSo ps1, PhanSo ps2) {
 PhanSo psthuong;
 psthuong.ts=ps1.ts*ps2.ms;
 psthuong.ms=ps1.ms*ps2.ts;
 RutGon(psthuong);
 return psthuong;
}

int main() {
    PhanSo ps1, ps2;
  cout<<"Nhap phan so thu nhat:\n";
  cin>>ps1;
  do {
  cout<<"Nhap phan so thu hai:\n";
  cin>>ps2;
  if(ps2.ts==0)
    cout<<"Loi. Tu so cua phan so thu 2 phai khac 0. Vui long nhap lai\n";
  } while(ps2.ts==0);

  cout<<"Phan so thu nhat: "<<ps1<<endl;
  cout<<"Phan so thu hai: "<<ps2<<endl;
  cout<<"Ket qua:\n";
  cout<<ps1<<" + "<<ps2<<" = "<<ps1+ps2<<endl;
  cout<<ps1<<" - "<<ps2<<" = "<<ps1-ps2<<endl;
  cout<<ps1<<" * "<<ps2<<" = "<<ps1*ps2<<endl;
  cout<<ps1<<" : "<<ps2<<" = "<<ps1/ps2<<endl;
  return 0;
}
