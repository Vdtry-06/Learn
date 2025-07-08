use Quan_Ly_Sinh_Vien
go
/*
	1. In danh sách các sinh viên của 1 lớp học
	2. Nhập vào 2 sinh viên, 1 môn học, tìm xem sinh viên nào có điểm thi môn học đó lần đầu tiên là cao hơn.
	3. Nhập vào 1 môn học và 1 mã sv, kiểm tra xem sinh viên có đậu môn này trong lần đầu tiên thi không, nếu đậu xuất ra 'Đậu' không thì xuất ra 'Không đậu'
	4. Nhập vào 1 khoa, in danh sách các sinh viên(mã sinh viên, họ tên, ngày sinh) thuộc khoa này
	5. Nhập vào 1 sinh viên và 1 môn học, in điểm thi của sinh viên này của các lần thi môn học đó.
		Ví dụ:
		Lần 1 : 10
		Lần 2 : 8
	6. Nhập vào 1 sinh viên, in ra các môn học mà sinh viên này phải học.
	7. Nhập vào 1 môn học, in danh sách các sinh viên đậu môn này trong lần thi đầu tiên.
	8. In điểm các môn học của sinh viên có mã số là MaSinhVien được nhập vào.
	(Chú ý: điểm của môn học là điểm thi của lần thi sau cùng)

	Bài tập về nhà:

	Thêm 1 quan hệ

	XepLoai:

	maSV	diemTrungBinh	ketQua	hocLuc
	9. Quy định : ketQua của sinh viên là ”Đạt‘ nếu diemTrungBinh (chỉ tính các môn đã có điểm) của sinh viên đó lớn hơn hoặc bằng 5 
	và không quá 2 môn dưới 4 điểm, ngược lại thì kết quả là không đạtĐưa dữ liệu vào bảng xếp loại. Sử dụng function 3 đã viết ở bài 4
	Đối với những sinh viên có ketQua là ”Đạt‘ thì hocLuc được xếp loại như sau:

	 diemTrungBinh >= 8 thì hocLuc là ”Giỏi”
	7 < = diemTrungBinh < 8 thì hocLuc là ”Khá” Còn lại là ”Trung bình”  

	10. Với các sinh viên có tham gia đầy đủ các môn học của khoa, chương trình mà sinh viên đang theo học, hãy in ra điểm trung bình cho các sinh viên này.
	Chú ý: Điểm trung bình được tính dựa trên điểm thi lần sau cùng. Sử dụng function 3 đã viết ở bài 4 
		
*/

-- 1. In danh sách các sinh viên của 1 lớp học
-- Phai co ma lop
-- Tim tat ca sinh vien dua theo ma lop
create proc KP_List_Sv_From_lop
	@MaLop varchar(10)
as
begin
	--set @MaLop = 'TH2002/01'
	select SinhVien.* from SinhVien
	left join Lop on SinhVien.MaLop = Lop.MaLop
	where Lop.MaLop = @MaLop
end

exec KP_List_Sv_From_lop 'TH2002/01'
go

-- 2. Nhập vào 1 sinh viên, 1 môn học, tìm xem sinh viên nào có điểm thi môn học đó lần đầu tiên là cao hơn.
create function Max_Diem_First_Time
(
	@MaSv varchar(10),
	@MaMh varchar(10)
)
returns float
as
begin
	declare @KetQua float;
	set @KetQua = 0;
	select @KetQua = Diem from KetQua
	where KetQua.MaSv = @MaSv
	and KetQua.MaMonHoc = @MaMh
	and KetQua.LanThi = 1
	return @KetQua
end
go

create proc Max_Diem_Sv
	@Masv1 varchar(10),
	@Masv2 varchar(10),
	@Mamh varchar(10)
as
begin
-- declare @Masv1 varchar(10)
-- declare @Masv2 varchar(10)
-- declare @Mamh varchar(10)

-- set @Masv1 = '0212001'
-- set @Masv2 = '0212003'
-- set @Mamh = 'THT01'

declare @Ketqua1 float
declare @Ketqua2 float
select @Ketqua1 = dbo.Max_Diem_First_Time(@Masv1, @Mamh)
select @Ketqua2 = dbo.Max_Diem_First_Time(@Masv2, @Mamh)
if (@Ketqua1 > @Ketqua2)
	print @Masv1
else 
	print @Masv2

end
go

exec dbo.Max_Diem_Sv '0212001', '0212003', 'THT01'
select dbo.Max_Diem_First_Time('0212001', 'THT01')
select dbo.Max_Diem_First_Time('0212003', 'THT01')
go

