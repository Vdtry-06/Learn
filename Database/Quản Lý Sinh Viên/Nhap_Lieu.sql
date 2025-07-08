use Quan_Ly_Sinh_Vien
go

-- Khoa
--c1
insert into Khoa(MaKhoa, TenKhoa, NamThanhLap) values('CNTT', N'Công nghệ thông tin', 1995)
go
--c2
insert into Khoa values ( 'VL', N'Vật Lý', 1970)
go

-- Khoa Hoc
insert into KhoaHoc values('K2002', 2002, 2006)
go
insert into KhoaHoc values('K2003', 2003, 2007)
go
insert into KhoaHoc values('K2004', 2004, 2008)
go

-- Chuong Trinh Hoc
insert into ChuongTrinhHoc values('CQ', N'Chính Quy')
go

-- Lop
insert into Lop values('TH2002/01', 'CNTT', 'CQ', 'K2002', 1)
go
insert into Lop values('TH2002/02', 'CNTT', 'CQ', 'K2002', 2)
go
insert into Lop values('VL2003/01', 'VL', 'CQ', 'K2003', 1)
go

-- Sinh Vien
insert into SinhVien values('0212001', N'Nguyễn Vĩnh An', 1984, N'Kinh', 'TH2002/01')
go
insert into SinhVien values('0212002', N'Nguyên Thanh Bình', 1985, N'Kinh', 'TH2002/01')
go
insert into SinhVien values('0212003', N'Nguyễn Thanh Cường', 1984, N'Kinh', 'TH2002/02')
go
insert into SinhVien values('0212004', N'Nguyễn Quốc Duy', 1983, N'Kinh', 'TH2002/02')
go
insert into SinhVien values('0311001', N'Phan Tuấn Anh', 1985, N'Kinh', 'VL2003/01')
go
insert into SinhVien values('0311002', N'Huỳnh Thanh Sang', 1984, N'Kinh', 'VL2003/01')
go

-- Mon Hoc
insert into MonHoc values('THT01', 'CNTT', N'Toán Cao cấp A1')
go
insert into MonHoc values('VLT01', 'VL', N'Toán Cao cấp A1')
go
insert into MonHoc values('THT02', 'CNTT', N'Toán rời rạc')
go
insert into MonHoc values('THCS01', 'CNTT', N'Cấu trúc dữ liệu 1')
go
insert into MonHoc values('THCS02', 'CNTT', N'Hệ điều hành')
go

-- Ket Qua
insert into KetQua values('0212001', 'THT01', 1, 4)
go
insert into KetQua values('0212001', 'THT01', 2, 7)
go
insert into KetQua values('0212002', 'THT01', 1, 8)
go
insert into KetQua values('0212003', 'THT01', 1, 6)
go
insert into KetQua values('0212004', 'THT01', 1, 9)
go
insert into KetQua values('0212001', 'THT02', 1, 8)
go
insert into KetQua values('0212002', 'THT02', 1, 5.5)
go
insert into KetQua values('0212003', 'THT02', 1, 4)
go
insert into KetQua values('0212003', 'THT02', 2, 6)
go
insert into KetQua values('0212001', 'THCS01', 1, 6.5)
go
insert into KetQua values('0212002', 'THCS01', 1, 4)
go
insert into KetQua values('0212003', 'THCS01', 1, 7)
go

-- Giang Khoa
insert into GiangKhoa values('CQ', 'CNTT', 'THT01', 2003, 1, 60, 30, 5)
go
insert into GiangKhoa values('CQ', 'CNTT', 'THT02', 2003, 2, 45, 30, 4)
go
insert into GiangKhoa values('CQ', 'CNTT', 'THT01', 2004, 1, 45, 30, 4)
go