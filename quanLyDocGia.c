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

void quanLyDocGia() {
    hienThiMenuQuanLyDocGia();
}

// Hàm hiển thị menu quản lý độc giả
void hienThiMenuQuanLyDocGia() {
    char luaChon;
    char dsMaDocGia[MAX_DOC_GIA][5] = {"0001", "0002", "0003", "0004", "0005", "0006"};
    char dsTenDocGia[MAX_DOC_GIA][50] = {"Nguyễn Văn A", "Nguyễn Văn B", "Nguyễn Văn C", "Trần Thị D", "Trần Thị E", "Trần Thị F"};
    char dsCCCD[MAX_DOC_GIA][13] = {"111111111111", "111111111112", "111111111113", "111111111114", "111111111115", "111111111116"};
    char dsNgaySinh[MAX_DOC_GIA][11] = {"1/1/1990", "1/1/1991", "1/1/1992", "1/1/1993", "1/1/1994", "1/1/1995"};
    char dsGioiTinh[MAX_DOC_GIA][10] = {"Nam", "Nam", "Nam", "Nữ", "Nữ", "Nữ"};
    char dsEmail[MAX_DOC_GIA][50] = {"nguyenvana@gmail.com", "nguyenvanb@gmail.com", "nguyenvanc@gmail.com", "tranthid@gmail.com", "tranthie@gmail.com", "tranthif@gmail.com"};
    char dsDiaChi[MAX_DOC_GIA][100] = {"Hồ Chí Minh", "Tiền Giang", "Đà Lạt", "Long An", "Nghệ An", "Hà Nội"};
    char dsNgayLapThe[MAX_DOC_GIA][11] = {"1/1/2024", "1/5/2024", "15/8/2024", "1/10/2022", "15/10/2023", "10/10/2024"};
    char dsNgayHetHan[MAX_DOC_GIA][11] = {"1/1/2028", "1/5/2028", "15/8/2028", "1/10/2026", "15/10/2027", "10/10/2028"};
    int demDocGia = 6;  // Số lượng độc giả ban đầu

    do {
        printf("\n=== Quan Ly Doc Gia ===\n");
        printf("a. Xem danh sach doc gia\n");
        printf("b. Them doc gia\n");
        printf("c. Chinh sua doc gia\n");
        printf("d. Xoa doc gia\n");
        printf("e. Tim kiem doc gia theo CCCD\n");
        printf("f. Tim kiem doc gia theo ho ten\n");
        printf("g. Thoat\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                xemDanhSachDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'b':
                themDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, &demDocGia);
                break;
            case 'c':
                chinhSuaDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'd':
                xoaDocGia(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, &demDocGia);
                break;
            case 'e':
                timKiemTheoCCCD(dsCCCD, dsMaDocGia, dsTenDocGia, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'f':
                timKiemTheoHoTen(dsMaDocGia, dsTenDocGia, dsCCCD, dsNgaySinh, dsGioiTinh, dsEmail, dsDiaChi, dsNgayLapThe, dsNgayHetHan, demDocGia);
                break;
            case 'g':
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 'g');
}
int getDemDocGia(int demDocGia) {
    return demDocGia; // Trả về giá trị của demDocGia
}


// Hàm xem danh sách độc giả
void xemDanhSachDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                        char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                        char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                        int demDocGia) {
    if (demDocGia == 0) {
        printf("Danh sach doc gia trong.\n");
    } else {
        printf("Danh sach doc gia:\n");
        for (int i = 0; i < demDocGia; i++) {
            printf("%d. Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                  i +1, dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
        }
    }
}

// Hàm thêm độc giả
void themDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13], 
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50], 
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11], 
                int *demDocGia) {
    if (*demDocGia >= MAX_DOC_GIA) {
        printf("Danh sach doc gia da day!\n");
        return;
    }

    printf("Nhap ma doc gia: ");
    scanf("%s", dsMaDocGia[*demDocGia]);
    printf("Nhap ten doc gia: ");
    scanf(" %[^\n]", dsTenDocGia[*demDocGia]);
    printf("Nhap CCCD: ");
    scanf("%s", dsCCCD[*demDocGia]);
    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    scanf("%s", dsNgaySinh[*demDocGia]);
    printf("Nhap gioi tinh: ");
    scanf("%s", dsGioiTinh[*demDocGia]);
    printf("Nhap email: ");
    scanf("%s", dsEmail[*demDocGia]);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", dsDiaChi[*demDocGia]);
    printf("Nhap ngay lap the (dd/mm/yyyy): ");
    scanf("%s", dsNgayLapThe[*demDocGia]);
    printf("Nhap ngay het han (dd/mm/yyyy): ");
    scanf("%s", dsNgayHetHan[*demDocGia]);

    (*demDocGia)++;
    printf("Them doc gia thanh cong!\n");
}

