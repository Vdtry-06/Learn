use HowKteam
go

-- Xuất ra danh sách tên bộ môn và số lượng giáo viên của bộ môn đó.
select TENBM, count(*) from dbo.BOMON as bm, dbo.GIAOVIEN as gv
where bm.MABM = gv.MABM
group by bm.TENBM

-- cột hiển thị phải là thuộc tính nằm trong khối group by hoặc là agreegate function

-- Xuất ra danh sách tên bộ môn và số lượng giáo viên của bộ môn đó.
select TENBM, count(*) from dbo.BOMON as bm, dbo.GIAOVIEN as gv
where bm.MABM = gv.MABM
group by bm.TENBM, bm.MABM

-- Xuất ra danh sách tên bộ môn và số lượng giáo viên của bộ môn đó.
select TENBM, PHONG, count(*) from dbo.BOMON as bm, dbo.GIAOVIEN as gv
where bm.MABM = gv.MABM
group by bm.TENBM, bm.PHONG

-- Xuất ra danh sách tên bộ môn và số lượng giáo viên của bộ môn đó.
select TENBM, MAKHOA, count(*) from dbo.BOMON as bm, dbo.GIAOVIEN as gv
where bm.MABM = gv.MABM
group by bm.TENBM, bm.MAKHOA

-- Lấy ra danh sách giáo viên có lương > luong trung bình của giáo viên
select * from dbo.GIAOVIEN
where LUONG > (select sum(LUONG) from dbo.GIAOVIEN) / (select count(*) from dbo.GIAOVIEN)

-- xuất ra tên giáo viên và số lượng công việc giáo viên đó làm
select gv.HOTEN, count(*) from dbo.GIAOVIEN as gv, dbo.DETAI as dt, dbo.CONGVIEC as cv 
where dt.GVCNDT = gv.MAGV and cv.MADT = dt.MADT
group by gv.HOTEN

-- xuất ra tên giáo viên và số lượng đề tài giáo viên đó làm
select HOTEN, count(*) from dbo.THAMGIADT as tg, dbo.GIAOVIEN as gv
where gv.MAGV = tg.MAGV
group by gv.MAGV, gv.HOTEN

-- Bài tập:
-- 1. Xuất ra tên giáo viên và số lượng người thân của gv đó.
select gv.HOTEN, count(*) from dbo.GIAOVIEN as gv, dbo.NGUOITHAN as nt
where gv.MAGV = nt.MAGV
group by gv.MAGV, gv.HOTEN

--2. Xuất ra tên giáo viên và số lượng đề tài đã hoàn thành mà giáo viên đó tham gia
select gv.HOTEN, count(*) from dbo.THAMGIADT as tg, dbo.GIAOVIEN as gv
where tg.MAGV = gv.MAGV and tg.KETQUA = N'Đạt'
group by gv.MAGV, gv.HOTEN

--3. Xuất ra tên khoa có tổng số lượng của giáo viên trong khoa là lớn nhất
select top(1) k.TENKHOA, count(*) from dbo.KHOA as k, dbo.BOMON as bm, dbo.GIAOVIEN as gv
where k.MAKHOA = bm.MAKHOA and bm.MABM = gv.MABM
group by k.MAKHOA, k.TENKHOA
order by count(*) desc

/*
Agreeate Function

avg()  : trả về giá trị trung bình
count(): trả về số lượng dòng
first(): trả về giá trị đầu tiên
last() : trả về giá trị cuối cùng
max()  : trả về giá trị lớn nhất
min()  : trả về giá trị nhỏ nhất
round(): trả về giá trị đượ làm tròn
sum () : trả về tổng
*/
/*
String Function

charindex			: tìm 1 phần tử có tồn tại trong chuỗi hay không
concat()			: cắt chuỗi
left()				: lấy phần tử bên trái
len() / length()	: lấy độ dài
lower() / lcase()	: viết thường
ltrim()				: cắt khoảng trắng bên trái
substring() / mid()	: chuỗi con
replace()			: thay thế
right()				: lấy phần tử bên phải
rtrim()				: cắt khoảng trắng bên phải
upper() / ucase()	: viết hoa
*/