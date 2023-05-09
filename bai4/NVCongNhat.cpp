#include "NVCongNhat.h"
#include <iomanip>
#include "handlingcstring.h"
NVCongNhat::NVCongNhat() : NhanVien()
{
	soNC = 0;
}

NVCongNhat::NVCongNhat(char* maNV, char* hoTen, char* gioiTinh, Date NS, char* diaChi, int soNC)
	: NhanVien(maNV, hoTen, gioiTinh, NS, diaChi), soNC(soNC)
{
}

NVCongNhat::NVCongNhat(const NhanVien nv, int so)
	: NhanVien(nv)
{
	soNC = so;
}

NVCongNhat::NVCongNhat(const NVCongNhat& nvcn)
	:NhanVien(nvcn)
{
	soNC = nvcn.soNC;
}

NVCongNhat::~NVCongNhat()
{
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& nhanvien)
{
	// TODO: insert return statement here
	NhanVien::operator=(nhanvien);
	soNC = nhanvien.soNC;
	return *this;
}

std::istream& NVCongNhat::Nhap(std::istream& is)
{
	// TODO: insert return statement here
	NhanVien::Nhap(is);
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "Nhap so ngay cong: ";
		is >> soNC;
		while (soNC > 26 || soNC < 22) {
			std::cout << "so ngay cong khong phu hop, nhap lai so ngay cong: ";
			is >> soNC;
		}
	}
	else {
		char* t;
		getline(t, is);
		soNC = atoi(t);

	}
	return is;
}

std::ostream& NVCongNhat::Xuat(std::ostream& os)
{
	// TODO: insert return statement here
	NhanVien::Xuat(os);
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << std::setw(5) << std::left << soNC;
	}
	else {
		os << soNC;
	}
	return os;
}

int NVCongNhat::Luong()
{
	return soNC * 500;
}

int NVCongNhat::getSo()
{
	return soNC;

}
