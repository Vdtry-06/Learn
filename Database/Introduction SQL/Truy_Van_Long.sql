use HowKteam
go

-- Kiểm tra xem giáo viên GV001 có phải là gv quản lý chuyên môn hay không
-- Lấy ra danh sách các mã giáo viên QLCM
-- Kiểm tra mã gv tồn tại trong danh sách đó
select * from dbo.GIAOVIEN
where MAGV = 001
/* 001 tồn tại trong danh sách */
and MAGV in
(
	select GVQLCM from dbo.GIAOVIEN
)

-- Truy vấn lồng trong from
select * from dbo.GIAOVIEN, (select * from dbo.DETAI) as dt

-- 1. Xuất ra danh sách giáo viên tham gia nhiều hơn 1 đề tài
-- Lấy ra tất cả thông tin của giáo viên khi mà
select * from dbo.GIAOVIEN as gv
-- Số lượng đề tài giáo viên đó tham gia > 1
where 1 <
(
	select count(*) from dbo.THAMGIADT
	where MAGV = gv.MAGV
)

-- 2. Xuất ra thông tin của khoa mà có nhiều hơn 2 giáo viên
select * from dbo.KHOA as k
where 2 < 
(
	select count(*) from dbo.GIAOVIEN as gv, dbo.BOMON as bm
	where gv.MABM = bm.MABM and bm.MAKHOA = k.MAKHOA
)

-- sắp xếp giảm dần descent
select * from dbo.GIAOVIEN
order by MAGV desc

-- sắp xếp tăng dần ascend
select * from dbo.GIAOVIEN
order by MAGV asc

-- lấy ra top 5 phần tử
select top(5) * from dbo.GIAOVIEN

/*
Bài tập:
1. Xuất ra thông tin giáo viên mà có hơn 2 người thân
2. Xuất ra danh sách các giáo viên lớn tuổi hơn ít nhất 5 người các giáo viên trong trường
-- Lấy ra danh sách (MaGV, Tuoi) as GVT
-- sắp xếp giảm dần
-- lấy ra danh sách GVT2 với số lượng phần tử = count(*) / 2
-- Kiểm tra mã GV tồn tại trong GVT2 là đúng
*/
-- 1. Xuất ra thông tin giáo viên mà có hơn 2 người thân
select * from dbo.GIAOVIEN as gv
where 2 <
(
	select count(*) from dbo.NGUOITHAN as nt
	where nt.MAGV = gv.MAGV
)

-- 2. Xuất ra danh sách các giáo viên lớn tuổi hơn ít nhất 5 người các giáo viên trong trường
select top(5) * from dbo.GIAOVIEN as gv
order by year(gv.NGSINH) asc
