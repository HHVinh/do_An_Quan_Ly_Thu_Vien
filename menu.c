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


void hienThiMenuChinh() {
    int luaChon;

    do {
        printf("\n=== MENU CHINH ===\n");
        printf("1. Quan ly doc gia\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

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
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 0);
}
