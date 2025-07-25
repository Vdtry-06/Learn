USE [master]
GO
/****** Object:  Database [Quan_Ly_Sinh_Vien]    Script Date: 8/14/2024 10:56:11 AM ******/
CREATE DATABASE [Quan_Ly_Sinh_Vien]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Quan_Ly_Sinh_Vien', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS\MSSQL\DATA\Quan_Ly_Sinh_Vien.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'Quan_Ly_Sinh_Vien_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL16.SQLEXPRESS\MSSQL\DATA\Quan_Ly_Sinh_Vien_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT, LEDGER = OFF
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET COMPATIBILITY_LEVEL = 160
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Quan_Ly_Sinh_Vien].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ARITHABORT OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET  ENABLE_BROKER 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET  MULTI_USER 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET QUERY_STORE = ON
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET QUERY_STORE (OPERATION_MODE = READ_WRITE, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 30), DATA_FLUSH_INTERVAL_SECONDS = 900, INTERVAL_LENGTH_MINUTES = 60, MAX_STORAGE_SIZE_MB = 1000, QUERY_CAPTURE_MODE = AUTO, SIZE_BASED_CLEANUP_MODE = AUTO, MAX_PLANS_PER_QUERY = 200, WAIT_STATS_CAPTURE_MODE = ON)
GO
USE [Quan_Ly_Sinh_Vien]
GO
/****** Object:  Table [dbo].[ChuongTrinhHoc]    Script Date: 8/14/2024 10:56:11 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ChuongTrinhHoc](
	[MaChuongTrinh] [varchar](10) NOT NULL,
	[TenChuongTrinh] [nvarchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaChuongTrinh] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[GiangKhoa]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GiangKhoa](
	[MaChuongTrinh] [varchar](10) NOT NULL,
	[MaKhoa] [varchar](10) NOT NULL,
	[MaMonHoc] [varchar](10) NOT NULL,
	[NamHoc] [int] NOT NULL,
	[HocKi] [int] NULL,
	[SoTietLyThuyet] [int] NULL,
	[SoTietThucHanh] [int] NULL,
	[SoTinChi] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaChuongTrinh] ASC,
	[MaKhoa] ASC,
	[MaMonHoc] ASC,
	[NamHoc] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[KetQua]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[KetQua](
	[MaSv] [varchar](10) NOT NULL,
	[MaMonHoc] [varchar](10) NOT NULL,
	[LanThi] [int] NOT NULL,
	[Diem] [float] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaSv] ASC,
	[MaMonHoc] ASC,
	[LanThi] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Khoa]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Khoa](
	[MaKhoa] [varchar](10) NOT NULL,
	[TenKhoa] [nvarchar](100) NULL,
	[NamThanhLap] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaKhoa] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[KhoaHoc]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[KhoaHoc](
	[MaKhoaHoc] [varchar](10) NOT NULL,
	[NamBatDau] [int] NULL,
	[NamKetThuc] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaKhoaHoc] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Lop]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Lop](
	[MaLop] [varchar](10) NOT NULL,
	[MaKhoa] [varchar](10) NOT NULL,
	[MaChuongTrinh] [varchar](10) NOT NULL,
	[MaKhoaHoc] [varchar](10) NOT NULL,
	[STT] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaLop] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MonHoc]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MonHoc](
	[MaMonHoc] [varchar](10) NOT NULL,
	[MaKhoa] [varchar](10) NOT NULL,
	[TenMonHoc] [nvarchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaMonHoc] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[SinhVien]    Script Date: 8/14/2024 10:56:12 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SinhVien](
	[MaSv] [varchar](10) NOT NULL,
	[HoTen] [nvarchar](100) NULL,
	[NamSinh] [int] NULL,
	[DanToc] [nvarchar](10) NULL,
	[MaLop] [varchar](10) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[MaSv] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[ChuongTrinhHoc] ([MaChuongTrinh], [TenChuongTrinh]) VALUES (N'CQ', N'Chính Quy')
GO
INSERT [dbo].[GiangKhoa] ([MaChuongTrinh], [MaKhoa], [MaMonHoc], [NamHoc], [HocKi], [SoTietLyThuyet], [SoTietThucHanh], [SoTinChi]) VALUES (N'CQ', N'CNTT', N'THT01', 2003, 1, 60, 30, 5)
INSERT [dbo].[GiangKhoa] ([MaChuongTrinh], [MaKhoa], [MaMonHoc], [NamHoc], [HocKi], [SoTietLyThuyet], [SoTietThucHanh], [SoTinChi]) VALUES (N'CQ', N'CNTT', N'THT01', 2004, 1, 45, 30, 4)
INSERT [dbo].[GiangKhoa] ([MaChuongTrinh], [MaKhoa], [MaMonHoc], [NamHoc], [HocKi], [SoTietLyThuyet], [SoTietThucHanh], [SoTinChi]) VALUES (N'CQ', N'CNTT', N'THT02', 2003, 2, 45, 30, 4)
GO
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212001', N'THCS01', 1, 6.5)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212001', N'THT01', 1, 4)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212001', N'THT01', 2, 7)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212001', N'THT02', 1, 8)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212002', N'THCS01', 1, 4)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212002', N'THT01', 1, 8)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212002', N'THT02', 1, 5.5)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212003', N'THCS01', 1, 7)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212003', N'THT01', 1, 6)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212003', N'THT02', 1, 4)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212003', N'THT02', 2, 6)
INSERT [dbo].[KetQua] ([MaSv], [MaMonHoc], [LanThi], [Diem]) VALUES (N'0212004', N'THT01', 1, 9)
GO
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamThanhLap]) VALUES (N'CNTT', N'Công nghệ thông tin', 1995)
INSERT [dbo].[Khoa] ([MaKhoa], [TenKhoa], [NamThanhLap]) VALUES (N'VL', N'Vật Lý', 1970)
GO
INSERT [dbo].[KhoaHoc] ([MaKhoaHoc], [NamBatDau], [NamKetThuc]) VALUES (N'K2002', 2002, 2006)
INSERT [dbo].[KhoaHoc] ([MaKhoaHoc], [NamBatDau], [NamKetThuc]) VALUES (N'K2003', 2003, 2007)
INSERT [dbo].[KhoaHoc] ([MaKhoaHoc], [NamBatDau], [NamKetThuc]) VALUES (N'K2004', 2004, 2008)
GO
INSERT [dbo].[Lop] ([MaLop], [MaKhoa], [MaChuongTrinh], [MaKhoaHoc], [STT]) VALUES (N'TH2002/01', N'CNTT', N'CQ', N'K2002', 1)
INSERT [dbo].[Lop] ([MaLop], [MaKhoa], [MaChuongTrinh], [MaKhoaHoc], [STT]) VALUES (N'TH2002/02', N'CNTT', N'CQ', N'K2002', 2)
INSERT [dbo].[Lop] ([MaLop], [MaKhoa], [MaChuongTrinh], [MaKhoaHoc], [STT]) VALUES (N'VL2003/01', N'VL', N'CQ', N'K2003', 1)
GO
INSERT [dbo].[MonHoc] ([MaMonHoc], [MaKhoa], [TenMonHoc]) VALUES (N'THCS01', N'CNTT', N'Cấu trúc dữ liệu 1')
INSERT [dbo].[MonHoc] ([MaMonHoc], [MaKhoa], [TenMonHoc]) VALUES (N'THCS02', N'CNTT', N'Hệ điều hành')
INSERT [dbo].[MonHoc] ([MaMonHoc], [MaKhoa], [TenMonHoc]) VALUES (N'THT01', N'CNTT', N'Toán Cao cấp A1')
INSERT [dbo].[MonHoc] ([MaMonHoc], [MaKhoa], [TenMonHoc]) VALUES (N'THT02', N'CNTT', N'Toán rời rạc')
INSERT [dbo].[MonHoc] ([MaMonHoc], [MaKhoa], [TenMonHoc]) VALUES (N'VLT01', N'VL', N'Toán Cao cấp A1')
GO
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0212001', N'Nguyễn Vĩnh An', 1984, N'Kinh', N'TH2002/01')
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0212002', N'Nguyên Thanh Bình', 1985, N'Kinh', N'TH2002/01')
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0212003', N'Nguyễn Thanh Cường', 1984, N'Kinh', N'TH2002/02')
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0212004', N'Nguyễn Quốc Duy', 1983, N'Kinh', N'TH2002/02')
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0311001', N'Phan Tuấn Anh', 1985, N'Kinh', N'VL2003/01')
INSERT [dbo].[SinhVien] ([MaSv], [HoTen], [NamSinh], [DanToc], [MaLop]) VALUES (N'0311002', N'Huỳnh Thanh Sang', 1984, N'Kinh', N'VL2003/01')
GO
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD FOREIGN KEY([MaChuongTrinh])
REFERENCES [dbo].[ChuongTrinhHoc] ([MaChuongTrinh])
GO
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD FOREIGN KEY([MaKhoa])
REFERENCES [dbo].[Khoa] ([MaKhoa])
GO
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD FOREIGN KEY([MaMonHoc])
REFERENCES [dbo].[MonHoc] ([MaMonHoc])
GO
ALTER TABLE [dbo].[KetQua]  WITH CHECK ADD FOREIGN KEY([MaSv])
REFERENCES [dbo].[SinhVien] ([MaSv])
GO
ALTER TABLE [dbo].[KetQua]  WITH CHECK ADD FOREIGN KEY([MaMonHoc])
REFERENCES [dbo].[MonHoc] ([MaMonHoc])
GO
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD FOREIGN KEY([MaChuongTrinh])
REFERENCES [dbo].[ChuongTrinhHoc] ([MaChuongTrinh])
GO
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD FOREIGN KEY([MaKhoaHoc])
REFERENCES [dbo].[KhoaHoc] ([MaKhoaHoc])
GO
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD FOREIGN KEY([MaKhoa])
REFERENCES [dbo].[Khoa] ([MaKhoa])
GO
ALTER TABLE [dbo].[MonHoc]  WITH CHECK ADD FOREIGN KEY([MaKhoa])
REFERENCES [dbo].[Khoa] ([MaKhoa])
GO
ALTER TABLE [dbo].[SinhVien]  WITH CHECK ADD FOREIGN KEY([MaLop])
REFERENCES [dbo].[Lop] ([MaLop])
GO
USE [master]
GO
ALTER DATABASE [Quan_Ly_Sinh_Vien] SET  READ_WRITE 
GO
