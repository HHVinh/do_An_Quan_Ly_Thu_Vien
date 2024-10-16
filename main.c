#include <stdio.h>
#include "khaiBaoHam.h"

int main() {
    int luaChon;
    do {
        printf("\n--- Quan Ly Thu Vien ---\n");
        printf("1. Quan ly doc gia\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                // Gọi hàm quản lý độc giả
                break;
            case 2:
                // Gọi hàm quản lý sách
                break;
            case 3:
                lapPhieuMuonSach();
                break;
            case 4:
                lapPhieuTraSach();
                break;
            case 5:
                // Gọi hàm thống kê
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}
