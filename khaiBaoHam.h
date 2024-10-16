#ifndef KHAIBOAHAM_H
#define KHAIBOAHAM_H

// Hàm quản lý độc giả
void xemDanhSachDocGia();
void themDocGia();
void chinhSuaDocGia();
void xoaDocGia();
void timKiemDocGiaTheoCMND();
void timKiemDocGiaTheoHoTen();

// Hàm quản lý sách
void xemDanhSachSach();
void themSach();
void chinhSuaSach();
void xoaSach();
void timKiemSachTheoISBN();
void timKiemSachTheoTen();

// Hàm lập phiếu mượn sách
void lapPhieuMuonSach();

/**
 * Hàm lập phiếu trả sách
 */
void lapPhieuTraSach();

// Hàm thống kê
void thongKeSoLuongSach();
void thongKeSoLuongSachTheoTheLoai();
void thongKeSoLuongDocGia();
void thongKeSoLuongDocGiaTheoGioiTinh();
void thongKeSoSachDangDuocMuon();
void thongKeDocGiaBiTreHan();

#endif
