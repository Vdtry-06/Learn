use HowKteam
go

-- Ví dụ 1: Kiểm tra xem lương của giáo viên nhập vào có > lương TB hay không
declare @LuongTB int
declare @SoLuongGV int

select @SoLuongGV = count(*) from dbo.GIAOVIEN
select @LuongTB = sum(LUONG) / @SoLuongGV from dbo.GIAOVIEN
declare @MaGV char(10) = '006'
declare @LuongMaGV int = 0

select @LuongMaGV = LUONG from dbo.GIAOVIEN
where MAGV = @MAGV
-- Nếu lương của @MaGV > @LuongTB
-- Xuất ra lớn hơn
-- ngược lại
-- Xuât ra nhỏ hơn

if @LuongMaGV > @LuongTB 
	begin
		print @LuongMaGV
		print @LuongTB
		print N'Lớn hơn'
	end
else 
	begin
		print @LuongMaGV
		print @LuongTB
		print N'Nhỏ hơn'
	end

--------------------------------------------------------------------

-- Ví dụ 2: Update lương của toàn bộ giáo viên nếu lương nhập cao hơn lương trung bình
-- Ngược lại chỉ update lương giáo viên nữ
declare @LuongTB int
declare @SoLuongGV int

select @SoLuongGV = count(*) from dbo.GIAOVIEN
select @LuongTB = sum(LUONG) / @SoLuongGV from dbo.GIAOVIEN

declare @Luong int = 1500
if (@Luong > @LuongTB)
	begin
		update dbo.GIAOVIEN set Luong = @Luong
	end
else
	Begin
		update dbo.GIAOVIEN set Luong = @Luong
		where PHAI = N'Nữ'
	end

	select * from dbo.GIAOVIEN