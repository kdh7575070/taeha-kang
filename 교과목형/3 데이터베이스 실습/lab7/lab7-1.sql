
SET serveroutput ON;

--프로시져 생성
CREATE OR REPLACE PROCEDURE ComputeMaxTotalHours (
  department_num IN DEPARTMENT.DNUMBER%TYPE,
  max_of_total_hours OUT WORKS_ON.HOURS%TYPE)
AS  
BEGIN
  DECLARE
    CURSOR C1
    IS

      select Pnumber as Project_num, total_hours 
      from (select Pnumber from PROJECT where Dnum = department_num order by Pnumber) 
      natural join (select Pno as Pnumber, SUM(Hours) as total_hours FROM WORKS_ON group by pno);
  --nested begin 1  
  BEGIN
    DBMS_OUTPUT.PUT_LINE('1. receive a department number: ' || department_num);
    DBMS_OUTPUT.PUT_LINE('2. compute');
    DBMS_OUTPUT.PUT_LINE('department_num  | project_num |  total_hours');
    
    FOR records IN C1 LOOP
       EXIT WHEN C1%NOTFOUND;
       DBMS_OUTPUT.PUT_LINE(department_num || '                 ' || records.Project_num || '              ' ||records.total_hours);
    END LOOP;
    
    select max(total_hours) into max_of_total_hours
    from (select Pnumber from PROJECT where Dnum = department_num order by Pnumber) 
    natural join (select Pno as Pnumber, SUM(Hours) as total_hours from WORKS_ON group by pno);

     --nested begin 2  
    BEGIN
      DBMS_OUTPUT.PUT_LINE('3. max of total hours: ' || max_of_total_hours);
    END;
  END;
END; 
/

DECLARE
  MaxOfTotalHours WORKS_ON.HOURS%TYPE;
BEGIN 
  ComputeMaxTotalHours(5, MaxOfTotalHours);
  DBMS_OUTPUT.PUT_LINE('4. (simple) max of total hours: ' || MaxOfTotalHours);
END;
/