#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "khaiBaoHam.h"
#include "menu.h"
#include "phieuMuonTraSach.h"
#include "quanLyDocGia.h"
#include "quanLySach.h"
#include "thongKe.h"

// Hàm chuyển đổi ký tự thành chữ thường
void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void quanLySach() {
    // Khởi tạo thông tin 10 sách
    char dsISBN[MAX_SACH][14] = {"9786043235764","9786043234088","9786049987742","9786043090937","9786040020562","9786043236990","9786043011269","9786049560939","9786043059469", "9786040020289"};
    char dsTenSach[MAX_SACH][100] = {"Truyện Kiều","Lục Vân Tiên","Sơn Tinh Thủy Tinh","Sự Tích Bánh Chưng Bánh Dày","Dế Mèn Phiêu Lưu Ký","Tấm Cám","Sách Giáo Khoa Ngữ Văn 6","Sách Giáo Khoa Ngữ Văn 9","Sách Giáo Khoa Tiếng Việt 1 - Tập 1","Sách Giáo Khoa Tiếng Việt 3 - Tập 2"};
    char dsTacGia[MAX_SACH][50] = {"Nguyễn Du","Nguyễn Đình Chiểu","Truyền Thuyết","Truyền Thuyết","Tô Hoài","Truyện Dân Gian","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục","Bộ Giáo Dục"};
    char dsTheLoai[MAX_SACH][30] = {"Văn Học","Văn Học","Truyện Cổ Tích","Truyện Cổ Tích","Văn Học Thiếu Nhi","Truyện Cổ Tích","Sách Giáo Khoa","Sách Giáo Khoa","Sách Giáo Khoa","Sách Giáo Khoa"};
    char dsNhaXuatBan[MAX_SACH][50] = {"NXB Văn Học","NXB Văn Học","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Kim Đồng","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục","NXB Giáo Dục"};
    char dsNamXuatBan[MAX_SACH][5] = {"2018","2019","2020","2020","2017","2018","2021","2021","2022","2022"};

    // Số lượng sách đã có sẵn
    int demSach = 10;

    hienThiMenuQuanLySach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, demSach);
}

void hienThiMenuQuanLySach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                            char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
                            int demSach) {
    char luaChon;

    do {
        printf("\n=== Quan Ly Sach ===\n");
        printf("a. Xem danh sach sach\n");
        printf("b. Them sach\n");
        printf("c. Chinh sua thong tin sach\n");
        printf("d. Xoa thong tin sach\n");
        printf("e. Tim kiem sach theo ISBN\n");
        printf("f. Tim kiem sach theo ten\n");
        printf("g. Thoat\n");
        printf("Nhap lua chon: ");
        scanf(" %c", &luaChon);
        luaChon = tolower(luaChon);

        switch (luaChon) {
            case 'a':
                xemDanhSachSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, demSach);
                break;
            case 'b':
                themSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, &demSach);
                break;
            case 'c':
                chinhSuaThongTinSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, demSach);
                break;
            case 'd':
                xoaSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, &demSach);
                break;
            case 'e':
                timKiemSachTheoISBN(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, demSach);
                break;
            case 'f':
                timKiemSachTheoTenSach(dsISBN, dsTenSach, dsTacGia, dsTheLoai, dsNhaXuatBan, dsNamXuatBan, demSach);
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

// Xem danh sách sách
void xemDanhSachSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                     char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
                     int demSach) {
    if (demSach == 0) {
        printf("Danh sach sach trong.\n");
    } else {
        printf("Danh sach sach:\n");
        for (int i = 0; i < demSach; i++) {
            printf("%d. ISBN: %s, Tên: %s, Tác giả: %s, Thể loại: %s, Nhà xuất bản: %s, Năm xuất bản: %s\n",
                   i + 1, dsISBN[i], dsTenSach[i], dsTacGia[i], dsTheLoai[i], dsNhaXuatBan[i], dsNamXuatBan[i]);
        }
    }
}

