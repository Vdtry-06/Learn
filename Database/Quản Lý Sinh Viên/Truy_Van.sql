use Quan_Ly_Sinh_Vien
go

-- Danh sach sinh vien khoa cong nghe thong tin khoa 2002-2006
select sv.* from dbo.SinhVien as sv, dbo.Lop as l, dbo.Khoa as k, dbo.KhoaHoc as kh
where sv.MaLop = l.MaLop and k.MaKhoa = l.MaKhoa and l.MaKhoa = 'CNTT' and kh.MaKhoaHoc = 'K2002'


-- Cho biet cac sinh vien (Ma sinh vien, Ho ten, Nam sinh) cua cac sinh vien hoc som hon tuoi quy dinh
-- (theo tuoi quy dinh thi sinh vien du 18 tuoi khi bat dau khoa hoc)
select sv.MaSv, sv.HoTen, sv.NamSinh from dbo.SinhVien as sv, dbo.Lop as l, dbo.KhoaHoc as kh
where sv.MaLop = l.MaLop and l.MaKhoaHoc = kh.MaKhoaHoc and kh.NamBatDau - sv.NamSinh < 18


-- Cho biet sinh vien khoa CNTT, khoa 2002-2006 chua hoc mon cau truc du lieu 1
select * from dbo.SinhVien as sv, dbo.Lop as l, dbo.Khoa as k, dbo.KhoaHoc as kh, dbo.MonHoc as mh
where sv.MaLop = l.MaLop and k.MaKhoa = l.MaKhoa and mh.MaKhoa = k.MaKhoa and k.MaKhoa = 'CNTT' and kh.MaKhoaHoc = 'K2002' 
and sv.MaSv not in 
(
	select sv.MaSv from dbo.SinhVien as sv, dbo.Lop as l, dbo.Khoa as k, dbo.KhoaHoc as kh, dbo.MonHoc as mh
	where sv.MaLop = l.MaLop and k.MaKhoa = l.MaKhoa and mh.MaKhoa = k.MaKhoa and k.MaKhoa = 'CNTT' and kh.MaKhoaHoc = 'K2002' 
	and mh.TenMonHoc = N'Cấu trúc dữ liệu 1'
)



-- B1: Cho biet sinh vien thi khong dau(diem < 5) mon cau truc du lieu 1 nhung chua thi lai
--C1
select * from dbo.SinhVien as sv, dbo.KetQua as kq, dbo.MonHoc as mh
where sv.MaSv = kq.MaSv and mh.MaMonHoc = kq.MaMonHoc and mh.MaMonHoc = 'THCS01' and kq.Diem < 5 and kq.LanThi = 1
and sv.MaSv not in
(
	select sv.MaSv from dbo.SinhVien as sv, dbo.KetQua as kq, dbo.MonHoc as mh
	where sv.MaSv = kq.MaSv and mh.MaMonHoc = kq.MaMonHoc and mh.MaMonHoc = 'THCS01' and kq.LanThi > 1
)

--C2
select * from SinhVien
left join KetQua on KetQua.MaSv = SinhVien.MaSv
left join MonHoc on MonHoc.MaMonHoc = KetQua.MaMonHoc
where MonHoc.MaMonHoc like 'THCS01'
and KetQua.LanThi = 1
and KetQua.Diem < 5
and SinhVien.MaSv not in
(
	select SinhVien.MaSv from SinhVien
	left join KetQua on KetQua.MaSv = SinhVien.MaSv
	left join MonHoc on MonHoc.MaMonHoc = KetQua.MaMonHoc
	where MonHoc.MaMonHoc like 'THCS01'
	and KetQua.LanThi > 1
)

--C3
select SinhVien.MaSv, SinhVien.HoTen, SinhVien.NamSinh, count(*) from SinhVien
left join KetQua on KetQua.MaSv = SinhVien.MaSv
left join MonHoc on MonHoc.MaMonHoc = KetQua.MaMonHoc
where MonHoc.MaMonHoc like 'THCS01' and KetQua.Diem < 5
group by SinhVien.MaSv, SinhVien.HoTen, SinhVien.NamSinh
having count(*) = 1


-- B2: Voi moi lop thuoc khoa CNTT, cho biet ma lop, ma khoa hoc ten chuong trinh va so sinh vien thuoc lop do
--C1
select l.MaLop, kh.MaKhoaHoc, cth.MaChuongTrinh, count(*) from Lop as l, Khoa as k, KhoaHoc as kh, ChuongTrinhHoc as cth, SinhVien as sv
where l.MaKhoa = k.MaKhoa 
and k.MaKhoa = 'CNTT' 
and l.MaKhoaHoc = kh.MaKhoaHoc 
and l.MaChuongTrinh = cth.MaChuongTrinh 
and l.MaLop = sv.MaLop
group by l.MaLop, kh.MaKhoaHoc, cth.MaChuongTrinh

--C2
select Lop.MaLop, KhoaHoc.MaKhoaHoc, ChuongTrinhHoc.MaChuongTrinh, count(*) as [SoLuongSinhVien] from Lop
left join Khoa on Lop.MaKhoa = Khoa.MaKhoa
left join KhoaHoc on KhoaHoc.MaKhoaHoc = Lop.MaKhoaHoc
left join ChuongTrinhHoc on ChuongTrinhHoc.MaChuongTrinh = Lop.MaChuongTrinh
left join SinhVien on SinhVien.MaLop = Lop.MaLop
where Khoa.MaKhoa = 'CNTT'
and SinhVien.MaLop = Lop.MaLop
group by Lop.MaLop, KhoaHoc.MaKhoaHoc, ChuongTrinhHoc.MaChuongTrinh


-- B3: Cho biet diem trung binh cua sinh vien co ma so 0212003(diem trung binh chi tinh tren lan thi sau cung cua sinh vien)
select SinhVien.MaSv, sum(KetQua.LanThi * KetQua.Diem) / sum(KetQua.LanThi) from SinhVien
left join KetQua on KetQua.MaSv = SinhVien.MaSv
where SinhVien.MaSv = '0212003'
group by SinhVien.MaSv
