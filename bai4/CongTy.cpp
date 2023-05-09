#include "CongTy.h"
#include <fstream>
#include <iomanip>
#include "handlingcstring.h"
CongTy::CongTy()
{
	dsNV = nullptr;
	sl = 0;
}

CongTy::CongTy(int sl)
{
	if (sl != 0) {
		for (int i = 0; i < sl; i++) {
			delete dsNV[i];
		}
	}
	this->sl = sl;
	dsNV = new NhanVien * [sl];
	for (int i = 0; i < sl; i++) {
		dsNV[i] = nullptr;
	}
}

CongTy::CongTy(const CongTy& congty)
{
	dsNV = congty.dsNV;
	sl = congty.sl;
}

CongTy::~CongTy()
{
	if (sl > 0) {
		for (int i = 0; i < sl; i++) {
			delete dsNV[i];
		}
	}
	delete[]dsNV;
	sl = 0;
}

CongTy& CongTy::operator=(const CongTy& congty)
{
	sl = congty.sl;
	dsNV = new NhanVien * [sl];
	for (int i = 0; i < sl; i++) {
		if (typeid(*congty.dsNV[i]) == typeid(NVCongNhat)) {
			NVCongNhat t(*congty.dsNV[i], congty.dsNV[i]->getSo());
			dsNV[i] = new NVCongNhat(t);
		}
		if (typeid(*congty.dsNV[i]) == typeid(NVSanXuat)) {
			NVSanXuat t(*congty.dsNV[i], congty.dsNV[i]->getSo());
			dsNV[i] = new NVSanXuat(t);
			//*dsNV[i] = t;
		}
	}
	return *this;
}

std::istream& CongTy::Nhap(std::istream& is)
{
	// TODO: insert return statement here
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "Nhap thong tin cho nhan vien: " << std::endl;
		int key;
		while (1) {
			std::cout << "Nhap 1 de them nhan vien la nhan vien cong nhat" << std::endl;
			std::cout << "Nhap 2 de them nhan vien la nhan vien san xuat" << std::endl;
			std::cout << "nhap 0 de thoat them nhan vien" << std::endl;
			std::cout << "Nhap loai nhan vien muon them: ";


			std::cin >> key;
			if (key == 1) {
				NhanVien* t = new NVCongNhat;
				t->Nhap(is);
				them(t);
			}
			if (key == 2) {
				NhanVien* t = new NVSanXuat;
				t->Nhap(is);
				them(t);
			}
			if (key == 0) {
				break;
			}
		}
	}
	return is;
}

std::ostream& CongTy::Xuat(std::ostream& os)
{
	// TODO: insert return statement here
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << std::setw(15) << std::left << "MaNV";
		os << std::setw(30) << std::left << "Ho Ten";
		os << std::setw(10) << std::left << "Gioi tinh";
		os << std::setw(15) << std::left << "Ngay sinh";
		os << std::setw(30) << std::left << "Dia chi";
		os << "So SP / So NC" << std::endl;
		for (int i = 0; i < sl; i++) {
			dsNV[i]->Xuat(os);
			os << std::endl;
		}
	}
	return os;
}

void CongTy::docFile(const char* filename)
{
	if (sl > 0) {
		for (int i = 0; i < sl; i++) {
			delete dsNV[i];
		}
		delete[]dsNV;
		dsNV = nullptr;
		sl = 0;
	}
	std::ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		std::cout << "Khong mo duoc file " << filename << std::endl;
		return;
	}

	while (!fin.eof()) {
		// doc file dat 
		NhanVien nv;
		nv.Nhap(fin);
		int so;
		fin >> so;
		fin.ignore();
		if (so < 16) {
			NhanVien* t = new NVSanXuat(nv, so);
			them(t);
		}
		else {
			NhanVien* t = new NVCongNhat(nv, so);
			them(t);
		}
	}
	fin.close();
}

void CongTy::ghiFile(const char* filename)
{
	std::ofstream fout;
	fout.open(filename);
	if (!fout.is_open()) {
		std::cout << "Khong mo duoc file " << filename << std::endl;
		return;
	}
	for (int i = 0; i < sl - 1; i++) {
		dsNV[i]->Xuat(fout);
		fout << std::endl;
	}
	dsNV[sl - 1]->Xuat(fout);
	fout.close();
}

int CongTy::soluong()
{
	return sl;
}