-- 3. Nhập vào 1 môn học và 1 mã sv, kiểm tra xem sinh viên có đậu môn này trong lần đầu tiên thi không, nếu đậu xuất ra 'Đậu' không thì xuất ra 'Không đậu'
create proc Check_Diem
(
	@Masv varchar(10),
	@Mamh varchar(10)
)
as
begin
	--declare @Masv varchar(10)
	--declare @Mamh varchar(10)
	--set @Masv = '0212003'
	--set @Mamh = 'THT01'
	if(exists(
		select * from KetQua
		where KetQua.MaSv = @Masv
		and KetQua.MaMonHoc = @Mamh
		and KetQua.LanThi = 1
		and KetQua.Diem >= 5
		))
		print N'Đậu'
	else
		print N'Không Đậu'
end
go

create proc Check_Diem_C2
(
	@Masv varchar(10),
	@Mamh varchar(10)
)
as
	begin
		declare @Diem float
		select @Diem = KetQua.Diem from KetQua
		where KetQua.MaSv = @Masv
		and KetQua.MaMonHoc = @Mamh
		and KetQua.LanThi = 1
		if(@Diem >= 5)
			print N'Đậu'
		else
			print N'Không Đậu'
	end
go

exec Check_Diem_C2'0212001', 'THT01'
go

-- 4. Nhập vào 1 khoa, in danh sách các sinh viên(mã sinh viên, họ tên, ngày sinh) thuộc khoa này
create proc Student_Of_Depart
	@MaKhoa varchar(10)
as
begin
	select SinhVien.* from SinhVien
	left join Lop on SinhVien.MaLop = Lop.MaLop
	left join Khoa on Lop.MaKhoa = Khoa.MaKhoa
	where Khoa.MaKhoa = @MaKhoa
end
go

exec Student_Of_Depart 'CNTT'
go
-- 5. Nhập vào 1 sinh viên và 1 môn học, in điểm thi của sinh viên này của các lần thi môn học đó.
create proc Score_Of_Student_Subject
	@Masv varchar(10),
	@Mamh varchar(10)
as
begin
	select SinhVien.*, KetQua.MaMonHoc, KetQua.Diem from SinhVien
	left join KetQua on SinhVien.MaSv = KetQua.MaSv
	where KetQua.MaSv = @Masv
	and KetQua.MaMonHoc = @Mamh
end
go

exec Score_Of_Student_Subject '0212003', 'THT02'
go

-- 6. Nhập vào 1 sinh viên, in ra các môn học mà sinh viên này phải học.
create proc Subjects_Student_Learn
	@Masv varchar(10)
as
begin
	select MonHoc.* from MonHoc
	left join Khoa on Khoa.MaKhoa = MonHoc.MaKhoa
	left join Lop on Lop.MaKhoa = Khoa.MaKhoa
	left join ChuongTrinhHoc on ChuongTrinhHoc.MaChuongTrinh = Lop.MaChuongTrinh
	left join KhoaHoc on KhoaHoc.MaKhoaHoc = Lop.MaKhoaHoc
	left join SinhVien on SinhVien.MaLop = Lop.MaLop
	where SinhVien.MaSv = @Masv
end

exec Subjects_Student_Learn '0212001'
go

-- 7. Nhập vào 1 môn học, in danh sách các sinh viên đậu môn này trong lần thi đầu tiên.
create proc Student_Obtain_Subject
	@Mamh varchar(10)
as
begin
	select * from SinhVien
	left join KetQua on KetQua.MaSv = SinhVien.MaSv
	where KetQua.MaMonHoc = @Mamh
	and KetQua.LanThi = 1
	and KetQua.Diem >= 5
end

exec Student_Obtain_Subject 'THT02'
go

-- 8. In điểm các môn học của sinh viên có mã số là MaSinhVien được nhập vào.
	--(Chú ý: điểm của môn học là điểm thi của lần thi sau cùng)
create proc Score_Last_Student
	@Masv varchar(10)
as
begin
	select * from KetQua
	where KetQua.MaSv = @Masv
	and KetQua.LanThi = 
	(
		select MAX(kq.LanThi) from KetQua kq
		where kq.MaSv = KetQua.MaSv
		and kq.MaMonHoc = KetQua.MaMonHoc
	)
end
go

exec Score_Last_Student '0212001'
go

/*
	Thêm 1 quan hệ
	XepLoai:
	maSV	diemTrungBinh	ketQua	hocLuc

	9. Quy định : ketQua của sinh viên là ”Đạt‘ nếu diemTrungBinh (chỉ tính các môn đã có điểm) của sinh viên đó lớn hơn hoặc bằng 5 
	và không quá 2 môn dưới 4 điểm, ngược lại thì kết quả là không đạt Đưa dữ liệu vào bảng xếp loại. Sử dụng function 3 đã viết ở bài 4
	Đối với những sinh viên có ketQua là ”Đạt‘ thì hocLuc được xếp loại như sau:

	 diemTrungBinh >= 8 thì hocLuc là ”Giỏi” 7 < = diemTrungBinh < 8 thì hocLuc là ”Khá” Còn lại là ”Trung bình”  
*/

create table XepLoai
(
	MaSv varchar(10) not null,
	DiemTB float,
	KetQua nvarchar(10),
	HocLuc nvarchar(10)

	primary key (MaSv)

	foreign key (MaSv) references SinhVien(MaSv)
)
go

