#include "CongTy.h"
#include "handlingcstring.h"
int main()
{
	CongTy Mihoyo;
	int chon;

	do {
		std::cout << "MENU" << std::endl;
		std::cout << "1. Nhap danh sach nhan vien cua cong ty" << std::endl;
		std::cout << "2. In danh sach nha vien cua cong ty" << std::endl;
		std::cout << "3. Tong luong" << std::endl;
		std::cout << "4. Nhung nhan vien co luong cao nhat" << std::endl;
		std::cout << "5. Luong trung binh" << std::endl;
		std::cout << "6. Tim nhan vien theo ma nhan vien" << std::endl;
		std::cout << "7. Tim nhan vien theo ten nhan vien" << std::endl;
		std::cout << "8. Tong nhan vien sinh trong thang 5" << std::endl;
		std::cout << "9. Them mot nhan vien moi" << std::endl;
		std::cout << "10. Xoa mot nhan vien" << std::endl;
		std::cout << "11. Ghi nhung sinh vien co luong thap hon luong trung binh vao file " << std::endl;
		std::cout << "0. Thoat" << std::endl;
		std::cout << "Lua chon cua ban: ";

		std::cin >> chon;
		switch (chon)
		{
		case 0: {
			std::cout << "cam on da su dung chuong trinh" << std::endl;
			break;
		}
		case 1: {
			std::cout << "Nhap danh sach nhan vien" << std::endl;
			std::cout << "1. Nhap vao tu ban phim" << std::endl;
			std::cout << "2. Lay thong tin tu file ds_NhanVien.dat." << std::endl;
			int k;
			std::cin >> k;

			if (k == 1) {
				Mihoyo.Nhap(std::cin);
			}
			if (k == 2) {
				Mihoyo.docFile("ds_NhanVien.dat");
			}

			break;
		}
		case 2: {
			std::cout << "Xuat danh sach nhan vien" << std::endl;
			std::cout << "1. Xuat thong tin ra man hinh" << std::endl;
			std::cout << "2. In thong tin ra file ds_NhanVien.dat." << std::endl;

			int k;
			std::cin >> k;

			if (k == 1) {
				Mihoyo.Xuat(std::cout);
			}
			if (k == 2) {
				Mihoyo.ghiFile("ds_NhanVien.dat");
			}
			break;
		}
		case 3: {
			std::cout << "Tong luong: " << Mihoyo.TongLuong();
			std::cout << std::endl;
			break;
		}
		case 4: {
			std::cout << "Nhung nhan vien co luong cao nhat" << std::endl;
			CongTy kq;
			kq = Mihoyo.NVcoLuongCaoNhat();
			kq.Xuat(std::cout);
			break;
		}
		case 5: {
			std::cout << "Luong trung binh: " << Mihoyo.LuongTrungBinh();
			std::cout << std::endl;
			break;
		}

		case 6: {
			std::cout << "Tim nhan vien theo ma" << std::endl;
			std::cout << "Nhap ma nhan vien ban muon tim: ";
			char* maNV = nullptr;
			std::cin.ignore();
			getline(maNV, std::cin);
			NhanVien* kq = Mihoyo.timtheoMa(maNV);
			std::cout << "Ket qua:  " << std::endl;
			kq->Xuat(std::cout);
			std::cout << std::endl;
			break;
		}
		case 7: {
			std::cout << "Tim nhan vien theo ten" << std::endl;
			std::cout << "Nhap ten nhan vien ban muon tim: ";
			char* tenNV = nullptr;
			std::cin.ignore();
			getline(tenNV, std::cin);
			CongTy kq = Mihoyo.timtheoTen(tenNV);
			std::cout << "Ket qua: " << std::endl;
			kq.Xuat(std::cout);
			break;
		}
		case 8: {
			std::cout << "Tong nhung nguoi sinh trong thang 5: " << Mihoyo.soNVsinhthang5();
			std::cout << std::endl;
			break;
		}
		case 9: {
			std::cout << "Them 1 nhan vien moi";
			NhanVien* nvmoi;
			std::cout << "Nhap thong tin cua nhan vien moi: " << std::endl;
			std::cout << "1. Nhan vien cong nhat " << std::endl;
			std::cout << "2. Nhan vien san xuat " << std::endl;
			std::cout << "Nhap loai nhan vien muon them: ";
			int type;
			std::cin >> type;
			if (type == 1) {
				nvmoi = new NVCongNhat;
				nvmoi->Nhap(std::cin);
				Mihoyo.them(nvmoi, "ds_NhanVien.dat");
			}
			if (type == 2) {
				nvmoi = new NVSanXuat;
				nvmoi->Nhap(std::cin);
				Mihoyo.them(nvmoi, "ds_NhanVien.dat");
			}


			break;
		}
		case 10: {
			std::cout << "Xoa mot nhan vien" << std::endl;
			std::cout << "Nhap ma nhan vien ban muon xoa: ";
			char* manv = nullptr;
			std::cin.ignore();
			getline(manv, std::cin);
			NhanVien* nvcu = Mihoyo.timtheoMa(manv);
			Mihoyo.xoa(nvcu, "ds_NhanVien.dat");
			break;
		}
		case 11: {
			std::cout << "Ghi thon tin cua nhung nhan vien co luong nho hon luong trung binh cua cong ty vao file" << std::endl;
			Mihoyo.ghiNVcoLuongNhoHon();
			break;
		}

		default:
			std::cout << "khong co tac vu nay, hay thu lai!!!";
			break;
		}
		std::cout << "---------------------------------------------------------------------------------------" << std::endl;
	} while (chon != 0);
	return 1;
}