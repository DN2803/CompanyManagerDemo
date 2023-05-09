#define _CRT_SECURE_NO_WARNINGS
#include "NhanVien.h"
#include "handlingcstring.h"
#include <iomanip>
#include <ctime>
NhanVien::NhanVien()
{
	maNV = NULL;
	hoTen = NULL;
	gioiTinh = 0;
	ngaySinh;
	diaChi = NULL;
}

NhanVien::NhanVien(char* maNV, char* hoTen, char* gioiTinh, Date ngaySinh, char* diaChi)
{
	strcpy(this->maNV, strlen(maNV), maNV);
	strcpy(this->hoTen, strlen(hoTen), hoTen);
	strcpy(this->gioiTinh, strlen(gioiTinh), gioiTinh);
	this->ngaySinh = ngaySinh;
	strcpy(this->diaChi, strlen(diaChi), diaChi);
}

NhanVien::NhanVien(const NhanVien& nhanVien)
{
	strcpy(maNV, strlen(nhanVien.maNV), nhanVien.maNV);
	strcpy(hoTen, strlen(nhanVien.hoTen), nhanVien.hoTen);
	strcpy(gioiTinh, strlen(nhanVien.gioiTinh), nhanVien.gioiTinh);
	ngaySinh = nhanVien.ngaySinh;
	strcpy(diaChi, strlen(nhanVien.diaChi), nhanVien.diaChi);
}

NhanVien::~NhanVien()
{
	delete[] maNV;
	delete[] hoTen;
	delete[] gioiTinh;
	delete[] diaChi;
}

char* NhanVien::getMaNV()
{
	return maNV;
}

char* NhanVien::getHoTen()
{
	return hoTen;
}

NhanVien& NhanVien::operator=(NhanVien nhanvien)
{
	// TODO: insert return statement here
	strcpy(maNV, strlen(nhanvien.maNV), nhanvien.maNV);
	strcpy(hoTen, strlen(nhanvien.hoTen), nhanvien.hoTen);
	strcpy(gioiTinh, strlen(nhanvien.gioiTinh), nhanvien.gioiTinh);
	ngaySinh = nhanvien.ngaySinh;
	strcpy(diaChi, strlen(nhanvien.diaChi), nhanvien.diaChi);
	return *this;
}

std::istream& NhanVien::Nhap(std::istream& is)
{
	// TODO: insert return statement here
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "\nnhap ma nhan vien:  ";

		is.ignore();
		getline(maNV, is);
		std::cout << "nhap ten nhan vien: ";
		getline(hoTen, is);
		std::cout << "nhap gioi tinh (nam hoac nu): ";
		getline(gioiTinh, is);
		while (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
			std::cout << "Gioi tinh khong hop le, ";
			std::cout << "Nhap lai gioi tinh: ";
			getline(hoTen, is);
		}

		std::cout << "nhap ngay sinh cua nhan vien theo dang dd/mm/yyyy: ";
		is >> ngaySinh;
		if (strcmp(gioiTinh, "nam")) {
			while (Tuoi() > 60 || Tuoi() < 18) {
				std::cout << "Tuoi khong hop le, ";
				std::cout << "Nhap lai ngay sinh co nam sinh phu hop: ";
				is >> ngaySinh;
			}
		}
		else {
			while (Tuoi() > 55 || Tuoi() < 18) {
				std::cout << "Tuoi khong hop le, ";
				std::cout << "Nhap lai ngay sinh co nam sinh phu hop: ";
				is >> ngaySinh;
			}
		}

		std::cout << "nhap dia chi cua nhan vien: ";
		is.ignore();
		getline(diaChi, is);

	}
	else {
		getline(maNV, is, ',');
		getline(hoTen, is, ',');
		getline(gioiTinh, is, ',');
		is >> ngaySinh;
		getline(diaChi, is, ',');

	}
	return is;
}

std::ostream& NhanVien::Xuat(std::ostream& os)
{
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << std::setw(15) << std::left << maNV;
		os << std::setw(30) << std::left << hoTen;
		os << std::setw(10) << std::left << gioiTinh;
		os << std::setw(15) << std::left << ngaySinh;
		os << std::setw(30) << std::left << diaChi;
	}
	else {
		os << maNV << ",";
		os << hoTen << ",";
		os << gioiTinh << ",";
		os << ngaySinh << ",";
		os << diaChi << ",";
	}
	return os;
}

bool NhanVien::sinhThang5()
{
	int thang = ngaySinh.getMonth();
	if (thang == 5) return true;
	return false;
}

int NhanVien::Tuoi()
{
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	int namHT = 1900 + ltm->tm_year;
	return namHT - ngaySinh.getYear();
}

