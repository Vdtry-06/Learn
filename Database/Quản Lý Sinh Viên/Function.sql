use Quan_Ly_Sinh_Vien
go

/*
1.Hãy viết các hàm chức năng sau:
	1.1 Với mã sinh viên và 1 mã khoa, kiểm tra xem sinh viên có thuộc khoa này không (trả về đúng hay sai).
	1.2 Tính điểm thi sau cùng của một sinh viên trong một môn học cụ thể.
	1.3 Tính điểm trung bình của sinh viên (chú ý: điểm trung bình được tính dựa trên lần thi sau cùng) sử dụng function 5.2 đã viết.
	1.4 Nhập vào 1 sinh viên và 1 môn học, trả về các điểm thi của sinh viên này trong các lần thi của môn học đó.
	1.5 Nhập vào 1 sinh viên, trả về danh sách các môn học mà sinh viên này phải học.(Bài tập về nhà)
*/


-- 1.1 Với mã sinh viên và 1 mã khoa, kiểm tra xem sinh viên có thuộc khoa này không (trả về đúng hay sai).
create function KF_Check_Sv_In_Khoa
(
	@Masv varchar(10),
	@Makhoa varchar(10)
)
returns varchar(5)
as
begin
declare @Ketqua varchar(5);
set @Ketqua = 'False'
if (exists ( select * from SinhVien
			left join Lop on Lop.MaLop = SinhVien.MaLop
			left join Khoa on Khoa.MaKhoa = Lop.MaKhoa
			where SinhVien.MaSv = @Masv
			and Khoa.MaKhoa = @Makhoa
			)
	)
	set @Ketqua = 'True'
else 
	set @Ketqua = 'False'
return @Ketqua
--print @Ketqua
end
go

select dbo.KF_Check_Sv_In_Khoa('0212003', 'VL')


-- 1.2 Tính điểm thi sau cùng của một sinh viên trong một môn học cụ thể.
create function KF_Last_Score_Of_Student
(
	@Masv varchar(10),
	@Mamh varchar(10)
)
returns float
as
begin
	declare @diem float;
	set @diem = 0;
	/*
	declare @Masv varchar(10);
	declare @Mamh varchar(10);
	set @Masv = '0212003';
	set @Mamh = 'THT02';
	*/
	select top 1 @diem = KetQua.Diem from KetQua
	where MaSv = @Masv
	and MaMonHoc = @Mamh
	order by KetQua.LanThi desc 
	return @diem;
end
go

select dbo.KF_Last_Score_Of_Student('0212003', 'THT02')

select * from SinhVien
left join KetQua on KetQua.MaSv = SinhVien.MaSv

-- 1.3 Tính điểm trung bình của sinh viên (chú ý: điểm trung bình được tính dựa trên lần thi sau cùng) sử dụng function 5.2 đã viết.
create function KF_Last_Avg_Score_Of_Student
(
	@Masv varchar(10)
)
returns float
as
begin
	declare @Ketqua float;
	declare @Mamh varchar(10);
	-- set @Masv = '0212002';

	select @Ketqua = avg(dbo.KF_Last_Score_Of_Student(@Masv, KetQua.MaMonHoc)) from KetQua
	where KetQua.MaSv = @Masv
	return @Ketqua
end
go

select dbo.KF_Last_Avg_Score_Of_Student('0212002')
go

-- 1.4 Nhập vào 1 sinh viên và 1 môn học, trả về các điểm thi của sinh viên này trong các lần thi của môn học đó.
create function KF_List_Score_Of_Student
(
	@Masv varchar(10),
	@Mamh varchar(10)
)
returns table
as
return
	/*
	declare @Masv varchar(10);
	declare @Mamh varchar(10);
	set @Masv = '0212001';
	set @Mamh = 'THT01';
	*/
	select KetQua.LanThi, KetQua.Diem from KetQua
	where MaSv = @Masv
	and MaMonHoc = @Mamh

go

select * from dbo.KF_List_Score_Of_Student('0212001', 'THT01')

select * from SinhVien
left join KetQua on KetQua.MaSv = SinhVien.MaSv
go

--1.5 Nhập vào 1 sinh viên, trả về danh sách các môn học mà sinh viên này phải học.(Bài tập về nhà)
create function KF_List_Subject_Of_Student
(
	@MaSv varchar(10)
)
returns table
as
return
	--declare @MaSv varchar(10);
	--set @MaSv = '0311001';

	select MonHoc.* from MonHoc
	left join Khoa on Khoa.MaKhoa = MonHoc.MaKhoa
	left join Lop on Lop.MaKhoa = Khoa.MaKhoa
	left join ChuongTrinhHoc on ChuongTrinhHoc.MaChuongTrinh = Lop.MaChuongTrinh
	left join KhoaHoc on KhoaHoc.MaKhoaHoc = Lop.MaKhoaHoc
	left join SinhVien on SinhVien.MaLop = Lop.MaLop
	where SinhVien.MaSv = @MaSv

go

select * from dbo.KF_List_Subject_Of_Student('0212001')