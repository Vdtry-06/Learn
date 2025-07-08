use HowKteam
go

-- Xuất ra số lượng giáo viên trong từng bộ môn mà số gv > 2
-- having -> như where của select nhưng dành cho group by
-- having là where của group by
select bm.MABM, count(*) from dbo.GIAOVIEN as gv, dbo.BOMON as bm
where bm.MABM = gv.MABM
group by bm.MABM
having count(*) > 1

-- Xuất ra mức lương và tổng tuổi của giáo viên nhận mức lương đó
-- và có người thân
-- và tuổi phải lớn hơn tuổi trung bình
-- C1
select LUONG, sum(year(getdate()) - year(GIAOVIEN.NGSINH)), count(*) from dbo.GIAOVIEN, dbo.NGUOITHAN
where GIAOVIEN.MAGV = NGUOITHAN.MAGV and GIAOVIEN.MAGV in (select MAGV from dbo.NGUOITHAN)
group by LUONG, GIAOVIEN.NGSINH
having year(getdate()) - year(GIAOVIEN.NGSINH) <
(
	(select sum(year(getdate()) - year(GIAOVIEN.NGSINH)) from dbo.GIAOVIEN)
	/ (select count(*) from dbo.GIAOVIEN)
)

--C2
select gv.LUONG, sum(year(getdate()) - year(gv.NGSINH)), count(*) from dbo.GIAOVIEN as gv, dbo.NGUOITHAN as nt
where nt.MAGV = gv.MAGV
group by gv.LUONG, gv.NGSINH
having count(*) > 0 and year(getdate()) - year(gv.NGSINH) <
(
	(select sum(year(getdate()) - year(GIAOVIEN.NGSINH)) from dbo.GIAOVIEN)
	/ (select count(*) from dbo.GIAOVIEN)
)