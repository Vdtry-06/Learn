use HowKteam
go
-- check: cho nó nằm trong phạm vi mình mong muốn
-- Có thể tạo check y như khóa chính
-- C1:
create table TestCheck
(
	ID int primary key identity,
	LUONG int check(LUONG > 3000 and LUONG < 9000)
)
go
--
insert dbo.TestCheck (LUONG)
values (3001)
--

-- C2
create table TestCheck
(
	ID int primary key identity,
	LUONG int,
	check(LUONG > 3000 and LUONG < 9000)
)
go

-- C3
create table TestCheck
(
	ID int primary key identity,
	LUONG int,
	constraint CK_LUONG check(LUONG > 3000 and LUONG < 9000)
)
go

-- C4: sửa bảng
alter table TestCheck add constraint CK_LUONG
check(LUONG > 3000 and LUONG < 9000)