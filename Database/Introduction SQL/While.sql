use HowKteam
go

declare @i int = 0
declare @n int = 10000

-- While(điều kiện thực hiện) -> khối lệnh thực hiện
while (@i < @n)
begin
	insert dbo.TestCheck (Luong)
	values (@i -- Luong - int
			)
	set @i += 1
end

select * from dbo.TestCheck
-- Insert 10000 record vào bảng BoMon
-- Mà không trùng ID
-- Tên bộ môn tăng dần

--------------------------------------------------------------------

declare @i int = 100
declare @n int = 10100

-- While(điều kiện thực hiện) -> khối lệnh thực hiện
while (@i < @n)
begin
	insert dbo.BOMON
	(
		MABM,
		TENBM,
		PHONG,
		DIENTHOAI,
		TRUONGBM,
		MAKHOA,
		NGAYNHANCHUC
	)
	values (@i, -- MABM - nchar(4)
			@i, -- TENBM - nchar(50)
			'B15', -- PHONG, - char(3)
			'000000000', -- DIENTHOAI, - char(11)
			null, -- TRUONGBM - nchar(3)
			N'CNTT', -- MAKHOA - nchar(4)
			getdate() -- NGAYNHANCHUC - date
			)
	set @i += 1
end

select * from dbo.BOMON