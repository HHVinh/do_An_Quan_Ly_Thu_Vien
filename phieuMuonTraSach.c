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

#define MAX_DOC_GIA 100
#define MAX_SACH 100
#define MAX_PHIEU 100
#define MAX_TEN 50
#define MAX_ISBN 14

char dsMaDocGia[MAX_DOC_GIA][5] = {"0001", "0002", "0003", "0004", "0005", "0006"};
char dsTenDocGia[MAX_DOC_GIA][50] = {"Nguyễn Văn A", "Nguyễn Văn B", "Nguyễn Văn C", "Trần Thị D", "Trần Thị E", "Trần Thị F"};
char dsCCCD[MAX_DOC_GIA][13] = {"111111111111", "111111111112", "111111111113", "111111111114", "111111111115", "111111111116"};
char dsNgaySinh[MAX_DOC_GIA][11] = {"1/1/1990", "1/1/1991", "1/1/1992", "1/1/1993", "1/1/1994", "1/1/1995"};
char dsGioiTinh[MAX_DOC_GIA][10] = {"Nam", "Nam", "Nam", "Nữ", "Nữ", "Nữ"};
char dsEmail[MAX_DOC_GIA][50] = {"nguyenvana@gmail.com", "nguyenvanb@gmail.com", "nguyenvanc@gmail.com", "tranthid@gmail.com", "tranthie@gmail.com", "tranthif@gmail.com"};
char dsDiaChi[MAX_DOC_GIA][100] = {"Hồ Chí Minh", "Tiền Giang", "Đà Lạt", "Long An", "Nghệ An", "Hà Nội"};
char dsNgayLapThe[MAX_DOC_GIA][11] = {"1/1/2024", "1/5/2024", "15/8/2024", "1/10/2022", "15/10/2023", "10/10/2024"};
char dsNgayHetHan[MAX_DOC_GIA][11] = {"1/1/2028", "1/5/2028", "15/8/2028", "1/10/2026", "15/10/2027", "10/10/2028"};

char dsISBN[MAX_SACH][14] = {"9999999999991","9999999999992","9999999999993","9999999999994","9999999999995","9999999999996","9999999999997","9999999999998","9999999999999", "9999999999910"};
char dsTenSach[MAX_SACH][100] = {"Truyện Kiều","Lục Vân Tiên","Sơn Tinh Thủy Tinh","Sự Tích Bánh Chưng Bánh Dày","Dế Mèn Phiêu Lưu Ký","Tấm Cám","Sách Giáo Khoa Ngữ Văn 6","Sách Giáo Khoa Ngữ Văn 9","Sách Giáo Khoa Tiếng Việt 1 - Tập 1","Sách Giáo Khoa Tiếng Việt 3 - Tập 2"};
char dsTacGia[MAX_SACH][50] = {"Nguyễn Du","Nguyễn Đình Chiểu","Truyền Thuyết","Truyền Thuyết","Tô Hoài","Truyện Dân Gian","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục"};
char dsTheLoai[MAX_SACH][30] = {"Văn Học","Văn Học","Truyện Cổ Tích","Truyện Cổ Tích","Văn Học Thiếu Nhi","Truyện Cổ Tích","Sách Giáo Khoa","Sách Giáo Khoa","Sách Giáo Khoa","Sách Giáo Khoa"};
char dsNhaXuatBan[MAX_SACH][50] = {"NXB Văn Học","NXB Văn Học","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục"};
char dsNamXuatBan[MAX_SACH][5] = {"2018","2019","2020","2020","2017","2018","2021","2021","2022","2022"};

//char dsMaDocGia[MAX_DOC_GIA][MAX_MA_DOC_GIA];
//char dsTenDocGia[MAX_DOC_GIA][MAX_TEN];
char dsISBN[MAX_SACH][MAX_ISBN];
char dsTenSach[MAX_SACH][100];
int giaSach; // Giá sách
char dsCCCDSachMuon[100][13];
char dsSachMuon[MAX_PHIEU][MAX_ISBN] = {"9999999999991","9999999999992"};
char dsMaDocGiaSachMuon[MAX_PHIEU][MAX_MA_DOC_GIA] = {"0001", "0002"};
char dsNgayMuon[MAX_PHIEU][11] = {"20/10/2024", "22/10/2024"};
char dsNgayTraDuKien[MAX_PHIEU][11] = {"27/10/2024", "29/10/2024"};

