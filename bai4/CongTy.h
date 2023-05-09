#ifndef _CONGTY_H
#define _CONGTY_H


#include "NVCongNhat.h"
#include "NVSanXuat.h"
class CongTy
{
private:
	NhanVien** dsNV;
	int sl;
public:
	CongTy();
	CongTy(int sl);
	CongTy(const CongTy& congty);
	~CongTy();
	CongTy& operator= (const CongTy& congty);
	std::istream& Nhap(std::istream& is);
	std::ostream& Xuat(std::ostream& os);
	void docFile(const char* filename);
	void ghiFile(const char* filename);
	int soluong();
	int TongLuong();
	float LuongTrungBinh();
	CongTy NVcoLuongCaoNhat();
	NhanVien* timtheoMa(char* maNV);
	CongTy timtheoTen(char* tenNV);
	int soNVsinhthang5();
	void them(NhanVien* NVmoi);
	void xoa(NhanVien* NVcu);
	void ghiNVcoLuongNhoHon();
	void them(NhanVien* NVmoi, const char* filename);
	void xoa(NhanVien* NVcu, const char* filename);


};
#endif // !_CONGTY_H
