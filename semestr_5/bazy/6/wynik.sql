create table bestEmp(ename char(10), sal numeric(7,2), comm numeric(7,2));

create function bestemp_trigger() returns trigger as '
DECLARE
	item record;
BEGIN
	if new.comm>new.sal then
		insert into bestemp(ename,sal,comm) values(new.ename,new.sal,new.comm);
	end if;
	return new;
END;'
LANGUAGE 'plpgsql';
		
create trigger bestemp_trigger_2 after insert or update on emp for each row execute procedure bestemp_trigger();

create function deldept_trigger(integer) returns void as '
	DELETE FROM emp where emp.deptno=$1;'
LANGUAGE 'SQL';

create trigger deldept_trigger_2 before delete on dept for each row execute procedure deldept_trigger(deptno);