int demDocGia = 6;
int demSach = 10;
int demSachMuon = 2;

/*static void init() {
    demDocGia = getDemDocGia(demDocGia);
    demSach = getDemSach(demSach);
}*/

// Hàm xác định số ngày trong một tháng của một năm nhất định
int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))) {
        return 29;
    }
    return ngayTrongThang[thang - 1];
}

// Hàm tính ngày trả dự kiến sau 7 ngày từ ngày mượn
void tinhNgayTraDuKien(char *ngayMuon, char *ngayTraDuKien) {
    int nam, thang, ngay;
    sscanf(ngayMuon, "%d/%d/%d", &ngay, &thang, &nam); // Tách năm, tháng, ngày từ chuỗi ngayMuon

    ngay += 7; // Thêm 7 ngày vào ngày mượn

    while (ngay > soNgayTrongThang(thang, nam)) {
        ngay -= soNgayTrongThang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    sprintf(ngayTraDuKien, "%02d/%02d/%04d", ngay, thang, nam);
}

// Hàm tính số ngày chênh lệch giữa hai ngày
int tinhChenhLechNgay(char *ngayTraThucTe, char *ngayTraDuKien) {
    int nam1, thang1, ngay1;
    int nam2, thang2, ngay2;
    sscanf(ngayTraThucTe, "%d/%d/%d", &ngay1, &thang1, &nam1);
    sscanf(ngayTraDuKien, "%d/%d/%d", &ngay2, &thang2, &nam2);

    int ngayChenhLech = 0;
    while (nam1 > nam2 || thang1 > thang2 || ngay1 > ngay2) {
        ngay2++;
        if (ngay2 > soNgayTrongThang(thang2, nam2)) {
            ngay2 = 1;
            thang2++;
            if (thang2 > 12) {
                thang2 = 1;
                nam2++;
            }
        }
        ngayChenhLech++;
    }

    return ngayChenhLech;
}

// Hàm kiểm tra tính hợp lệ của ISBN
int kiemTraISBN(char *isbn) {
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            return 1; // ISBN hợp lệ
        }
    }
    return 0; // ISBN không hợp lệ
}

// Hàm kiểm tra tính hợp lệ của mã độc giả
int kiemTraMaDocGia(char *maDocGia) {
    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsMaDocGia[i], maDocGia) == 0) {
            return 1; // Mã độc giả hợp lệ
        }
    }
    return 0; // Mã độc giả không hợp lệ
}

// Hàm mượn trả sách
void muonTraSach() {
    hienThiMenuMuonTraSach();
}

