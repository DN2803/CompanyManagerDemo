#include "NVSanXuat.h"
#include "handlingcstring.h"
#include <iomanip>
NVSanXuat::NVSanXuat() : NhanVien()
{
	soSP = 0;
}

NVSanXuat::NVSanXuat(char* maNV, char* hoTen, char* gioiTinh, Date NS, char* diaChi, int soSP)
	: NhanVien(maNV, hoTen, gioiTinh, NS, diaChi), soSP(soSP)
{
}

NVSanXuat::NVSanXuat(const NVSanXuat& nvcn)
	:NhanVien(nvcn)
{
	soSP = nvcn.soSP;
}

NVSanXuat::NVSanXuat(const NhanVien& nv, int so) : NhanVien(nv)
{
	soSP = so;
}

NVSanXuat::~NVSanXuat()
{
}

NVSanXuat& NVSanXuat::operator=(const NVSanXuat& nhanvien)
{
	// TODO: insert return statement here
	NhanVien::operator=(nhanvien);
	soSP = nhanvien.soSP;
	return *this;
}

std::istream& NVSanXuat::Nhap(std::istream& is)
{
	// TODO: insert return statement here
	NhanVien::Nhap(is);
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "Nhap so san pham: ";
		is >> soSP;
		while (soSP > 15 || soSP < 10) {
			std::cout << "so san pham khong phu hop, nhap lai so san pham: ";
			is >> soSP;
		}
	}
	else {
		char* t;
		getline(t, is);
		soSP = atoi(t);
	}
	return is;
}

std::ostream& NVSanXuat::Xuat(std::ostream& os)
{
	// TODO: insert return statement here
	NhanVien::Xuat(os);
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << std::setw(5) << std::left << soSP;
	}
	else {
		os << soSP;
	}
	return os;
}

int NVSanXuat::Luong()
{
	return 50 * soSP;
}

int NVSanXuat::getSo()
{
	return soSP;
}
