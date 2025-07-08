use HowKteam
go
-- tao function ko co parameter
create function uf_SelectAllGiaoVien()
returns table
as return select * from dbo.GIAOVIEN
go

select * from uf_SelectAllGiaoVien()

-- huy function
drop function uf_SelectAllGiaoVien

-- tao function co parameter
create function uf_LUONGGV(@MAGV char(10))
returns int
as
begin
	declare @Luong int
	select @Luong = LUONG from dbo.GIAOVIEN where MAGV = @MAGV
	return @Luong
end
go
select dbo.uf_LUONGGV(MAGV) from dbo.GIAOVIEN

-- Sua function co parameter
alter function uf_LUONGGV(@MAGV char(10))
returns int
as
begin
	declare @Luong int
	select @Luong = LUONG from dbo.GIAOVIEN where MAGV = @MAGV
	return @Luong
end
-------------------------------------------------------------------------
-- Tao function tinh mot so truyen vao phai la so chan hay khong
create function uf_Test(@Num int)
returns nvarchar(20)
as 
begin
	if(@Num % 2 = 0) 
		return N'Số Chẵn'
	else
		return N'Số lẻ'
	return N'Không xác định'
end

create function uf_AgeOfYear(@Year date)
returns int
as
begin
	return year(getdate()) - year(@Year)
end

select dbo.uf_AgeOfYear(NGSINH), dbo.uf_Test(dbo.uf_AgeOfYear(NGSINH)) from dbo.GIAOVIEN