// Thêm sách
void themSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50], 
              char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5], 
              int *demSach) {
    if (*demSach >= MAX_SACH) {
        printf("Danh sach sach da day!\n");
        return;
    }

    printf("Nhap ISBN (tối đa 13 ký tự): ");
    scanf("%s", dsISBN[*demSach]);

    printf("Nhap ten sach: ");
    scanf(" %[^\n]", dsTenSach[*demSach]);

    printf("Nhap tac gia: ");
    scanf(" %[^\n]", dsTacGia[*demSach]);

    printf("Nhap the loai: ");
    scanf(" %[^\n]", dsTheLoai[*demSach]);

    printf("Nhap nha xuat ban: ");
    scanf(" %[^\n]", dsNhaXuatBan[*demSach]);

    printf("Nhap nam xuat ban: ");
    scanf("%s", dsNamXuatBan[*demSach]);

    (*demSach)++;
    printf("Them sach thanh cong!\n");
}

// Chỉnh sửa thông tin sách
void chinhSuaThongTinSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                  char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
                  int demSach) {
    char isbn[14];
    printf("Nhap ISBN sach can chinh sua: ");
    scanf("%s", isbn);

    int found = 0;
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            found = 1;
            printf("Chinh sua thong tin cho sach: %s\n", dsTenSach[i]);

            printf("Nhap ten sach moi: ");
            scanf(" %[^\n]", dsTenSach[i]);

            printf("Nhap tac gia moi: ");
            scanf(" %[^\n]", dsTacGia[i]);

            printf("Nhap the loai moi: ");
            scanf(" %[^\n]", dsTheLoai[i]);

            printf("Nhap nha xuat ban moi: ");
            scanf(" %[^\n]", dsNhaXuatBan[i]);

            printf("Nhap nam xuat ban moi: ");
            scanf("%s", dsNamXuatBan[i]);

            printf("Chinh sua thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
    }
}

// Xóa sách
void xoaSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
             char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
             int *demSach) {
    char isbn[14];
    printf("Nhap ISBN sach can xoa: ");
    scanf("%s", isbn);

    int found = 0;
    for (int i = 0; i < *demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            found = 1;
            // Di chuyển các sách sau nó về trước
            for (int j = i; j < *demSach - 1; j++) {
                strcpy(dsISBN[j], dsISBN[j + 1]);
                strcpy(dsTenSach[j], dsTenSach[j + 1]);
                strcpy(dsTacGia[j], dsTacGia[j + 1]);
                strcpy(dsTheLoai[j], dsTheLoai[j + 1]);
                strcpy(dsNhaXuatBan[j], dsNhaXuatBan[j + 1]);
                strcpy(dsNamXuatBan[j], dsNamXuatBan[j + 1]);
            }
            (*demSach)--; // Giảm số lượng sách
            printf("Xoa sach thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
    }
}

// Tìm kiếm sách theo ISBN
void timKiemSachTheoISBN(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                          char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
                          int demSach) {
    char isbn[14];
    printf("Nhap ISBN sach can tim: ");
    scanf("%s", isbn);

    int found = 0;
    for (int i = 0; i < demSach; i++) {
        if (strcmp(dsISBN[i], isbn) == 0) {
            found = 1;
            printf("Tim thay sach:\n");
            printf("ISBN: %s, Tên: %s, Tác giả: %s, Thể loại: %s, Nhà xuất bản: %s, Năm xuất bản: %s\n",
                   dsISBN[i], dsTenSach[i], dsTacGia[i], dsTheLoai[i], dsNhaXuatBan[i], dsNamXuatBan[i]);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
    }
}

// Tìm kiếm sách theo tên
void timKiemSachTheoTenSach(char dsISBN[][14], char dsTenSach[][100], char dsTacGia[][50],
                             char dsTheLoai[][30], char dsNhaXuatBan[][50], char dsNamXuatBan[][5],
                             int demSach) {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", tenSach);

    int found = 0;
    char tenSachLower[100];
    toLower(tenSach); // Chuyển tên sách tìm kiếm thành chữ thường

    for (int i = 0; i < demSach; i++) {
        strcpy(tenSachLower, dsTenSach[i]);
        toLower(tenSachLower); // Chuyển tên sách trong danh sách thành chữ thường
        if (strstr(tenSachLower, tenSach) != NULL) { // Tìm kiếm phần tên sách
            found = 1;
            printf("Tim thay sach:\n");
            printf("ISBN: %s, Tên: %s, Tác giả: %s, Thể loại: %s, Nhà xuất bản: %s, Năm xuất bản: %s\n",
                   dsISBN[i], dsTenSach[i], dsTacGia[i], dsTheLoai[i], dsNhaXuatBan[i], dsNamXuatBan[i]);
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten: %s\n", tenSach);
    }
}

int getDemSach(int demSach) {
    return demSach; // Trả về số lượng sách
}