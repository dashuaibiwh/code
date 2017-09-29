Create table Student(
	Sno char(20) primary key,
	Sname varchar(20),
	Ssex char(2) check(Ssex in('��','Ů')),
	Sage smallint,
	Sdept	varchar(20)
);

Create table Course(
	Cno char(20) primary key,
	Cname varchar(20),
	Cpno  varchar(20),
	Ccredit INT
);
 Create table SC(
	Sno char(20) primary key,
	Cno char(20),
	Grade INT
);

/*1*/
select Student.Sname,Course.Cname,SC.Grade
from Student,Course,SC
where Student.Sno=SC.Sno
AND Course.Cno=SC.Cno

/*2*/
select Student.Sno,Student.Sname,Course.Cname,SC.Grade
from Student left outer join SC on(Student.Sno=SC.Sno),Course

/*3*/
select Sname,Sage
from Student
where Sage < ANY(select Sage
				 from Student
				 where Sdept='��ϢѧԺ')
And Sdept<>'��ϢѧԺ'

/*4*/
select Sname
from Student
where not exists(
		select *from Course
		where not exists(
			select *from SC
			where Sno=Student.Sno
			AND Cno = Course.Cno
		)		
)

/*5*/
select *from Student where Sno in(
    select Sno from SC where Grade > (
          select Grade from SC 
		where Sno = ( select Sno from Student where Sname = '�Թ���')
		and Cno = (select Cno from Course where Cname = '���ÿ�����')
    )
	and Cno = (select Cno from Course where Cname = '���ÿ�����')
)


select * from student where sno in (select sc.sno 
from sc,(select sc.* 
from sc,(select sno 
from student where sname = '�Թ���') s 
where sc.sno = s.sno) g 
where sc.grade>g.grade)

/*6*/
select Student.Sname,Avg(Grade)as SCORE 
from Student,SC
group by Student.Sname

	
/*7*/
select Student.Sno,Sum(SC.Grade) as CREDITSUM 
from Student,SC
where Sage<21
AND Student.Sdept='��ϢѧԺ'  
AND SC.Sno = Student.Sno
group by Student.Sno
order by Sum(SC.Grade)


	
/*8*/
select cname,sname,grade
from Student,SC,Course 
where Student.sno =SC.sno 
and SC.cno =Course.cno  
and grade=(select MAX(grade) from SC where SC.cno =Course.cno )


/*9*/
select distinct Sname 
from Student,SC SCX
where not exists(
	select * from SC SCY
	where SCY.Sno = '2012001001' 
	AND NOT exists (
		select * from SC SCZ
		where SCZ.Sno=SCX.Sno AND
		SCZ.Cno=SCY.Cno
	)
);




insert into Student(Sno,Sname,Ssex,Sage,Sdept)
values ('2017001001','������','��',21,'��ϢѧԺ');



update SC
set Grade=Grade+10(
	select Sname
	from Student
	where Student.Sname='��Ц��'
)


select *from Student