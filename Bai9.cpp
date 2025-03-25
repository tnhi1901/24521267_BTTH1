#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include<algorithm>
using namespace std;

struct NgayMoSo {
    int day, month, year;
};

struct soTKiem {
    string maSo;
    string loaiTK;
    string tenKH;
    string cmnd;
    NgayMoSo ngaymo;
    double tienGui;
    double laisuat;

    void xuatSTK() {
    cout<<"\n------ Thong tin so tiet kiem -------\n";
    cout<<"Ma so: " << maSo<<endl;
    cout<<"Loai tiet kiem: "<<loaiTK<<endl;
    cout<<"Ho ten khach hang: "<<tenKH<<endl;
    cout<<"CMND: "<<cmnd<<endl;
    cout<<"Ngay mo so: " << setw(2)<< setfill('0')<<ngaymo.day<< "/"
         <<setw(2)<<setfill('0')<<ngaymo.month<< "/"
         <<ngaymo.year<< endl;
    cout<<"So tien gui: "<< fixed << setprecision(0) <<tienGui<<" VND\n";
}
};

//Ham kiem tra ma so hop le (toi da 5 ky tu, khong chua khoang trang, hoac ky tu dac biet)
bool checkMS(string &ms) {
    if(ms.length()>5) return false;
    for(char c: ms) {
        if(!((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')))
            return false;
    }
    return true;
}

//ham kiem tra loai tiet kiem hop le
bool checkLoaiTK(string &loai) {
    return loai.length() <= 10;
}

//ham kiem tra ho ten khach hang
bool checkTen(string ten) {
    // Xoa khoang trang dau va cuoi
    while (!ten.empty() && ten.front() == ' ') ten.erase(ten.begin());
    while (!ten.empty() && ten.back() == ' ') ten.pop_back();
     int i;
    // kiem tra do dai hop le
     if (ten.length() < 2 || ten.length() > 30) return false;
    // kiem tra ly tu khong hop le
     for (int i = 0; i < ten.length(); i++)
             if (! ((ten[i] >= 'a' && ten[i] <= 'z') || (ten[i] >= 'A' && ten[i] <= 'Z') || ten[i] == ' '))
            return false;
     return true;
}

//ham kiem tra cmnd
bool checkCMND(string &cmnd) {
    // kiem tra do dai cmnd tu 9 den 12
    int length = cmnd.length();
    if (length != 9 && length != 12) return false;

    // kiem tra tung ky tu xem co phai ky tu so khong
    for (char c : cmnd) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// kiem tra nam nhuan
bool NamNhuan(int year) {
    return (year%400==0) || (year%4==0 && year%100!=0);
    }
// ham tre ve so ngay trong thang
    int dayinMonth(int month, int year) {
      int D[]={31,28,31,30,31,30,31,31,30,31,30,31};
      if(month==2 && NamNhuan(year)) return 29;
      return D[month -1];
    }
// kiem tra ngay hop le
    bool checkNgay(NgayMoSo ngaymo) {
       if (ngaymo.year < 0) return false;
       if(ngaymo.month<1 || ngaymo.month>12) return false;
       if(ngaymo.day<1 || ngaymo.day>dayinMonth(ngaymo.month, ngaymo.year)) return false;
       return true;
    }

//ham kiem tra tien hop le
bool checkTien(double tien) {
return tien>0;
}

//ham nhap ngay mo so
NgayMoSo nhapNgayMS() {
    NgayMoSo ms;
    string input;
    do {
        cout << "Nhap ngay mo so (dd/mm/yyyy) ";
        cin >> input;

        if (sscanf(input.c_str(), "%d/%d/%d", &ms.day, &ms.month, &ms.year) != 3 || !checkNgay(ms)) {
            cout << "Loi! Vui long nhap lai\n";
        } else {
            break;
        }
    } while (true);

    return ms;
}

//ham nhap ngay
NgayMoSo nhapNgay() {
    NgayMoSo nn;
    string input;
    do {
        cout << "Nhap ngay (dd/mm/yyyy) ";
        cin >> input;

        if (sscanf(input.c_str(), "%d/%d/%d", &nn.day, &nn.month, &nn.year) != 3 || !checkNgay(nn)) {
            cout << "Loi! Vui long nhap lai\n";
        } else {
            break;
        }
    } while (true);

    return nn;
}

//nhap thong tin
void nhapSTK(vector<soTKiem> &stk) {
    int n;
    cout<<"Nhap so luong so tiet kiem\n";
    cin>>n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    stk.resize(n);

    for(int i=0; i<n; i++) {
        cout<<"Nhap thong tin STK thu "<<i+1<<endl;
        soTKiem &so=stk[i];
    do {
        cout<<"Nhap ma so tiet kiem:\n";
        cin>>so.maSo;
        if(!checkMS(so.maSo)) cout<<"Ma khong hop le. Nhap lai:\n";
    } while(!checkMS(so.maSo));

    do {
        cout<<"Nhap loai tiet kiem:\n";
        cin.ignore();
        getline(cin,so.loaiTK);
        if(!checkLoaiTK(so.loaiTK)) cout<<"Khong hop le. Nhap lai:\n";
    } while(!checkLoaiTK(so.loaiTK));

    do {
        cout<<"Nhap ten khach hang:\n";
        getline(cin,so.tenKH);
        if(!checkTen(so.tenKH)) cout<<"Ten khong hop le. Nhap lai:\n";
    } while(!checkTen(so.tenKH));

    do {
        cout<<"Nhap cmnd:\n";
        cin>>so.cmnd;
        if(!checkCMND(so.cmnd)) cout<<"CMND khong hop le. Nhap lai:\n";
    } while(!checkCMND(so.cmnd));

    so.ngaymo=nhapNgayMS();

    do {
        cout << "Nhap so tien gui: ";
        cin >> so.tienGui;
        if (so.tienGui <= 0) {
            cout << "So tien phai lon hon 0. Nhap lai.\n";
        }
    } while (so.tienGui <= 0);

}
}


// ham tinh so thang (tinh tu ngay mo so den hien tai)
int tinhSoThangGui (NgayMoSo ngaymo) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int namHtai = 1900 + ltm->tm_year;
    int thangHtai = 1 + ltm->tm_mon;

    int soThang = (namHtai - ngaymo.year) * 12 + (thangHtai - ngaymo.month);
    return soThang;
}

//ham tinh tien lai theo loai tiet kiem
double tinhTienLai(soTKiem &stk, double lsNganHan, double lsDaiHan) {
    int soThangGui = tinhSoThangGui(stk.ngaymo);
    double laiSuat = (soThangGui > 6) ? lsDaiHan : lsNganHan;
    return stk.tienGui * (laiSuat / 100) * (soThangGui / 12.0);
}

//cap nhat lai suat
void capNhatLaiSuat(double &lsNganHan, double &lsDaiHan) {
    cout<<"Nhap lai suat ngan han (%/nam):\n";
    cin>>lsNganHan;
    cout<<"Nhap lai suat dai han (%/nam):\n";
    cin>>lsDaiHan;
}

//ham rut tien theo loai tiet kiem
void rutTien(vector<soTKiem> &stk, double lsNganHan, double lsDaiHan) {
    string matk;
    cout<<"Nhap ma stk can rut:\n";
    cin>>matk;
    bool found=false;
    for(size_t i=0; i<stk.size(); i++) {
            if(stk[i].maSo==matk) {
            found=true;
    double soTienRut;
    cout<<"Nhap so tien can rut:\n";
    cin>>soTienRut;
    if (soTienRut > stk[i].tienGui) {
        cout<<"Khong du so du de rut!\n";
        return;
    }


    int soThangGui = tinhSoThangGui(stk[i].ngaymo);
    double laiSuat = (soThangGui > 6) ? lsDaiHan : 0.5; // neu rut truoc han, lai suat chi duoc tinh 0.5%

    double tienLai = stk[i].tienGui * (laiSuat / 100) * (soThangGui / 12.0);  //chuyen doi lai suat ve so thuc va so thang gui dua ve nam
    stk[i].tienGui -= soTienRut;

    cout<<"Ban da rut "<<soTienRut<<endl;
    cout<<"So du con lai: "<<stk[i].tienGui<< endl;
    break;
}
    }
if(!found) cout<<"Khong tim thay ma hop le.\n";
}

//ham tim kiem so tiet kiem theo cmnd hoac ma so
void timSTK(vector<soTKiem> &stk, string key) {
    bool found=false;
    for(size_t i=0; i<stk.size(); i++) {
        if(stk[i].cmnd==key || stk[i].maSo==key) {
            stk[i].xuatSTK();
            found=true;
        }
    }
    if(!found) cout<<"Khong tim thay so tiet kiem nao.\n";
}

//ham so sanh ngay mo so
bool soSanhNgay(NgayMoSo &a, NgayMoSo &b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

void lietKeSTK(vector<soTKiem> &stk, NgayMoSo &tuNgay, NgayMoSo &denNgay) {
    cout<<"Cac so tiet kiem mo tu " << tuNgay.day << "/" << tuNgay.month << "/" << tuNgay.year
         << " den " << denNgay.day << "/" << denNgay.month << "/" << denNgay.year << ":\n";
         bool found=false;
    for (size_t i=0; i<stk.size(); i++) {
        if (soSanhNgay(tuNgay, stk[i].ngaymo) && soSanhNgay(stk[i].ngaymo, denNgay)) {
            stk[i].xuatSTK();
            found=true;
    }
}
    if (!found) {
        cout << "Khong co so tiet kiem nao trong khoang thoi gian nay.\n";
}
}

//ham sap xep
bool sxTienGiam(soTKiem a, soTKiem b) {
    return a.tienGui > b.tienGui;
}

bool sxNgayTang(soTKiem a, soTKiem b) {
    return soSanhNgay(a.ngaymo, b.ngaymo);
}


int main() {
    vector<soTKiem> stk;
    int chon;
    double lsNganHan, lsDaiHan;
    do {
        cout<<"\n===== CHUONG TRINH QUAN LY SO TIET KIEM =====\n";
        cout << "0. Thoat CT\n";
        cout << "1. Nhap so tiet kiem\n";
        cout << "2. Xuat danh sach so tiet kiem\n";
        cout << "3. Cap nhat lai suat\n";
        cout << "4. Tinh tien lai\n";
        cout << "5. Rut tien\n";
        cout << "6. Tim kiem so tiet kiem theo CMND hoac ma so\n";
        cout << "7. Liet ke so tiet kiem trong khoang thoi gian\n";
        cout << "8. Sap xep so tiet kiem theo tien gui (giam dan)\n";
        cout << "9. Sap xep so tiet kiem theo ngay mo so (tang dan)\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 0:
                cout<<"Dang thoat CT...\n";
                break;
            case 1: {
                nhapSTK(stk);
                break;
            }
            case 2: {
            for (size_t i=0; i<stk.size(); i++) stk[i].xuatSTK();
                break;
            }
            case 3: {
                capNhatLaiSuat(lsNganHan, lsDaiHan);
                break;
            }
            case 4: {
           for (size_t i=0; i<stk.size(); i++) {
                    double tienLai = tinhTienLai(stk[i], lsNganHan, lsDaiHan);
                    cout << "Tien lai cua so tiet kiem " << stk[i].maSo << " la: " << fixed<<setprecision(0)<<tienLai << " VND\n";
           }
                break;
            }
            case 5: {
               rutTien(stk, lsNganHan, lsDaiHan);
               break;
                }

            case 6: {
                string key;
                cout << "Nhap CMND hoac ma so tiet kiem can tim:\n";
                cin >> key;
                timSTK(stk, key);
                break;
            }
            case 7: {
               cout << "Nhap ngay bat dau:\n";
               NgayMoSo tuNgay = nhapNgay();
               cout << "Nhap ngay ket thuc:\n";
               NgayMoSo denNgay = nhapNgay();

               lietKeSTK(stk, tuNgay, denNgay);
               break;
              }

            case 8: {
               cout << "Danh sach sap xep theo tien gui (giam dan):\n";
               sort(stk.begin(), stk.end(), sxTienGiam);
               for (size_t i = 0; i < stk.size(); i++) stk[i].xuatSTK();
               break;
                }
            case 9: {
               cout << "Danh sach sap xep theo ngay mo so (tang dan):\n";
               sort(stk.begin(), stk.end(), sxNgayTang);
               for (size_t i = 0; i < stk.size(); i++) stk[i].xuatSTK();
               break;
             }

            default:
                cout<<"Lua chon khong hop le. Moi chon lai!";
                break;
            }
            } while(chon!=0);
           return 0;
}
