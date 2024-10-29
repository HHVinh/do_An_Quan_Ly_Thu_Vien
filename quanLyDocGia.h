#ifndef QUAN_LY_DOC_GIA_H
#define QUAN_LY_DOC_GIA_H

#include <stdio.h>

#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "quanLySach.h"
#include "thongKe.h"

// Định nghĩa các hằng số
#define MAX_DOC_GIA 100
#define MAX_TEN 50
#define MAX_CCCD 13
#define MAX_MA_DOC_GIA 5
#define MAX_EMAIL 50
#define MAX_DIACHI 100
#define MAX_GIOITINH 10
#define MAX_NGAYSINH 11
#define MAX_NGAYTHET 11


// Hàm hiển thị menu quản lý độc giả
void hienThiMenuQuanLyDocGia();

// Hàm xem danh sách độc giả
void xemDanhSachDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                        char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                        char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                        int demDocGia);

// Hàm thêm độc giả
void themDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13], 
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50], 
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11], 
                int *demDocGia);

// Hàm chỉnh sửa độc giả
void chinhSuaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                     char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                     char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                     int demDocGia);

// Hàm xóa độc giả
void xoaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                int *demDocGia);

// Hàm tìm kiếm độc giả theo CCCD
void timKiemTheoCCCD(char dsCCCD[][13], char dsMaDocGia[][5], char dsTenDocGia[][50],
                      char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                      char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                      int demDocGia);

// Hàm tìm kiếm độc giả theo họ tên
void timKiemTheoHoTen(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                       char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                       char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                       int demDocGia);

#endif // QUAN_LY_DOC_GIA_H

