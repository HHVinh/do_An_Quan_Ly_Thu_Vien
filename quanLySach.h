#ifndef QUAN_LY_SACH_H
#define QUAN_LY_SACH_H

#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "thongKe.h"

// Định nghĩa các hằng số
#define MAX_SACH 100   // Số lượng sách tối đa

// Khai báo các hàm sử dụng trong file quanLySach.c

// Hàm hiển thị menu quản lý sách
void hienThiMenuQuanLySach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50], 
                            char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
                            int demSach);

// Hàm xem danh sách sách
void xemDanhSachSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                     char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
                     int demSach);

// Hàm thêm sách
void themSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
              char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
              int *demSach);

// Hàm chỉnh sửa thông tin sách
void chinhSuaThongTinSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                          char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
                          int demSach);

// Hàm xóa sách
void xoaSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
             char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
             int *demSach);

// Hàm tìm kiếm sách theo ISBN
void timKiemSachTheoISBN(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                         char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
                         int demSach);

// Hàm tìm kiếm sách theo tên sách
void timKiemSachTheoTenSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                            char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
                            int demSach);

#endif // QUAN_LY_SACH_H


