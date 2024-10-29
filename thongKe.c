#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "quanLySach.h"
#include "thongKe.h"

int demDocGia; // Khai báo toàn cục
int demSach;   // Khai báo toàn cục
int demSachMuon;   // Khai báo toàn cục

static void init() {
    demDocGia = getDemDocGia(demDocGia); // Gán giá trị
    demSach = getDemSach(demSach);      // Gán giá trị
    demSachMuon = getDemSachMuon(demSachMuon); // Gán giá trị
}

// Hàm thống kê số lượng độc giả, sách và phiếu mượn
void thongKe() {
    printf("\n=== Thong Ke ===\n");

    // Kiểm tra và in ra số lượng độc giả
    if (demDocGia >= 0) {
        printf("Tong so doc gia: %d\n", demDocGia);
    } else {
        printf("So doc gia khong hop le!\n");
    }

    // Kiểm tra và in ra số lượng sách
    if (demSach >= 0) {
        printf("Tong so sach: %d\n", demSach);
    } else {
        printf("So sach khong hop le!\n");
    }

    // Kiểm tra và in ra số lượng phiếu mượn
    if (demSachMuon >= 0) {
        printf("Tong sach dang duoc muon: %d\n", demSachMuon);
    } else {
        printf("Khong co sach nao duoc muon!\n");
    }
}


/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "khaiBaoHam.h"

extern int demDocGia;  // Biến đếm số lượng độc giả
extern int demSach;    // Biến đếm số lượng sách
extern int demSachMuon;   // Biến đếm số lượng phiếu

void thongKe() {
    printf("\n=== Thong Ke ===\n");
    printf("Tong so doc gia: %d\n", demDocGia);
    printf("Tong so sach: %d\n", demSach);
    printf("Tong so phieu muon: %d\n", demSachMuon);
}
*/