// Hàm hiển thị menu mượn trả sách
void hienThiMenuMuonTraSach() {
    char luaChon;

    do {
        printf("\n=== Muon Tra Sach ===\n");
        printf("a. Muon sach\n");
        printf("b. Tra sach\n");
        printf("c. Thoát\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                lapPhieuMuonSach();
                break;
            case 'b':
                lapPhieuTraSach();
                break;
            case 'c':
                printf("Thoát.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
                break;
        }
    } while (luaChon != 'c');
}

// Hàm lập phiếu mượn sách
void lapPhieuMuonSach() {
    char maDocGia[MAX_MA_DOC_GIA];
    printf("Nhap ma doc gia: ");
    scanf("%s", maDocGia);

    if (!kiemTraMaDocGia(maDocGia)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach muon: ");
    scanf("%s", isbn);

    if (!kiemTraISBN(isbn)) {
        printf("Khong tim thay ISBN sach!\n");
        return;
    }

    strcpy(dsSachMuon[demSachMuon], isbn);
    strcpy(dsMaDocGiaSachMuon[demSachMuon], maDocGia);
    printf("Nhap ngay muon (dd/mm/yyyy): ");
    scanf("%s", dsNgayMuon[demSachMuon]);

    tinhNgayTraDuKien(dsNgayMuon[demSachMuon], dsNgayTraDuKien[demSachMuon]);

    demSachMuon++;
    printf("Lap phieu muon sach thanh cong!\n");

    printf("Danh sach sach muon:\n");
    for (int i = 0; i < demSachMuon; i++) {
        printf("Ma doc gia: %s, ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
               dsMaDocGiaSachMuon[i], dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
    }
}

// Hàm lập phiếu trả sách
void lapPhieuTraSach() {
    char maDocGia[MAX_MA_DOC_GIA];
    printf("Nhap ma doc gia: ");
    scanf("%s", maDocGia);

    if (!kiemTraMaDocGia(maDocGia)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    printf("Danh sach sach muon:\n");
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsMaDocGiaSachMuon[i], maDocGia) == 0) {
            printf("%d. ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
                   i + 1, dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
        }
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach can tra: ");
    scanf("%s", isbn);

    int foundSachMuon = -1;
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsSachMuon[i], isbn) == 0 && strcmp(dsMaDocGiaSachMuon[i], maDocGia) == 0) {
            foundSachMuon = i;
            break;
        }
    }
    if (foundSachMuon == -1) {
        printf("Khong tim thay ISBN trong dsSachMuon!\n");
        return;
    }

        char ngayTra[11];
    printf("Nhap ngay tra thuc te (dd/mm/yyyy): ");
    scanf("%s", ngayTra);

    int hienTrang;
    printf("Nhap hien trang sach (1. Con, 2. Mat): ");
    scanf("%d", &hienTrang);
    
    // Kiểm tra tình trạng sách hợp lệ
    if (hienTrang < 1 || hienTrang > 2) {
        printf("Hien trang sach khong hop le! Vui long nhap lai.\n");
        return;
    }

    // Tính toán số tiền thanh toán
    int soTienThanhToan = 0;
    char *ngayTraDuKien = dsNgayTraDuKien[foundSachMuon];
    int chenhLechNgay = tinhChenhLechNgay(ngayTra, ngayTraDuKien);

    if (hienTrang == 1) { // Sách còn
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 0; // Trường hợp 1
        } else {
            soTienThanhToan = 5000 * chenhLechNgay; // Trường hợp 2
        }
    } else if (hienTrang == 2) { // Sách mất
        printf("Hãy nhập giá của quyển sách:");
        scanf("%d", &giaSach);
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 2 * giaSach; // Trường hợp 3
        } else {
            soTienThanhToan = 5000 * chenhLechNgay + 2 * giaSach; // Trường hợp 4
        }
    }

    // Hiển thị thông tin trả sách
    printf("Ma doc gia: %s\n", maDocGia);
    printf("ISBN: %s\n", dsSachMuon[foundSachMuon]);
    printf("Ngay muon: %s\n", dsNgayMuon[foundSachMuon]);
    printf("Ngay tra du kien: %s\n", dsNgayTraDuKien[foundSachMuon]);
    printf("Ngay tra thuc te: %s\n", ngayTra);
    printf("So tien can thanh toan: %d\n", soTienThanhToan);

    // Xóa sách đã trả khỏi danh sách mượn
    for (int i = foundSachMuon; i < demSachMuon - 1; i++) {
        strcpy(dsSachMuon[i], dsSachMuon[i + 1]);
        strcpy(dsCCCDSachMuon[i], dsCCCDSachMuon[i + 1]);
        strcpy(dsNgayMuon[i], dsNgayMuon[i + 1]);
        strcpy(dsNgayTraDuKien[i], dsNgayTraDuKien[i + 1]);
    }
    demSachMuon--;
    printf("Lap phieu tra sach thanh cong!\n");
}



/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "quanLySach.h"
#include "thongKe.h"

#define MAX_DOC_GIA 100
#define MAX_SACH 100
#define MAX_PHIEU 100
#define MAX_TEN 50
#define MAX_CCCD 13
#define MAX_ISBN 20

char dsCCCD[MAX_DOC_GIA][MAX_CCCD];
char dsTenDocGia[MAX_DOC_GIA][MAX_TEN];
char dsISBN[MAX_SACH][MAX_ISBN];
char dsTenSach[MAX_SACH][MAX_TEN];
int dsGia[MAX_SACH]; // Giá sách
char dsSachMuon[MAX_PHIEU][MAX_ISBN] = {"ISBN0001", "ISBN0003"};
char dsCCCDSachMuon[MAX_PHIEU][MAX_CCCD] = {"111111111111", "111111111113"};
char dsNgayMuon[MAX_PHIEU][11] = {"2024-10-20", "2024-10-22"};
char dsNgayTraDuKien[MAX_PHIEU][11] = {"2024-10-27", "2024-10-29"};

