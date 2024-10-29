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


int main() {
    hienThiMenuChinh();
}
    /*int luaChon;

    do {
        hienThiMenuChinh();
        printf("Nhap lua chon: ");
        
        // Kiểm tra kiểu dữ liệu nhập vào
        if (scanf("%d", &luaChon) != 1) {
            printf("Nhap khong hop le. Vui long nhap lai!\n");
            while(getchar() != '\n'); // Xóa bộ đệm nhập liệu
            continue; // Quay lại đầu vòng lặp
        }

        // Kiểm tra nếu người dùng nhập 0 ngay lập tức
        if (luaChon == 0) {
            printf("Thoat chuong trinh.\n");
            break; // Thoát khỏi vòng lặp
        }

        switch (luaChon) {
            case 1:
                quanLyDocGia();
                break;
            case 2:
                quanLySach();
                break;
            case 3:
                lapPhieuMuonSach();
                break;
            case 4:
                lapPhieuTraSach();
                break;
            case 5:
                thongKe();
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (1); // Vòng lặp vô hạn cho đến khi gặp break

    return 0;
}
*/

/*
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

void hienThiMenuChinh(); // Chỉ cần khai báo, không cần định nghĩa ở đây

int main() {
    int luaChon;

    do {
        hienThiMenuChinh();
        printf("Nhap lua chon: ");
        
        // Kiểm tra kiểu dữ liệu nhập vào
        if (scanf("%d", &luaChon) != 1) {
            printf("Nhap khong hop le. Vui long nhap lai!\n");
            while(getchar() != '\n'); // Xóa bộ đệm nhập liệu
            continue; // Quay lại đầu vòng lặp
        }

        switch (luaChon) {
            case 1:
                quanLyDocGia();
                break;
            case 2:
                quanLySach();
                break;
            case 3:
                lapPhieuMuonSach();
                break;
            case 4:
                lapPhieuTraSach();
                break;
            case 5:
                thongKe();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}
*/
