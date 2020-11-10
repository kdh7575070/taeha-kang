--TABLE 만들기

CREATE TABLE DEPARTMENT(
  Dname VARCHAR(15) NOT NULL,
  Dnumber NUMBER NOT NULL,
  Mgr_ssn CHAR(9) DEFAULT '888665555' NOT NULL,
  Mgr_start_date DATE,
  PRIMARY KEY(Dnumber),
  UNIQUE(Dname)
);

CREATE TABLE EMPLOYEE(
  Fname VARCHAR(15) NOT NULL,
  Minit CHAR,
  Lname VARCHAR(15),
  Ssn CHAR(9) NOT NULL,
  Bdate DATE,
  Address VARCHAR(30),
  Sex CHAR,
  Salary NUMBER(10,2),
  Super_ssn CHAR(9),
  Dno NUMBER DEFAULT 1 NOT NULL,
  PRIMARY KEY(Ssn)
);

-- DATA삽입

INSERT INTO EMPLOYEE VALUES ('John', 'B', 'Smith', '123456789', TO_DATE('1965-01-09', 'yyyy-mm-dd'), '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
INSERT INTO EMPLOYEE VALUES ('Franklin', 'T', 'Wong', '333445555', TO_DATE('1968-01-19', 'yyyy-mm-dd'), '368 Voss, Houstom, TX', 'F', 40000, '888665555', 5);
INSERT INTO EMPLOYEE VALUES ('Alicia', 'J', 'Zelaya', '999887777', TO_DATE('1968-01-19', 'yyyy-mm-dd'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);
INSERT INTO EMPLOYEE VALUES ('Jennifer', 'S', 'Wallace', '987654321', TO_DATE('1941-06-20', 'yyyy-mm-dd'), '291 Berry, Bellaire, TX','F',43000,'888665555', 4);
INSERT INTO EMPLOYEE VALUES ('Ramesh', 'K', 'Narayan', '666884444', TO_DATE('1962-09-15', 'yyyy-mm-dd'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);
INSERT INTO EMPLOYEE VALUES ('Joyce', 'A', 'English', '453453453', TO_DATE('1972-07-31', 'yyyy-mm-dd'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);
INSERT INTO EMPLOYEE VALUES ('Ahmad', 'V', 'Jabbar', '987987987', TO_DATE('1969-03-29', 'yyyy-mm-dd'), '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);
INSERT INTO EMPLOYEE VALUES ('James', 'E', 'Borg', '888665555', TO_DATE('1937-11-10', 'yyyy-mm-dd'), '450 Stone, Houston, TX','M',55000,Null, 1);

INSERT INTO DEPARTMENT VALUES ('Research', 5, '333445555', TO_DATE('1988-05-22', 'yyyy-mm-dd'));
INSERT INTO DEPARTMENT VALUES ('Administration', 4, '987654321', TO_DATE('1995-01-01', 'yyyy-mm-dd'));
INSERT INTO DEPARTMENT VALUES ('Headquarters', 1, '888665555', TO_DATE('1981-06-19', 'yyyy-mm-dd'));

-- FK추가

ALTER TABLE DEPARTMENT ADD FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;
ALTER TABLE EMPLOYEE ADD FOREIGN KEY(Super_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;
ALTER TABLE EMPLOYEE ADD FOREIGN KEY (Dno) REFERENCES Department(dnumber) ON DELETE SET NULL;
  
commit;

select * from employee;
select * from department;

create table DEPT_LOCATIONS(
  Dnumber NUMBER NOT NULL,
  Dlocation VARCHAR(15) NOT NULL,
  PRIMARY KEY(Dnumber, Dlocation)
);

CREATE TABLE PROJECT(
  Pname VARCHAR(15) NOT NULL,
  Pnumber NUMBER NOT NULL,
  Plocation VARCHAR(15),
  Dnum NUMBER NOT NULL,
  PRIMARY KEY(Pnumber),
  UNIQUE(Pname)
);

CREATE TABLE WORKS_ON(
  Essn CHAR(9) NOT NULL,
  Pno NUMBER NOT NULL,
  Hours DECIMAL(3,1),
  PRIMARY KEY(Essn, Pno)
);

CREATE TABLE DEPENDENT(
  Essn CHAR(9) NOT NULL,
  Dependent_name VARCHAR(15) NOT NULL,
  Sex CHAR,
  Bdate DATE,
  Relationship VARCHAR(8),
  PRIMARY KEY(Essn, Dependent_name)
);

commit;

select * from dept_locations;
select * from project;
select * from works_on;
select * from dependent;

--DATA 삽입

INSERT INTO DEPT_LOCATIONS VALUES (1, 'Houston');
INSERT INTO DEPT_LOCATIONS VALUES (4, 'Stafford');
INSERT INTO DEPT_LOCATIONS VALUES (5, 'Bellaire');
INSERT INTO DEPT_LOCATIONS VALUES (5, 'Sugarland');
INSERT INTO DEPT_LOCATIONS VALUES (5, 'Houston');

INSERT INTO WORKS_ON VALUES ('123456789', 1, 32.5);
INSERT INTO WORKS_ON VALUES ('123456789', 2, 7.5);
INSERT INTO WORKS_ON VALUES ('666884444', 3, 40.0);
INSERT INTO WORKS_ON VALUES ('453453453', 1, 20.0);
INSERT INTO WORKS_ON VALUES ('453453453', 2, 20.0);
INSERT INTO WORKS_ON VALUES ('333445555', 2, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 3, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 10, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 20, 10.0);
INSERT INTO WORKS_ON VALUES ('999887777', 30, 30.0);
INSERT INTO WORKS_ON VALUES ('999887777', 10, 10.0);
INSERT INTO WORKS_ON VALUES ('987987987', 10, 35.0);
INSERT INTO WORKS_ON VALUES ('987987987', 30, 5.0);
INSERT INTO WORKS_ON VALUES ('987654321', 30, 20.0);
INSERT INTO WORKS_ON VALUES ('987654321', 20, 15.0);
INSERT INTO WORKS_ON VALUES ('888665555', 20, NULL);
  
INSERT INTO PROJECT VALUES ('ProductX', 1, 'Bellaire', 5);
INSERT INTO PROJECT VALUES ('ProductY', 2, 'Sugarland', 5);
INSERT INTO PROJECT VALUES ('ProductZ', 3, 'Houston', 5);
INSERT INTO PROJECT VALUES ('Computerization', 10, 'Stafford', 4);
INSERT INTO PROJECT VALUES ('Reorganization', 20, 'Houston', 1);
INSERT INTO PROJECT VALUES ('Newbenefits', 30, 'Stafford', 4);
  
INSERT INTO DEPENDENT VALUES ('333445555', 'Alice', 'F', TO_DATE('1986-04-05', 'yyyy-mm-dd'),'Daughter');
INSERT INTO DEPENDENT VALUES ('333445555', 'Theodore', 'M', TO_DATE('1983-10-25', 'yyyy-mm-dd'),'Son');
INSERT INTO DEPENDENT VALUES ('333445555', 'Joy', 'F', TO_DATE('1958-05-03', 'yyyy-mm-dd'),'Spouse');
INSERT INTO DEPENDENT VALUES ('987654321', 'Abner', 'M', TO_DATE('1942-02-28', 'yyyy-mm-dd'),'Spouse');
INSERT INTO DEPENDENT VALUES ('123456789', 'Michael', 'M', TO_DATE('1988-01-04', 'yyyy-mm-dd'),'Son');
INSERT INTO DEPENDENT VALUES ('123456789', 'Alice', 'F', TO_DATE('1988-12-30', 'yyyy-mm-dd'),'Daughter');
INSERT INTO DEPENDENT VALUES ('123456789', 'Elizabeth', 'F', TO_DATE('1967-05-05', 'yyyy-mm-dd'),'Spouse');

-- FK 추가

ALTER TABLE DEPT_LOCATIONS ADD FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE;
ALTER TABLE PROJECT ADD FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber) ON DELETE SET NULL;
ALTER TABLE WORKS_ON ADD FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;
ALTER TABLE WORKS_ON ADD FOREIGN KEY (Pno) REFERENCES PROJECT(Pnumber) ON DELETE SET NULL;
ALTER TABLE DEPENDENT ADD FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE;

commit;

--질의

select Fname, Minit, Lname from Project, Works_on, Employee where DNO=5 and Salary >= 10000 and Pname = 'ProductZ' and Pno = Pnumber and Essn = ssn order by Lname ASC;
select Dname, Ssn, Lname from Employee, Department where Address like '%Dallas%' and Dnumber = Dno and Super_ssn = '987654321';
select Lname, Hours from Employee, Works_on, Project where Pname = 'ProductX' and Pno = Pnumber and Ssn = Essn order by Hours DESC;
select Lname, Fname, Hours from Employee, Works_on, Project where Pname = 'Computerization' and Pno = Pnumber and Hours >= 10 and Ssn = Essn order by Hours ASC;
select Fname, Relationship from Dependent, Employee where Essn = Ssn and Super_ssn = '333445555';

--삭제

delete from Dependent where Essn = '333445555';
select * from Dependent;
delete from Department where Dnumber = 5;
delete from Works_on where Pno = 30;
select * from Works_on;

rollback;
select * from Works_on;

--업뎃

update Project p set p.Plocation = 'Houston' where Dnum = 5;
select * from Project where Dnum = '5';
update Employee e set e.Super_ssn = NULL where Ssn = '123456789';
select * from Employee where Ssn = '123456789';
update Department d set d.Dname = 'Design' where Dnumber = 5;
select * from Department where Dnumber = 5;

rollback;
select * from Department;