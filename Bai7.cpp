#include<iostream>
#include<vector>
#include<cctype>
#include <algorithm>
#include<string>
using namespace std;
struct HocSinh {
    string Hoten, xepLoai;
    double toan, van, anh, dtb;
};

// Hàm tính điểm trung bình và xếp loại học sinh
void DTBvaXL (HocSinh &hs) {
    hs.dtb=(hs.toan*2+hs.van+hs.anh)/4;
    if(hs.dtb>=9) hs.xepLoai="Xuat sac\n";
    else if(hs.dtb>=8) hs.xepLoai="Gioi\n";
    else if(hs.dtb>=6.5) hs.xepLoai="Kha\n";
    else if(hs.dtb>=5) hs.xepLoai="Trung binh\n";
    else hs.xepLoai="Yeu\n";
}

// Hàm kiểm tra họ tên hợp lệ
bool kiemTraTen(string ten) {
    // Xóa khoảng trắng đầu và cuối
    while (!ten.empty() && ten.front() == ' ') ten.erase(ten.begin());
    while (!ten.empty() && ten.back() == ' ') ten.pop_back();

    // Kiểm tra lại sau khi đã xóa khoảng trắng
     int i;
    // Kiểm tra độ dài hợp lệ
     if (ten.length() < 2 || ten.length() > 50) return false;
    // Kiểm tra ký tự không hợp lệ
     for (int i = 0; i < ten.length(); i++)
             if (! ((ten[i] >= 'a' && ten[i] <= 'z') || (ten[i] >= 'A' && ten[i] <= 'Z') || ten[i] == ' '))
            return false;
     return true;
}


// Hàm nhập danh sách học sinh
void nhapDS(vector<HocSinh> &ds ) {
    int n;
    cout<<"Nhap so luong hoc sinh: "<<endl;
    cin>>n;
    ds.resize(n);

    for(int i=0; i<n; i++) {
        cout<<"Nhap ho ten hoc sinh thu "<<i+1<<":";
        cin.ignore();
        do {
        getline(cin, ds[i].Hoten);
        if(!kiemTraTen(ds[i].Hoten)) {
            cout<<"Ten khong hop le! Vui long nhap lai!"<<endl;
         }
        } while(!kiemTraTen(ds[i].Hoten));

        do {
            cout<<"Nhap diem Toan:\n";
            cin>>ds[i].toan;
            if(ds[i].toan<0 || ds[i].toan>10)
                cout<<"Nhap sai. Vui long nhap lai!\n";
        } while(ds[i].toan<0 || ds[i].toan>10);

        do {
            cout<<"Nhap diem Van:\n";
            cin>>ds[i].van;
            if(ds[i].van<0 || ds[i].van>10)
                cout<<"Nhap sai. Vui long nhap lai!\n";
        } while(ds[i].van<0 || ds[i].van>10);

        do {
            cout<<"Nhap diem Tieng Anh:\n";
            cin>>ds[i].anh;
            if(ds[i].anh<0 || ds[i].anh>10)
                cout<<"Nhap sai. Vui long nhap lai!\n";
        } while(ds[i].anh<0 || ds[i].anh>10);

        DTBvaXL(ds[i]);
    }
}



// Hàm in danh sách học sinh
void inDS(vector<HocSinh> ds) {
    cout<<"---------------Danh sach hoc sinh---------------\n";
    for(size_t i=0; i<ds.size(); i++) {
        cout<<"Hoc sinh: "<<ds[i].Hoten<<endl;
        cout<<"Diem trung binh: "<<ds[i].dtb<<endl;
        cout<<"Xep loai: "<<ds[i].xepLoai<<endl;
    }
}

// Hàm tìm học sinh có điểm trung bình cao nhất
void DTBmax(vector<HocSinh> ds) {
    double maxDiem=-1;
    for(int i=0; i<ds.size(); i++) {
        if(ds[i].dtb>maxDiem)
            maxDiem=ds[i].dtb;
    }

    for(int i=0; i<ds.size(); i++) {
        if(ds[i].dtb==maxDiem) {
            cout<<"Ho ten: "<<ds[i].Hoten<<endl;
            cout<<"Diem trung binh: "<<ds[i].dtb<<endl;
            cout<<endl;
    }
 }
}

// Hàm tìm học sinh theo từ khóa
void tenHsKey(vector<HocSinh> &ds, string key) {
    string keyLower=key;
    transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);
    bool found=false;
    for(int i=0; i<ds.size(); i++) {
        string tenLower=ds[i].Hoten;
        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        if(tenLower.find(keyLower) != string::npos) {
            cout<<"Ho ten: "<<ds[i].Hoten<<endl;
            cout<<"Diem trung binh: "<<ds[i].dtb<<endl;
            cout<<endl;
            found=true;
        }
    }
    if(!found) cout<<"Khong tim thay ket qua\n";
}

// Hàm tìm học sinh có điểm Toán thấp nhất
void toanMin(vector<HocSinh> &ds) {
//kiem tra xem tat ca hoc sinh co cung diem toan hay khong
    bool equal=true;
    for(size_t i=1; i<ds.size(); i++) {
        if(ds[i].toan != ds[0].toan) {
            equal=false;
            break;
        }
    }
    if(equal) {
        cout<<"Tat ca hoc sinh co diem Toan bang nhau: "<<ds[0].toan<<endl;
        return;
    }
//tim hoc sinh co diem toan thap nhat
    double minDiem=11;
    for(int i=0; i<ds.size(); i++) {
        if(ds[i].toan<minDiem)
            minDiem=ds[i].toan;
    }
    for(int i=0; i<ds.size(); i++) {
        if(ds[i].toan==minDiem) {
            cout<<"Ho ten: "<<ds[i].Hoten<<endl;
            cout<<"Diem Toan: "<<ds[i].toan<<endl;
            cout<<endl;
        }
    }

}


int main() {
    vector<HocSinh> ds;
    int chon;
    string key;
    while(true) {
        cout<<"\n---CHUONG TRINH QUAN LY HOC SINH---\n";
        cout<<"0.Thoat CT\n";
        cout<<"1.Nhap danh sach hoc sinh\n";
        cout<<"2.Hien thi danh sach hoc sinh\n";
        cout<<"3.Danh sach hoc sinh co diem toan thap nhat\n";
        cout<<"4.Hoc sinh co diem trung binh cao nhat\n";
        cout<<"5.Tim kiem hoc sinh theo tu khoa\n";
        cout<<"Nhap lua chon: \n";
        cin>>chon;
        cin.ignore();

        switch(chon) {
        case 0:
            cout<<"Dang thoat CT...\n";
            return 0;
        case 1:
            nhapDS(ds);
            break;
        case 2:
            inDS(ds);
            break;
        case 3:
            toanMin(ds);
            break;
        case 4:
            DTBmax(ds);
            break;
            toanMin(ds);
            break;
        case 5:
            cout<<"Nhap tu khoa:\n";
            getline(cin,key);
            tenHsKey(ds,key);
            break;
        default:
            cout<<"Ban chon sai. Moi chon lai\n";
            break;
        }
    }
    return 0;
}