create function Diem_TB
(
	@Masv varchar(10)
)
returns float
as
begin
	declare @Diem float
	select @Diem = sum(GiangKhoa.SoTinChi * KetQua.Diem) / sum(GiangKhoa.SoTinChi) from KetQua
	left join GiangKhoa on GiangKhoa.MaMonHoc = KetQua.MaMonHoc
	where KetQua.MaSv = @Masv 
	and KetQua.LanThi = 
					(
						select Max(kq.LanThi) from KetQua kq
						where kq.MaMonHoc = KetQua.MaMonHoc
						and kq.MaSv = KetQua.MaSv
					)
	return @Diem
end
go

create function Result_Score_Student
(
	@Masv varchar(10)
)
returns nvarchar(10)
as
begin
	declare @Diem float
	declare @Cnt int
	declare @Ketqua nvarchar(10)

	select @Diem = sum(GiangKhoa.SoTinChi * KetQua.Diem) / sum(GiangKhoa.SoTinChi) from KetQua
	left join GiangKhoa on GiangKhoa.MaMonHoc = KetQua.MaMonHoc
	where KetQua.MaSv = @Masv 
	and KetQua.LanThi = 
					(
						select Max(kq.LanThi) from KetQua kq
						where kq.MaMonHoc = KetQua.MaMonHoc
						and kq.MaSv = KetQua.MaSv
					)

	select @Cnt = count(*) from KetQua
	where KetQua.MaSv = @Masv and KetQua.LanThi > 1

	if(@Diem >= 5 and @Cnt <= 2)
		set @Ketqua = N'Đạt'
	else
		set @Ketqua = N'Không Đạt'

	return @Ketqua
end
go

create function Qualification_Student
(
	@Masv varchar(10)
)
returns nvarchar(10)
as
begin
	declare @Diem float
	declare @Hocluc nvarchar(10)

	select @Diem = sum(GiangKhoa.SoTinChi * KetQua.Diem) / sum(GiangKhoa.SoTinChi) from KetQua
	left join GiangKhoa on GiangKhoa.MaMonHoc = KetQua.MaMonHoc
	where KetQua.MaSv = @Masv 
	and KetQua.LanThi = 
					(
						select Max(kq.LanThi) from KetQua kq
						where kq.MaMonHoc = KetQua.MaMonHoc
						and kq.MaSv = KetQua.MaSv
					)
	if(@Diem >= 8)
		set @Hocluc = N'Giỏi'
	else if(@Diem < 8 and @Diem >= 7)
		set @Hocluc = N'Khá'
	else
		set @Hocluc = N'Trung Bình'

	return @Hocluc
end
go

insert into XepLoai (MaSv, DiemTB, KetQua, HocLuc)
select  MaSv, 
		dbo.Diem_TB(MaSv), 
		dbo.Result_Score_Student(MaSv), 
		dbo.Qualification_Student(MaSv) 
from SinhVien
go

select * from XepLoai

-- 10. Với các sinh viên có tham gia đầy đủ các môn học của khoa, chương trình mà sinh viên đang theo học, hãy in ra điểm trung bình cho các sinh viên này.
-- Chú ý: Điểm trung bình được tính dựa trên điểm thi lần sau cùng. Sử dụng function 3 đã viết ở bài 4 
create function Avg_Score
(
	@Masv varchar(10)
)
returns float
as
begin
	declare @DiemTB float

	select @DiemTB = 
				(
					select sum(GiangKhoa.SoTinChi * KetQua.Diem) / sum(GiangKhoa.SoTinChi) from KetQua
					left join GiangKhoa on GiangKhoa.MaMonHoc = KetQua.MaMonHoc
					where KetQua.MaSv = @Masv 
					and KetQua.LanThi = 
									(
										select Max(kq.LanThi) from KetQua kq
										where kq.MaMonHoc = KetQua.MaMonHoc
										and kq.MaSv = KetQua.MaSv
									)
				) 
	from GiangKhoa
	left join Khoa on Khoa.MaKhoa = GiangKhoa.MaKhoa
	left join Lop on Lop.MaKhoa = Khoa.MaKhoa
	left join SinhVien on SinhVien.MaLop = Lop.MaLop
	left join KhoaHoc on KhoaHoc.MaKhoaHoc = Lop.MaKhoaHoc
	left join MonHoc on MonHoc.MaMonHoc = GiangKhoa.MaMonHoc
	left join ChuongTrinhHoc on ChuongTrinhHoc.MaChuongTrinh = GiangKhoa.MaChuongTrinh
	where SinhVien.MaSv = @Masv
	and GiangKhoa.NamHoc >= KhoaHoc.NamBatDau
	and GiangKhoa.NamHoc <= KhoaHoc.NamKetThuc
	return @DiemTB
end
go

select SinhVien.*, dbo.Avg_Score(MaSv) as [DiemTB] from SinhVien
go