// Hàm chỉnh sửa độc giả
void chinhSuaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                     char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                     char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                     int demDocGia) {
    char maDocGia[5];
    printf("Nhap ma doc gia can chinh sua: ");
    scanf("%s", maDocGia);

    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            printf("Chinh sua doc gia: \n");
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", dsTenDocGia[i]);
            printf("Nhap CCCD moi: ");
            scanf("%s", dsCCCD[i]);
            printf("Nhap ngay sinh moi (dd/mm/yyyy): ");
            scanf("%s", dsNgaySinh[i]);
            printf("Nhap gioi tinh moi: ");
            scanf("%s", dsGioiTinh[i]);
            printf("Nhap email moi: ");
            scanf("%s", dsEmail[i]);
            printf("Nhap dia chi moi: ");
            scanf(" %[^\n]", dsDiaChi[i]);
            printf("Nhap ngay lap the moi: ");
            scanf("%s", dsNgayLapThe[i]);
            printf("Nhap ngay het han moi (dd/mm/yyyy): ");
            scanf("%s", dsNgayHetHan[i]);
            printf("Chinh sua doc gia thanh cong!\n");
            return;
        }
    }
    printf("Ma doc gia khong ton tai!\n");
}

// Hàm xóa độc giả
void xoaDocGia(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                int *demDocGia) {
    char maDocGia[5];
    printf("Nhap ma doc gia can xoa: ");
    scanf("%s", maDocGia);

    for (int i = 0; i < *demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            for (int j = i; j < *demDocGia - 1; j++) {
                strcpy(dsMaDocGia[j], dsMaDocGia[j + 1]);
                strcpy(dsTenDocGia[j], dsTenDocGia[j + 1]);
                strcpy(dsCCCD[j], dsCCCD[j + 1]);
                strcpy(dsNgaySinh[j], dsNgaySinh[j + 1]);
                strcpy(dsGioiTinh[j], dsGioiTinh[j + 1]);
                strcpy(dsEmail[j], dsEmail[j + 1]);
                strcpy(dsDiaChi[j], dsDiaChi[j + 1]);
                strcpy(dsNgayLapThe[j], dsNgayLapThe[j + 1]);
                strcpy(dsNgayHetHan[j], dsNgayHetHan[j + 1]);
            }
            (*demDocGia)--;
            printf("Xoa doc gia thanh cong!\n");
            return;
        }
    }
    printf("Ma doc gia khong ton tai!\n");
}

// Hàm tìm kiếm độc giả theo CCCD
void timKiemTheoCCCD(char dsCCCD[][13], char dsMaDocGia[][5], char dsTenDocGia[][50],
                      char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                      char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                      int demDocGia) {
    char cccd[13];
    printf("Nhap CCCD can tim: ");
    scanf("%s", cccd);
    int found = 0;

    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsCCCD[i], cccd) == 0) {
            printf("Tim thay doc gia:\n");
            printf("Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia co CCCD: %s\n", cccd);
    }
}

// Hàm tìm kiếm độc giả theo họ tên
void timKiemTheoHoTen(char dsMaDocGia[][5], char dsTenDocGia[][50], char dsCCCD[][13],
                       char dsNgaySinh[][11], char dsGioiTinh[][10], char dsEmail[][50],
                       char dsDiaChi[][100], char dsNgayLapThe[][11], char dsNgayHetHan[][11],
                       int demDocGia) {
    char ten[50];
    printf("Nhap ten doc gia can tim: ");
    scanf(" %[^\n]", ten);
    int found = 0;

    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < demDocGia; i++) {
        if (strstr(dsTenDocGia[i], ten) != NULL) { // Kiểm tra xem tên có chứa chuỗi tìm kiếm không
            printf("Ma doc gia: %s, Ten: %s, CCCD: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   dsMaDocGia[i], dsTenDocGia[i], dsCCCD[i], dsNgaySinh[i], dsGioiTinh[i], dsEmail[i], dsDiaChi[i], dsNgayLapThe[i], dsNgayHetHan[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia co ten: %s\n", ten);
    }
}

