use HowKteam
go

-- Tạo index trên bảng người thân
-- Tăng tốc độ tìm kiếm <> chậm tốc độ thêm, xóa, sửa
-- Cho phép các trường trùng nhau
create index IndexName on dbo.NGUOITHAN(MaGV)

-- Không cho phép các trường trùng nhau
create unique index IndexNameUnique on dbo.GIAOVIEN(MaGV)

select * from dbo.GIAOVIEN