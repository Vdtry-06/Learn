create database Quan_Ly_Sinh_Vien
go

use Quan_Ly_Sinh_Vien
go
/*
Sua cot trong bang
	ALTER TABLE Khoa
	ALTER COLUMN TenKhoa nvarchar(100)
	GO
*/
create table Khoa
(
	MaKhoa varchar(10) primary key,
	TenKhoa nvarchar(10),
	NamThanhLap int
)
go

create table KhoaHoc
(
	MaKhoaHoc varchar(10) primary key,
	NamBatDau int,
	NamKetThuc int
)
go

create table ChuongTrinhHoc
(
	MaChuongTrinh varchar(10) primary key,
	TenChuongTrinh nvarchar(100)
)
go

create table Lop
(
	MaLop varchar(10) primary key,
	MaKhoa varchar(10) not null,
	MaChuongTrinh varchar(10) not null,
	MaKhoaHoc varchar(10)not null,
	STT int

	foreign key(MaKhoa) references Khoa(MaKhoa),
	foreign key(MaChuongTrinh) references ChuongTrinhHoc(MaChuongTrinh),
	foreign key(MaKhoaHoc) references KhoaHoc(MaKhoaHoc)
)
go

create table SinhVien
(
	MaSv varchar(10) primary key,
	HoTen nvarchar(100),
	NamSinh int,
	DanToc nvarchar(10),
	MaLop varchar(10) not null

	foreign key (MaLop) references Lop(MaLop)
)
go

create table MonHoc
(
	MaMonHoc varchar(10) primary key,
	MaKhoa varchar(10) not null,
	TenMonHoc nvarchar(100)

	foreign key (MaKhoa) references Khoa(MaKhoa)
)
go

create table KetQua
(
	MaSv varchar(10) not null,
	MaMonHoc varchar(10) not null,
	LanThi int,
	Diem float

	primary key (MaSv, MaMonHoc, LanThi)

	foreign key (MaSv) references SinhVien(MaSv),
	foreign key (MaMonHoc) references MonHoc(MaMonHoc)
)
go

create table GiangKhoa
(
	MaChuongTrinh varchar(10) not null,
	MaKhoa varchar(10) not null,
	MaMonHoc varchar(10) not null,
	NamHoc int not null,
	HocKy int,
	SoTietLyThuyet int,
	SoTietThucHanh int,
	SoTinChi int

	primary key (MaChuongTrinh, MaKhoa, MaMonHoc, NamHoc),

	foreign key (MaChuongTrinh) references ChuongTrinhHoc(MaChuongTrinh),
	foreign key (MaKhoa) references Khoa(MaKhoa),
	foreign key (MaMonHoc) references MonHoc(MaMonHoc)
)
go

