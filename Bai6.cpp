#include<iostream>
#include<vector>
using namespace std;

// Hàm kiểm tra xem mảng A có phải là mảng con của B hay không
    vector<int> KtraMangCon(vector<int> &a, vector<int> &b) {
        vector<int> position;

        // Trường hợp: nếu A lớn hơn B
        if(a.size() > b.size()) {
            cout<<"Mang con khong the lon hon mang me!";
        }

        if(b.empty()) {
            cout<<"Mang me rong, khong the chua mang con!";
        }

        // Trường hợp: nếu A rỗng, nó có thể nằm ở mọi vị trí trong B (bao gồm cả đầu và cuối)
        // Do đó, i chạy từ 0 đến b.size()
        if(a.empty()) {
            cout<<"Mang con rong, co the nam o moi vi tri trong mang me:\n";
            for(int i=0; i<=b.size(); i++) {
                position.push_back(i);// Thêm tất cả vị trí hợp lệ vào danh sách
            }
            return position;
        }

        // Trường hợp: Mảng A và mảng B thông thường
        // Duyệt từng vị trí trong B để kiểm tra xem A có xuất hiện ở đó không
        for(int i=0; i<= b.size()-a.size(); i++) {
            bool found=true;    // Biến kiểm tra xem A có khớp với đoạn tương ứng trong B không

        // So sánh từng phần tử của A với một đoạn trong B
            for(int j=0; j<a.size(); j++) {
                if(b[i+j]!=a[j]) {  // Nếu có bất kỳ phần tử nào không khớp
                found=false;   // Đánh dấu là không tìm thấy
                break;  // Thoát vòng lặp
                }
            }
// Nếu tìm thấy A tại vị trí i, thêm vào danh sách kết quả
        if(found) position.push_back(i);
    }
    return position;   // Trả về danh sách các vị trí tìm thấy
    }

int main() {
    int sizeA, sizeB;
    cout<<"Nhap n phan tu mang B va mang A: ";
    cin>>sizeB>>sizeA;
    vector<int> a(sizeA), b(sizeB);
    cout<<"Nhap phan tu mang B: "<<endl;
    for(int i=0; i<sizeB; i++) {
        cin>>b[i];
    }
    cout<<"Nhap phan tu mang A: "<<endl;
    for(int i=0; i<sizeA; i++) {
        cin>>a[i];
    }
    vector<int> position=KtraMangCon(a,b);
//position.size() là số lần mảng A xuất hiện trong mảng B
    cout<<position.size()<<endl;
//range-based for loop: duyệt từng phần tử của mảng póition từ đầu đến cuối để xuất ra
    for(int pos : position)
        cout<<pos<<" ";
        return 0;
    }