char dsSachMuon[MAX_PHIEU][MAX_ISBN]; // Mảng lưu ISBN của sách đã mượn
char dsCCCDSachMuon[MAX_PHIEU][MAX_CCCD]; // Mảng lưu CCCD của độc giả đã mượn
char dsNgayMuon[MAX_PHIEU][11]; // Ngày mượn
char dsNgayTraDuKien[MAX_PHIEU][11]; // Ngày trả dự kiến

int demDocGia;
int demSach;
int demSachMuon = 2;

static void init() {
    demDocGia = getDemDocGia(demDocGia);
    demSach = getDemSach(demSach);
}

// Hàm xác định số ngày trong một tháng của một năm nhất định
int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))) {
        return 29;
    }
    return ngayTrongThang[thang - 1];
}

// Hàm tính ngày trả dự kiến sau 7 ngày từ ngày mượn
void tinhNgayTraDuKien(char *ngayMuon, char *ngayTraDuKien) {
    int nam, thang, ngay;
    sscanf(ngayMuon, "%d-%d-%d", &nam, &thang, &ngay); // Tách năm, tháng, ngày từ chuỗi ngayMuon

    ngay += 7; // Thêm 7 ngày vào ngày mượn

    while (ngay > soNgayTrongThang(thang, nam)) {
        ngay -= soNgayTrongThang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    sprintf(ngayTraDuKien, "%04d-%02d-%02d", nam, thang, ngay);
}

// Hàm tính số ngày chênh lệch giữa hai ngày
int tinhChenhLechNgay(char *ngayTraThucTe, char *ngayTraDuKien) {
    int nam1, thang1, ngay1;
    int nam2, thang2, ngay2;
    sscanf(ngayTraThucTe, "%d-%d-%d", &nam1, &thang1, &ngay1);
    sscanf(ngayTraDuKien, "%d-%d-%d", &nam2, &thang2, &ngay2);

    int ngayChenhLech = 0;
    while (nam1 > nam2 || thang1 > thang2 || ngay1 > ngay2) {
        ngay2++;
        if (ngay2 > soNgayTrongThang(thang2, nam2)) {
            ngay2 = 1;
            thang2++;
            if (thang2 > 12) {
                thang2 = 1;
                nam2++;
            }
        }
        ngayChenhLech++;
    }

    return ngayChenhLech;
}

// Hàm kiểm tra tính hợp lệ của ISBN
int kiemTraISBN(char *isbn) {
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            return 1; // ISBN hợp lệ
        }
    }
    return 0; // ISBN không hợp lệ
}

// Hàm kiểm tra tính hợp lệ của CCCD
int kiemTraCCCD(char *cccd) {
    for (int i = 0; i < demDocGia; i++) {
        if (strcmp(dsCCCD[i], cccd) == 0) {
            return 1; // CCCD hợp lệ
        }
    }
    return 0; // CCCD không hợp lệ
}

// Hàm mượn trả sách
void muonTraSach() {
    hienThiMenuMuonTraSach();
}

