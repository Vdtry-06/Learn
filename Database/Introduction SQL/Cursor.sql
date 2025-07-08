use HowKteam
go

-- Khi có nhu cầu duyệt từng record của bảng. Với mỗi record có kết quả xử lý riêng thì dùng Cursor

-- declare <Tên con trỏ> cursor for <câu select>
--open <Tên con trỏ>

-- fetch next from <Tên con trỏ> into <Danh sách các biến tương ứng kết quả truy vấn>

-- while @@fetch_status = 0
-- begin
-- Câu lệnh thực hiện
-- fetch next lại lần nữa
-- fetch next from <Tên con trỏ> into <Danh sách các biến tương ứng kết quả truy vấn>
-- end

-- close <Tên con trỏ>
-- deallocate <Tên con trỏ>
-------------------------------------------------------------------------
-- Từ tuổi của giáo viên
-- Nếu > 50 thì lương = 2500
-- Nếu > 40 & < 50 thì lương = 2000
-- Ngược lại lương = 1500

select * from dbo.GIAOVIEN
-- Lấy ra danh sách MAGV kèm tuổi đưa vào con trỏ có tên là GiaoVienCursor
declare GiaoVienCursor cursor for select MAGV, year(getdate()) - year(NGSINH) from dbo.GIAOVIEN

open GiaoVienCursor

declare @MaGV char(10)
declare @Tuoi int

fetch next from GiaoVienCursor into @MaGV, @Tuoi

while @@FETCH_STATUS = 0
begin
	if @Tuoi > 50
		begin
			update dbo.GIAOVIEN set LUONG = 2500
			where @MaGV = MAGV
		end
	else if @Tuoi > 40 and @Tuoi < 50
		begin
			update dbo.GIAOVIEN set LUONG = 2000
			where @MaGV = MAGV
		end
	else
		begin
			update dbo.GIAOVIEN set LUONG = 1500
			where @MaGV = MAGV
		end
	fetch next from GiaoVienCursor into @MaGV, @Tuoi
end

close GiaoVienCursor
deallocate GiaoVienCursor