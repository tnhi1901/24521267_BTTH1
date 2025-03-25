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
    void nhap(PhanSo &ps) {
        cout<<"Nhap tu so: ";
        cin>>ps.ts;
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
        if(ps.ts==0) cout<<"0"<<endl;
        else if (ps.ms==1) cout<<ps.ts<<endl;
        else cout<<ps.ts<<"/"<<ps.ms<<endl;
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
int main() {
    PhanSo ps;
    nhap(ps);
    RutGon(ps);
    in(ps);
    return 0;
}