int CongTy::TongLuong()
{
	int tongLuong = 0;
	for (int i = 0; i < sl; i++) {
		tongLuong += dsNV[i]->Luong();
	}
	return tongLuong;
}

float CongTy::LuongTrungBinh()
{
	return (float)TongLuong() / sl;
}

CongTy CongTy::NVcoLuongCaoNhat()
{
	int LuongCaoNhat = 0;
	for (int i = 0; i < sl; i++) {
		int luong = dsNV[i]->Luong();
		if (LuongCaoNhat < luong) LuongCaoNhat = luong;
	}
	CongTy* nvLuongCaoNhat = new CongTy;
	for (int i = 0; i < sl; i++) {
		if (dsNV[i]->Luong() == LuongCaoNhat) {
			NhanVien* thoaman = nullptr;
			if (typeid(*dsNV[i]) == typeid(NVCongNhat)) {
				NVCongNhat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVCongNhat(t);
			}
			if (typeid(*dsNV[i]) == typeid(NVSanXuat)) {
				NVSanXuat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVSanXuat(t);
			}
			nvLuongCaoNhat->them(thoaman);
		}
	}
	return *nvLuongCaoNhat;
}

NhanVien* CongTy::timtheoMa(char* maNV)
{
	NhanVien* kq = nullptr;
	for (int i = 0; i < sl; i++) {
		if (strcmp(dsNV[i]->getMaNV(), maNV) == 0) {
			kq = dsNV[i];
		}
	}
	return kq;
}

CongTy CongTy::timtheoTen(char* tenNV)
{
	CongTy* dsNguoiCungTen = new CongTy;
	for (int i = 0; i < sl; i++) {
		if (strcmp(dsNV[i]->getHoTen(), tenNV) == 0) {
			NhanVien* thoaman = nullptr;
			if (typeid(*dsNV[i]) == typeid(NVCongNhat)) {
				NVCongNhat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVCongNhat(t);
			}
			if (typeid(*dsNV[i]) == typeid(NVSanXuat)) {
				NVSanXuat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVSanXuat(t);
			}
			dsNguoiCungTen->them(thoaman);

		}
	}
	return *dsNguoiCungTen;
}

int CongTy::soNVsinhthang5()
{
	int tong = 0;
	for (int i = 0; i < sl; i++) {
		if (dsNV[i]->sinhThang5()) tong++;
	}
	return tong;

}

void CongTy::them(NhanVien* NVmoi)
{
	if (NVmoi == nullptr) return;
	++sl;
	NhanVien** tam = new NhanVien * [sl];
	for (int i = 0; i < sl - 1; i++)
		tam[i] = nullptr;
	for (int i = 0; i < sl - 1; i++) {
		tam[i] = dsNV[i];
	}
	tam[sl - 1] = NVmoi;
	delete[] dsNV;
	dsNV = tam;
}

void CongTy::xoa(NhanVien* NVcu)
{
	if (NVcu == nullptr) {
		std::cout << "da khong ton tai nguoi nay, khong the thuc hien tac vu" << std::endl;
		return;
	}
	for (int i = 0; i < sl; i++) {
		if (NVcu->getMaNV() == dsNV[i]->getMaNV()) {
			for (int j = i; j < sl - 1; j++) {
				dsNV[j] = dsNV[j + 1];
			}
			//delete dsNV[sl];
			--sl;
			return;
		}
	}
}

void CongTy::ghiNVcoLuongNhoHon()
{
	CongTy* thaphon = new CongTy;
	for (int i = 0; i < sl; i++) {
		if (dsNV[i]->Luong() < LuongTrungBinh()) {
			NhanVien* thoaman = nullptr;
			if (typeid(*dsNV[i]) == typeid(NVCongNhat)) {
				NVCongNhat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVCongNhat(t);
			}
			if (typeid(*dsNV[i]) == typeid(NVSanXuat)) {
				NVSanXuat t(*dsNV[i], dsNV[i]->getSo());
				thoaman = new NVSanXuat(t);
			}
			thaphon->them(thoaman);

		}
	}
	thaphon->ghiFile("emp_LowerAvgSalary.dat");
	delete thaphon;
}

void CongTy::them(NhanVien* NVmoi, const char* filename)
{
	them(NVmoi);
	ghiFile(filename);
}

void CongTy::xoa(NhanVien* NVcu, const char* filename)
{
	xoa(NVcu);
	ghiFile(filename);
}
