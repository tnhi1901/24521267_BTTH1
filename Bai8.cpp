#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include <sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct NgayBay {
    int day, month, year;
};

struct GioBay {
    int gio, phut;
};

struct ChuyenBay {
      string maBay;
      GioBay giobay;
      NgayBay ngaybay;
      string noiDi, noiDen;

// ham xuat thong tin chuyen bay
void xuatDS() {
    cout<<"\n------Thong tin chuyen bay-------\n";
    cout<<"Code: "<<maBay<<endl;
    cout<<"dd/mm/yyyy: "<<ngaybay.day<<"/"<<ngaybay.month<<"/"<<ngaybay.year<<endl;
    cout << "Time: "<<setw(2)<< setfill('0')<<giobay.gio<< ":"
         <<setw(2)<<setfill('0')<<giobay.phut<<endl;
    cout<<"From: "<<noiDi<<endl;
    cout<<"To: "<<noiDen<<endl;
}
};

// ham chuyen chuoi thanh chu thuong
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

// ham kiem tra ma chuyen bay hop le
bool checkMa(string &ma) {
    if(ma.length()>5) return false;
    for(char c: ma) {
        if(!((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')))
            return false;
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
    bool checkNgay(NgayBay d) {
       if (d.year < 0) return false;
       if(d.month<1 || d.month>12) return false;
       if(d.day<1 || d.day>dayinMonth(d.month, d.year)) return false;
       return true;
    }

// nhap ngay bay
NgayBay nhapNgayBay() {
    NgayBay nb;
    string input;
    do {
        cout << "Nhap ngay bay (dd/mm/yyyy) ";
        cin >> input;

        if (sscanf(input.c_str(), "%d/%d/%d", &nb.day, &nb.month, &nb.year) != 3 || !checkNgay(nb)) {
            cout << "Loi! Vui long nhap lai\n";
        } else {
            break;
        }
    } while (true);

    return nb;
}

// Kiem tra gio hop le
bool checkTime(int gio, int phut) {
    return (gio>=0 && gio<=23 && phut>=0 && phut<=59);
}
// Nhao gio bay (hh:mm)
GioBay nhapGioBay() {
    GioBay gb;
    string input;
    bool valid = false;

    do {
        cout << "Nhap gio bay (hh:mm): ";
        cin >> input;

        stringstream ss(input);
        char delim;
        ss >> gb.gio >> delim >> gb.phut;

        if (ss.fail() || delim != ':' || !checkTime(gb.gio, gb.phut)) {
            cout << "Loi! Vui long nhap lai.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            valid = true;
        }
    } while (!valid);

    return gb;
}


//kiem tra noi di va den
bool checkDiDen(string &dd) {
    if(dd.length()>20) return false;
    for(char c: dd) {
        if (!( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c==' '))
            return false;
    }
    return true;
}

void nhapDS(vector<ChuyenBay> &ds) {
    int n;
    cout<<"Nhap so luong chuyen bay\n";
    cin>>n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ds.resize(n);

    for(int i=0; i<n; i++) {
        cout<<"Nhap thong tin chuyen bay thu "<<i+1<<endl;
        ChuyenBay &cb=ds[i];

    //nhap ma chuyen bay
    do {
        cout<<"Nhap ma chuyen bay:\n";
        getline(cin,cb.maBay);
        if(!checkMa(cb.maBay))
            cout<<"Loi! Vui long nhap lai ma chuyen bay.\n";
    } while(!checkMa(cb.maBay));


    //nhap ngay bay
    cb.ngaybay = nhapNgayBay();
    //nhap gio bay
    cb.giobay = nhapGioBay();
    //nhap noi di
    cin.ignore();
    do {
        cout << "Nhap dia diem xuat phat: ";
        getline(cin, cb.noiDi);
        cb.noiDi = toLowerCase(cb.noiDi);
        if (!checkDiDen(cb.noiDi)) {
            cout << "Loi! Vui long nhap lai.\n";
    }
} while (!checkDiDen(cb.noiDi));
    //nhap noi di
    do {
        cout << "Nhap dia diem den: ";
        getline(cin,cb.noiDen);
        cb.noiDen = toLowerCase(cb.noiDen);
        if (!checkDiDen(cb.noiDen)) {
             cout << "Loi! Vui long nhap lai.\n";
    }
} while (!checkDiDen(cb.noiDen));

}
cout<<endl;
}


//ham sap xep chuyen bay theo ngay gio khoi hanh
bool sapxepTime(const ChuyenBay &a, const ChuyenBay &b) {
    if(a.ngaybay.year != b.ngaybay.year) return a.ngaybay.year<b.ngaybay.year;
    if(a.ngaybay.month != b.ngaybay.month) return a.ngaybay.month<b.ngaybay.month;
    if(a.ngaybay.day != b.ngaybay.day) return a.ngaybay.day<b.ngaybay.day;
    if(a.giobay.gio != b.giobay.gio) return a.giobay.gio<b.giobay.gio;
    return a.giobay.phut<b.giobay.phut;
}

//xoa khoang trang
string normalize(string str) {
    // xoa khoang trang dau va cuoi
    while (!str.empty() && str.front() == ' ') str.erase(str.begin());
    while (!str.empty() && str.back() == ' ') str.pop_back();

    // chuyen toan bo ky tu ve chu thuong
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// ham liet ke danh sach theo noi di cung ngay cua chuyen bay
void lietkeDS(vector<ChuyenBay> &ds, string &noiDi, NgayBay &n) {
    bool found = false;
    noiDi = normalize(noiDi); // Dùng normalize

    for (size_t i = 0; i < ds.size(); i++) {
        if (normalize(ds[i].noiDi) == noiDi &&
            ds[i].ngaybay.day == n.day &&
            ds[i].ngaybay.month == n.month &&
            ds[i].ngaybay.year == n.year) {
            ds[i].xuatDS();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay nao phu hop!\n";
    }
}

//ham tim kiem chuyen bay theo ma, noi di(den)
void timkiemMa(vector<ChuyenBay> &ds, string key) {
    bool found = false;
    key = normalize(key); //Chuan hoa du lieu nhap vao

    for (size_t i = 0; i < ds.size(); i++) {
        if (normalize(ds[i].maBay) == key ||
            normalize(ds[i].noiDi) == key ||
            normalize(ds[i].noiDen) == key) {
            ds[i].xuatDS();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay chuyen bay nao\n";
    }
}


//ham dem so chuyen bay giua 2 dia diem
int demChuyenBay(vector<ChuyenBay> &ds, string &noiDi, string &noiDen) {
    noiDi = toLowerCase(noiDi);   // Chuẩn hóa trước khi so sánh
    noiDen = toLowerCase(noiDen);
    int dem=0;
    for(size_t i=0; i<ds.size(); i++) {
        if(ds[i].noiDi==noiDi && ds[i].noiDen==noiDen)
            dem++;
    }
    return dem;
}

int main() {
    vector<ChuyenBay> ds;
    nhapDS(ds);
    int chon;
    do {
    cout<<"0.Thoat trinh duyet\n";
    cout<<"1.Danh sach chuyen bay sau khi sap xep\n";
    cout<<"2.Tim kiem chuyen bay trong danh sach\n";
    cout<<"3.Liet ke danh sach chuyen bay thong qua dia diem (cung ngay)\n";
    cout<<"4.Dem so luong chuyen bay tu A den B\n";
    cout<<"Nhap lua chon:\n";
    cin>>chon;
    cin.ignore();
    switch(chon) {
      case 0:
        cout<<"Dang thoat trinh duyet...\n";
        break;
      case 1: {
        //goi ham sap xep sau khi nhap danh sach
        sort(ds.begin(), ds.end(), sapxepTime);
        //xuat danh sach sau khi sap xep
        cout<<"Danh sach chuyen bay da sap xep\n";
        for(size_t i=0; i<ds.size(); i++) {
             ds[i].xuatDS();
           }
           break;
        }
      case 2: {
          string key;
          cout<<"Nhap ma chuyen bay hoac noi di hoac noi den cua ban.\n";
          getline(cin,key);
          timkiemMa(ds,key);
          break;
      }
     case 3: {
         string noiDi;
         cout << "Nhap dia diem xuat phat: ";
         getline(cin, noiDi);

         NgayBay ngay = nhapNgayBay(); // Dùng lại hàm nhập ngày có kiểm tra

        lietkeDS(ds, noiDi, ngay);
         break;
}


      case 4: {
        string noiDi, noiDen;
        cout << "Nhap dia diem xuat phat: ";
        getline(cin, noiDi);
        cout << "Nhap dia diem den: ";
        getline(cin, noiDen);
        int count = demChuyenBay(ds, noiDi, noiDen);
        cout << "So chuyen bay tu " << noiDi << " den " << noiDen << ": " << count << endl;
        break;
            }
      default:
        cout << "Lua chon khong hop le, vui long chon lai!\n";
        }
    } while(chon != 0);
    return 0;
}

