use HowKteam
go

select * from dbo.NGUOITHAN where TEN = 'Vy'

begin transaction
delete dbo.NGUOITHAN where TEN = 'Hùng'
-- chuỗi thao tác loằn ngoằn phức tạp
rollback -- hủy bỏ trans

--------------------------------------------------------------------

begin transaction
delete dbo.NGUOITHAN where TEN = 'Hùng'
-- chuỗi thao tác loằn ngoằn phức tạp
commit -- chấp nhận trans

declare @Trans varchar(20)
select @Trans = 'Trans1'

---------------------------------------------------------------------

begin transaction @trans
delete dbo.NGUOITHAN where TEN = 'Hùng'
-- chuỗi thao tác loằn ngoằn phức tạp
commit transaction @Trans -- chấp nhận trans

---------------------------------------------------------------------

begin transaction
save transaction Trans1
delete dbo.NGUOITHAN where TEN = 'Hùng'

save transaction Trans2
delete dbo.NGUOITHAN where TEN = 'Vy'
rollback transaction Trans1