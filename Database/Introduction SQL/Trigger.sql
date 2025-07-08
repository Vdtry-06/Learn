use HowKteam
go


-- Trigger sẽ được gọi mỗi khi có thao tác thay đổi thông tin bảng
-- Inserted: Chứa những trường đã insert | update vào bảng
-- Deleted: Chứa những trường đã bị xóa khỏi bảng
create trigger utg_InsertGiaoVien on dbo.GIAOVIEN 
for insert, update
as
begin
	-- rollback tran -- hủy bỏ thay đổi cập nhật bảng
	print 'Trigger2'
end
go

select * from dbo.GIAOVIEN

insert dbo.GIAOVIEN
	(
		MAGV,
		HOTEN,
		LUONG,
		PHAI,
		NGSINH,
		DIACHI,
		GVQLCM,
		MABM
	)
values (N'011', -- MAGV nchar(3),
		N'Giáo viên mới', -- HOTEN nvarchar(50),
		0.0, -- LUONG float,
		N'Nam', -- PHAI nchar(3),
		getdate(), -- NGSINH date,
		N'NA', -- DIACHI nchar(50)
		NULL , --  GVQLCM nchar(3),
		N'MMT'-- MABM nchar(4),
		)
---------------------------------------------------------------------------
-- Không cho phép xóa thông tin của giáo viên có tuổi > 40
create trigger utg_AbortOlderThan40 on dbo.GIAOVIEN
for delete
as
begin
	declare @Count int = 0
	select @count = count(*) from deleted
	where (year(getdate()) - year(deleted.NGSINH)) < 1
	if (@count > 0)
	begin
	print N'Không được xóa người  > 40 tuổi'
		rollback tran
	end
end

select * from dbo.GIAOVIEN

delete dbo.GIAOVIEN where MAGV = '011'

insert dbo.GIAOVIEN
	(
		MAGV,
		HOTEN,
		LUONG,
		PHAI,
		NGSINH,
		DIACHI,
		GVQLCM,
		MABM
	)
values (N'012', -- MAGV nchar(3),
		N'dgdsdfd', -- HOTEN nvarchar(50),
		0.0, -- LUONG float,
		N'Nam', -- PHAI nchar(3),
		'20040603', -- NGSINH date,
		N'HN', -- DIACHI nchar(50)
		NULL , --  GVQLCM nchar(3),
		N'MMT'-- MABM nchar(4),
		)