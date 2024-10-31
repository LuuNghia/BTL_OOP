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
class NhanVien:public Nguoi{
	private:
		string chucVu;
		string id;
		double luong;
		static string dsID[200]; 
        static int soLuongID;
	public:
		NhanVien();
		NhanVien(string id,string chucVu,double luong);
		NhanVien(const NhanVien &NV);
        static bool kiemTraID(const string& id);
		void nhapNV();
		void xuatNV();
		void nhapDanhSachNV(NhanVien ds[], int n);
        void xuatDanhSachNV( NhanVien ds[], int n);
        void sapXepTheoID(NhanVien ds[], int n);
        void sapXepTheoHoTen(NhanVien ds[], int n);
        void timKiemTheoID(NhanVien ds[],int n,string ID);
        void timKiemTheoHoTen(NhanVien ds[],int n,string ten);
        void timKiemNVLuongCaoNhat(NhanVien ds[],int n);
        void timKiemTheoCCCD(NhanVien ds[],int n,string x);
};
string NhanVien::dsID[200];
int NhanVien::soLuongID = 0;
NhanVien::NhanVien():Nguoi(){
	id=" ";
	chucVu=" ";
	luong=0;
}
NhanVien::NhanVien(string id,string chucVu,double luong):Nguoi(){
	this->id=id;
	this->chucVu=chucVu;
	this->luong=luong;
}
NhanVien::NhanVien(const NhanVien &NV):Nguoi(NV){
	this->id=NV.id;
	this->chucVu=NV.chucVu;
	this->luong=NV.luong;
}
//kiem tra id co trung hay khong
bool NhanVien::kiemTraID(const string& id){
    for(int i = 0; i < soLuongID; i++){
        if(dsID[i] == id){
            return true;
        }
    }
    return false;
}

