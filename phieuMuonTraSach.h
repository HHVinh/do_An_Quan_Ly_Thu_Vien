// quanLyMuonTraSach.h
#ifndef QUANLYMUONTRASACH_H
#define QUANLYMUONTRASACH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "quanLyDocGia.h"
#include "quanLySach.h"

#define MAX_DOC_GIA 100
#define MAX_SACH 100
#define MAX_PHIEU 100
#define MAX_TEN 50
#define MAX_CCCD 13
#define MAX_ISBN 14

// Khai báo các biến toàn cục
extern char dsCCCD[MAX_DOC_GIA][MAX_CCCD];
extern char dsTenDocGia[MAX_DOC_GIA][MAX_TEN];
extern char dsISBN[MAX_SACH][MAX_ISBN];
extern char dsTenSach[MAX_SACH][100];
extern int dsGia[MAX_SACH]; // Giá sách
extern char dsSachMuon[MAX_SACH][MAX_ISBN]; // Mảng lưu ISBN của sách đã mượn
extern char dsCCCDSachMuon[MAX_PHIEU][MAX_CCCD]; // Mảng lưu CCCD của độc giả đã mượn
extern char dsNgayMuon[MAX_PHIEU][11]; // Ngày mượn
extern char dsNgayTraDuKien[MAX_PHIEU][11]; // Ngày trả dự kiến
int demSachMuon; // Đếm số lượng sách mượn

// Khai báo các hàm
void muonTraSach();
void hienThiMenuMuonTraSach();
void lapPhieuMuonSach();
void lapPhieuTraSach();

#endif // QUANLYMUONTRASACH_H
