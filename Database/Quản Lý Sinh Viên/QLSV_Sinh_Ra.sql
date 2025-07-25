USE [master]
GO
/****** Object:  Database [Quan_Ly_Sinh_Vien]    Script Date: 8/13/2024 9:37:17 PM ******/
CREATE DATABASE [Quan_Ly_Sinh_Vien]
USE [Quan_Ly_Sinh_Vien]
GO
/****** Object:  Table [dbo].[ChuongTrinhHoc]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[GiangKhoa]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[KetQua]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[Khoa]    Script Date: 8/13/2024 9:37:17 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Khoa](
	[MaKhoa] [varchar](10) NOT NULL,
	[TenKhoa] [nvarchar](10) NULL,
	[NamThanhLap] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaKhoa] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[KhoaHoc]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[Lop]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[MonHoc]    Script Date: 8/13/2024 9:37:17 PM ******/
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
/****** Object:  Table [dbo].[SinhVien]    Script Date: 8/13/2024 9:37:17 PM ******/
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
