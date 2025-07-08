use Quan_Ly_Sinh_Vien
go

/*
	Hãy cài đặt các ràng buộc toàn vẹn sau (bằng check constraint, unique constraint, rule hoặc trigger):
	Miền giá trị

	1. ChuongTrinh mà chỉ có thể là ‘CQ‘ hoặc ‘CD‘ hoặc ‘TC’
	2. Chỉ có 2 học kỳ là ‘HK1‘ và ‘HK2‘
	3. Số tiết lý thuyết (GiangKhoa.soTietLyThuyet) tối đa là 120
	4. Số tiết thực hành (GiangKhoa.soTietThucHanh) tối đa là 60
	5. Số tín chỉ (GiangKhoa.soTinChi) của một môn học tối đa là 6
	6. Điểm thi (KetQua.diem) được chấm theo thang điểm 10 và chính xác đến 0.5  
	(làm bằng 2 cách: kiểm tra và báo lỗi nếu không đúng quy định; tự động làm tròn nếu không đúng qui định về độ chính xác)

	Bài tập về nhà
	Liên thuộc tính trên 1 quan hệ

	7. Năm kết thúc khóa học phải lớn hơn hoặc bằng năm bắt đầu 
	8. Số tiết lý thuyết của mỗi giảng khóa không nhỏ hơn số tiết thực hành Liên bộ trên 1 quan hệ
*/

-- 1. ChuongTrinh mà chỉ có thể là ‘CQ‘ hoặc ‘CD‘ hoặc ‘TC’
-- Dung Check
select * from ChuongTrinhHoc
alter table ChuongTrinhHoc
add constraint Check_MaCT check(MaChuongTrinh in ('CQ', 'CD', 'TC'))

-- Dung Trigger
create trigger Tg_Check_MaCT on ChuongTrinhHoc
for insert, update
as
begin
	declare @Mact varchar(10)
	select @Mact = MaChuongTrinh from inserted
	if(@Mact not in ('CQ', 'CD', 'TC'))
		rollback
end