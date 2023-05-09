#ifndef _NVCONGNHAT_H_
#define _NVCONGNHAT_H_


#include "NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
	int soNC;
public:
	//constructor 
	NVCongNhat();
	NVCongNhat(char* maNV, char* hoTen, char* gioiTinh, Date NS, char* diaChi, int soNC);
	NVCongNhat(const NhanVien nv, int so);
	NVCongNhat(const NVCongNhat& nvcn);
	//destructor 
	~NVCongNhat();
	//
	NVCongNhat& operator= (const NVCongNhat& nhanvien);
	//input 
	std::istream& Nhap(std::istream& is);
	//xuat
	std::ostream& Xuat(std::ostream& os);
	//
	int Luong();
	int getSo();
};

#endif // !_NVCONGNHAT_H_