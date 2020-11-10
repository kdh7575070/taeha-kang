DROP TABLE EMPLOYEE_NEW;
CREATE TABLE EMPLOYEE_NEW AS (select * from EMPLOYEE);

create or replace TRIGGER Salary_violation
--event
BEFORE INSERT OR UPDATE OF Salary, Super_ssn ON EMPLOYEE FOR EACH ROW
DECLARE
  Salary_viol EMPLOYEE_NEW.Salary%TYPE;
  CURSOR C1
  IS
  select Salary from EMPLOYEE_NEW where Ssn = :new.Super_ssn;
BEGIN
  OPEN C1;
  LOOP
    FETCH C1 INTO Salary_viol;
    EXIT WHEN C1%NOTFOUND;
    IF (:new.Salary > Salary_viol ) THEN
      RAISE_APPLICATION_ERROR('-20000', 'The new salary is higher than supervisor salary.');
    END IF;
  END LOOP; 
END;
/

-- what if insert?
SET serveroutput ON;
UPDATE EMPLOYEE SET Salary = 56000 WHERE Ssn = '987654321';