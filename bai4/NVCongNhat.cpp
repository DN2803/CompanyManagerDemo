#include "NVCongNhat.h"
#include <iomanip>
#include "handlingcstring.h"
#include "exception.h"
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
		while (1) {
			try {
				is >> soNC;
				if (soNC > 26 || soNC < 22) throw Exception("Loi: so ngay cong khong hop le, so ngay cong trong khoang 22 toi 26\n");
				break;
			}
			catch (Exception e) {
				cout << e.getMessage();
				cout << "hay nhap lai so ngay cong: ";
			}
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