// Hàm hiển thị menu mượn trả sách
void hienThiMenuMuonTraSach() {
    char luaChon;

    do {
        printf("\n=== Muon Tra Sach ===\n");
        printf("a. Muon sach\n");
        printf("b. Tra sach\n");
        printf("c. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                lapPhieuMuonSach();
                break;
            case 'b':
                lapPhieuTraSach();
                break;
            case 'c':
                printf("Quay lai menu chinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
                break;
        }
    } while (luaChon != 'c');
}

// Hàm lập phiếu mượn sách
void lapPhieuMuonSach() {
    char cccd[MAX_CCCD];
    printf("Nhap ma doc gia: ");
    scanf("%s", cccd);

    if (!kiemTraCCCD(cccd)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach muon: ");
    scanf("%s", isbn);

    if (!kiemTraISBN(isbn)) {
        printf("Khong tim thay ISBN sach!\n");
        return;
    }

    strcpy(dsSachMuon[demSachMuon], isbn);
    strcpy(dsCCCDSachMuon[demSachMuon], cccd);
    printf("Nhap ngay muon (YYYY-MM-DD): ");
    scanf("%s", dsNgayMuon[demSachMuon]);

    tinhNgayTraDuKien(dsNgayMuon[demSachMuon], dsNgayTraDuKien[demSachMuon]);

    demSachMuon++;
    printf("Lap phieu muon sach thanh cong!\n");

    printf("Danh sach sach muon:\n");
    for (int i = 0; i < demSachMuon; i++) {
        printf("CCCD: %s, ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
               dsCCCDSachMuon[i], dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
    }
}

// Hàm lập phiếu trả sách
void lapPhieuTraSach() {
    char cccd[MAX_CCCD];
    printf("Nhap ma doc gia: ");
    scanf("%s", cccd);

    if (!kiemTraCCCD(cccd)) {
        printf("Khong tim thay ma doc gia!\n");
        return;
    }

    printf("Danh sach sach muon:\n");
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsCCCDSachMuon[i], cccd) == 0) {
            printf("%d. ISBN: %s, Ngay muon: %s, Ngay tra du kien: %s\n",
                   i + 1, dsSachMuon[i], dsNgayMuon[i], dsNgayTraDuKien[i]);
        }
    }

    char isbn[MAX_ISBN];
    printf("Nhap ma ISBN sach can tra: ");
    scanf("%s", isbn);

    int foundSachMuon = -1;
    for (int i = 0; i < demSachMuon; i++) {
        if (strcmp(dsSachMuon[i], isbn) == 0 && strcmp(dsCCCDSachMuon[i], cccd) == 0) {
            foundSachMuon = i;
            break;
        }
    }
    if (foundSachMuon == -1) {
        printf("Khong tim thay ISBN trong dsSachMuon!\n");
        return;
    }

    char ngayTra[11];
    printf("Nhap ngay tra thuc te (YYYY-MM-DD): ");
    scanf("%s", ngayTra);

    int hienTrang;
    printf("Nhap hien trang sach (1. Con, 2. Mat): ");
    scanf("%d", &hienTrang);
    
    // Kiểm tra tình trạng sách hợp lệ
    if (hienTrang < 1 || hienTrang > 2) {
        printf("Hien trang sach khong hop le! Vui long nhap lai.\n");
        return;
    }

    // Tính toán số tiền thanh toán
    int soTienThanhToan = 0;
    char *ngayTraDuKien = dsNgayTraDuKien[foundSachMuon];
    int chenhLechNgay = tinhChenhLechNgay(ngayTra, ngayTraDuKien);

    if (hienTrang == 1) { // Sách còn
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 0; // Trường hợp 1
        } else {
            soTienThanhToan = 5000 * chenhLechNgay; // Trường hợp 2
        }
    } else if (hienTrang == 2) { // Sách mất
        if (chenhLechNgay <= 0) {
            soTienThanhToan = 2 * dsGia[foundSachMuon]; // Trường hợp 3
        } else {
            soTienThanhToan = 5000 * chenhLechNgay + 2 * dsGia[foundSachMuon]; // Trường hợp 4
        }
    }

    // Hiển thị thông tin trả sách
    printf("Ma doc gia: %s\n", cccd);
    printf("ISBN: %s\n", dsSachMuon[foundSachMuon]);
    printf("Ngay muon: %s\n", dsNgayMuon[foundSachMuon]);
    printf("Ngay tra du kien: %s\n", dsNgayTraDuKien[foundSachMuon]);
    printf("Ngay tra thuc te: %s\n", ngayTra);
    printf("So tien can thanh toan: %d\n", soTienThanhToan);

    // Xóa sách đã trả khỏi danh sách mượn
    for (int i = foundSachMuon; i < demSachMuon - 1; i++) {
        strcpy(dsSachMuon[i], dsSachMuon[i + 1]);
        strcpy(dsCCCDSachMuon[i], dsCCCDSachMuon[i + 1]);
        strcpy(dsNgayMuon[i], dsNgayMuon[i + 1]);
        strcpy(dsNgayTraDuKien[i], dsNgayTraDuKien[i + 1]);
    }
    demSachMuon--;
    printf("Lap phieu tra sach thanh cong!\n");
}

int getDemSachMuon(int demSachMuon) {
    return demSachMuon; // Trả về số lượng sách
}*/

