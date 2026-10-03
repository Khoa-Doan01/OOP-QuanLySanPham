#include <iostream> 
#include <string> 
#include <iomanip>
using namespace std;
//Issue 2
class Sanpham
{
	private :
		string MaSP;
		string TenSP;
		string DonViTinh;
		double DonGia;
		int SlTonKho;
	public :
		//Constructor mac dinh
		Sanpham()
		{
			MaSP="";
			TenSP="";
			DonViTinh="";
			DonGia=0.0;
			SlTonKho=0;
		} 
		//Constructor day du tham so
		Sanpham (string ma, string ten, string donvi, double gia, int sl)
		{
			MaSP=ma;
			TenSP=ten;
			DonViTinh=donvi;
			DonGia=gia;
			SlTonKho=sl;
		 } 
		 //Getter
		 string getMaSP() const
		 {
		 	return MaSP;
		 }
		 string getTenSP() const
		 {
		 	return TenSP;
		 }
		 string getDonViTinh() const
		 {
		 	return DonViTinh;
		 }
		 double getDonGia () const
		 {
		 	return DonGia;
		 }
		 int getSlTonKho () const
		 {
		 	return SlTonKho;
		 }
		 //Setter
		 void setMaSP(string ma)
		 {
		 	MaSP=ma;
		 }
		 void setTenSP(string ten)
		 {
		 	TenSP=ten;
		 }
		 void setDonViTinh(string donvi)
		 {
		 	DonViTinh=donvi;
		 }
		 void setDonGia(double gia)
		 {
		 	DonGia=gia;
		 }
		 void setSlTonKho(int sl)
		 {
		 	SlTonKho=sl;
		 }
		 //Nhap,xuat
		 void nhap();
		 void xuat() const;
};
//Nhap xuat san pham
void Sanpham::nhap()
{
	cout<<"Nhap ma san pham: ";
	getline(cin,MaSP);
	
	cout<<"Nhap ten san pham: ";
	getline(cin,TenSP);
	
	cout<<"Nhap don vi tinh: ";
	getline(cin,DonViTinh);
	
	cout<<"Nhap don gia: ";
	cin>>DonGia;
	
	cout<<"Nhap so luong ton: ";
	cin>>SlTonKho;
	 
	cin.ignore();
}
void Sanpham::xuat() const
{
    cout << left
         << setw(10) << MaSP
         << setw(25) << TenSP
         << setw(15) << DonViTinh
         << right << setw(15) << DonGia
         << setw(15) << SlTonKho
         << endl;
}
//Issue 3
class QuanLySanPham
{
	private:
		Sanpham ds[200];// (mang 0<n<200) 
		int SoLuong;
	public:
		QuanLySanPham()
		{
			SoLuong=0;
		}
		void NhapDanhSach();
		void InDanhSach() const;
		void SapXep();
		void TimKhiem();
		void Them();
		void Xoa();
};
void QuanLySanPham::NhapDanhSach()
{
	do
	{
		cout<<"Nhap so luong san pham (0 < n < 200): ";
		cin>>SoLuong;
		if(SoLuong<=0||SoLuong>=200)
		{
			cout<<"So luong san pham khong hop le vui long nhap lai.\n"; 
		 } 
	}while(SoLuong<=0||SoLuong>=200);
	cin.ignore();
	for (int i=0;i<SoLuong;i++)
	{
		cout<<"\nNhap san pham thu "<<i+1<<"\n";
		ds[i].nhap(); 
	} 
}
void QuanLySanPham::InDanhSach() const
{
    if (SoLuong == 0)
    {
        cout << "Danh sach hang hoa rong\n";
        return;
    }
    cout << "\nDANH SACH SAN PHAM\n";
    cout << left
         << setw(5)  << "STT"
         << setw(10) << "MaSP"
         << setw(25) << "TenSP"
         << setw(15) << "DonViTinh"
         << right << setw(15) << "DonGia"
         << setw(15) << "SlTonKho"
         << endl;
    cout << string(85, '-') << endl;
    for (int i = 0; i < SoLuong; i++)
    {
        cout << left << setw(5) << i + 1;
        ds[i].xuat();
    }
}
//Issue 4
void QuanLySanPham::SapXep()
{
	for (int i=0;i<SoLuong-1;i++)
	{
		for (int j=0; j<SoLuong-i-1;j++)
		{
			if (ds[j].getDonGia()>ds[j+1].getDonGia())
			{
				Sanpham temp= ds[j];
				ds[j]=ds[j+1];
				ds[j+1]= temp;
			}
		}
	}
	cout<<"\n Da sap xep danh sach theo don gia tang dan\n";
}
//Issue 5
void QuanLySanPham::TimKhiem()
{
	string MaCanTim;
	cout<< "Nhap ma san pham can tim: ";
	getline(cin,MaCanTim);
	bool Timthay=false;
	for (int i=0;i< SoLuong;i++)
	{
		if(ds[i].getMaSP()==MaCanTim)
		{
			cout<<"\nTim thay san pham:\n";
			cout<<"MaSP\t"
			    <<"TenSP\t"
			    <<"DonViTinh\t"
			    <<"DonGia\t"
			    <<"SlTonKho\n";
			ds[i].xuat();
			Timthay=true;
			break;
		}
	}
	if (!Timthay)
	{
		cout<<"Khong tim thay san pham voi ma vua nhap\n";
	}
}
//Issue 6
void QuanLySanPham::Them()
{
	if(SoLuong>=200)
	{
		cout<<"Danh sach da day, khong the them\n";
		return;
	}
	int k;
	do
	{
		cout<<"Nhap vi tri can them (0<=k<="<<SoLuong<<"):";
		cin>>k;
		if (k<0||k>SoLuong)
		{
			cout<<"Vi tri khong hop le hay nhap lai\n";
		}
	}while(k<0||k>SoLuong);
	cin.ignore();
	Sanpham sp;
	cout<<"\nNhap san pham moi\n";
	sp.nhap();
	for(int i=SoLuong;i>k;i--)
	{
		ds[i]=ds[i-1];
	}
	ds[k]=sp;
	SoLuong++;
	cout<<"Da them san pham vao danh sach\n";
}
void QuanLySanPham::Xoa()
{
	if(SoLuong==0){
		cout<<"Danh sach hang hoa rong, khong the xoa\n";
		return;
	}
	int k;
	do
	{
		cout<<"Nhap vi tri can xoa (0 <= k < "<<SoLuong<<"):";
		cin>>k;
		if (k<0||k>=SoLuong)
		{
			cout<<"Vi tri khong hop le, nhap lai\n";
		}
	}while(k<0||k>=SoLuong);
	for (int i=k;i<SoLuong-1;i++)
	{
		ds[i]=ds[i+1];
	}
	SoLuong--;
	cout<<"Xoa san pham thanh cong\n";
}
int main()
{
	QuanLySanPham ql;
	int LuaChon;
	do
	{
		cout<<"\n\n1.Nhap danh sach san pham\n";
		cout<<"2.In danh sach san pham\n";
		cout<<"3.Sap xep theo don gia tang dan\n";
		cout<<"4.Tim kiem san pham theo ma\n";
		cout<<"5.Them san pham tai vi tri k\n";
		cout<<"6.Xoa san pham tai vi tri k\n";
		cout<<"0.Thoat chuong trinh chay\n";
		cout<<"\nNhap lua chon: ";
		cin>>LuaChon;
		cin.ignore();
		switch (LuaChon)
		{
		case 1:
			ql.NhapDanhSach();
			break;
		case 2:
		    ql.InDanhSach();
			break;
		case 3:
			ql.SapXep();
			ql.InDanhSach();
			break;	
		case 4:
			ql.TimKhiem();
			break;
		case 5:
			ql.Them();
			break;
		case 6:
			ql.Xoa();
			break;
		case 0:
			cout<<"Ket thuc chuong trinh\n";
			break;
		default:
			cout<<"Lua chon khong hop le\n";
		}
	}while (LuaChon !=0);
	return 0;
}
 
