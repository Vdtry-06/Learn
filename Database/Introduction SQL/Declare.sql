use HowKteam
go

-- Tìm ra mã giáo viên có lương cao nhất
select MAGV from dbo.GIAOVIEN
where LUONG = (select min(LUONG) from dbo.GIAOVIEN)

-- C1: 
-- Lấy ra tuổi của giáo viên với mã GV 001
select year(getdate()) - year(NGSINH) from dbo.GIAOVIEN
where MAGV = (select MAGV from dbo.GIAOVIEN where LUONG = (select min(LUONG) from dbo.GIAOVIEN))

-- C2:
-- Tạo ra 1 biến kiểu char lưu mã giáo viên lương thấp nhất
declare @MinSalaryMAGV char(10)
select @MinSalaryMAGV = MAGV from dbo.GIAOVIEN where LUONG = (select min(LUONG) from dbo.GIAOVIEN)
select year(getdate()) - year(NGSINH) from dbo.GIAOVIEN
where MAGV = @MinSalaryMAGV

--------------------------------------------------------------------------
-- Khởi tạo với kiểu dữ liệu
-- Biến bắt đầu = kí hiệu @
declare @i int

-- Khởi tạo với giá trị mặc định
declare @j int = 0

-- set dữ liệu cho biến
set @i = @i + 1
set @i += 1
set @j += @i

-- set thông qua cấu select
declare @MaxLuong int
select @MaxLuong = MAX(LUONG) from dbo.GIAOVIEN

---------------------------------------------------------------------
-- 1. Xuất ra số lượng người thân của giáo viên 001
-- Lưu mã giáo viên 001 lại
-- Tìm ra số lượng người thân tương ứng mã giáo viên
-- C1
select count(*) from dbo.GIAOVIEN, dbo.NGUOITHAN
where NGUOITHAN.MAGV = GIAOVIEN.MAGV and GIAOVIEN.MAGV = '001'

-- C2
declare @MaGV char(10) = '001'
select count(*) from dbo.NGUOITHAN 
where MAGV = @MaGV
----------------------------------------------------------------------
-- 2. Xuất ra tên của giáo viên có lương thấp nhất
declare @MinLuong int
declare @Ten nvarchar(100)
select @MinLuong = min(LUONG) from dbo.GIAOVIEN
select @Ten = HOTEN from dbo.GIAOVIEN
where LUONG = @MinLuong

-- Xuất giá trị ra màn hình
print @Ten