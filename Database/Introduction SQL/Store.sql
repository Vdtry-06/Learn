use HowKteam
go

/*
 - Store PROCEDURE:
	Stored procedures thường được sử dụng trong các hệ thống lớn, 
	nơi mà việc quản lý hiệu suất, bảo mật và tính toàn vẹn dữ liệu 
	là rất quan trọng.
 - Lưu trữ chương trình hay thủ tục để tái sử dụng đoạn code
 - Thực hiện lệnh Transact-SQL EXECUTE (EXEC) thực thi các stored procedure.  
 - Store procedure khác với các hàm xử lý là giá trị trả về của chúng
 - Không chứa trong tên và chúng không được sử dụng trực tiếp trong biểu thức
  
*/

/*
 - Động: Có thể chỉnh sửa khối lệnh, tái sử dụng nhiều lần  
 - Nhanh hơn: Tự phân tích cú pháp cho tối ưu. Và tạo bản sao để lần chạy sau không cần thực thi lại từ đầu.  
 - Bảo mật: Giới hạn quyền cho user nào sử dụng user nào không 
 - Giảm bandwidth: với các gói transaction lớn. Vài ngàn dòng lệnh một lúc thì dùng sotre sẽ đảm bảo.  
*/  

/*
 - CREATE PROC <Tên_store>  
 - [Parameter nếu có]
 as
 begin
 	 <code xử lý>
 end
 Nếu chỉ là câu truy vấn thì có thể không cần begin và end 
*/


create proc usp_Test
@MAGV nvarchar(10), @Luong int
as
begin
	select * from dbo.GIAOVIEN 
	where MAGV = @MAGV and LUONG = @Luong
end
go

-- C1: không c?n th? t?
exec dbo.usp_Test @MaGV = N'', @Luong = 0
-- C2: ph?i tu?n t?
exec dbo.usp_Test N'', 0
-- execute dbo.usp_Test @MaGV = N'', @Luong = 0
-- execute dbo.usp_Test N'', 0
go

create proc usp_SelectAllGiaoVien

drop proc usp_SelectAllGiaoVien
as select * from dbo.GIAOVIEN
go

exec dbo.usp_SelectAllGiaoVien