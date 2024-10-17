#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Nguoi{
	public:
	    string hoTen;      
	    string gioiTinh;      
	    int ngaySinh;
		int thangSinh;
		int namSinh;        
	    string diaChi;     
	    string cccd;       
	    string sdt;      
	    string email;
	    static string dsCCCD[200]; 
        static int soLuongCCCD;
        static string dsSDT[200]; 
        static int soLuongSDT;
	public:
		Nguoi();
		Nguoi(string hoTen,string gioiTinh,int ngaySinh,int thangSinh,int namSinh,string cccd,string sdt, string diaChi,string email);
		Nguoi(const Nguoi &N);
		void nhap();
		void xuat();
		bool namNhuan(int nam);
		static bool kiemTraCCCD(const string& cccd);
		static bool kiemTraSDT(const string& sdt);
};
string Nguoi::dsCCCD[200];
int Nguoi::soLuongCCCD = 0;
string Nguoi::dsSDT[200];
int Nguoi::soLuongSDT = 0;
Nguoi::Nguoi(){
	hoTen=" ";
	gioiTinh=" ";
	ngaySinh=0;
	thangSinh=0;
	namSinh=0;
	cccd=" ";
	sdt=" ";
	diaChi=" ";
	email=" ";
	
}
Nguoi::Nguoi(string hoTen,string gioiTinh,int ngaySinh,int thangSinh,int namSinh,string cccd,string sdt, string diaChi,string email){
	this->hoTen=hoTen;
	this->gioiTinh=gioiTinh;
	this->ngaySinh=ngaySinh;
	this->thangSinh=thangSinh;
	this->namSinh=namSinh;
	this->cccd=cccd;
	this->sdt=sdt;
	this->diaChi=diaChi;
	this->email=email;
}
Nguoi::Nguoi(const Nguoi &N){
	this->hoTen=N.hoTen;
	this->gioiTinh=N.gioiTinh;
	this->ngaySinh=N.ngaySinh;
	this->thangSinh=N.thangSinh;
	this->namSinh=N.namSinh;
	this->cccd=N.cccd;
	this->sdt=N.sdt;
	this->diaChi=N.diaChi;	
	this->email=N.email;
}
//kiem tra nam nhuan
bool Nguoi::namNhuan(int nam){
    return(nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
//kiem tra CCCD co bi trung khong
bool Nguoi::kiemTraCCCD(const string& cccd){
    for(int i = 0; i < soLuongCCCD; i++){
        if(dsCCCD[i] == cccd){
            return true; 
        }
    }
    return false; 
}
//kiem tra  SDT co bi trung khong
bool Nguoi::kiemTraSDT(const string& sdt){
    for(int i = 0; i < soLuongSDT; i++){
        if (dsSDT[i] == sdt) {
            return true; 
        }
    }
    return false; 
}
void Nguoi::nhap(){
	cout<<"Nhap ho ten: ";
	getline(cin,hoTen);
	//nhap va kiem tra ngay thang nam sinh 
    bool valid = false; 
    do{
        valid = true;  
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        if (namSinh < 0){
            cout << "\033[31m";//red
            cout << "Nam khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m"; //reset 
            valid = false;
        }
        if(valid){
            cout << "Nhap thang sinh: ";
            cin >> thangSinh;
            if (thangSinh < 1 || thangSinh > 12) {
                cout << "\033[31m";//red
                cout << "Thang khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m"; //reset 
                valid = false;
                }
        }
        if (valid){
            cout << "Nhap ngay sinh: ";
            cin >> ngaySinh;
            if(thangSinh == 1 || thangSinh == 3 || thangSinh == 5 || thangSinh == 7 || thangSinh == 8 || thangSinh == 10 || thangSinh == 12) {
                if(ngaySinh < 1 || ngaySinh > 31) {
                    cout << "\033[31m";//red
                    cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                    cout << "\033[0m"; //reset 
                    valid = false;
                    }
            }else if(thangSinh == 4 || thangSinh == 6 || thangSinh == 9 || thangSinh == 11) {
                if(ngaySinh < 1 || ngaySinh > 30) {
                    cout << "\033[31m";//red
                    cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                    cout << "\033[0m"; //reset 
                    valid = false;
                }
            }else if (thangSinh == 2){
                if(namNhuan(namSinh)) {
                    if(ngaySinh < 1 || ngaySinh > 29){
                        cout << "\033[31m";//red
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        cout << "\033[0m"; //reset 
                        valid = false;
                    }
                }else{
                    if(ngaySinh < 1 || ngaySinh > 28){
                        cout << "\033[31m";//red
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        cout << "\033[0m"; //reset 
                        valid = false;
                    }
                }
            }
        }
    }
	while (!valid);

   // Nhap va kiem tra gioi tinh
    cin.ignore(); 
    while (true) {
        cout << "Gioi tinh cua khach hang (Nam/Nu/Khac): ";
        getline(cin, gioiTinh);
        if (gioiTinh == "Nam" || gioiTinh == "nam" ||
            gioiTinh == "Nu" || gioiTinh == "nu" ||
            gioiTinh == "Khac" || gioiTinh == "khac") {
            break; 
        } else {
        	cout << "\033[31m";//red
            cout << "Gioi tinh khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }

    // Nhap va kiem tra SDT
    while (true){
        cout << "Nhap so dien thoai (Phai lon hon 2 va be hon 11 so): ";
        getline(cin, sdt);
        if(sdt.length() < 11 && sdt.length() > 2) {
            bool validSDT = true;
            for(int i = 0; i < sdt.length(); i++){
            	char c = sdt[i];
                if(!isdigit(c)){
                    validSDT = false;
                    break;
                }
            }
	        if(validSDT && !kiemTraSDT(sdt)){
                dsSDT[soLuongSDT++] = sdt;
                break;
            }
        }
        cout << "\033[31m";//red
        cout<<"So SDT khong hop le hoac da ton tai! Vui long nhap lai."<<endl;
        cout << "\033[0m"; //reset 
    }

    // Nhap va kiem tra so CCCD
    while (true){
        cout << "Nhap so CCCD (Phai du 12 so): ";
        getline(cin, cccd);
        if(cccd.length() == 12){
            bool validCCCD = true;
            for(int i = 0; i < cccd.length(); i++){
            	char c = cccd[i];
                if (!isdigit(c)){//isdigit de kiem tra ki tu co phai la so hay khong
                    validCCCD = false;
                    break;
                }
            }
	       	if(validCCCD && !kiemTraCCCD(cccd)){
                dsCCCD[soLuongCCCD++] = cccd;
                break;
            }
        }
        cout << "\033[31m";//red
        cout<<"So CCCD khong hop le hoac da ton tai! Vui long nhap lai."<<endl;
        cout << "\033[0m"; //reset 
    }
    cout<<"Nhap dia chi: ";
	getline(cin,diaChi);
    cout<<"Nhap email: ";
	getline(cin,email);	
}
void Nguoi::xuat(){
    cout<<"Ho va ten: "<<hoTen<<endl;
    cout<<"Ngay sinh: "<<ngaySinh<<"/"<<thangSinh<<"/"<<namSinh<<endl;
    cout<<"Gioi tinh: "<<gioiTinh<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    cout<<"So CCCD: "<<cccd<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Dia chi: "<<diaChi<<endl;
}

class KhachHang:public Nguoi{
    private:
    public:
        string getCCCD();  
       string getHoTen();
       void searchCCCD(KhachHang customers[], int customerCount, string x);
       void searchName(KhachHang customers[], int customerCount,const string H);

};

string KhachHang::getCCCD(){
    return cccd;
}
string KhachHang::getHoTen(){
    return hoTen;
}

//Tim kiem khach hang theo CCCD
void KhachHang::searchCCCD(KhachHang customers[], int customerCount, string x){
    bool found = false;
    for(int i=0; i<customerCount; i++){
        if(customers[i].getCCCD()==x){
             found = true;
            if (found ) {
                cout << "\033[1;32m"; //Green 
            }
            customers[i].xuat();
            if (found) {
                cout << "\033[0m"; //reset 
            }
            break;
            
        }
    }
    
      if (!found){
        cout << "\033[31m";//red
        cout << "Khach hang voi CCCD " << x << " khong tim thay!" << endl;
         cout << "\033[0m"; //reset 
      
    }
        
}
//Tim kiem khach hang theo ten
void KhachHang::searchName(KhachHang customers[], int customerCount,const string H){
    bool found = false;
    for(int i=0; i<customerCount; i++){
        if(customers[i].getHoTen()==H){
            found = true;
            if (found ) {
                cout << "\033[1;32m"; //Green 
            }
            customers[i].xuat();
            if (found) {
                cout << "\033[0m"; //reset 
            }
            break;
            
        }
    }
     if (!found){
        cout << "\033[31m";//red
        cout << "Khach hang voi tên " << H << " khong tim thay!" << endl;
         cout << "\033[0m"; //reset 
      
    }
       
}
class Phong {
private:
    string loaiPhong;  // Loai phong ("VIP" hoac "Binh thuong")
    string phanLoai;   // Phan loai phong ("Phong don" hoac "Phong doi")
    string trangThai;  // Trang thai phong
    double gia;        // Gia phong
    int soPhong;      // So phong

public:
    Phong();  // Constructor mac dinh
    Phong(string loai, string phanLoai, double gia, int soPhong);  // Constructor co tham so
    Phong(const Phong &phong);  // Constructor sao chep

    void nhapPhong();
    void xuatPhong();
    int getSoPhong() const;
    double getGia();  // Lay gia phong
    void setGia(double g);  // Thiet lap gia phong
    void capNhatPhong(string trangThaiMoi);  // Cap nhat trang thai phong
    void sapXepPhong(Phong ds[], int n);  // Sap xep phong
};

Phong::Phong() {
    this->soPhong = 0;
    this->loaiPhong = "";
    this->phanLoai = "";
    this->gia = 0.0;
    this->trangThai = "Trong";  // Khoi tao trang thai la "Trong"
}

Phong::Phong(string loai, string phanLoai, double gia, int soPhong) {
    this->soPhong = soPhong;
    this->loaiPhong = loai;
    this->phanLoai = phanLoai;
    this->gia = gia;
    this->trangThai = "Trong";  // Khoi tao trang thai la "Trong"
}

// Constructor sao chep
Phong::Phong(const Phong &phong) {
    this->soPhong = phong.soPhong;
    this->loaiPhong = phong.loaiPhong;
    this->phanLoai = phong.phanLoai;
    this->gia = phong.gia;
    this->trangThai = phong.trangThai;
}

void Phong::nhapPhong() {
    cout << "Nhap so phong: ";
    cin >> soPhong;

    cin.ignore();
    while (true) {
        cout << "Nhap loai phong (VIP, Thuong): ";
        getline(cin, loaiPhong);
        if (loaiPhong == "VIP" || loaiPhong == "vip" ||
            loaiPhong == "Thuong" || loaiPhong == "thuong") {
            break; 
        } else {
            cout << "\033[31m";//red
            cout << "Phong khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }

   
    while (true) {
        cout << "Nhap phan loai phong (Don, Doi): ";
        getline(cin, phanLoai);
        if (phanLoai == "don" || phanLoai == "Don" ||
            phanLoai == "doi" || phanLoai == "Doi") {
            break; 
        } else {
            cout << "\033[31m";//red
            cout << "Phong khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }
    
    

    do {
        cout << "Nhap gia phong (>= 0): ";
        cin >> gia;
        if (gia < 0) {
            cout << "\033[31m";//red
            cout << "Gia phong phai lon hon hoac bang 0. Vui long nhap lai!" << endl;
            cout << "\033[0m"; //reset 
        }
    } while (gia < 0);

    trangThai = "Trong"; 
}

void Phong::xuatPhong() {
    cout << soPhong<<" " << loaiPhong <<" "<< phanLoai <<" "  << trangThai << endl; // Xuat trang thai
}

int Phong::getSoPhong() const {
    return soPhong; 
}

double Phong::getGia() {
    return gia;  // Tra ve gia phong
}

void Phong::setGia(double g) {
    gia = g;  // Thiet lap gia phong
}

void Phong::capNhatPhong(string trangThaiMoi) {
    trangThai = trangThaiMoi;
    cout << "\033[1;32m"; // Green
    cout << "Phong " << soPhong << " da duoc cap nhat." << endl;
    cout << "\033[0m"; // Reset color
}

void Phong::sapXepPhong(Phong ds[], int n) {
    cout << "Danh sach phong sau khi sap xep theo so phong:" << endl;
    int pos;
    Phong x;
    for (int i = 1; i < n; i++) {
        x = ds[i]; 
        pos = i - 1;
        while (pos >= 0 && ds[pos].getSoPhong() > x.getSoPhong()) {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = x;
    }

    // Xuat danh sach phong sau khi sap xep
    for (int i = 0; i < n; i++) {
        ds[i].xuatPhong();
    }
}
class DatPhong : public Phong, public KhachHang {
private:
    string ngayDen; 
    string ngayDi; 


public:

    void nhapDatPhong(DatPhong vitri[], int count);
    void xuatDatPhong(); 
    bool kiemTrangay(string start,  string end);
    bool isValidDate(int day, int month, int year);
    bool isLeapYear(int year);
    bool kiemTraTrungPhong(DatPhong vitri[], int count);
    bool kiemTraTrungCCCD(DatPhong vitri[], int count, const string& cccd);
    // Thêm hàm tìm kiếm
    void searchByCCCD(DatPhong bookings[], int count, const string &cccd);
    void searchByName(DatPhong bookings[], int count, const string &name);
    static void xuatDanhSachDatPhong( DatPhong vitri[], int count);
    
};

bool DatPhong::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool DatPhong::isValidDate(int day, int month, int year) {
    if (year < 0){
        cout << "Nam khong hop le! Moi nhap lai!" << endl;
        return false;
    }
    if (month < 1 || month > 12) {
        cout << "\033[31m";
        cout << "Thang khong hop le! Moi nhap lai!" << endl;
        cout << "\033[0m";
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if(day < 1 || day > 31) {
            cout << "\033[31m";
            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m";
            return false;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        if(day < 1 || day > 30) {
            cout << "\033[31m";
            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m";
            return false;
        }
    } else if (month == 2){
        if(isLeapYear(year)) {
            if(day < 1 || day > 29){
                cout << "\033[31m";
                cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m";
                return false;
            }
        } else {
            if(day < 1 || day > 28){
                cout << "\033[31m";
                cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m";
                return false;
            }
        }
    }
    return true;
}

bool DatPhong::kiemTrangay(string start, string end) {
    // Tách ngày, tháng, năm từ chuỗi ngày theo định dạng "DD/MM/YYYY"
    //stoi chuyển kí tự string thành int
    int ngayStart = stoi(start.substr(0, 2));//lấy 2 ký tự đầu tiên từ start, tức là ngày.
    int thangStart = stoi(start.substr(3, 2));// lấy 2 ký tự tiếp theo từ vị trí thứ 3, tức là tháng.
    int namStart = stoi(start.substr(6, 4));//tương tự

    int ngayEnd = stoi(end.substr(0, 2));
    int thangEnd = stoi(end.substr(3, 2));
    int namEnd = stoi(end.substr(6, 4));

    // Kiểm tra tính hợp lệ của ngày
    if (!isValidDate(ngayStart, thangStart, namStart) || !isValidDate(ngayEnd, thangEnd, namEnd)) {
        return false;
    }

    // Kiểm tra năm trước
    if (namStart < namEnd && (thangStart < thangEnd || thangStart == thangEnd || thangStart > thangEnd)&& 
        (ngayStart < ngayEnd || ngayStart == ngayEnd || ngayStart > ngayEnd)) {
        return true;  // Nếu năm bắt đầu nhỏ hơn năm kết thúc, luôn hợp lệ
    } 
    
    if(namStart == namEnd){
    // Nếu cùng năm, kiểm tra tiếp tháng
    if (thangStart < thangEnd) 
        return true;
    }
    
    if(thangStart == thangEnd && namStart == namEnd){
    // Nếu cùng tháng, so sánh ngày
        if(ngayStart <= ngayEnd)
        return true;
    }
    return false;
}

bool DatPhong::kiemTraTrungPhong(DatPhong vitri[], int count) {
     
    for (int i = 0; i < count; ++i) {
        if (this->getSoPhong() == vitri[i].getSoPhong()) {
            // Kiểm tra xem có sự chồng chéo về thời gian không
            if (kiemTrangay(vitri[i].ngayDen, this->ngayDen) && kiemTrangay(this->ngayDen, vitri[i].ngayDi)) {
                return true; // Trùng lịch
            }
            if (kiemTrangay(this->ngayDen, vitri[i].ngayDen) && kiemTrangay(vitri[i].ngayDen, this->ngayDi)) {
                return true; // Trùng lịch
            }
        }
    }
    return false; // Không trùng
}

bool DatPhong::kiemTraTrungCCCD(DatPhong vitri[], int count, const string& cccd) {
    for (int i = 0; i < count; ++i) {
        if (vitri[i].getCCCD() == cccd) {
            return true; // CCCD đã tồn tại
        }
    }
    return false; // CCCD chưa tồn tại
}

void DatPhong::nhapDatPhong(DatPhong vitri[], int count) {
    bool dateTrung;
    do {
        dateTrung = false;
        Phong::nhapPhong();
        
        do {
            KhachHang::nhap(); 
            if (kiemTraTrungCCCD(vitri, count, this->getCCCD())) {
                cout << "\033[31m";
                cout << "CCCD da ton tai. Vui long nhap lai!" << endl;
                cout << "\033[0m";
            }
        } while (kiemTraTrungCCCD(vitri, count, this->getCCCD()));

        bool validDates;
        do {
            validDates = true;
            cout << "Nhap ngay den (DD/MM/YYYY): ";
            getline(cin, ngayDen);
            cout << "Nhap ngay di (DD/MM/YYYY): ";
            getline(cin, ngayDi);
            if (!kiemTrangay(ngayDen, ngayDi)) {
                validDates = false;
                cout << "\033[31m";
                cout << "Hay nhap ngay cho dung. Ngay den phai nho hon hoac bang ngay di. Vui long nhap lai!" << endl;
                cout << "\033[0m"; 
            } else {
                dateTrung = kiemTraTrungPhong(vitri, count);
                if (dateTrung) {
                    cout << "\033[31m";
                    cout << "Phong da duoc dat trong khoang thoi gian nay. Vui long chon phong khac hoac thay doi ngay!" << endl;
                    cout << "\033[0m";
                    validDates = false;
                }
            }
        } while (!validDates);
    } while (dateTrung);
}
void DatPhong::xuatDatPhong() {
    cout << "|" << left << setw(22) << hoTen 
         << "|" << setw(15) << cccd 
         << "|" << setw(12) << getSoPhong() 
         << "|" << setw(12) << ngayDen.substr(0,2) + "/" + ngayDen.substr(3,2) + "/" + ngayDen.substr(6,4)
         << "|" << setw(12) << ngayDi.substr(0,2) + "/" + ngayDi.substr(3,2) + "/" + ngayDi.substr(6,4)
         << "|" << setw(11) << gioiTinh 
         << "|" << setw(13) << sdt 
         << "|" << setw(27) << email 
         << "|" << setw(32) << diaChi << "|" << endl;
}

void DatPhong::xuatDanhSachDatPhong(DatPhong vitri[], int count) {
    cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";

    for (int i = 0; i < count; ++i) {
        vitri[i].xuatDatPhong();
        cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
}
void DatPhong::searchByCCCD(DatPhong bookings[], int count, const string &cccd) {
    bool found = false;
   cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    for (int i = 0; i < count; i++) {
        if (bookings[i].getCCCD() == cccd) {
            found = true;
            cout << "\033[1;32m"; // Green
            bookings[i].xuatDatPhong();
            cout << "\033[0m"; // Reset color
        } else {
            bookings[i].xuatDatPhong();
        }
         cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
    if (!found) {
        cout << "\033[31m"; // Red
        cout << "Khach hang voi CCCD " << cccd << " khong tim thay!" << endl;
        cout << "\033[0m"; // Reset color
    }
}

void DatPhong::searchByName(DatPhong bookings[], int count, const string &name) {
    bool found = false;
    cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";

    for (int i = 0; i < count; i++) {
        if (bookings[i].getHoTen() == name) {
            found = true;
            cout << "\033[1;32m"; // Green
            bookings[i].xuatDatPhong();
            cout << "\033[0m"; // Reset color
        } else {
            bookings[i].xuatDatPhong();
        }
                cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
    if (!found) {
        cout << "\033[31m"; // Red
        cout << "Khach hang voi ten " << name << " khong tim thay!" << endl;
        cout << "\033[0m"; // Reset color
    }
}

void xoaKhachHang(DatPhong bookings[], int &count) {
    if (count == 0) {   
        cout << "\033[31m";//red
        cout << "Khong co khach hang de xoa." << endl;
        cout << "\033[0m"; //reset 
        return;
    }
    
    int index;
    cout << "Nhap vi tri khach hang can xoa (0-" << count - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= count) {
        cout << "\033[31m";//red
        cout << "Vi tri khach hang khong hop le." << endl;
        cout << "\033[0m"; //reset 
        return;
    }

    // Chuyen cac vi tri sau vi tr xa ln m?t vi tr
    for (int i = index; i < count - 1; ++i) {
        bookings[i] = bookings[i + 1];
    }
    count--; // Giam so luong khach hang  
    cout << "\033[1;32m"; // Green
    cout << "Da xoa khach hang tai vi tri " << index << "." << endl;
    cout << "\033[0m"; // Reset color
}
int main() {
    DatPhong vitri[100]; 
    int count = 0; 
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Dat phong" << endl;
        cout << "2. Xuat thong tin dat phong" << endl;
        cout << "3. Tim kiem thong tin khach da dat phong theo CCCD" << endl;
        cout << "4. Tim kiem thong tin khach da dat phong theo ten khach hang" << endl;
        cout << "5. Xoa khach hang" << endl;
        cout << "6. Thoat" << endl;
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 100) {
                    vitri[count].nhapDatPhong(vitri, count);
                    count++;
                } else {
                    cout << "Khong the them khach hang. Phong da dat toi da." << endl;
                }
                break;
              case 2:
                if (count == 0) {
                    cout << "Khong co khach hang." << endl;
                } else {
                    DatPhong::xuatDanhSachDatPhong(vitri, count);
                }
                break;
            case 3: {
                string cccd;
                cout << "Nhap CCCD khach hang can tim: ";
                cin.ignore();
                getline(cin, cccd);
                vitri[0].searchByCCCD(vitri, count, cccd);
                break;
            }
            case 4: {
                string name;
                cout << "Nhap ten khach hang can tim: ";
                cin.ignore();
                getline(cin, name);
                vitri[0].searchByName(vitri, count, name);
                break;
            }
            case 5:
                xoaKhachHang(vitri, count);
                break;
            case 6:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (choice != 6);

    return 0;
}