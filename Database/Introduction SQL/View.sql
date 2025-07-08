use HowKteam
go

select * from dbo.GIAOVIEN

-- T?o ra 1 b?ng l?u th�ng tin gi�o vi�n, t�n b? m�n v� l??ng c?a gi�o vi�n ?�
select HOTEN, TENBM, LUONG into LuongGiaoVien from dbo.GIAOVIEN, dbo.BOMON
where GIAOVIEN.MABM = BOMON.MABM

select * from LuongGiaoVien

update dbo.GIAOVIEN set LUONG = 90000
where MAGV = '006'

select * from dbo.GIAOVIEN

-- View l� b?ng ?o
-- C?p nh?t d? li?u theo b?ng m� view truy v?n t?i m?i khi l?y view ra d�ng

-- T?o ra view TestView t? c�u truy v?n
create view TestView as
select * from dbo.GIAOVIEN

select * from TestView

update dbo.GIAOVIEN set LUONG = 90
where MAGV = '006'

select * from TestView

-- x�a view
drop view TestView

-- update view
alter view TestView as
select HOTEN from dbo.GIAOVIEN

-- t?o view c� d?u
create view [Gi�o d?c mi?n ph�] as
select * from dbo.KHOA

select * from [Gi�o d?c mi?n ph�]