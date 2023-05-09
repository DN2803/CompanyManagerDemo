#ifndef _NHANVIEN_H_
#define _NHANVIEN_H_


#include "Date.h"

class NhanVien
{
private:
	char* maNV;
	char* hoTen;
	char* gioiTinh;
	Date ngaySinh;
	char* diaChi;
public:
	// constructor 
	NhanVien();
	NhanVien(char* maNV, char* hoTen, char* gioiTinh, Date ngaySinh, char* diaChi);
	NhanVien(const NhanVien& nhanVien);
	// Destructor
	~NhanVien();
	//gettor
	char* getMaNV();
	char* getHoTen();
	virtual int getSo() { return 0; };
	//settor
	// 
	//operator =
	virtual NhanVien& operator= (NhanVien nhanvien);
	//Input
	virtual std::istream& Nhap(std::istream& is);
	//Output
	virtual std::ostream& Xuat(std::ostream& os);

	virtual int Luong() { return 0; };
	bool sinhThang5();
	int Tuoi();
};

#endif // !_NHANVIEN_H_