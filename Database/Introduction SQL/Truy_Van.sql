use HowKteam
go
select GV.MAGV, GV.HOTEN, NT.TEN from dbo.GIAOVIEN as GV, dbo.NGUOITHAN as NT
where GV.MAGV = NT.MAGV

-- lấy ra giáo viên lương > 2000
select * from dbo.GIAOVIEN
where LUONG > 2000

-- lấy ra giáo viên là nữ và lương > 2000
select * from dbo.GIAOVIEN as GV
where GV.PHAI = N'Nữ' and GV.LUONG > 2000  

-- lấy ra giáo viên nhỏ hơn 40 tuổi
-- year -> lấy ra năm của ngày
-- getdate -> lấy ngày hiện tại
select * from dbo.GIAOVIEN as GV
where year(getdate()) - year(GV.NGSINH) > 40

-- lấy ra họ tên giáo viên, năm sinh và tuổi của giáo viên ngỏ hơn 40 tuổi
select GV.HOTEN, GV.NGSINH, year(getdate()) - year(GV.NGSINH) from dbo.GIAOVIEN as GV
where year(getdate()) - year(GV.NGSINH) > 40

-- lấy ra mã Gv, tên Gv và tên khoa của giáo viên đó làm việc
select gv.MAGV, gv.HOTEN, k.TENKHOA from dbo.GIAOVIEN as gv, dbo.BOMON as bm, dbo.KHOA as k
where bm.MAKHOA = k.MAKHOA and gv.MABM = bm.MABM

select * from dbo.BOMON

-- lấy ra giáo viên là trưởng bộ môn
select gv.* from dbo.GIAOVIEN as gv, dbo.BOMON as bm
where bm.TRUONGBM = gv.MAGV

-- count(*) -> đếm số lượng của tất cả các record
-- count(tên trường) -> đếm số lượng tên trường đó
select count(*) as N'Số Lượng giáo viên' from dbo.GIAOVIEN

-- đếm số lượng người thân của giáo viên có mã gv là 007
select count(nt.TEN) as N'Số Lượng người thân' from dbo.GIAOVIEN as gv, dbo.NGUOITHAN as nt
where gv.MAGV = 007 and nt.MAGV = gv.MAGV

-- lấy ra tên giáo viên và tên đề tài người đó tham gia
select gv.HOTEN, dt.TENDT from dbo.GIAOVIEN as gv, dbo.THAMGIADT as tg, dbo.DETAI as dt
where gv.MAGV = tg.MAGV and tg.MADT = dt.MADT

-- lấy ra tên giáo viên và tên đề tài người đó tham gia khi mà người đó tham gia nhiều hơn 1 lần
-- truy vấn lồng

-- bài tập
-- 1. xuất ra thông tin giáo viên và giáo viên quản lý chủ nhiệm của người đó
-- C1
select * from dbo.GIAOVIEN
where GVQLCM != MAGV
-- C2
select gv1.HOTEN, gv2.HOTEN from dbo.GIAOVIEN as gv1, dbo.GIAOVIEN as gv2
where gv1.GVQLCM = gv2.MAGV

-- 2. xuất ra số lượng giáo viên của khoa CNTT
select count(*) from dbo.GIAOVIEN as gv, dbo.BOMON as bm, dbo.KHOA as k
where gv.MABM = bm.MABM and k.MAKHOA = bm.MAKHOA and k.MAKHOA = 'CNTT'

-- 3. xuất ra thông tin giáo viên và đề tài người đó tham gia khi mà kết quả là đạt
select * from dbo.GIAOVIEN as gv, dbo.THAMGIADT as tg
where tg.KETQUA = N'Đạt' and gv.MAGV = tg.MAGV