use HowKteam
go

select * from dbo.GIAOVIEN

-- T?o ra 1 b?ng l?u thông tin giáo viên, tên b? môn và l??ng c?a giáo viên ?ó
select HOTEN, TENBM, LUONG into LuongGiaoVien from dbo.GIAOVIEN, dbo.BOMON
where GIAOVIEN.MABM = BOMON.MABM

select * from LuongGiaoVien

update dbo.GIAOVIEN set LUONG = 90000
where MAGV = '006'

select * from dbo.GIAOVIEN

-- View là b?ng ?o
-- C?p nh?t d? li?u theo b?ng mà view truy v?n t?i m?i khi l?y view ra dùng

-- T?o ra view TestView t? câu truy v?n
create view TestView as
select * from dbo.GIAOVIEN

select * from TestView

update dbo.GIAOVIEN set LUONG = 90
where MAGV = '006'

select * from TestView

-- xóa view
drop view TestView

-- update view
alter view TestView as
select HOTEN from dbo.GIAOVIEN

-- t?o view có d?u
create view [Giáo d?c mi?n phí] as
select * from dbo.KHOA

select * from [Giáo d?c mi?n phí]