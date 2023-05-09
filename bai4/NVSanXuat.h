#ifndef _NVSANXUAT_H_
#define _NVSANXUAT_H_


#include "NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
	int soSP;
public:
	//constructor 
	NVSanXuat();
	NVSanXuat(char* maNV, char* hoTen, char* gioiTinh, Date NS, char* diaChi, int soSP);
	NVSanXuat(const NVSanXuat& nvsx);
	NVSanXuat(const NhanVien& nv, int so);
	//destructor 
	~NVSanXuat();
	//
	NVSanXuat& operator=(const NVSanXuat& nhanvien);
	//input 
	std::istream& Nhap(std::istream& is);
	//xuat
	std::ostream& Xuat(std::ostream& os);
	//
	int Luong();
	int getSo();

};

#endif // !_NVSANXUAT_H_