//nhap 1 nhan vien
void NhanVien::nhapNV(){
    while(true){
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        if(!kiemTraID(id)){ 
            dsID[soLuongID++] = id; 
            break;
        }else{
        	cout << "\033[31m";//red
            cout << "ID da ton tai! Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }
	Nguoi::nhap();
	cout<<"Nhap chuc vu: ";
	getline(cin,chucVu);
	cout<<"Nhap luong trung binh: ";
	cin>>luong;		
}
//xuat 1 nhan vien
void NhanVien::xuatNV(){
    cout << "|" << left<< setw(12) << id 
			    << "|" << setw(22) << hoTen 
			    << "|" << setw(11) << gioiTinh 
		        << "|" << setw(3) << setfill('0') << ngaySinh 
                << "/" << setw(2) << setfill('0') << thangSinh 
                << "/" << setw(4) << setfill('0') << namSinh << setfill(' ')
		        << "|" << setw(15) << cccd
		        << "|" << setw(12) << sdt 
		        << "|" << setw(27) << email 
		        << "|" << setw(32) << diaChi
				<< "|" << setw(20) << chucVu  
				<< "|" << setw(14) << fixed << setprecision(2) << luong << "|" << endl;
}
//Nhap danh sach nhan vien
void NhanVien:: nhapDanhSachNV(NhanVien ds[],int n){
	for(int i=0;i<n;i++){
		cout<<"============================================"<<endl;
		cout<<"Nhap nhan vien thu "<<i+1<<":"<<endl;
		ds[i].nhapNV();
	}
}
//xuat danh sach sinh vien
void NhanVien::xuatDanhSachNV( NhanVien ds[],int n){
    cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
    cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
    cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
    for(int i=0;i<n;i++){
    	ds[i].xuatNV();
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";

	}
}
//sap xep tang dan theo ID
void NhanVien::sapXepTheoID(NhanVien ds[], int n){
	cout<<"Danh sach nhan vien sau khi sap xep theo ID:"<<endl;
	cout<<"============================================"<<endl;
	int pos;
	NhanVien x;
	for(int i=1; i<n; i++){
		x = ds[i]; pos = i-1;
		while((pos>=0)&&(ds[pos].id>x.id)){
			ds[pos+1] = ds[pos];
			pos--;
		}
		ds[pos+1] = x;
	}
}
//sap xep theo ho ten
void NhanVien::sapXepTheoHoTen(NhanVien ds[], int n){
    cout<<"Danh sach nhan vien sau khi sap xep theo ho ten:"<<endl;
    cout<<"============================================"<<endl;
    for(int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (ds[i].hoTen > ds[j].hoTen){
                NhanVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}
//tim kiem theo ID
void NhanVien::timKiemTheoID(NhanVien ds[],int n,string ID){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].id==ID){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co ID: "<<ID<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem theo ho ten
void NhanVien::timKiemTheoHoTen(NhanVien ds[],int n,string ten){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].hoTen==ten){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co ho ten: "<<ten<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem theo so CCCD
void NhanVien::timKiemTheoCCCD(NhanVien ds[],int n,string x){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].cccd==x){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
            cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co so CCCD: "<<x<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem nhan vien co muc luong cao nhat
void NhanVien::timKiemNVLuongCaoNhat(NhanVien ds[],int n){
	cout << "Thong tin nhan vien co muc luong cao nhat :" << endl;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	int max=0;
	for(int i=0;i<n;i++){
		if(ds[i].luong>ds[max].luong){
			max=i;
			cout << "\033[1;32m"; // Green
            ds[max].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
            cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
}
int main(){
	int choice;
	NhanVien NV;
	NhanVien *ds = NULL;
	do{
	cout<<"====================MENU===================="<<endl;
	cout<<"1.Nhap so luong nhan vien!"<<endl;
	cout<<"2.Nhap danh sach nhan vien!"<<endl;
    cout<<"3.Xuat danh sach nhan vien!" << endl;
    cout<<"4.Sap xep nhan vien tang dan theo ID!"<<endl;
    cout<<"5.Sap xep nhan vien tang dan theo ho ten!"<<endl;
    cout<<"6.Tim kiem nhan vien theo ID!"<<endl;
    cout<<"7.Tim kiem nhan vien theo ho ten!"<<endl;
    cout<<"8.Tim kiem nhan vien co luong cao nhat!"<<endl;
    cout<<"9.Tim kiem nhan vien theo so CCCD!"<<endl;
    cout<<"0.Thoat!"<<endl;
    cout<<"============================================"<<endl;
    cout<<"Xin moi nhap lua chon cua ban: ";
    cin>>choice;
    switch (choice){
            case 1:
            	int n;
				cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				ds = new NhanVien[n];
                break;
            case 2:
                if(ds!=NULL){
                	NV.nhapDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap so luong nhan vien!"<< endl;
                }
                break;
            case 3:
                if(ds!=NULL){
                	cout<<"DANH SACH NHAN VIEN"<<endl;
					NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 4:
                if(ds!=NULL){
	                NV.sapXepTheoID(ds,n);
	                NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 5:
                if(ds!=NULL){
                    NV.sapXepTheoHoTen(ds,n);
    				NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 6:
                if(ds!=NULL){
				    cout<<"Nhap ID cua nhan vien can tim: ";
				    string ID;
					cin.ignore();
					getline(cin,ID);
					cout<<"============================================"<<endl;
				    NV.timKiemTheoID(ds,n,ID);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 7:
                if(ds!=NULL){
				    cout<<"Nhap ho ten cua nhan vien can tim: ";
				    string ten;
				    cin.ignore();
				    getline(cin, ten);
				    cout<<"============================================"<<endl;
				    NV.timKiemTheoHoTen(ds,n,ten);
                } else {
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 8:
                if(ds!=NULL){
                	NV.timKiemNVLuongCaoNhat(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 9:
                if(ds!=NULL){
				    cout<<"Nhap so CCCD cua nhan vien can tim: ";
				    string x;
					cin.ignore();
					getline(cin,x);
					cout<<"============================================"<<endl;
				    NV.timKiemTheoCCCD(ds,n,x);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 0:
                cout<<"Thoat chuong trinh!"<<endl;
                break;
            default:
                cout<<"Lua chon khong hop le! Vui long nhap lai."<<endl;
        }
    }while(choice!=0);
 
	return 0;
}
